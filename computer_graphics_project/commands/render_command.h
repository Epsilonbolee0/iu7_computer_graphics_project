#pragma once

#include "base_command.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class RenderCommand: public BaseCommand {
public:
    explicit RenderCommand(std::shared_ptr<render::BaseDrawer> drawer);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::shared_ptr<render::BaseDrawer> _drawer;
};

}
