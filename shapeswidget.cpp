#include "shapeswidget.h"

ShapesWidget::ShapesWidget(QWidget *parent) :
    QWidget(parent)
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,229,204));

    dim = 60;
}

void ShapesWidget::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void ShapesWidget::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}

void ShapesWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(dim);
    b->setFixedHeight(dim);
    hLayout->addWidget(b);
}

ShapesWidgetShapes::ShapesWidgetShapes()
{
    hLayout = new QHBoxLayout;

    lineButton = new QPushButton("line");
    setButtonProperties(lineButton);
    pointButton = new QPushButton("point");
    setButtonProperties(pointButton);
    circleButton = new QPushButton("circle");
    setButtonProperties(circleButton);
    rectangleButton = new QPushButton("rectangle");
    setButtonProperties(rectangleButton);
    roundedRectangleButton = new QPushButton("rounded\nrectangle");
    setButtonProperties(roundedRectangleButton);
    polygonButton = new QPushButton("polygon");
    setButtonProperties(polygonButton);
    arcButton = new QPushButton("arc");
    setButtonProperties(arcButton);
    chordButton = new QPushButton("chord");
    setButtonProperties(chordButton);
    pieButton = new QPushButton("pie");
    setButtonProperties(pieButton);
    pathButton = new QPushButton("path");
    setButtonProperties(pathButton);
    textButton = new QPushButton("text");
    setButtonProperties(textButton);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}

ShapesWidgetEndPath::ShapesWidgetEndPath()
{
    hLayout = new QHBoxLayout;

    backButton = new QPushButton("back to\nshapes");
    setButtonProperties(backButton);
    endPathButton = new QPushButton("end path");
    setButtonProperties(endPathButton);

    hLayout->addWidget(endPathButton);
    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);

    this->setLayout(hLayout);
}


