#ifndef FLOW_MANAGER_H
#define FLOW_MANAGER_H

#include <vector>
#include <queue>
#include "quant.h"
#include "map.h"

namespace modeling {

class FlowManager {
public:
    FlowManager() = default;
    void loadMap(std::string filename);
    void execute(std::size_t iters, Vector3d _pos, float volume_);
    std::vector<std::queue<Quant>> log();
private:
    Map map_;
    std::queue<Quant> quants_;
    std::vector<std::queue<Quant>> quant_log;
};

}

#endif // FLOW_MANAGER_H
