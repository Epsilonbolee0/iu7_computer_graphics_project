#pragma once

#include "base_command.h"
#include "intermediary/intermediary.h"

namespace commands {

class RemoveModelCommand: public BaseCommand {
public:
    RemoveModelCommand(std::string object_name);
    void execute(std::shared_ptr<Intermediary> intermediary) override;

private:
    std::string _object_name;

};

}
