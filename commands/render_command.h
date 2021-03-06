#ifndef LAB4_RENDERCOMMAND_H
#define LAB4_RENDERCOMMAND_H

#include "basecommand.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class RenderCommand: public BaseCommand {
public:
    explicit RenderCommand(std::shared_ptr<render::BaseDrawer> drawer, int sample_n);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::shared_ptr<render::BaseDrawer> _drawer;
    int _sample_n;
};

} // namespace commands

#endif //LAB4_RENDERCOMMAND_H
