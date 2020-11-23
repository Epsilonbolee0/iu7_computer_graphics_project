#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class ObjectTypeException: public BaseViewerException {
public:
    ObjectTypeException() = default;
    explicit ObjectTypeException(std::string message): BaseViewerException(message) {};

    const char * what() const noexcept override {
        return "Wrong object type";
    }
};

}
