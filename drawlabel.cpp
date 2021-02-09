#include "drawlabel.h"
#include <QDebug>
#include <QString>

DrawLabel::DrawLabel(QImage &pixmap)
    : _pixmap(&pixmap) {
    j = 0;
}

void DrawLabel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), *_pixmap);
    painter.end();
}

void DrawLabel::advanceState() {
    if (j == 9)
        j = 0;
    QString cache_name = "presets/1_1_100_";
    _pixmap->load(cache_name  + QString::number(++j) + ".png");
    update();
}
