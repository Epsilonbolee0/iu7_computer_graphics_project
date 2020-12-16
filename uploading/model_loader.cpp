#include "model_loader.h"

namespace uploading {

ModelLoader::ModelLoader(BaseLoader *loader): _loader(loader) {}

std::vector<std::shared_ptr<objects::Model>> ModelLoader::loadModel(std::string source_name, std::string model_name) {
    _loader->open(source_name);

    std::size_t length = _loader->readSceneInfo();
    std::vector<std::shared_ptr<objects::Model>> _result;
    int _cnt = 0;
    _result.resize(100);

    for (std::size_t i = 0; i < length; i++) {
        std::shared_ptr<GeometryObject> _obj = _loader->readObjectInfo();
        Material _mat = _loader->readMaterialInfo();
        auto triangles = static_cast<Parallelepiped*>(_obj.get())->get_polygons();
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
