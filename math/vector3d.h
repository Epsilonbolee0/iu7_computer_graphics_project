#ifndef POINT_H
#define POINT_H

#include <memory>
#include "matrix.h"

namespace math {

class Vector3d {
public:
    Vector3d();
    Vector3d(float x, float y, float z);

    float x() const;
    float y() const;
    float z() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float product(Vector3d point) const;
    float length();
    Vector3d multScalar(float k) const ;   
    Vector3d add(Vector3d &point);
    Vector3d subtract(const Vector3d &point);
    Vector3d clamp();
    Vector3d cross(const Vector3d &point);

    void transform(const math::Matrix *matrix);
private:
    float _x;
    float _y;
    float _z;
};

} // namespace math

#endif // POINT_H
