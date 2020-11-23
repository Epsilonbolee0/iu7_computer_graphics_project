#include "scene_manager.h"

namespace scene {

SceneManager::SceneManager(): _scene(new Scene()){}

std::shared_ptr<Scene> SceneManager::getScene() {
    return _scene;
}

void SceneManager::setCamera() {
    _camera = _scene->getCamera();
}

std::shared_ptr<Camera> SceneManager::getCamera() {
    if (!_camera) {
        throw exceptions::NoCameraException();
    }
    return _camera;
}

}
