#include "qt_drawer.h"

namespace render {

QtDrawer::QtDrawer(QPainter *painter): _painter(painter) {
    _painter->setPen(QColor(0, 0, 0));
    _pen = QPen(QColor(0, 0, 0));
}

void QtDrawer::drawLine(const math::Vector3d &p1, const math::Vector3d &p2) {
    auto w = 275;
    auto h = 275;
    _painter->drawLine(w + std::round(p1.x()), h - std::round(p1.y()),
                       w + std::round(p2.x()), h - std::round(p2.y()));
}

void QtDrawer::drawPoint(const QColor &color, int x, int y) {
    int w =  275;
    int h =  275;
    _pen.setColor(color);
    _painter->setPen(_pen);
    _painter->drawPoint(w + x , h - y);
}

std::pair<int, int> QtDrawer::getSize() {
    return {550, 550};
}

void QtDrawer::drawImage(const QImage _buffer) {
    _painter->drawImage(QPoint(0, 0), _buffer);
}

} // namespace render
