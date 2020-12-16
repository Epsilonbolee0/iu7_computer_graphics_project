#include "yaw_camera_command.h"

namespace commands {

YawCameraCommand::YawCameraCommand(std::string object_name, float angle):
    _object_name(object_name), _rotation(angle, 0, 0) {}

void YawCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Vector3d moving(0, 0, 0);
    intermediary->transformCamera(moving, _rotation);
}

} // namespace commands
