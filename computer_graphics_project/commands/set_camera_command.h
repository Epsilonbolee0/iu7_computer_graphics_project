#pragma once

#include <string>
#include "base_command.h"
#include "../intermediary/intermediary.h"

namespace commands {

class SetCameraCommand: public BaseCommand {
public:
    explicit SetCameraCommand();
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _name;
};

}
