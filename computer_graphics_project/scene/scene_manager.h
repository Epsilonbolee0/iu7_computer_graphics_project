#pragma once

#include "base_manager.h"
#include "../exceptions/no_camera_exception.h"
#include "scene.h"

namespace scene {

class SceneManager: public BaseManager {
public:
    SceneManager();

    std::shared_ptr<Scene> getScene();
    void setCamera();
    std::shared_ptr<objects::Camera> getCamera();
private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<objects::Camera> _camera;
};

}
