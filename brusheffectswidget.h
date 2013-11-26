#ifndef BRUSHEFFECTSWIDGET_H
#define BRUSHEFFECTSWIDGET_H

#include "basewidget.h"

class BrushEffectsWidget : public BaseWidget
{
public:
    explicit BrushEffectsWidget();
};

class BrushEffectsWidgetBrushEffects : public BrushEffectsWidget
{
public:
    explicit BrushEffectsWidgetBrushEffects(QWidget *parent = 0);
    QPushButton *brushSizeButton;
    QPushButton *brushColorButton;
    QPushButton *paintButton;
    QPushButton *waterColorButton;
    QPushButton *calligraphyButton;
    QPushButton *pencilButton;
    QPushButton *sprayPaintButton;
    QPushButton *dustButton;
};

class BrushEffectsWidgetBrushSizes : public BrushEffectsWidget
{
public:
    explicit BrushEffectsWidgetBrushSizes();
    QString currentSize;
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *si1Button;
    QPushButton *si5Button;
    QPushButton *si10Button;
    QPushButton *si20Button;
    QPushButton *si50Button;
    QPushButton *si100Button;
};

#endif // BRUSHEFFECTSWIDGET_H
