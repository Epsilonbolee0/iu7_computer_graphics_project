#include "water.h"
#include "geometry_objects/Sphere.h"
#include "geometry_objects/Parallelepiped.h"
#include "geometry_objects/GeometryObject.h"
#include <cmath>
#include <QDebug>

using objects::Water;
using objects::GeometryObject;
using objects::Model;
using objects::Sphere;

Water::Water(): Model("water") {}

void Water::_set_object(Vector3d land_beneath, float volume) {
    Vector3d vec_(land_beneath.x(), land_beneath.z(), land_beneath.y());
    auto obj = Parallelepiped(vec_, 1, 1, volume / 100, 0);
    std::shared_ptr<GeometryObject> _obj = std::make_shared<objects::Parallelepiped>(obj);
    set_object(_obj);
}

std::vector<std::shared_ptr<Model>> Water::sphere_approx(Vector3d land_beneath, float volume) {
    std::vector<std::shared_ptr<Model>> result_(64);
    Water temp_;
    std::size_t rows_ = 8, cols_ = 8;

    volume /= (100 * rows_ * cols_ * 6) ;
    float radius = pow(volume, 0.33);

    temp_._set_material(radius);

    float x = land_beneath.x() + 0.7 - radius * (rows_ - 1);
    float z = land_beneath.y() + 1  - radius * (cols_ - 1);
    Vector3d vec_(x, land_beneath.z(), z);


    for (std::size_t i = 0; i < rows_; i++) {
        vec_.setX(vec_.x() + radius / 1.1);
        vec_.setZ(z);
        qDebug() << vec_.x();

        for (std::size_t j = 0; j < cols_; j++) {
            Model *bulk = new Model("water");
            vec_.setZ(vec_.z() + radius);
            vec_.setY(vec_.y() + float(std::rand() % 100 - 50) / 800);
            auto obj = Sphere(vec_, radius / 1.1);
            std::shared_ptr<GeometryObject> _obj = std::make_shared<objects::Sphere>(obj);
            bulk->set_object(_obj);
            bulk->set_material(temp_.get_material());
            result_[i * rows_ + j].reset(bulk);
            vec_.setY(land_beneath.z());
        }
    }

    return result_;
}

void Water::_set_material(float volume) {
    Material mat_;
    mat_.specular = 0.35;
    mat_.reflective = 0.6;
    mat_.roughness = 0.0;
    mat_.transparency = 1;
    mat_.color = objects::DARK_BLUE;


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
