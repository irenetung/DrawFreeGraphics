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
    explicit ColorsWidgetPaintTools();
    QPushButton *outlineButton;
    QPushButton *fillButton;
    QPushButton *brushButton;
    QPushButton *backgroundButton;
};

class ColorsWidgetColors : public ColorsWidget
{
public:
    explicit ColorsWidgetColors();
    QPixmap *pink;

    QPushButton *backButton;
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
    QPushButton *whiteButton;
    QPushButton *customColorButton;
};

class ColorsWidgetOutlineSizes : public ColorsWidget
{
public:
    explicit ColorsWidgetOutlineSizes();
    QPushButton *backButton;
    QPushButton *on1Button;
    QPushButton *op1Button;

};
#endif // COLORSWIDGET_H
