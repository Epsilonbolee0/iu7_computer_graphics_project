#include "matrix.h"

namespace math {

Matrix::Matrix() {
    _data.resize(4);
    for (auto &row: _data) {
        row.resize(4);
    }
}

float Matrix::get(size_t i, size_t j) const {
    return _data[i][j];
}

void Matrix::set(size_t i, size_t j, float value) {
    _data[i][j] = value;
}

} // namespace math