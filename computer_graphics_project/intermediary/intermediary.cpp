#include "intermediary.h"

namespace intermediary {

Intermediary::Intermediary():
    _renderer(new renderer::Renderer),
    _loader(new uploading::FileLoader) {}

void Intermediary::addModel(std::string file_name, std::string name) {
    std::shared_ptr<Model> model = _loader.loadModel(file_name, name);
    _scene_manager.getScene()->addModel(std::shared_ptr<objects::Model>(model));
}

void Intermediary::removeModel(std::string model_name) {
    auto scene = _scene_manager.getScene();
    scene->removeModel(scene->getObject(model_name));
}

void Intermediary::setCamera() {
    auto camera = new objects::Camera();
    _scene_manager.setCurrentCamera(camera_name);
}

void Intermediary::removeCamera(std::string model_name) {
    auto scene = _scene_manager.getScene();
    scene->removeCamera();
}

void Intermediary::transformCamera(int &move, int &rotate) {
    auto camera = _scene_manager.getScene()->getCamera();
    _transformer.moveObject(camera, move.x(), move.y(), move.z());
    _camera_manager.roll(camera, rotate.x());
    _camera_manager.pitch(camera, rotate.y());
    _camera_manager.yaw(camera, rotate.z());
}

void Intermediary::transformModel(std::string model_name, int &move, int &rotate) {
    auto obj = _scene_manager.getScene()->getObject(model_name);
    _transformer.moveObject(obj, move.x(), move.y(), move.z());
    _transformer.rotateObjectX(obj, rotate.x());
    _transformer.rotateObjectY(obj, rotate.y());
    _transformer.rotateObjectZ(obj, rotate.z());
}

void Intermediary::draw(std::shared_ptr<BaseDrawer> drawer) {
    _renderer->setDrawer(drawer);
    _renderer->setCamera(_scene_manager.getCamera());
    _scene_manager.getScene()->getModels()->accept(_renderer);
}

}
