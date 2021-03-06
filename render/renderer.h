#ifndef LAB4_RENDERER_H
#define LAB4_RENDERER_H

#include <memory>
#include <raytracer/Raytracer.h>
#include <mutex>
#include "base_drawer.h"
#include "../exceptions/drawer_exception.h"
#include "../scene/scene.h"
#include "../objects/model.h"
#include "../objects/camera.h"
#include "math/vector3d.h"
#include "../math/transform_matrix.h"
#include <QImage>

namespace render {

using namespace math;
using namespace objects;

class Renderer {
public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void render(scene::Scene &scene, int sample_num);
    void threadRender(scene::Scene &scene, int y0, int n);

private:
    std::shared_ptr<BaseDrawer> _drawer;
    raytracer::Raytracer _raytracer;
    std::mutex _mutex;
    QImage _buffer;

    Vector3d canvasToViewport(float x, float y);
    Vector3d rotatePoint(math::Vector3d &p, Camera &camera);
};

} // namespace render;

#endif //LAB4_RENDERER_H
