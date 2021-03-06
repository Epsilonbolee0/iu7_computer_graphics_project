#include <cmath>
#include "Parallelepiped.h"

namespace objects {

Parallelepiped::Parallelepiped(Vector3d point, float width, float length, float height, float angle) {
    float phi = M_PI / 2 - angle;
    Vector3d left_cl_bot = point;
    Vector3d right_cl_bot = {
        point.x() + length * std::cos(angle),
        point.y(),
        point.z() + std::sin(angle)
    };
    Vector3d left_far_bot = {
        point.x() - width * std::cos(phi),
        point.y(),
        point.z() + width * std::sin(phi)
    };
    Vector3d right_far_bot = {
        left_far_bot.x() + length * std::cos(angle),
        left_far_bot.y(),
        left_far_bot.z() + std::sin(angle)
    };
    Vector3d left_cl_top = {point.x(), point.y() + height, point.z()};
    Vector3d left_far_top = {left_far_bot.x(), left_far_bot.y() + height, left_far_bot.z()};
    Vector3d right_cl_top = {right_cl_bot.x(), right_cl_bot.y() + height, right_cl_bot.z()};
    Vector3d right_far_top = {right_far_bot.x(), right_far_bot.y() + height, right_far_bot.z()};

    _polygons.push_back(new Triangle(left_cl_top, right_cl_bot, left_cl_bot)); // close
    _polygons.push_back(new Triangle(right_cl_top, right_cl_bot, left_cl_top));
    _polygons.push_back(new Triangle(left_cl_bot, left_far_bot, left_cl_top)); // left
    _polygons.push_back(new Triangle(left_far_bot, left_far_top, left_cl_top));
    _polygons.push_back(new Triangle(left_far_bot, right_far_bot, left_far_top)); // far
    _polygons.push_back(new Triangle(right_far_top, left_far_top, right_far_bot));
    _polygons.push_back(new Triangle(right_far_bot, right_far_top, right_cl_bot)); // right
    _polygons.push_back(new Triangle(right_cl_bot, right_cl_top, right_far_top));
    _polygons.push_back(new Triangle(left_cl_top, left_far_top, right_far_top)); // top
    _polygons.push_back(new Triangle(left_cl_top, right_far_top, right_cl_top));
    _polygons.push_back(new Triangle(left_cl_bot, left_far_bot, right_cl_bot)); // bottom
    _polygons.push_back(new Triangle(right_cl_bot, right_far_bot, left_far_bot));
}

void Parallelepiped::intersectRay(objects::Ray &ray, float &int1, float &int2, bool &isInt) {
    float t_int1 = 0.0, t_int2 = 0.0;
    auto is_intersected = false;

    for (const auto &polygon: _polygons) {
        polygon->intersectRay(ray, t_int1, t_int2, isInt);
        if (isInt) {
            is_intersected = true;
            if (t_int1 < int1) {
                int1 = t_int1;
                _last_intersected = polygon;
            }
            if (t_int2 > int1 && t_int2 < int2) {
                int2 = t_int2;
            }
        }
    }

    isInt = is_intersected;
}

Vector3d Parallelepiped::getNormal(Vector3d &point, const Vector3d &direction) const {
    return _last_intersected->getNormal(point, direction);
}
const std::vector<Triangle *> Parallelepiped::get_polygons() const {
    return _polygons;
}

} // namespace objects
