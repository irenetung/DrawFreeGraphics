#include "brusheffectswidget.h"

BrushEffectsWidget::BrushEffectsWidget(QWidget *parent) :
    QWidget(parent)
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(204,255,204));

    dim = 60;
}

void BrushEffectsWidget::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void BrushEffectsWidget::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}

void BrushEffectsWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(dim);
    b->setFixedHeight(dim);
    hLayout->addWidget(b);
}

BrushEffectsWidgetBrushEffects::BrushEffectsWidgetBrushEffects(QWidget *parent)
{
    hLayout = new QHBoxLayout;

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

    QSpacerItem *horizSpacer = new QSpacerItem(dim,dim,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);

    this->setLayout(hLayout);
}
