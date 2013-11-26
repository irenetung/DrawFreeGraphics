#include "shapeswidget.h"

ShapesWidget::ShapesWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(153,255,153));
    this->setStyleSheet(tr("QPushButton{background-color:#CCFFCC; border-color:#00CC66; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}"));
}

ShapesWidgetShapes::ShapesWidgetShapes()
{
    QPainter iconPainter;
    QPen iconPen;
    iconPen.setColor(Qt::black);
    iconPen.setWidth(8);
    iconPen.setStyle(Qt::SolidLine);
    iconPen.setCapStyle(Qt::RoundCap);
    iconPen.setJoinStyle(Qt::RoundJoin);
    QBrush iconBrush(Qt::white);
    QRectF rect(30,50,120,80);
    QPolygon polygon;
    polygon << QPoint(40,140) << QPoint(40,40) << QPoint(100,40) << QPoint(140,90) << QPoint(100,140);
    QFont iconFont;
    iconFont.setPixelSize(100);

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
    iconPainter.begin(textButtonIcon);
    iconPainter.setFont(iconFont);
    iconPainter.drawText(rect,Qt::AlignCenter,tr("A"));
    iconPainter.end();

    outlineSizeButton = new QPushButton(tr("Set\nOutline\nSize"));
    outlineSizeButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
    setButtonProperties(outlineSizeButton);
    outlineColorButton = new QPushButton(tr("Set\nOutline\nColor"));
    outlineColorButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
    setButtonProperties(outlineColorButton);
    fillColorButton = new QPushButton(tr("Set\nFill\nColor"));
    fillColorButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
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
    backButton = new QPushButton(tr("< Shapes"));
    backButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
    setButtonProperties(backButton);
    endPathButton = new QPushButton(tr("end path"));
    setButtonProperties(endPathButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ShapesWidgetOutlineSizes::ShapesWidgetOutlineSizes()
{
    currentSize = tr("The current outline size is: %1. Adjust the outline size. Or click a shape on the canvas to change its outline size. Toggle the sign button to change the increments from positive to negative or vice versa.");

    backButton = new QPushButton(tr("< Shapes"));
    backButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
    setButtonProperties(backButton);
    signButton = new QPushButton(tr("+"));
    signButton->setStyleSheet(tr("QPushButton{background-color:#99FFCC;}"));
    setButtonProperties(signButton);

    si1Button = new QPushButton(tr("1"));
    setButtonProperties(si1Button);
    si5Button = new QPushButton(tr("5"));
    setButtonProperties(si5Button);
    si10Button = new QPushButton(tr("10"));
    setButtonProperties(si10Button);
    si20Button = new QPushButton(tr("20"));
    setButtonProperties(si20Button);
    si50Button = new QPushButton(tr("50"));
    setButtonProperties(si50Button);
    si100Button = new QPushButton(tr("100"));
    setButtonProperties(si100Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToGroup(si1Button);
    addToGroup(si5Button);
    addToGroup(si10Button);
    addToGroup(si20Button);
    addToGroup(si50Button);
    addToGroup(si100Button);
}


ShapesWidgetKeyboardLetters::ShapesWidgetKeyboardLetters()
{
    qButton = new QPushButton(tr("Q"));
    setButtonProperties(qButton);
    wButton = new QPushButton(tr("W"));
    setButtonProperties(wButton);
    eButton = new QPushButton(tr("E"));
    setButtonProperties(eButton);
    rButton = new QPushButton(tr("R"));
    setButtonProperties(rButton);
    tButton = new QPushButton(tr("T"));
    setButtonProperties(tButton);
    yButton = new QPushButton(tr("Y"));
    setButtonProperties(yButton);
    uButton = new QPushButton(tr("U"));
    setButtonProperties(uButton);
    iButton = new QPushButton(tr("I"));
    setButtonProperties(iButton);
    oButton = new QPushButton(tr("O"));
    setButtonProperties(oButton);
    pButton = new QPushButton(tr("P"));
    setButtonProperties(pButton);

    aButton = new QPushButton(tr("A"));
    setButtonProperties(aButton);
    sButton = new QPushButton(tr("S"));
    setButtonProperties(sButton);
    dButton = new QPushButton(tr("D"));
    setButtonProperties(dButton);
    fButton = new QPushButton(tr("F"));
    setButtonProperties(fButton);
    gButton = new QPushButton(tr("G"));
    setButtonProperties(gButton);
    hButton = new QPushButton(tr("H"));
    setButtonProperties(hButton);
    jButton = new QPushButton(tr("J"));
    setButtonProperties(jButton);
    kButton = new QPushButton(tr("K"));
    setButtonProperties(lButton);
    lButton = new QPushButton(tr("L"));
    setButtonProperties(lButton);

    shiftButton= new QPushButton(tr("Shift"));
    setButtonProperties(shiftButton);
    zButton = new QPushButton(tr("Z"));
    setButtonProperties(zButton);
    xButton = new QPushButton(tr("X"));
    setButtonProperties(xButton);
    cButton = new QPushButton(tr("C"));
    setButtonProperties(cButton);
    vButton = new QPushButton(tr("V"));
    setButtonProperties(vButton);
    bButton = new QPushButton(tr("B"));
    setButtonProperties(bButton);
    nButton = new QPushButton(tr("N"));
    setButtonProperties(nButton);
    mButton = new QPushButton(tr("M"));
    setButtonProperties(mButton);
    backSpaceButton = new QPushButton(tr("Backspace"));
    setButtonProperties(backSpaceButton);

    numbersButton = new QPushButton(tr("123"));
    setButtonProperties(numbersButton);
    spaceButton = new QPushButton(tr("Space"));
    setButtonProperties(spaceButton);
    enterButton = new QPushButton(tr("Enter"));
    setButtonProperties(enterButton);
}


ShapesWidgetKeyboardNumbers::ShapesWidgetKeyboardNumbers()
{

}


ShapesWidgetKeyboardSymbols::ShapesWidgetKeyboardSymbols()
{

}
