#include "pitch_camera_command.h"

namespace commands {

PitchCameraCommand::PitchCameraCommand(double angle): _rotation(0, angle, 0) {};

void PitchCameraCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(moving, _rotation);
}

}
