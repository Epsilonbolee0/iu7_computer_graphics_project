#include "scene.h"

namespace scene {

Scene::Scene(): _objects(new Composite) {}

void Scene::removeModel(std::shared_ptr<Object> obj) {
    ssize_t i = _objects->getIndex(obj);
    if (i >= 0) {
        _objects->remove(size_t(i));
    }
}

void Scene::removeCamera() {
    _camera.erase();
}

std::shared_ptr<Camera> Scene::getCamera() {
    return _camera;
}

std::shared_ptr<Object> Scene::getObject(std::string model_name) {
    auto objects = _objects->getObjects();
    for (auto &obj: objects) {
        if (obj->getName() == model_name) {
            return obj;
        }
    }

    throw exceptions::ObjectSearchException();
}

void Scene::addModel(std::shared_ptr<Model> obj) {
    _objects->add(obj);
}

void Scene::setCamera(std::shared_ptr<Camera> camera) {
    _camera = camera;
}

std::vector<std::shared_ptr<Object>> Scene::getObjects() {
    return _objects->getObjects();
}

std::shared_ptr<Composite> Scene::getModelsComposite() {
    return _objects;
}

}
