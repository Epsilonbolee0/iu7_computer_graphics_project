#pragma once

#include "base_viewer_exception.h"

namespace exceptions {

class DrawerInitException: public BaseViewerException {
public:
    DrawerInitException() = default;
    explicit DrawerInitException(std::string message): BaseViewerException(message) {}

    const char * what() const noexcept override {
        return "Drawer was not initialized";
    }
};

}
