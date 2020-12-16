#include "transform_matrix.h"

namespace math {

MoveMatrix::MoveMatrix(float x, float y, float z) {
    _data[0][0] = 1;
    _data[1][1] = 1;
    _data[2][2] = 1;
    _data[3][3] = 1;
    _data[0][3] = x;
    _data[1][3] = y;
    _data[2][3] = z;
}

ScaleMatrix::ScaleMatrix(float x, float y, float z) {
    _data[0][0] = x;
    _data[1][1] = y;
    _data[2][2] = z;
    _data[3][3] = 1;
}

RotateOxMatrix::RotateOxMatrix(float angle) {
    _data[0][0] = 1;
    _data[1][1] = cos(angle);
    _data[1][2] = -sin(angle);
    _data[2][1] = sin(angle);
    _data[2][2] = cos(angle);
    _data[3][3] = 1;
}

RotateOyMatrix::RotateOyMatrix(float angle) {
    _data[0][0] = cos(angle);
    _data[1][1] = 1;
    _data[2][0] = -sin(angle);
    _data[0][2] = sin(angle);
    _data[2][2] = cos(angle);
    _data[3][3] = 1;
}

RotateOzMatrix::RotateOzMatrix(float angle) {
    _data[0][0] = cos(angle);
    _data[0][1] = -sin(angle);
    _data[1][0] = sin(angle);
    _data[1][1] = cos(angle);
    _data[2][2] = 1;
    _data[3][3] = 1;
}

} // namespace math
