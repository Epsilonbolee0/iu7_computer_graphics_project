#include "map.h"

using modeling::Map;

void Map::resize(std::size_t _size) {
    _data.resize(_size);
    for (auto& row: _data) {
        row.resize(_size);
    }
}

Map::Map(std::string filename) {
    std::ifstream _file;
    std::size_t x0, y0, z0;
    std::size_t x1, y1, z1;
    int _cnt;
    float _unnecessary_data;

    resize(5);
    _file.open(filename);
    _file >> _cnt;

    for (int i = 0; i < _cnt; i++) {
        _file >> x0 >> y0 >> z0 ;
        _file >> z1 >> x1 >> y1;

        for (std::size_t x = x0; x < x0 + x1; x++) {
            for (std::size_t z = z0; z < z0 + z1; z++) {
                if (_data[x][z] < y0 + y1)
                    _data[x][z] = y0 + y1;
            }
        }

        for (std::size_t j = 0; j < _skip_after && !_file.eof(); j++) {
            _file >> _unnecessary_data;
        }
    }

    _file.close();
}

std::vector<std::vector<float>> Map::data() {
    return _data;
}

std::vector<Cell> Map::getNeighbours(Vector3d _pos) {
    std::size_t left_border = _pos.x() > 0 ? _pos.x() - 1 : 0;
    std::size_t right_border = _pos.x() < _data.size() - 1 ? _pos.x() + 1 : _data.size() - 1;
    std::size_t bottom_border = _pos.y() > 0 ? _pos.y() - 1 : 0;
    std::size_t top_border = _pos.y() < _data.size() - 1 ? _pos.y() + 1 : (_data[0]).size() - 1;

    std::vector<Cell> vec_;
    int our_height = _data[_pos.x()][_pos.y()];

    for (std::size_t x = left_border; x <= right_border; x++) {
        for (std::size_t y = bottom_border; y <= top_border; y++) {
            if (x != _pos.x() || y != _pos.y()) {
                int delta =  our_height - _data[x][y];
                if (delta >= 0)
                    vec_.push_back(Cell{delta, Vector3d(x, y, _data[x][y])});
            }
        }
    }

    return vec_;
}
