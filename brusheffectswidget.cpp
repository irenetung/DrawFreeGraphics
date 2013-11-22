#include "brusheffectswidget.h"

BrushEffectsWidget::BrushEffectsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(204,255,204));
}

BrushEffectsWidgetBrushEffects::BrushEffectsWidgetBrushEffects(QWidget *parent)
{
    hLayout = new FlowLayout;

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

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
