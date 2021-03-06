#ifndef VIEWER_RAYTRACER_H
#define VIEWER_RAYTRACER_H

#include "math/vector3d.h"
#include "objects/geometry_objects/Ray.h"
#include "objects/geometry_objects/GeometryObject.h"
#include "objects/material.h"
#include "scene/scene.h"
#include <random>

namespace raytracer {

using math::Vector3d;
using objects::Ray;

struct Intersection {
    std::shared_ptr<objects::Model> model;
    float t1;
    bool ok;
};

class Raytracer {
public:
    void setScene(scene::Scene *scene);
    void setSamplesNum(int s_num) { _samples_num = s_num; }
    Vector3d traceRay(Ray ray, float min_t, float max_t, int depth);
private:
    static constexpr float eps = 1e-3;

    Vector3d reflectRay(Vector3d &v1, Vector3d &v2);
    Intersection closestIntersection(Ray &ray, float min_t, float max_t);
    float computeLighting(Vector3d &point, Vector3d &normal, Vector3d &view, float specular);

    int _samples_num;
    scene::Scene *_scene;
    std::default_random_engine generator;
};

} // namespace raytracer

#endif //VIEWER_RAYTRACER_H
