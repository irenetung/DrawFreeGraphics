#include "brusheffectswidget.h"

BrushEffectsWidget::BrushEffectsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(184,184,233));
    this->setStyleSheet("QPushButton{background-color:#CCCCFF; border-color:#6666FF; border-style:solid; border-width:3px; border-radius:3px;} QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}");
}

BrushEffectsWidgetBrushEffects::BrushEffectsWidgetBrushEffects(QWidget *parent)
{
    brushSizeButton = new QPushButton("Set\nBrush\nSize");
    brushSizeButton->setStyleSheet("QPushButton{background-color:#C0C0C0;}");
    setButtonProperties(brushSizeButton);
    brushColorButton = new QPushButton("Set\nBrush\nColor");
    brushColorButton->setStyleSheet("QPushButton{background-color:#C0C0C0;}");
    setButtonProperties(brushColorButton);
    paintButton = new QPushButton("paint");
    setButtonProperties(paintButton);
    waterColorButton = new QPushButton("water\ncolor");
    setButtonProperties(waterColorButton);
    calligraphyButton = new QPushButton("calligraphy");
    setButtonProperties(calligraphyButton);
    pencilButton = new QPushButton("pencil");
    setButtonProperties(pencilButton);
    sprayPaintButton = new QPushButton("spray\npaint");
    setButtonProperties(sprayPaintButton);
    dustButton = new QPushButton("dust");
    setButtonProperties(dustButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(paintButton);
    addToButtonGroup(waterColorButton);
    addToButtonGroup(calligraphyButton);
    addToButtonGroup(pencilButton);
    addToButtonGroup(sprayPaintButton);
    addToButtonGroup(dustButton);

    buttonGroup->setExclusive(true);
}
