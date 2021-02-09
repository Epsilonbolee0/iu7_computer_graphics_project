#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>
#include "math/vector3d.h"
#include "objects/model.h"
#include "objects/material.h"
#include "objects/geometry_objects/GeometryObject.h"

namespace uploading {

using objects::Model;
using objects::GeometryObject;
using math::Vector3d;

class BaseLoader
{
public:
    virtual ~BaseLoader() = default;

    virtual void open(std::string source_name) = 0;
    virtual void close() = 0;
    virtual std::shared_ptr<GeometryObject> readObjectInfo() = 0;
    virtual Material readMaterialInfo() = 0;
    virtual std::size_t readSceneInfo() = 0;
    virtual Vector3d readPoint() = 0;
    virtual std::string llt() = 0;
};

}

#endif // BASE_LOADER_H
