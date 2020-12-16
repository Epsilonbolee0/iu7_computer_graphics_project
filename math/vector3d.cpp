#include <cmath>
#include "vector3d.h"
#include "matrix.h"


namespace math {

Vector3d::Vector3d(): _x(0), _y(0), _z(0) {}

Vector3d::Vector3d(float x, float y, float z): _x(x), _y(y), _z(z) {}

float Vector3d::x() const {
    return _x;
}

float Vector3d::y() const {
    return _y;
}

float Vector3d::z() const {
    return _z;
}

void Vector3d::setX(float x) {
    _x = x;
}

void Vector3d::setY(float y) {
    _y = y;
}

void Vector3d::setZ(float z) {
    _z = z;
}

void Vector3d::transform(const Matrix *matrix) {
    std::vector<float> result(4);
    std::vector<float> data = {_x, _y, _z, 1.};
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            result[i] += data[j] * matrix->get(i, j);
        }
    }

    *this = {result[0], result[1], result[2]};
}

float Vector3d::product(Vector3d point) const {
    return _x * point.x() + _y * point.y() + _z * point.z();
}

float Vector3d::length() {
    return std::sqrt(product(*this));
}

Vector3d Vector3d::multScalar(float k) const {
    return {_x * k, _y * k, _z * k};
}

Vector3d Vector3d::add(Vector3d &point) {
    return {_x + point.x(), _y + point.y(), _z + point.z()};
}

Vector3d Vector3d::subtract(const Vector3d &point) {
    return {_x - point.x(), _y - point.y(), _z - point.z()};
}
Vector3d Vector3d::clamp() {
    return Vector3d(std::min(255, std::max(0, int(_x))),
            std::min(255, std::max(0, int(_y))),
            std::min(255, std::max(0, int(_z))));
}

Vector3d Vector3d::cross(const Vector3d &point) {
    return {_y * point.z() - _z * point.y(), _z * point.x() - _x *point.z(), _x * point.y() - _y * point.x()};
}

} // namespace math
