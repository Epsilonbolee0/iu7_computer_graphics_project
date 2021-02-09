#ifndef FILE_LOADER_IMP_H
#define FILE_LOADER_IMP_H

#include <string>
#include <iostream>
#include <fstream>
#include "base_loader.h"
#include "objects/model.h"
#include "exceptions/file_open_exception.h"
#include "objects/geometry_objects/Parallelepiped.h"
#include "objects/geometry_objects/Sphere.h"
#include "objects/geometry_objects/Pyramid.h"
#include "objects/geometry_objects/Triangle.h"
#include "objects/geometry_objects/Prism.h"
#include "objects/Material.h"

#include "../objects/model.h"

namespace uploading {

using objects::Model;
using objects::GeometryObject;
using objects::Parallelepiped;
using objects::Sphere;
using objects::Pyramid;
using objects::Triangle;
using objects::Prism;

class FileLoader: public BaseLoader {
public:
    FileLoader() = default;
    ~FileLoader() override;

    void open(std::string source_name) override;
    void close() override;

    std::shared_ptr<GeometryObject> readParallelepipedInfo();
    std::shared_ptr<GeometryObject> readSphereInfo();
    std::shared_ptr<GeometryObject> readPyramidInfo();
    std::shared_ptr<GeometryObject> readTriangleInfo();
    std::shared_ptr<GeometryObject> readPrismInfo();

    std::shared_ptr<GeometryObject> readObjectInfo() override;
    Material readMaterialInfo() override;
    std::size_t readSceneInfo() override;
    Vector3d readPoint() override;
    std::string llt() override;
private:
    std::ifstream _file;
    std::string _llt;
};

}

#endif // FILE_LOADER_IMP_H
