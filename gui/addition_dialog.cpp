#include "addition_dialog.h"
#include <ui_addition_dialog.h>
#include <QtWidgets/QColorDialog>
#include <iostream>

AdditionDialog::AdditionDialog(QWidget *parent)
    : QDialog(parent),
      _ui(new Ui::Dialog),
      _color(Qt::red),
      _added(false) {
    _ui->setupUi(this);
}

AdditionDialog::~AdditionDialog() {
    delete _ui;
}

void AdditionDialog::color() {
    auto color = QColorDialog::getColor();
    if (color.isValid()) {
        _color = color;
        std::string style = "background-color: rgb("
                + std::to_string(color.red()) + ","
                + std::to_string(color.green()) + ","
                + std::to_string(color.blue()) + ");";
        _ui->pushButton->setStyleSheet(QString(style.c_str()));
    }
}

void AdditionDialog::accept() {
    switch (_ui->tabWidget->currentIndex()) {
    case 0:
        createSphere();
        break;
    case 1:
        createParallelepiped();
        break;
    case 2:
        createPyramid();
        break;
    case 3:
        createPrism();
    }
    creatematerial();
    _added = true;
    close();
}

void AdditionDialog::cancel() {
    close();
}

std::vector<std::shared_ptr<objects::GeometryObject>> AdditionDialog::object() const {
    return _object;
}

Material AdditionDialog::Material() const {
    return _material;
}

bool AdditionDialog::is_added() const {
    return _added;
}

void AdditionDialog::createSphere() {
    float x = _ui->s_x->value();
    float y = _ui->s_y->value();
    float z = _ui->s_z->value();
    float r = _ui->s_r->value();
    _object.push_back(std::make_shared<objects::Sphere>(math::Vector3d(x, y, z), r));
}

void AdditionDialog::createParallelepiped() {
    math::Vector3d dot = {_ui->paral_x->value(), _ui->paral_y->value(), _ui->paral_z->value()};
    float w = _ui->paral_w->value();
    float h = _ui->paral_h->value();
    float l = _ui->paral_l->value();
    float angle = _ui->paral_a->value() / 180 * M_PI;

    auto triangles = objects::Parallelepiped(dot, w, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::createPyramid() {
    math::Vector3d dot = {_ui->pyr_x->value(), _ui->pyr_y->value(), _ui->pyr_z->value()};
    float h = _ui->pyr_h->value();
    float l = _ui->pyr_l->value();
    float angle = _ui->pyr_a->value() / 180 * M_PI;

    auto triangles = objects::Pyramid(dot, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::createPrism() {
    math::Vector3d dot = {_ui->pr_x->value(), _ui->pr_y->value(), _ui->pr_z->value()};
    float h = _ui->pr_h->value();
    float l = _ui->pr_l->value();
    float angle = _ui->pr_a->value() / 180 * M_PI;

    auto triangles = objects::Prism(dot, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::creatematerial() {
    float spec = _ui->spec->value();
    float refl = _ui->refl->value();
    float rough = _ui->rough->value();
    _material = {
        math::Vector3d{
            float(_color.red()),
            float(_color.green()),
            float(_color.blue())},
        spec, refl, rough, 0
    };
}
