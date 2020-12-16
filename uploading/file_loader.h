#ifndef FILE_LOADER_IMP_H
#define FILE_LOADER_IMP_H

#include <string>
#include <iostream>
#include <fstream>
#include "base_loader.h"
#include "objects/model.h"
#include "exceptions/file_open_exception.h"
#include "objects/geometry_objects/parallelepiped.h"
#include "objects/material.h"

#include "../objects/model.h"

namespace uploading {

using objects::Model;
using objects::GeometryObject;
using objects::Parallelepiped;

class FileLoader: public BaseLoader {
public:
    FileLoader() = default;
    ~FileLoader() override;

    void open(std::string source_name) override;
    void close() override;

    std::shared_ptr<GeometryObject> readObjectInfo() override;
    Material readMaterialInfo() override;
    std::size_t readSceneInfo() override;
    Vector3d readPoint() override;

private:
    std::ifstream _file;
};

}

#endif // FILE_LOADER_IMP_H
