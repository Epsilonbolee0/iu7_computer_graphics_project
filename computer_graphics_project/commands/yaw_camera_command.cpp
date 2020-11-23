#include "yaw_camera_command.h"

namespace commands {

YawCameraCommand::YawCameraCommand(double angle): _rotation(0, 0, angle) {};

void YawCameraCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(moving, _rotation);
}

}
