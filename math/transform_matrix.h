#ifndef TRANSFORM_MATRIX_H
#define TRANSFORM_MATRIX_H

#include <cmath>
#include "matrix.h"

namespace math {

class MoveMatrix: public Matrix {
public:
    MoveMatrix(float x, float y, float z);
};

class ScaleMatrix: public Matrix {
public:
    ScaleMatrix(float x, float y, float z);
};

class RotateOxMatrix: public Matrix {
public:
    RotateOxMatrix(float angle);
};

class RotateOyMatrix: public Matrix {
public:
    RotateOyMatrix(float angle);
};

class RotateOzMatrix: public Matrix {
public:
    RotateOzMatrix(float angle);
};

} // namespace math

#endif // TRANSFORM_MATRIX_H
