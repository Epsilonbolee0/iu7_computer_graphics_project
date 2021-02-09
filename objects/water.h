#ifndef WATER_H
#define WATER_H

#include "model.h"
#include "math/vector3d.h"

namespace objects {

using math::Vector3d;

class Water : public Model {
public:
    explicit Water();

    void _set_object(Vector3d land_beneath, float volume);
    void _set_material(float volume);
    static std::vector<std::shared_ptr<Model>> sphere_approx(Vector3d land_beneath, float volume);
};

const Vector3d LIGHT_BLUE = Vector3d(175, 238, 238);
const Vector3d BLUE = Vector3d(0, 206, 209);
const Vector3d DARK_BLUE = Vector3d(0, 191, 255);
const Vector3d VERY_DARK_BLUE = Vector3d(65, 105, 225);

}

#endif // WATER_H
