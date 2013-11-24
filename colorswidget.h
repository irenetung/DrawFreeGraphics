#ifndef COLORSWIDGET_H
#define COLORSWIDGET_H

#include <QWidget>
#include "basewidget.h"

class ColorsWidget : public BaseWidget
{
public:
    explicit ColorsWidget();
};

class ColorsWidgetPaintTools : public ColorsWidget
{
public:
    //QButtonGroup paintToolsGroup;
    explicit ColorsWidgetPaintTools();
    QPushButton *outlineButton;
    QPushButton *fillButton;
    QPushButton *silhouetteButton;
    QPushButton *brushButton;
    QPushButton *backgroundButton;
};

class ColorsWidgetColors : public ColorsWidget
{
public:
    explicit ColorsWidgetColors();
    QPixmap *peachButtonIcon;
    QPixmap *pinkButtonIcon;
    QPixmap *redButtonIcon;
    QPixmap *orangeButtonIcon;
    QPixmap *yellowButtonIcon;
    QPixmap *greenButtonIcon;
    QPixmap *blueButtonIcon;
    QPixmap *purpleButtonIcon;
    QPixmap *brownButtonIcon;
    QPixmap *blackButtonIcon;
    QPixmap *grayButtonIcon;
    QPixmap *whiteButtonIcon;

    QPushButton *backButton;
    QPushButton *whiteButton;
    QPushButton *peachButton;
    QPushButton *pinkButton;
    QPushButton *redButton;
    QPushButton *orangeButton;
    QPushButton *yellowButton;
    QPushButton *greenButton;
    QPushButton *blueButton;
    QPushButton *purpleButton;
    QPushButton *brownButton;
    QPushButton *blackButton;
    QPushButton *grayButton;
    QPushButton *prevCustomButton;
    QPushButton *customColorButton;

};

#endif // COLORSWIDGET_H
