#ifndef ADDITION_DIALOG_H
#define ADDITION_DIALOG_H

#include <QDialog>
#include "objects/geometry_objects/GeometryObject.h"
#include "objects/geometry_objects/Sphere.h"
#include "objects/geometry_objects/Parallelepiped.h"
#include "objects/geometry_objects/Pyramid.h"
#include "objects/geometry_objects/Prism.h"
#include "objects/material.h"

namespace Ui {
    class Dialog;
}

class AdditionDialog : public QDialog {
    Q_OBJECT
public:
    explicit AdditionDialog(QWidget *parent = nullptr);
    ~AdditionDialog() override;

    bool is_added() const;
    Material Material() const;
    std::vector<std::shared_ptr<objects::GeometryObject>> object() const;

public slots:
    void color();
    void accept() override;
    void cancel();
private:
    Ui::Dialog *_ui;
    QColor _color;
    std::vector<std::shared_ptr<objects::GeometryObject>> _object;
    struct Material _material;
    bool _added;

    void createSphere();
    void createParallelepiped();
    void createPyramid();
    void createPrism();
    void creatematerial();
};

#endif // ADDITION_DIALOG_H
