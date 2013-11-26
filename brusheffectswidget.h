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

#endif // BRUSHEFFECTSWIDGET_H
