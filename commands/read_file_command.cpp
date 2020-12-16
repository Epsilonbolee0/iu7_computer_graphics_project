#include "read_file_command.h"

namespace commands {

ReadFileCommand::ReadFileCommand(std::string file_name, std::string model_name):
    _model_name(model_name), _file_name(file_name) {}

void ReadFileCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->load(_file_name, _model_name);
}

}
