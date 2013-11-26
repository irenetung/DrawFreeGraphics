#include "shapeswidget.h"

ShapesWidget::ShapesWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(153,255,153));
    this->setStyleSheet("QPushButton{background-color:#CCFFCC; border-color:#00CC66; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}");
}

ShapesWidgetShapes::ShapesWidgetShapes()
{
    QPainter iconPainter;
    QPen iconPen;
    iconPen.setColor(Qt::black);
    iconPen.setWidth(8);
    QBrush iconBrush(Qt::white);
    QRectF rect(30,50,120,80);
    QPolygon polygon;
    polygon << QPoint(40,140) << QPoint(40,40) << QPoint(100,40) << QPoint(140,90) << QPoint(100,140);

    lineButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    lineButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(lineButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.drawLine(40,40,140,140);
    iconPainter.end();
    pointButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    pointButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(pointButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.drawPoint(90,90);
    iconPainter.end();
    circleButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    circleButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(circleButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawEllipse(rect);
    iconPainter.end();
    rectangleButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    rectangleButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(rectangleButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawRect(rect);
    iconPainter.end();
    roundedRectangleButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    roundedRectangleButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(roundedRectangleButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawRoundedRect(rect,20,20);
    iconPainter.end();
    polygonButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    polygonButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(polygonButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawPolygon(polygon);
    iconPainter.end();
    arcButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    arcButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(arcButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.drawArc(rect,30*16,120*16);
    iconPainter.end();
    chordButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    chordButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(chordButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawChord(rect,30*16,120*16);
    iconPainter.end();
    pieButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    pieButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(pieButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawPie(rect,30*16,120*16);
    iconPainter.end();
    pathButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    pathButtonIcon->fill(QColor(204,255,204));
    iconPainter.begin(pathButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawPolyline(polygon);
    iconPainter.end();
    textButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    textButtonIcon->fill(QColor(204,255,204));
    /*iconPainter.begin(textButtonIcon);
    iconPainter.setPen(iconPen);
    iconPainter.setBrush(iconBrush);
    iconPainter.drawText(QPointF(90,90),"A");
    iconPainter.end();*/

    outlineSizeButton = new QPushButton("set\noutline\nsize");
    outlineSizeButton->setStyleSheet("QPushButton{background-color:#99FFCC;}");
    setButtonProperties(outlineSizeButton);
    outlineColorButton = new QPushButton("set\noutline\ncolor");
    outlineColorButton->setStyleSheet("QPushButton{background-color:#99FFCC;}");
    setButtonProperties(outlineColorButton);
    fillColorButton = new QPushButton("set\nfill\ncolor");
    fillColorButton->setStyleSheet("QPushButton{background-color:#99FFCC;}");
    setButtonProperties(fillColorButton);

    lineButton = new QPushButton(QIcon(*lineButtonIcon), tr(""));
    setButtonProperties(lineButton);
    pointButton = new QPushButton(QIcon(*pointButtonIcon), tr(""));
    setButtonProperties(pointButton);
    circleButton = new QPushButton(QIcon(*circleButtonIcon), tr(""));
    setButtonProperties(circleButton);
    rectangleButton = new QPushButton(QIcon(*rectangleButtonIcon), tr(""));
    setButtonProperties(rectangleButton);
    roundedRectangleButton = new QPushButton(QIcon(*roundedRectangleButtonIcon), tr(""));
    setButtonProperties(roundedRectangleButton);
    polygonButton = new QPushButton(QIcon(*polygonButtonIcon), tr(""));
    setButtonProperties(polygonButton);
    arcButton = new QPushButton(QIcon(*arcButtonIcon), tr(""));
    setButtonProperties(arcButton);
    chordButton = new QPushButton(QIcon(*chordButtonIcon), tr(""));
    setButtonProperties(chordButton);
    pieButton = new QPushButton(QIcon(*pieButtonIcon), tr(""));
    setButtonProperties(pieButton);
    pathButton = new QPushButton(QIcon(*pathButtonIcon), tr(""));
    setButtonProperties(pathButton);
    textButton = new QPushButton(QIcon(*textButtonIcon), tr(""));
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
    backButton = new QPushButton("< shapes");
    backButton->setStyleSheet("QPushButton{background-color:#99FFCC;}");
    setButtonProperties(backButton);
    endPathButton = new QPushButton("end path");
    setButtonProperties(endPathButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ShapesWidgetOutlineSizes::ShapesWidgetOutlineSizes()
{
    backButton = new QPushButton("< shapes");
    backButton->setStyleSheet("QPushButton{background-color:#99FFCC;}");
    setButtonProperties(backButton);
    on1Button = new QPushButton("-1");
    setButtonProperties(on1Button);
    op1Button = new QPushButton("+1");
    setButtonProperties(op1Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
