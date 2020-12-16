#ifndef VIEWER_PRISM_H
#define VIEWER_PRISM_H

#include <cmath>
#include "Triangle.h"

namespace objects {

class Prism: public GeometryObject {
public:
    Prism(Vector3d point, float base_width, float height, float angle);

    void intersectRay(Ray &ray, float &int1, float &int2, bool &isInt) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
    const std::vector<Triangle *> get_polygons() const;
private:
    std::vector<Triangle*> _polygons;
    Triangle *_last_intersected;
};

} // namespace objects


#endif //VIEWER_PRISM_H
