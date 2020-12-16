#ifndef VIEWER_POINTLIGHT_H
#define VIEWER_POINTLIGHT_H

#include "BaseLight.h"

namespace lights {

using math::Vector3d;

class PointLight: public BaseLight {
public:
    PointLight(Vector3d &position, float intensity);

    Vector3d getDirection(math::Vector3d &target) override;
    float getDistance(math::Vector3d &target) override;
    float getIntensity() const override;
    void change(Vector3d p, float i) override;
private:
    Vector3d _position;
    float _intensity;
};

} // namespace lights

#endif //VIEWER_POINTLIGHT_H
