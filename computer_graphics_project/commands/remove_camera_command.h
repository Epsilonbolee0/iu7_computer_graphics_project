#pragma once

#include "base_command.h"
#include "intermediary/intermediary.h"

namespace commands {

class RemoveCameraCommand: public BaseCommand {
public:
    RemoveCameraCommand();
    void execute(std::shared_ptr<Intermediary> intermediary) override;
};

}
