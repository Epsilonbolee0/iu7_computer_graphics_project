#include <cmath>
#include <iostream>
#include "Raytracer.h"
#include "objects/geometry_objects/Parallelepiped.h"
#include "QDebug"

namespace raytracer {

Vector3d Raytracer::reflectRay(math::Vector3d &v1, math::Vector3d &v2) {
    return v2.multScalar(2 * v1.product(v2)).subtract(v1);
}

void Raytracer::setScene(scene::Scene *scene) {
    _scene = scene;
}

Intersection Raytracer::closestIntersection(Ray &ray, float min_t, float max_t) {
    float closest_t = 1.7e+308;
    std::shared_ptr<objects::Model> closest_model;
    auto models = _scene->getObjects();

    for (auto &obj: models) {
        float t1, t2;
        bool isIntersect = false;
        obj->get_object()->intersectRay(ray, t1, t2, isIntersect);
        if (not isIntersect) {
            continue;
        }

        if (t1 < closest_t and min_t < t1 and t1 < max_t) {
            closest_t = t1;
            closest_model = obj;
        }
        if (t2 < closest_t and min_t < t2 and t2 < max_t) {
            closest_t = t2;
            closest_model = obj;
        }
    }

    bool ok = (bool) closest_model;

    return {closest_model, closest_t, ok};
}

float Raytracer::computeLighting(Vector3d &point, Vector3d &normal, Vector3d &view, float specular) {
    float intensity = 0.2;
    float length_n = normal.length();
    float length_v = view.length();

    auto lights = _scene->getLights();
    for (auto &light: lights) {
        Vector3d vec_l = light->getDirection(point);
        float t_max = vec_l.length();
        vec_l = vec_l.multScalar(1./vec_l.length());

        Ray ray{point, vec_l};
        auto blocker = closestIntersection(ray, eps, t_max);
        if (blocker.ok) {
            continue;
        }

        float n_dot_l = normal.product(vec_l);
        if (n_dot_l > 0) {
            intensity += light->getIntensity() * n_dot_l / (length_n * vec_l.length());
        }

        if (specular >= 0) {
            Ray reflected_ray = ray.reflect(normal);

            float r_dot_v = reflected_ray.direction().product(view);
            if (r_dot_v > 0) {
                intensity += light->getIntensity()
                    * std::pow(r_dot_v / (reflected_ray.direction().length() * length_v), specular);
            }
        }
    }

    return intensity;
}

Vector3d Raytracer::traceRay(Ray ray, float min_t, float max_t, int depth) {
    auto intersection = closestIntersection(ray, min_t, max_t);
    if (not intersection.ok) {
        return {255, 140, 0};
    }

    auto object = intersection.model->get_object();
    auto material = intersection.model->get_material();

    auto intersection_point = ray.direction().multScalar(intersection.t1);
    intersection_point = ray.origin().add(intersection_point);
    auto normal = object->getNormal(intersection_point, ray.direction());

    auto view = ray.direction().multScalar(-1);
    auto lighting = computeLighting(intersection_point, normal, view, material.specular);
    auto local_color = material.color.multScalar(lighting);

    if (material.reflective <= 0 or depth <= 0) {
         return local_color;
    }

    auto reflected_dir = reflectRay(view, normal);

    std::uniform_real_distribution<double> distribution(0., 1.);
    Vector3d reflected_color = {0, 0, 0};

    auto color = local_color.multScalar(1 - material.reflective);
    reflected_color = reflected_color.multScalar(material.reflective);

    color.add(reflected_color);
    return color;
}

}
