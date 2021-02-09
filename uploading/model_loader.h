#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "abs_model_loader.h"
#include "memory"
#include "vector"

namespace uploading {

using objects::Model;

class ModelLoader: public AbsModelLoader {
public:
    explicit ModelLoader(BaseLoader *loader);
    std::vector<std::shared_ptr<objects::Model>> loadModel(std::string source_name, std::string model_name) override;
private:
    std::unique_ptr<BaseLoader> _loader;
};

} // namespace uploading

#endif // MODEL_LOADER_H
