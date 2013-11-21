#include "colorswidget.h"

ColorsWidget::ColorsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,229,204));
}

ColorsWidgetPaintTools::ColorsWidgetPaintTools()
{
    hLayout = new FlowLayout;

    outlineButton = new QPushButton("outline");
    setButtonProperties(outlineButton);
    fillButton = new QPushButton("fill");
    setButtonProperties(fillButton);
    brushButton = new QPushButton("brush");
    setButtonProperties(brushButton);
    backgroundButton = new QPushButton("back\nground");
    setButtonProperties(backgroundButton);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ColorsWidgetColors::ColorsWidgetColors()
{
    hLayout = new FlowLayout;

    pink = new QPixmap(buttonWidth,buttonHeight);
    pink->fill(QColor(255,229,204));

    backButton = new QPushButton("back");
    setButtonProperties(backButton);
    peachButton = new QPushButton("peach");
    setButtonProperties(peachButton);
    pinkButton = new QPushButton(QIcon(*pink), tr(""));
    setButtonProperties(pinkButton);
    redButton = new QPushButton("red");
    setButtonProperties(redButton);
    orangeButton = new QPushButton("orange");
    setButtonProperties(orangeButton);
    yellowButton = new QPushButton("yellow");
    setButtonProperties(yellowButton);
    greenButton = new QPushButton("green");
    setButtonProperties(greenButton);
    blueButton = new QPushButton("blue");
    setButtonProperties(blueButton);
    purpleButton = new QPushButton("purple");
    setButtonProperties(purpleButton);
    brownButton = new QPushButton("brown");
    setButtonProperties(brownButton);
    blackButton = new QPushButton("black");
    setButtonProperties(blackButton);
    grayButton = new QPushButton("gray");
    setButtonProperties(grayButton);
    whiteButton = new QPushButton("white");
    setButtonProperties(whiteButton);
    customColorButton = new QPushButton("custom\ncolor");
    setButtonProperties(customColorButton);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ColorsWidgetOutlineSizes::ColorsWidgetOutlineSizes()
{
    hLayout = new FlowLayout;

    backButton = new QPushButton("back to\ncolors");
    setButtonProperties(backButton);
    on1Button = new QPushButton("-1");
    setButtonProperties(on1Button);
    op1Button = new QPushButton("+1");
    setButtonProperties(op1Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
