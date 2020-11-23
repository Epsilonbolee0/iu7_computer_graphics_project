#include "remove_camera_command.h"

namespace commands {

RemoveCameraCommand::RemoveCameraCommand(){};

void RemoveCameraCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    intermediary->removeCamera();
}

}
