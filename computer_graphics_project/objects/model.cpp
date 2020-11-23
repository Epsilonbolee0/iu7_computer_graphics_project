#include "model.h"

namespace objects {

Model::Model(std::string name): Object(name), _mesh(new Mesh) {}

void Model::addPoint(Point& p){
    _mesh->addPoint(p);
}

void Model::addEdge(size_t first, size_t second) {
    _mesh->addEdge(first, second);
}

void Model::transform(const std::shared_ptr<Matrix>) {
    _mesh->transform(matrix);
}

void Model::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

}
