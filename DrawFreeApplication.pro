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
    canvas.cpp

HEADERS  += mainwindow.h \
    prompt.h \
    shapeswidget.h \
    item.h \
    canvas.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc