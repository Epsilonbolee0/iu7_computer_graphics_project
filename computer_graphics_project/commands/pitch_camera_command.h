#pragma once

#include "base_command.h"
#include "math/point.h"
#include "intermediary/intermediary.h"

namespace commands {

class PitchCameraCommand: public BaseCommand {
public:
    PitchCameraCommand(double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _object_name;
    math::Point _rotation;
};

}
