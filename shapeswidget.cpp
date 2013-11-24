#include "shapeswidget.h"

ShapesWidget::ShapesWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(153,255,153));
    this->setStyleSheet("QPushButton{background-color:#CCFFCC; border-color:#00CC66; border-style:solid; border-width:3px; border-radius:3px;} QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}");
}

ShapesWidgetShapes::ShapesWidgetShapes()
{
    outlineSizeButton = new QPushButton("set\noutline\nsize");
    setButtonProperties(outlineSizeButton);
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

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(lineButton);
    addToButtonGroup(pointButton);
    addToButtonGroup(circleButton);
    addToButtonGroup(rectangleButton);
    addToButtonGroup(roundedRectangleButton);
    addToButtonGroup(polygonButton);
    addToButtonGroup(arcButton);
    addToButtonGroup(chordButton);
    addToButtonGroup(pieButton);
    addToButtonGroup(pathButton);
    addToButtonGroup(textButton);

    buttonGroup->setExclusive(true);
}

ShapesWidgetEndPath::ShapesWidgetEndPath()
{
    backButton = new QPushButton("back to\nshapes");
    setButtonProperties(backButton);
    endPathButton = new QPushButton("end path");
    setButtonProperties(endPathButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ShapesWidgetOutlineSizes::ShapesWidgetOutlineSizes()
{
    backButton = new QPushButton("back to\ncolors");
    setButtonProperties(backButton);
    on1Button = new QPushButton("-1");
    setButtonProperties(on1Button);
    op1Button = new QPushButton("+1");
    setButtonProperties(op1Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
