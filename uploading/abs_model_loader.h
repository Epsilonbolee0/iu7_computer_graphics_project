#ifndef ABS_MODEL_LOADER_H
#define ABS_MODEL_LOADER_H

#include "memory"
#include "file_loader.h"
#include "objects/model.h"

namespace uploading {

using objects::Model;

class AbsModelLoader {
public:
    AbsModelLoader() = default;
    virtual ~AbsModelLoader() = default;
    virtual std::vector<std::shared_ptr<objects::Model>> loadModel(std::string source_name, std::string model_name) = 0;
};

}

#endif // ABS_MODEL_LOADER_H
