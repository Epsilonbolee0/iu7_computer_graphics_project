#pragma once

#include <string>
#include "base_command.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class AddModelCommand: public BaseCommand {
public:
    explicit AddModelCommand(std::string file_name, std::string model_name);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _file_name;
    std::string _model_name;
};

}
