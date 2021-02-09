#include "flow_manager.h"
#include <QDebug>

using modeling::Quant;
using modeling::Map;
using modeling::FlowManager;


std::vector<std::queue<Quant>> FlowManager::log() {
    return quant_log;
}

void FlowManager::loadMap(std::string filename) {
    map_ = Map(filename);
}

void FlowManager::execute(std::size_t iters, Vector3d _pos, float volume_) {
    std::queue<Quant> quant_memo_;

    _pos.setZ(map_.data()[_pos.x()][_pos.y()]);

    Quant start_ = Quant(50, Vector3d(0, 0, 3), Vector3d(0, 0, 0));
    quants_.push(start_);
    start_ = Quant(80, Vector3d(1, 4, 3), Vector3d(0, 0, 0));
    quants_.push(start_);

    quant_log.push_back(quants_);

    for (std::size_t iter_ = 0; iter_ < iters - 1 && quants_.size(); iter_++) {
        while (quants_.size()) {
            auto current_ = quants_.front();
            quants_.pop();
            auto cells_ = map_.getNeighbours(current_.pos());
            for (auto& value_: current_.tick(cells_)) {
                quant_memo_.push(value_);
            }
        }

        quant_memo_ = Quant::merge(quant_memo_);

        while (quant_memo_.size()) {
            auto elem_ = quant_memo_.front();
            quant_memo_.pop();
            quants_.push(elem_);
        }

        quant_log.push_back(quants_);
    }
}



