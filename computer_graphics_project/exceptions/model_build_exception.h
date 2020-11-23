#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class ModelBuildException: public BaseViewerException {
public:
    ModelBuildException() = default;
    explicit ModelBuildException(std::string message): BaseViewerException(message) {}

    const char * what() const noexcept override {
        return "Error while building model";
    }
};

}
