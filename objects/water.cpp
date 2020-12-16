#include "water.h"
#include "geometry_objects/Parallelepiped.h"

using objects::Water;

Water::Water(): Model("water") {}

void Water::_set_object(Vector3d land_beneath, float volume) {
    Vector3d vec_(land_beneath.x(), land_beneath.z(), land_beneath.y());
    auto obj = Parallelepiped(vec_, 1, 1, volume / 100, 0);
    std::shared_ptr<GeometryObject> _obj = std::make_shared<objects::Parallelepiped>(obj);
    set_object(_obj);
}

void Water::_set_material(float volume) {
    Material mat_;
    mat_.specular = 0.4;
    mat_.reflective = 0.5;
    mat_.roughness = 0.0;
    mat_.transparency = 0.5;

    if (volume < 5) {
        mat_.color = objects::LIGHT_BLUE;
    } else if (volume < 20) {
        mat_.color = objects::BLUE;
    } else if (volume < 40) {
        mat_.color = objects::DARK_BLUE;
    } else {
        mat_.color = objects::VERY_DARK_BLUE;
    }

    set_material(mat_);
}
