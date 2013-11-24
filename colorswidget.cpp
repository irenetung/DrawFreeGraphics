#include "colorswidget.h"

ColorsWidget::ColorsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(204,255,153));
    this->setStyleSheet("QPushButton{background-color:#E5FFCC; border-color:#66CC00; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        );
}

ColorsWidgetPaintTools::ColorsWidgetPaintTools()
{
    outlineButton = new QPushButton("outline");
    setButtonProperties(outlineButton);
    fillButton = new QPushButton("fill");
    setButtonProperties(fillButton);
    brushButton = new QPushButton("brush");
    setButtonProperties(brushButton);
    silhouetteButton = new QPushButton("silhouette");
    setButtonProperties(silhouetteButton);
    backgroundButton = new QPushButton("back\nground");
    setButtonProperties(backgroundButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

ColorsWidgetColors::ColorsWidgetColors()
{
    peachButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    peachButtonIcon->fill(QColor(255,239,213));
    pinkButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    pinkButtonIcon->fill(QColor(255,102,178));
    redButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    redButtonIcon->fill(QColor(255,51,51));
    orangeButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    orangeButtonIcon->fill(QColor(255,128,0));
    yellowButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    yellowButtonIcon->fill(QColor(255,255,51));
    greenButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    greenButtonIcon->fill(QColor(102,204,0));
    blueButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    blueButtonIcon->fill(QColor(0,128,255));
    purpleButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    purpleButtonIcon->fill(QColor(153,51,255));
    brownButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    brownButtonIcon->fill(QColor(102,51,0));
    blackButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    blackButtonIcon->fill(QColor(0,0,0));
    grayButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    grayButtonIcon->fill(QColor(192,192,192));
    whiteButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    whiteButtonIcon->fill(QColor(255,255,255));

    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    whiteButton = new QPushButton(QIcon(*whiteButtonIcon), tr(""));
    setButtonProperties(whiteButton);
    peachButton = new QPushButton(QIcon(*peachButtonIcon), tr(""));
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
    prevCustomButton = new QPushButton("previous\ncustom\ncolor");
    setButtonProperties(prevCustomButton);
    customColorButton = new QPushButton("custom\ncolor");
    setButtonProperties(customColorButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(whiteButton);
    addToButtonGroup(peachButton);
    addToButtonGroup(pinkButton);
    addToButtonGroup(redButton);
    addToButtonGroup(orangeButton);
    addToButtonGroup(yellowButton);
    addToButtonGroup(greenButton);
    addToButtonGroup(blueButton);
    addToButtonGroup(purpleButton);
    addToButtonGroup(brownButton);
    addToButtonGroup(blackButton);
    addToButtonGroup(grayButton);
    addToButtonGroup(prevCustomButton);

    buttonGroup->setExclusive(true);
}
