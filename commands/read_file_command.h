#ifndef READ_FILE_COMMAND_H
#define READ_FILE_COMMAND_H

#include <string>
#include "basecommand.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class ReadFileCommand: public BaseCommand {
public:
    explicit ReadFileCommand(std::string model_name, std::string file_name);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _model_name;
    std::string _file_name;
};

}

#endif // READ_FILE_COMMAND_H
