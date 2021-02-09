#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "windows.h"
#include <fstream>
#include <QTimer>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget),
    _facade(new ViewerFacade),
    _elements_num(0)
{
    ui->setupUi(this);
    _draw_label = new DrawLabel(_pixmap);
    _draw_label->resize(550 , 550);
    layout()->addWidget(_draw_label);
    _pixmap = QImage(550, 550, QImage::Format_RGB32);
    _pixmap.fill(Qt::white);
    setFocusPolicy(Qt::StrongFocus);
    i = 0;
    connect(&_timer, SIGNAL(timeout()), _draw_label, SLOT(advanceState()));
}

Widget::~Widget() {
    delete _draw_label;
    delete ui;
}

void Widget::render() {
    QPainter painter(&_pixmap);
    _pixmap.fill(Qt::black);
    auto drawer = new render::QtDrawer(&painter);
    auto command = new commands::RenderCommand(std::shared_ptr<render::BaseDrawer>(drawer), 1);
    try {
        auto begin = std::chrono::steady_clock::now();
        _facade->execCommand(command);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << elapsed_ms.count() << std::endl;
        _draw_label->update();
    } catch(exceptions::CameraLackException) {
        QMessageBox::critical(nullptr, "Error", "Choose camera to render smth");
    }
    delete command;
}

void Widget::remove() {
    if (ui->comboBox->count() <= 0) {
        return;
    }

    std::string name = ui->comboBox->currentText().toStdString();
    commands::RemoveModelCommand command(name);
    _facade->execCommand(&command);
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void Widget::moveForward() {
    float z = 0.5;
    commands::MoveCameraCommand command("camera", Vector3d{0, 0, z});
    _facade->execCommand(&command);
    render();
}

void Widget::moveBackward() {
    float z = -0.5;
    commands::MoveCameraCommand command("camera", Vector3d{0, 0, z});
    _facade->execCommand(&command);
    render();
}

void Widget::moveLeft() {
    float x = -0.5;
    commands::MoveCameraCommand command("camera", Vector3d{x, 0, 0});
    _facade->execCommand(&command);
    render();
}

void Widget::moveRight() {
    float x = 0.5;
    commands::MoveCameraCommand command("camera", Vector3d{x, 0, 0});
    _facade->execCommand(&command);
    render();
}

void Widget::moveUp() {
    float y = 0.5;
    commands::MoveCameraCommand command("camera", Vector3d{0, y, 0});
    _facade->execCommand(&command);
    render();
}

void Widget::moveDown() {
    float y = -0.5;
    commands::MoveCameraCommand command("camera", Vector3d{0, y, 0});
    _facade->execCommand(&command);
    render();
}

void Widget::rotateLeft() {
    float phi = 10;
    commands::PitchCameraCommand command("camera", phi);
    _facade->execCommand(&command);
    render();
}

void Widget::rotateRight() {
    float phi = -10;
    commands::PitchCameraCommand command("camera", phi);
    _facade->execCommand(&command);
    render();
}

void Widget::lookUp() {
    float ksi = 10;
    commands::YawCameraCommand command("camera", ksi);
    _facade->execCommand(&command);
    render();
}

void Widget::lookDown() {
    float ksi = -10;
    commands::YawCameraCommand command("camera", ksi);
    _facade->execCommand(&command);
    render();
}

void Widget::changeLight() {
    Vector3d pos = {
        float(ui->x_light_input->value()),
        float(ui->y_light_input->value()),
        float(ui->z_light_input->value())
    };

    auto intensity = ui->int_light_input->value();
    commands::LightEditCommand command(pos, intensity);
    _facade->execCommand(&command);
}

void Widget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    switch (key)
    {
    case Qt::Key_W:
        moveForward();
        break;
    case Qt::Key_A:
        moveLeft();
        break;
    case Qt::Key_S:
        moveBackward();
        break;
    case Qt::Key_D:
        moveRight();
        break;
    case Qt::Key_Shift:
        moveDown();
        break;
    case Qt::Key_Space:
        moveUp();
        break;
    case Qt::Key_Up:
        lookUp();
        break;
    case Qt::Key_Down:
        lookDown();
        break;
    case Qt::Key_Right:
        rotateRight();
        break;
    case Qt::Key_Left:
        rotateLeft();
        break;
    }
}

void Widget::add() {
    AdditionDialog dialog;
    dialog.exec();
    if (dialog.is_added()) {
        std::string obj_name = "Object№" + std::to_string(++_elements_num);
        for (auto &obj: dialog.object()) {
            commands::AddModelCommand command(obj_name, obj, dialog.Material());
            _facade->execCommand(&command);
        }
        ui->comboBox->addItem(obj_name.c_str());
    }
    dialog.close();
}

void Widget::load() {
    QString file = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("Открыть файл"),
                                                    "../computer-graphic-project/landscapes",
                                                    "landscape files (*.lnd)");
        if (file.isEmpty())
            return;

        std::string file_name = file.toLocal8Bit().constData();
        auto path_end = file_name.rfind("/");
        auto pos = file_name.rfind(".");
        std::string model_name = file_name.substr(path_end + 1, pos - path_end - 1);

        std::ifstream _file;
        int new_cnt;
        _file.open(file_name);
        _file >> new_cnt;
        _file.close();

        commands::ReadFileCommand command(file_name, model_name);
        try {
            _facade->execCommand(&command);
            for (int i = 0; i < new_cnt; i++) {
                auto name = model_name + "№" + std::to_string(i + 1);
                ui->comboBox->addItem(name.c_str());
            }
            render();
        } catch(exceptions::FileOpenException e) {
            QMessageBox::critical(nullptr, "Error", "Couldn't open file");
        } catch(std::exception e) {
            QMessageBox::critical(nullptr, "Error", "Some problems occured while reading file");
        }
}

void Widget::simulate() {
    Vector3d vec_ = Vector3d(0, 0, 0);
    QString cache_name = "presets/" + QString::number(1) + "_" + QString::number(1) + "_";
    cache_name += QString::number(100) + "_";

    std::ifstream infile(cache_name.toUtf8().constData());
    if (!infile.good()) {
        commands::SimulateCommand command(vec_, float(100));
        _facade->execCommand(&command);
        render();
        this->_pixmap.save(cache_name + QString::number(++i) + ".png", nullptr, -1);
    } else {
        _pixmap.load(cache_name  + QString::number(++i) + ".png");
        _draw_label->update();
    }
}

void Widget::animate() {
    QString cache_name = "presets/wall_";
    if (_timer.isActive()) {
        _timer.stop();
    } else {
        _timer.start(100);
    }
}
