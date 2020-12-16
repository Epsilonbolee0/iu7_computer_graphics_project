#ifndef VIEWER_PYRAMID_H
#define VIEWER_PYRAMID_H

#include "GeometryObject.h"
#include "Triangle.h"

namespace objects {

class Pyramid: public GeometryObject {
public:
    Pyramid(Vector3d point, float base_side, float height, float angle);

    void intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
    const std::vector<Triangle*> get_polygons() const;
private:
    std::vector<Triangle*> _polygons;
    Triangle *_last_intersected;
};

} // namespace objects

#endif //VIEWER_PYRAMID_H
