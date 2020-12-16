#include "simulate_command.h"

namespace commands {

SimulateCommand::SimulateCommand(Vector3d vec_, float volume):
 start(vec_), volume(volume) {}

void SimulateCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    intermediary->simulate(start, volume);
}

}
