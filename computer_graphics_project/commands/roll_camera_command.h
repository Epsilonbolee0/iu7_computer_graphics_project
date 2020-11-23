#pragma once

#include "base_command.h"
#include "math/point.h"
#include "intermediary/intermediary.h"

namespace commands {

class RollCameraCommand: public BaseCommand {
public:
    RollCameraCommand(double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    math::Point _rotation;
};

}