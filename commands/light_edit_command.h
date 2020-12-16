#ifndef LIGHT_EDIT_COMMAND_H
#define LIGHT_EDIT_COMMAND_H

#include "basecommand.h"

namespace commands  {

using intermediary::Intermediary;
using math::Vector3d;

class LightEditCommand: public BaseCommand {
public:
    LightEditCommand(Vector3d &pos, float intensity);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    Vector3d _position;
    float _intensity;
};

} // namespace commands

#endif // LIGHT_EDIT_COMMAND_H
