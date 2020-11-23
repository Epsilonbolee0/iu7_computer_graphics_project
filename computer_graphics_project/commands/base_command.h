#pragma once

#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class BaseCommand
{
public:
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<Intermediary> intermediary) = 0;
};

}

