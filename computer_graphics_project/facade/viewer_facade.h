#pragma once

#include "../intermediary/intermediary.h"
#include "../commands/base_command.h"

namespace facade {

using intermediary::Intermediary;
using commands::BaseCommand;

class ViewerFacade {
public:
    ViewerFacade();
    void execCommand(BaseCommand *command);
private:
    std::shared_ptr<Intermediary> _intermediary;
};

}
