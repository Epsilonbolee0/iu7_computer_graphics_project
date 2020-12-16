#ifndef VIEWER_material_H
#define VIEWER_material_H

struct Material {
    math::Vector3d color;
    float specular;
    float reflective;
    float roughness;
    float transparency;
};

#endif //VIEWER_material_H
