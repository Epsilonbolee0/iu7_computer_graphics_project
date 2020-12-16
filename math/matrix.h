#ifndef LAB4_MATRIX_H
#define LAB4_MATRIX_H

#include <vector>

namespace math {

class Matrix {
public:
    Matrix();

    float get(size_t i, size_t j) const;
    void set(size_t i, size_t j, float value);
protected:
    std::vector<std::vector<float>> _data;
};

} // namespace matrix

#endif //LAB4_MATRIX_H
