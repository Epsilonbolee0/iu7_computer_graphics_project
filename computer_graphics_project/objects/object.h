#pragma once

#include <memory>
#include <string>
#include "../visitor/visitor.h"
#include "../math/point.h"
#include "../math.matrix.h"

namespace objects {

using math::Matrix;

class Object {
public:
    Object() = default;
    Object(std::string name): _name(name) {}
    virtual ~Object() = default;
    virtual void transform(const std::shared_ptr<Matrix>) = 0;
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    std::string getName() {return _name; }

private:
    std::string _name;

};

}
