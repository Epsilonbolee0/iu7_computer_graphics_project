#include "model_loader.h"
#include <QDebug>

namespace uploading {

ModelLoader::ModelLoader(BaseLoader *loader): _loader(loader) {}

std::vector<std::shared_ptr<objects::Model>> ModelLoader::loadModel(std::string source_name, std::string model_name) {
    _loader->open(source_name);

    std::size_t length = _loader->readSceneInfo();
    std::vector<std::shared_ptr<objects::Model>> _result;
    int _cnt = 0;
    _result.resize(1000);

    for (std::size_t i = 0; i < length; i++) {
        std::shared_ptr<GeometryObject> _obj = _loader->readObjectInfo();
        Material _mat = _loader->readMaterialInfo();

        std::vector<objects::Triangle*> triangles;
        auto _llt = _loader->llt();

        if (_llt == "Parallelepiped") {
            triangles = static_cast<Parallelepiped*>(_obj.get())->get_polygons();
        } else if (_llt == "Pyramid") {
            triangles = static_cast<Pyramid*>(_obj.get())->get_polygons();
        } else if (_llt == "Triangle" || _llt == "Sphere") {
            Model* temp = new Model(model_name + "№" + std::to_string(i + 1));
            temp->set_object(_obj);
            temp->set_material(_mat);
            _result[_cnt++].reset(temp);
        } else if (_llt == "Prism") {
            triangles = static_cast<Prism*>(_obj.get())->get_polygons();
        }

        for (auto& triangle : triangles) {
            Model* temp = new Model(model_name + "№" + std::to_string(i + 1));
            _obj.reset(triangle);
            temp->set_object(_obj);
            temp->set_material(_mat);
            _result[_cnt++].reset(temp);
        }
    }

    _result.resize(_cnt);
    _loader->close();

    return _result;
}

}
