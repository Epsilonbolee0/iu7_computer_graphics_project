#ifndef VIEWER_BASELIGHT_H
#define VIEWER_BASELIGHT_H

#include "math/vector3d.h"

namespace lights {

class BaseLight {
public:
    virtual math::Vector3d getDirection(math::Vector3d &target) = 0;
    virtual float getDistance(math::Vector3d &target) = 0;
    virtual float getIntensity() const = 0;
    virtual void change(math::Vector3d p, float i) = 0;
};

} // namespace lights

#endif //VIEWER_BASELIGHT_H

