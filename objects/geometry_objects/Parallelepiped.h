#ifndef VIEWER_PARALLELEPIPED_H
#define VIEWER_PARALLELEPIPED_H

#include "Triangle.h"

namespace objects {

class Parallelepiped: public GeometryObject {
public:
    Parallelepiped(Vector3d point, float width, float length, float height, float angle);

    void intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
    const std::vector<Triangle*> get_polygons() const;
private:
    std::vector<Triangle*> _polygons;
    Triangle *_last_intersected;
};

} // namespace objects

#endif //VIEWER_PARALLELEPIPED_H
