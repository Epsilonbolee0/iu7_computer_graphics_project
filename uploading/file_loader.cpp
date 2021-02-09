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

std::shared_ptr<GeometryObject> FileLoader::readTriangleInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    Vector3d a, b, c;
    a = readPoint();
    b = readPoint();
    c = readPoint();

    Triangle *_obj = new Triangle(a, b, c);

    std::shared_ptr<GeometryObject> _result(_obj);

    return _result;
}

std::shared_ptr<GeometryObject> FileLoader::readPrismInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    Vector3d point = readPoint();
    float _width, _length;

    _file >> _width >> _length;
    Prism *_obj = new Prism(point, _width, _length, 1);

    std::shared_ptr<GeometryObject> _result(_obj);

    return _result;
}

std::shared_ptr<GeometryObject> FileLoader::readParallelepipedInfo() {
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

std::shared_ptr<GeometryObject> FileLoader::readSphereInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    Vector3d point = readPoint();
    float _radius;

    _file >> _radius;
    Sphere *_obj = new Sphere(point, _radius);

    std::shared_ptr<GeometryObject> _result(_obj);

    return _result;
}

std::shared_ptr<GeometryObject> FileLoader::readPyramidInfo() {
    if (!_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    Vector3d point = readPoint();
    float _base_side, _height;

    _file >> _base_side >> _height;
    Pyramid *_obj = new Pyramid(point, _base_side, _height, 0);

    std::shared_ptr<GeometryObject> _result(_obj);

    return _result;
}


std::shared_ptr<GeometryObject> FileLoader::readObjectInfo() {
    std::string _name;
    std::shared_ptr<GeometryObject> _obj;

    _file >> _name;

    _llt = _name;
    if (_name == "Parallelepiped") {
        _obj = readParallelepipedInfo();
    } else if (_name == "Sphere") {
        _obj = readSphereInfo();
    } else if (_name == "Pyramid") {
        _obj = readPyramidInfo();
    } else if (_name == "Triangle") {
        _obj = readTriangleInfo();
    } else if (_name == "Prism") {
        _obj = readPrismInfo();
    }

    return _obj;
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

std::string FileLoader::llt() {
    return _llt;
}

}
