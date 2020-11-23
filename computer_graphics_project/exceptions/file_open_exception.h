#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class FileOpenException: public BaseViewerException {
public:
    FileOpenException() = default;
    explicit FileOpenException(std::string message): BaseViewewException(message) {};

    const char * what() const noexcept override {
        return "Unable to open file";
    }
};

}
