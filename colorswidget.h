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
    QString borderColor;

    QPushButton *outlineButton;
    QPushButton *fillButton;
    QPushButton *silhouetteButton;
    QPushButton *brushButton;
    QPushButton *backgroundButton;
};

class ColorsWidgetColors : public ColorsWidget
{
public:
    enum WidgetType{OUTLINE,FILL,STAMPS,BRUSHEFFECTS,BACKGROUND};
    explicit ColorsWidgetColors(WidgetType widgetType);
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
    QPixmap *prevCustomButtonIcon;

    QPushButton *colorsBackButton;
    QPushButton *otherBackButton;
    QPushButton *alphaButton;
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

class ColorsWidgetAlpha : public ColorsWidget
{
public:
    enum AlphaWidgetType{OUTLINE,FILL,STAMPS,BRUSHEFFECTS,BACKGROUND};
    explicit ColorsWidgetAlpha(ColorsWidgetAlpha::AlphaWidgetType widgetType);
    QString currentAlpha;
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *transparentButton;
    QPushButton *a1Button;
    QPushButton *a5Button;
    QPushButton *a10Button;
    QPushButton *a20Button;
    QPushButton *a50Button;
    QPushButton *a100Button;
    QPushButton *opaqueButton;
};

#endif // COLORSWIDGET_H
