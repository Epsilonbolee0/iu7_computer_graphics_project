#pragma once

#include <vector>
#include "object.h"
#include "mesh.h"
#include "../math/point.h"

namespace objects {

using math::Point;

class Model: public Object {
public:
    Model(std::string name);

    void addPoint(Point& p);
    void addEdge(size_t first, size_t second);
    void transform(const std::shared_ptr<Matrix>) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
    std::shared_ptr<Mesh> getMesh() {return _mesh; }

private:
    std::shared_ptr<Mesh> _mesh;
};

}
