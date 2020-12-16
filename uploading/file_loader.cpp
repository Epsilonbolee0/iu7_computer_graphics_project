#include "file_loader.h"

namespace uploading {

FileLoader::~FileLoader() {
    close();
}

void FileLoader::open(std::string source_name) {
    if (_file.is_open()) {
        close();
    }

    _file.open(source_name);
    if (!_file) {
        throw exceptions::FileOpenException();
    }
}

void FileLoader::close() {
    if (_file.is_open()) {
        _file.close();
    }
}

Vector3d FileLoader::readPoint() {
    float x_, y_, z_;
    _file >> x_ >> y_ >> z_;
    return Vector3d(x_, y_, z_);
}

std::size_t FileLoader::readSceneInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    int _num;
    _file >> _num;
    return _num;
}

std::shared_ptr<GeometryObject> FileLoader::readObjectInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    Vector3d point = readPoint();
    float _width, _length, _height;

    _file >> _width >> _length >> _height;
    Parallelepiped *_obj = new Parallelepiped(point, _width, _length, _height, 0);

    std::shared_ptr<GeometryObject> _result(_obj);

    return _result;
}

Material FileLoader::readMaterialInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    float specular, reflective, roughness;

    Vector3d color = readPoint();
    _file >> specular >> reflective >> roughness;
    Material _material = {color, specular, reflective, roughness, 0};

    return _material;
}

}
