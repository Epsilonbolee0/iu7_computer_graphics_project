#include "Prism.h"

namespace objects {

Prism::Prism(math::Vector3d point, float base_width, float height, float angle) {
    Vector3d left_cl_bot = point;
    Vector3d right_cl_bot = {
        point.x() + base_width * std::cos(angle),
        point.y(),
        point.z() + base_width * std::sin(angle)
    };
    Vector3d far_bot = {
        point.x() + base_width * std::cos(angle + M_PI / 3),
        point.y(),
        point.z() + base_width * std::sin(angle)
    };
    Vector3d left_cl_top = {point.x(), point.y() + height, point.z()};
    Vector3d right_cl_top = {right_cl_bot.x(), right_cl_bot.y() + height, right_cl_bot.z()};
    Vector3d far_top = {far_bot.x(), far_bot.y() + height, far_bot.z()};

    _polygons.push_back(new Triangle(left_cl_top, right_cl_bot, left_cl_bot)); // close
    _polygons.push_back(new Triangle(right_cl_top, right_cl_bot, left_cl_top));
    _polygons.push_back(new Triangle(left_cl_bot, far_bot, left_cl_top)); // left
    _polygons.push_back(new Triangle(far_bot, far_top, left_cl_top));
    _polygons.push_back(new Triangle(far_bot, far_top, right_cl_bot)); // right
    _polygons.push_back(new Triangle(right_cl_bot, right_cl_top, far_top));
    _polygons.push_back(new Triangle(left_cl_top, far_top, far_top)); // top
    _polygons.push_back(new Triangle(left_cl_top, far_top, right_cl_top));
    _polygons.push_back(new Triangle(left_cl_bot, far_bot, right_cl_bot)); // bottom
    _polygons.push_back(new Triangle(right_cl_bot, far_bot, far_bot));
}

void Prism::intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) {
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

Vector3d Prism::getNormal(Vector3d &point, const Vector3d &direction) const {
    return _last_intersected->getNormal(point, direction);
}

const std::vector<Triangle *> Prism::get_polygons() const {
    return _polygons;
}

}
