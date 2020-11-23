#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class NoCameraException: public BaseViewerException {
public:
    NoCameraException() = default;
    explicit NoCameraException(std::string message): BaseViewerException(message) {}

    const char * what() const noexcept override {
        return "No camera is set!";
    }
};

}
