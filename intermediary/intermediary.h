#ifndef INTERMEDIARY_H
#define INTERMEDIARY_H

#include <memory>
#include "exceptions/object_type_exception.h"
#include "math/vector3d.h"
#include "render/renderer.h"
#include "transformations/camera_manager.h"
#include "objects/model.h"
#include "objects/water.h"
#include "uploading/model_loader.h"
#include "modeling/flow_manager.h"

namespace intermediary {

using objects::Object;
using objects::Model;
using objects::Water;
using objects::Camera;
using render::BaseDrawer;
using math::Vector3d;
using uploading::ModelLoader;
using modeling::FlowManager;
using modeling::Quant;

class Intermediary {
public:
    Intermediary();

    void addModel(const std::string &model_name, std::shared_ptr<objects::GeometryObject> &obj, const Material &mat);
    void removeModel(const std::string &model_name);

    void changeLight(Vector3d &pos, float intensity);
    void transformCamera(math::Vector3d &move, math::Vector3d &rotate);
    void transformModel(std::string model_name, Vector3d &move, Vector3d &scale, Vector3d &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer, int sample_n);
    void load(std::string filename, std::string name);
    void simulate(Vector3d start_, float volume);
    void addWater(Quant quant_);

private:
    std::size_t i;
    std::shared_ptr<render::Renderer> _renderer;
    transformations::CameraManager _cam_manager;
    modeling::FlowManager _flow_manager;
    ModelLoader _model_loader;
    scene::Scene _scene;
};

}

#endif // INTERMEDIARY_H
