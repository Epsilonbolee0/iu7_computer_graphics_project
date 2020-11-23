#pragma once

#include "base_command.h"
#include "../math/point.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Point;

class MoveCameraCommand: public BaseCommand {
public:
    MoveCameraCommand(Point move);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _object_name;
    Point _move;
};

}
