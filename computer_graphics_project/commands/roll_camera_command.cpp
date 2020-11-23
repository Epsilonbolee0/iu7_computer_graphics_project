#include "roll_camera_command.h"

namespace commands {

RollCameraCommand::RollCameraCommand(double angle): _rotation(angle, 0, 0) {}

void RollCameraCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(moving, _rotation);
}
}

