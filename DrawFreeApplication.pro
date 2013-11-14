#-------------------------------------------------
#
# Project created by QtCreator 2013-11-02T16:38:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawFreeApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    prompt.cpp \
    shapeswidget.cpp \
    item.cpp \
    canvas.cpp \
    cursorwidget.cpp \
<<<<<<< HEAD
    brusheffectswidget.cpp \
    drawwidget.cpp
=======
    stampswidget.cpp
>>>>>>> 4b8faeb1c9a7e7c2e86f0ac0c9badfc60af8b276

HEADERS  += mainwindow.h \
    prompt.h \
    shapeswidget.h \
    item.h \
    canvas.h \
    cursorwidget.h \
<<<<<<< HEAD
    brusheffectswidget.h \
    drawwidget.h
=======
    stampswidget.h
>>>>>>> 4b8faeb1c9a7e7c2e86f0ac0c9badfc60af8b276

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
