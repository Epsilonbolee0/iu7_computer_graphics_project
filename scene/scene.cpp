#include <lights/PointLight.h>
#include <math.h>
#include "scene.h"

namespace scene {

Scene::Scene(): _camera(new Camera) {
    Vector3d pos = {0, -1, 3};
    std::shared_ptr<GeometryObject> obj(new Sphere(pos, 1));
    std::shared_ptr<Model> mod(new Model("a"));

    Vector3d posl = {2, 3 ,0};
    std::shared_ptr<lights::BaseLight> l(new lights::PointLight(posl, 0.4));
    addLight(l);

    posl = {0, 2, -3};
    l.reset(new lights::PointLight(posl, 0.3));
    addLight(l);

    Vector3d posc = {2.5, 3, -8};
    _camera->setPosition(posc);
}

void Scene::removeModel(std::string name) {
    for (size_t i = 0; i < _objects.size(); i++) {
        while (i < _objects.size() && _objects[i]->getName() == name) {
            _objects.erase(_objects.begin() + i);
        }
    }
}

std::shared_ptr<Camera> Scene::getCamera() {
    return _camera;
}

std::shared_ptr<Object> Scene::getObject(std::string model_name) {
    for (auto &obj: _objects) {
        if (obj->getName() == model_name) {
            return obj;
        }
    }

    throw exceptions::ObjectSearchException();
}

void Scene::addModel(std::shared_ptr<Model> obj) {
    _objects.push_back(obj);
}

std::vector<std::shared_ptr<Model>> & Scene::getObjects() {
    return _objects;
}

std::vector<std::shared_ptr<lights::BaseLight>> &Scene::getLights() {
    return _lights;
}

void Scene::addLight(std::shared_ptr<lights::BaseLight> light) {
    _lights.push_back(light);
}

void Scene::changeLight(Vector3d &pos, float intensity) {
    _lights[0]->change(pos, intensity);
}

void Scene::clearScene() {
    _objects.clear();
}

} // namespace scene
