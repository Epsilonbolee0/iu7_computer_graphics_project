#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <memory>
#include <iostream>

#include "drawlabel.h"
#include "gui/addition_dialog.h"
#include "math/vector3d.h"
#include "commands/add_model_command.h"
#include "commands/render_command.h"
#include "commands/yaw_camera_command.h"
#include "commands/pitch_camera_command.h"
#include "commands/move_camera_command.h"
#include "commands/remove_model_command.h"
#include "commands/light_edit_command.h"
#include "commands/read_file_command.h"
#include "commands/simulate_command.h"
#include "exceptions/file_open_exception.h"
#include "exceptions/camera_lack_exception.h"
#include "facade/viewer_facade.h"
#include "render/qt_drawer.h"

namespace Ui {
class Widget;
}

using facade::ViewerFacade;
using math::Vector3d;

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void moveLeft();
    void moveRight();
    void moveForward();
    void moveBackward();
    void moveUp();
    void moveDown();
    void lookUp();
    void lookDown();
    void rotateLeft();
    void rotateRight();


public slots:
    void add();
    void remove();
    void render();
    void changeLight();
    void load();
    void simulate();
    //void save();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    Ui::Widget *ui;
    DrawLabel *_draw_label;
    QImage _pixmap;
    std::unique_ptr<ViewerFacade> _facade;
    size_t _elements_num;
    int i;
};

#endif // WIDGET_H
