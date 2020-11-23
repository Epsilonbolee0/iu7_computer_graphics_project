#pragma once

namespace Visitor {

class Model;
class Camera;
class Composite;

class Visitor {
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void visit(Camera& camera) = 0;
    virtual void visit(Model& model) = 0;
    virtual void visit(Composite& composite) = 0;
};

}
