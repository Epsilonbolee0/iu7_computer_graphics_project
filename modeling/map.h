#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "math/matrix.h"
#include "math/vector3d.h"
#include <string>
#include <fstream>

namespace modeling {
    using math::Matrix;
    using math::Vector3d;

class Map : public Matrix {
public:
    Map() = default;
    Map(std::string _filename);
    void resize(std::size_t _size);
    std::vector<Cell> getNeighbours(Vector3d _pos);
    std::vector<std::vector<float>> data();
private:
    static const std::size_t _skip_after = 6;
};

}

#endif // MAP_H
