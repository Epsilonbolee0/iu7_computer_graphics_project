#pragma once

#include <memory>
#include <vector>

#include "../exceptions/no_camera_exception.h"
#include "../exceptions/object_search_exception.h"
#include "../objects/composite.h"
#include "../objects/model.h"
#include "../objects/camera.h"

namespace scene {

using namespace objects;

class Scene {
public:
    Scene();

    void addModel(std::shared_ptr<Model> obj);
    void setCamera(std::shared_ptr<Camera> obj);

    void removeModel(std::shared_ptr<Object> obj);
    void removeCamera();

    std::shared_ptr<Composite> getModelsComposite();
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Object> getObject(std::string model_name);
    std::vector<std::shared_ptr<Object>> getObjects();
private:
    std::shared_ptr<Composite> _objects;
    std::shared_ptr<Camera> _camera;
};

}
