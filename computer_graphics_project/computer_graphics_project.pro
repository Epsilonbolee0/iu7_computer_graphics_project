QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands/add_model_command.cpp \
    commands/move_camera_command.cpp \
    commands/pitch_camera_command.cpp \
    commands/remove_camera_command.cpp \
    commands/remove_model_command.cpp \
    commands/render_command.cpp \
    commands/roll_camera_command.cpp \
    commands/set_camera_command.cpp \
    commands/yaw_camera_command.cpp \
    facade/viewer_facade.cpp \
    intermediary/intermediary.cpp \
    main.cpp \
    mainwindow.cpp \
    math/matrix.cpp \
    math/point.cpp \
    math/transform_matrix.cpp \
    objects/camera.cpp \
    objects/composite.cpp \
    objects/mesh.cpp \
    objects/model.cpp \
    objects/object.cpp \
    scene/scene.cpp \
    scene/scene_manager.cpp

HEADERS += \
    base_manager.h \
    commands/add_model_command.h \
    commands/base_command.h \
    commands/move_camera_command.h \
    commands/pitch_camera_command.h \
    commands/remove_camera_command.h \
    commands/remove_model_command.h \
    commands/render_command.h \
    commands/roll_camera_command.h \
    commands/set_camera_command.h \
    commands/transform_model_command.h \
    commands/yaw_camera_command.h \
    exceptions/base_viewer_exception.h \
    exceptions/drawer_exception.h \
    exceptions/file_open_exception.h \
    exceptions/model_build_exception.h \
    exceptions/no_camera_exception.h \
    exceptions/object_search_exception.h \
    exceptions/object_type_exception.h \
    facade/viewer_facade.h \
    intermediary/intermediary.h \
    mainwindow.h \
    math/matrix.h \
    math/point.h \
    math/transform_matrix.h \
    objects/camera.h \
    objects/composite.h \
    objects/mesh.h \
    objects/model.h \
    objects/object.h \
    scene/scene.h \
    scene/scene_manager.h \
    visitor/visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
