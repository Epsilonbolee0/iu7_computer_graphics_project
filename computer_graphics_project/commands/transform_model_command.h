#pragma once

#include "base_command.h"
#include "../math/point.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Point;

class TransformModelCommand: public BaseCommand {
public:
    TransformModelCommand(std::string object_name, Point move, Point rotate);
    void execute(int intermediary) override;
private:
    std::string _object_name;
    Point _move;
    Point _rotate;
};

}
