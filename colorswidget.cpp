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

    peachButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    peachButtonIcon->fill(QColor(255,239,213));
    pinkButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    pinkButtonIcon->fill(QColor(255,102,178));
    redButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    redButtonIcon->fill(QColor(255,51,51));
    orangeButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    orangeButtonIcon->fill(QColor(255,128,0));
    yellowButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    yellowButtonIcon->fill(QColor(255,255,51));
    greenButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    greenButtonIcon->fill(QColor(102,204,0));
    blueButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    blueButtonIcon->fill(QColor(0,128,255));
    purpleButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    purpleButtonIcon->fill(QColor(153,51,255));
    brownButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    brownButtonIcon->fill(QColor(102,51,0));
    blackButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    blackButtonIcon->fill(QColor(0,0,0));
    grayButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    grayButtonIcon->fill(QColor(192,192,192));
    whiteButtonIcon = new QPixmap(buttonWidth,buttonHeight);
    whiteButtonIcon->fill(QColor(255,255,255));

    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    peachButton = new QPushButton(QIcon(*peachButtonIcon), tr(""));
   // peachButton = new QPushButton(tr(""));
    setButtonProperties(peachButton);
    pinkButton = new QPushButton(QIcon(*pinkButtonIcon), tr(""));
    setButtonProperties(pinkButton);
    redButton = new QPushButton(QIcon(*redButtonIcon), tr(""));
    setButtonProperties(redButton);
    orangeButton = new QPushButton(QIcon(*orangeButtonIcon), tr(""));
    setButtonProperties(orangeButton);
    yellowButton = new QPushButton(QIcon(*yellowButtonIcon), tr(""));
    setButtonProperties(yellowButton);
    greenButton = new QPushButton(QIcon(*greenButtonIcon), tr(""));
    setButtonProperties(greenButton);
    blueButton = new QPushButton(QIcon(*blueButtonIcon), tr(""));
    setButtonProperties(blueButton);
    purpleButton = new QPushButton(QIcon(*purpleButtonIcon), tr(""));
    setButtonProperties(purpleButton);
    brownButton = new QPushButton(QIcon(*brownButtonIcon), tr(""));
    setButtonProperties(brownButton);
    blackButton = new QPushButton(QIcon(*blackButtonIcon), tr(""));
    setButtonProperties(blackButton);
    grayButton = new QPushButton(QIcon(*grayButtonIcon), tr(""));
    setButtonProperties(grayButton);
    whiteButton = new QPushButton(QIcon(*whiteButtonIcon), tr(""));
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
