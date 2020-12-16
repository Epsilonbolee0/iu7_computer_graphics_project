#ifndef VIEWER_SPHERE_H
#define VIEWER_SPHERE_H

#include <math/matrix.h>
#include "GeometryObject.h"

namespace objects {

class Sphere: public GeometryObject {
public:
    Sphere(Vector3d position, float radius);

    void intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
private:
    Vector3d _position;
    float _radius;
};

} // namespace objects

#endif //VIEWER_SPHERE_H
