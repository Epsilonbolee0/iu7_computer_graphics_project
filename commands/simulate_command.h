#ifndef SIMULATE_COMMAND_H
#define SIMULATE_COMMAND_H

#include "basecommand.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Vector3d;

class SimulateCommand: public BaseCommand {
public:
    explicit SimulateCommand(Vector3d start, float volume);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    Vector3d start;
    float volume;
};

} // namespace commands

#endif // SIMULATE_COMMAND_H
