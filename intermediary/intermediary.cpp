#include "intermediary.h"
#include <QDebug>

namespace intermediary {

Intermediary::Intermediary():
    _renderer(new render::Renderer),
    _model_loader(new uploading::FileLoader),
    _scene(){}

void Intermediary::addModel(const std::string &model_name, std::shared_ptr<objects::GeometryObject> &obj, const Material &mat) {
    auto model = std::make_shared<Model>(model_name);
    model->set_object(obj);
    model->set_material(mat);
    _scene.addModel(std::shared_ptr<objects::Model>(model));
}

void Intermediary::removeModel(const std::string &model_name) {
    _scene.removeModel(model_name);
}

void Intermediary::changeLight(math::Vector3d &pos, float intensity) {
    _scene.changeLight(pos, intensity);
}

void Intermediary::transformCamera(math::Vector3d &move, math::Vector3d &rotate) {
    auto camera = _scene.getCamera();
    _cam_manager.move(camera, move);
    _cam_manager.roll(camera, rotate.x());
    _cam_manager.pitch(camera, rotate.y());
    _cam_manager.yaw(camera, rotate.z());
}

void Intermediary::draw(std::shared_ptr<BaseDrawer> drawer, int sample_n) {
    _renderer->setDrawer(drawer);
    _renderer->render(_scene, sample_n);
}

void Intermediary::load(std::string file_name, std::string name) {
    _scene.clearScene();
    std::vector<std::shared_ptr<objects::Model>> models = _model_loader.loadModel(file_name, name);
    for (auto& model: models) {
        _scene.addModel(std::shared_ptr<objects::Model>(model));
    }
    i = 0;
    _flow_manager.loadMap(file_name);
}

void Intermediary::addWater(Quant quant_) {
     Water water_;
     auto water_data = Water::sphere_approx(quant_.pos(), quant_.volume());

     std::shared_ptr<objects::GeometryObject> _obj;

     for (auto& ptr: water_data) {
          _scene.addModel(ptr);
     }
}

void Intermediary::simulate(Vector3d start, float volume) {
    if (i == 0) {
        _flow_manager.execute(10, start, volume);
    }
    auto curr_log = _flow_manager.log()[i++];

    removeModel("water");
    while (curr_log.size()) {
        addWater(curr_log.front());
        curr_log.pop();
    }
}

} // namespace intermediary
