#include "camera.h"

namespace objects {

Camera::Camera(): Object(), _x_angle(0), _y_angle(0), _z_angle(0) {
    _position = math::Point(0, 0, 300);
}

const math::Point& Camera::getPosition() const {
    return _position;
}

void Camera::setPosition(const math::Point& position) {
    _position = position;
}

double Camera::getXAngle() const {
    return _x_angle;
}

void Camera::setXAngle(double x_angle) {
    _x_angle = x_angle;
}

double Camera::getYAngle() const {
    return _y_angle;
}

void Camera::setYAngle(double y_angle) {
    _y_angle = y_angle;
}

double Camera::getZAngle() const {
    return _z_angle;
}

void Camera::setZAngle(double z_angle) {
    _z_angle = z_angle;
}
