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

ShapesWidgetShapes::ShapesWidgetShapes()
{
    previousShapeButton = new QPushButton("previous\nshape");
    previousShapeButton->setFixedWidth(dim);
    previousShapeButton->setFixedHeight(dim);

    lineButton = new QPushButton("line");
    lineButton->setFixedWidth(dim);
    lineButton->setFixedHeight(dim);

    pointButton = new QPushButton("point");
    pointButton->setFixedWidth(dim);
    pointButton->setFixedHeight(dim);

    circleButton = new QPushButton("circle");
    circleButton->setFixedWidth(dim);
    circleButton->setFixedHeight(dim);

    rectangleButton = new QPushButton("rectangle");
    rectangleButton->setFixedWidth(dim);
    rectangleButton->setFixedHeight(dim);

    roundedRectangleButton = new QPushButton("rounded\nrectangle");
    roundedRectangleButton->setFixedWidth(dim);
    roundedRectangleButton->setFixedHeight(dim);

    polygonButton = new QPushButton("polygon");
    polygonButton->setFixedWidth(dim);
    polygonButton->setFixedHeight(dim);

    arcButton = new QPushButton("arc");
    arcButton->setFixedWidth(dim);
    arcButton->setFixedHeight(dim);

    chordButton = new QPushButton("chord");
    chordButton->setFixedWidth(dim);
    chordButton->setFixedHeight(dim);

    pieButton = new QPushButton("pie");
    pieButton->setFixedWidth(dim);
    pieButton->setFixedHeight(dim);

    pathButton = new QPushButton("path");
    pathButton->setFixedWidth(dim);
    pathButton->setFixedHeight(dim);

    textButton = new QPushButton("text");
    textButton->setFixedWidth(dim);
    textButton->setFixedHeight(dim);

    hLayout = new QHBoxLayout;
    hLayout->addWidget(previousShapeButton);
    hLayout->addWidget(lineButton);
    hLayout->addWidget(pointButton);
    hLayout->addWidget(circleButton);
    hLayout->addWidget(rectangleButton);
    hLayout->addWidget(roundedRectangleButton);
    hLayout->addWidget(polygonButton);
    hLayout->addWidget(arcButton);
    hLayout->addWidget(chordButton);
    hLayout->addWidget(pieButton);
    hLayout->addWidget(pathButton);
    hLayout->addWidget(textButton);
    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);

    this->setLayout(hLayout);
}

ShapesWidgetEndPath::ShapesWidgetEndPath()
{
    endPathButton = new QPushButton("end path");
    endPathButton->setFixedWidth(dim);
    endPathButton->setFixedHeight(dim);

    hLayout = new QHBoxLayout;
    hLayout->addWidget(endPathButton);
    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);

    this->setLayout(hLayout);

}
