#include "set_camera_command.h"

namespace commands {

SetCameraCommand::SetCameraCommand(){};

void SetCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->setCamera();
}

}
