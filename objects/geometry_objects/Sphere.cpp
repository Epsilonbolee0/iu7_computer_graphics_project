#include <cmath>
#include "Sphere.h"

namespace objects {

Sphere::Sphere(Vector3d position, float radius)
    : _position(position), _radius(radius) {}

void Sphere::intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) {
    auto oc = ray.origin().subtract(_position);

    float k1 = ray.direction().product(ray.direction());
    float k2 = 2 * oc.product(ray.direction());
    float k3 = oc.product(oc) - _radius * _radius;

    float discriminant = k2 * k2 - 4 * k1 * k3;
    if (discriminant < 0) {
        int1 = 0;
        int2 = 0;
        isInt = false;
    } else {
        discriminant = std::sqrt(discriminant);
        int1 = (-k2 + discriminant) / (2 * k1);
        int2 = (-k2 - discriminant) / (2 * k1);
        isInt = true;
    }
}

Vector3d Sphere::getNormal(Vector3d &point, const Vector3d &) const {
    auto normal = point.subtract(_position);
    normal = normal.multScalar(1 / normal.length());
    return normal;
}

} // namespace objects
