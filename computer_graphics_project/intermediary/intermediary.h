#pragma once

#include <memory>
#include "../exceptions/object_type_exception.h"
#include "../math/point.h"
#include "../render/renderer.h"
#include "../transformations/tranformer.h"
#include "../transformations/camera_manager.h"
#include "../uploading/file_loader.h"
#include "../uploading/model_loader.h"
#include "../scene/scene_manager.h"
#include "../objects/model.h"

namespace intermediary {

using objects::Object;
using objects::Model;
using objects::Camera;
using render::BaseDrawer;
using math::Point;

class Intermediary
{
public:
    Intermediary();

    void addModel(std::string file_name, std::string model_name);
    void removeModel(std::string model_name);

    void setCamera();
    void removeCamera();

    void transformCamera(Point& move, Point& rotate);
    void transformModel(std::string model_name, Point& move, Point& rotate)

    void draw(std::shared_ptr<BaseDrawer> drawer);

private:
    std::shared_ptr<render::Renderer> _renderer;
    uploading::ModelLoader _loader;
    transformations::Transformer _transformer;
    transformations::CameraManager _camera_manager;
    scene::SceneManager _scene_manager;
};

}
