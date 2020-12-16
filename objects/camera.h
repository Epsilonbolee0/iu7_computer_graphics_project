#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "math/vector3d.h"

namespace objects {

class Camera: public Object {
public:
    Camera();
    Camera(std::string name);

    const math::Vector3d &getPosition() const;
    void setPosition(const math::Vector3d &_position);
    float getXAngle() const;
    void setXAngle(float _x_angle);
    float getYAngle() const;
    void setYAngle(float _y_angle);
    float getZAngle() const;
    void setZAngle(float _z_angle);

    void transform(const math::Matrix *matrix);
private:
    math::Vector3d _position;
    float _x_angle;
    float _y_angle;
    float _z_angle;
};

} // namespace objects

#endif // CAMERA_H
