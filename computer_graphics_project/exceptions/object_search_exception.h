#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class ObjectSearchException: public BaseViewerException {
public:
    ObjectSearchException() = default;
    explicit ObjectSearchException(std::string message): BaseViewerException(message) {};

    const char * what() const noexcept override {
        return "Object wasn't found";
    }
};

}
