#include "colorswidget.h"

ColorsWidget::ColorsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(204,255,153));
    this->setStyleSheet("QPushButton{background-color:#E5FFCC; border-color:#66CC00; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QLabel{background-color:#E5FFCC; border-color:#66CC00;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}");
}

ColorsWidgetPaintTools::ColorsWidgetPaintTools()
{
    borderColor = tr("QPushButton {border-color: %1;}");

    outlineButton = new QPushButton(tr("Outline"));
    outlineButton->setStyleSheet(borderColor.arg(QColor(0,0,0).name()));
    setButtonProperties(outlineButton);
    fillButton = new QPushButton(tr("Fill"));
    fillButton->setStyleSheet(borderColor.arg(QColor(255,255,255).name()));
    setButtonProperties(fillButton);
    silhouetteButton = new QPushButton(tr("Silhouette"));
    silhouetteButton->setStyleSheet(borderColor.arg(QColor(0,0,0).name()));
    setButtonProperties(silhouetteButton);
    brushButton = new QPushButton(tr("Brush"));
    brushButton->setStyleSheet(borderColor.arg(QColor(0,0,0).name()));
    setButtonProperties(brushButton);
    backgroundButton = new QPushButton(tr("Background"));
    backgroundButton->setStyleSheet(borderColor.arg(QColor(255,255,255).name()));
    setButtonProperties(backgroundButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToGroup(outlineButton);
    addToGroup(fillButton);
    addToGroup(silhouetteButton);
    addToGroup(brushButton);
    addToGroup(backgroundButton);
}

ColorsWidgetColors::ColorsWidgetColors(ColorsWidgetColors::WidgetType widgetType)
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
    purpleButtonIcon->fill(QColor(153,0,153));
    brownButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    brownButtonIcon->fill(QColor(102,51,0));
    blackButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    blackButtonIcon->fill(QColor(0,0,0));
    grayButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    grayButtonIcon->fill(QColor(192,192,192));
    whiteButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    whiteButtonIcon->fill(QColor(255,255,255));
    prevCustomButtonIcon = new QPixmap(buttonWidth*3,buttonHeight*3);
    prevCustomButtonIcon->fill(QColor(255,255,255));

    colorsBackButton = new QPushButton(tr("< paint\ntools"));
    colorsBackButton->setStyleSheet(tr("QPushButton{background-color:#99FF99;}"));
    setButtonProperties(colorsBackButton);

    switch(widgetType) {
        case SHAPES:
            otherBackButton = new QPushButton(tr("< shapes"));
            otherBackButton->setStyleSheet(tr("QPushButton{background-color:#99FF99;}"));
            setButtonProperties(otherBackButton);
            break;
        case STAMPS:
            otherBackButton = new QPushButton(tr("< silhouette\nstamps"));
            otherBackButton->setStyleSheet(tr("QPushButton{background-color:#99FF99;}"));
            setButtonProperties(otherBackButton);
            break;
        case BRUSHEFFECTS:
            otherBackButton = new QPushButton(tr("< brush\neffects"));
            otherBackButton->setStyleSheet(tr("QPushButton{background-color:#99FF99;}"));
            setButtonProperties(otherBackButton);
            break;
        default:
            break;
    }

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
    prevCustomButton = new QPushButton(QIcon(*prevCustomButtonIcon), tr(""));
    setButtonProperties(prevCustomButton);
    customColorButton = new QPushButton("Custom\nColor");
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
