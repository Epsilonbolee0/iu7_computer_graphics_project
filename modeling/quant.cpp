#include "quant.h"

using modeling::Quant;
#include <algorithm>
#include <iostream>
#include <QDebug>

bool cell_cmp(Cell a, Cell b) {
    return a.delta < b.delta;
}

Quant::Quant(float volume_, const Vector3d pos_, const Vector3d vel_) {
    this->volume_ = volume_;
    this->p_ = pos_;
    this->v_ = vel_;
    this->visited_cells.push_back(pos_.x() * 5 + pos_.y());
}

void Quant::flow(Vector3d a, float t) {
    this->p_.setX(this->p_.x() + this->v_.x() * t + a.x() * (t * t) / 2);
    this->p_.setY(this->p_.y() + this->v_.y() * t + a.y() * (t * t) / 2);
    this->p_.setZ(this->p_.z() + this->v_.z() * t + a.z() * (t * t) / 2);

    this->v_.setX(this->v_.x() + a.x() * t);
    this->v_.setY(this->v_.y() + a.y() * t);
    this->v_.setZ(this->v_.z() + a.z() * t);
}

void Quant::bump(Quant& other) {
    other.volume_ = 0;
    this->volume_ += other.volume_;
    this->v_.add(other.v_);
}

std::queue<Quant> Quant::merge(std::queue<Quant> quants_) {
    std::vector<Quant> _result;
    std::queue<Quant> _queue;
    std::size_t id_;
    Quant temp_quant = Quant(0, math::Vector3d(0, 0, 0), math::Vector3d(0, 0, 0));

    _result.resize(25, temp_quant);

    while (quants_.size()) {
        auto quant_ = quants_.front();
        quants_.pop();
        id_ = quant_.p_.x() * 5 + quant_.p_.y();

        if (_result[id_].volume() == 0) {
            _result[id_].p_.setX(quant_.p_.x());
            _result[id_].p_.setY(quant_.p_.y());
            _result[id_].p_.setZ(quant_.p_.z());
        }

        _result[id_].setVolume(_result[id_].volume() + quant_.volume());
    }

    std::size_t deleted = 0;
    for (int i = _result.size() - 1; i >= 0; i--) {
        if (_result[i].volume() == 0) {
            std::swap(_result[i],  _result[_result.size() - ++deleted]);
        }
    }

    _result.resize(25 - deleted);
    for (auto& element_: _result) {
        _queue.push(element_);
    }

    return _queue;
}

std::vector<Quant> Quant::tick(std::vector<Cell> cells_) {
    std::vector<Quant> result_;

    int deleted = 0;
    for (int i = cells_.size() - 1; i >= 0; i--) {
        int id = cells_[i].position_.x() * 5 + cells_[i].position_.y();
        for (int j = 0; j < this->visited_cells.size(); j++)
            if (this->visited_cells[j] * 5 + this->visited_cells[j] == id)
                std::swap(cells_[i],  cells_[cells_.size() - ++deleted]);
    }
    cells_.resize(cells_.size() - deleted);

    if (this->volume_ < this->min_volume_ || !cells_.size()) {
        result_.push_back(*this);
        return result_;
    }

    std::sort(cells_.begin(), cells_.end(), cell_cmp);
    std::size_t dest_numb = std::rand() % (cells_.size()) + 1;
    qDebug() << dest_numb;

    int delta_summ = 0;
    for (std::size_t i = 0; i < dest_numb; i++) {
        delta_summ += cells_[i].delta;
    }

    for (std::size_t i = 0; i < dest_numb; i++) {
        float pred_volume_ = this->flow_coeff_ * this->volume_ * (cells_[i].delta + 1) / (float(delta_summ) + dest_numb);
        if (pred_volume_ > this->min_volume_) {
            Quant new_ = Quant{pred_volume_, cells_[i].position_, Vector3d(0, 0, 0)};
            for (auto& pos_: this->visited_cells)
                new_.visited_cells.push_back(pos_);
            result_.push_back(new_);
            this->volume_ -= pred_volume_;
        }
    }

    result_.push_back(*this);

    return result_;
}

math::Vector3d Quant::pos() {
    return p_;
}

Quant& Quant::operator=(const Quant& other_) {
    volume_ = other_.volume_;
    p_ = other_.p_;
    v_ = other_.v_;

    return *this;
}

float Quant::volume() {
    return volume_;
}

void Quant::setVolume(float value) {
    this->volume_ = value;
}
