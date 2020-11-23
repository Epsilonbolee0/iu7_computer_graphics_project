#include "move_camera_command.h"

namespace commands {

MoveCameraCommand::MoveCameraCommand(math::Point move): _move(move) {};

void MoveCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Point rotation(0, 0, 0);
    intermediary->transformCamera(_move, rotation);
}

}
