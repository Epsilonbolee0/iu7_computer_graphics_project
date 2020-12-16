#ifndef QUANT_H
#define QUANT_H

#include "math/vector3d.h"
#include "cell.h"
#include <queue>

namespace modeling {

using math::Vector3d;

class Quant {
public:
    Quant() = default;
    Quant(float volume_, const Vector3d pos_, const Vector3d velocity_);
    Vector3d pos();
    float volume();
    void setVolume(float delta);
    void setPosition(Vector3d pos_);
    void flow(Vector3d acceleration_, float time_);
    void bump(Quant& other);
    Quant& operator=(const Quant& other_);

    std::vector<Quant> tick(std::vector<Cell> cells_);
    static std::queue<Quant> merge(std::queue<Quant> quant_);

private:
    std::vector<int> visited_cells;
    float volume_;
    Vector3d p_;
    Vector3d v_;
    const float min_volume_ = 5;
    const float flow_coeff_ = 0.4;
};

}

#endif // QUANT_H
