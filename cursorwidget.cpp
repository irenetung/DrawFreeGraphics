#include "cursorwidget.h"
#include <QDebug>

CursorWidget::CursorWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,255,153));
    this->setStyleSheet("QPushButton{background-color:#FFFFCC; border-color:#FF9933; border-style:solid; border-width:3px; border-radius:3px;} QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}");
}

CursorWidgetCursors::CursorWidgetCursors()
{
    translateButton = new QPushButton("translate");
    setButtonProperties(translateButton);
    scaleButton = new QPushButton("scale");
    setButtonProperties(scaleButton);
    stretchButton = new QPushButton("stretch");
    setButtonProperties(stretchButton);
    rotateButton = new QPushButton("rotate");
    setButtonProperties(rotateButton);
    depthButton = new QPushButton("depth");
    setButtonProperties(depthButton);
    shearButton = new QPushButton("shear");
    setButtonProperties(shearButton);
    changeOutlineColorButton = new QPushButton("change\noutline\ncolor");
    setButtonProperties(changeOutlineColorButton);
    changeFillColorButton = new QPushButton("change\nfill\ncolor");
    setButtonProperties(changeFillColorButton);
    changeBrushColorButton = new QPushButton("change\nbrush\ncolor");
    setButtonProperties(changeBrushColorButton);
    changeOutlineSizeButton = new QPushButton("change\noutline\nsize");
    setButtonProperties(changeOutlineSizeButton);
    changeBrushSizeButton = new QPushButton("change\nbrush\nsize");
    setButtonProperties(changeBrushSizeButton);
    copyButton = new QPushButton("copy");
    setButtonProperties(copyButton);
    deleteButton = new QPushButton("delete");
    setButtonProperties(deleteButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

//-------------------------------------------------------
CursorWidgetTranslate::CursorWidgetTranslate()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    signButton = new QPushButton("+");
    setButtonProperties(signButton);
    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);

    t1Button = new QPushButton("1");
    setButtonProperties(t1Button);
    t5Button = new QPushButton("5");
    setButtonProperties(t5Button);
    t10Button = new QPushButton("10");
    setButtonProperties(t10Button);
    t20Button = new QPushButton("20");
    setButtonProperties(t20Button);
    t50Button = new QPushButton("50");
    setButtonProperties(t50Button);
    t100Button = new QPushButton("100");
    setButtonProperties(t100Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(t1Button);
    addToButtonGroup(t5Button);
    addToButtonGroup(t10Button);
    addToButtonGroup(t20Button);
    addToButtonGroup(t50Button);
    addToButtonGroup(t100Button);

    buttonGroup->setExclusive(true);
}

void CursorWidgetTranslate::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

void CursorWidgetTranslate::toggleDirection(bool directionHorizontal)
{
    if(directionHorizontal == true) {
        directionButton->setText("horizontal");
    } else {
        directionButton->setText("vertical");
    }
}
//-------------------------------------------------------
CursorWidgetScale::CursorWidgetScale()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    signButton = new QPushButton("+");
    setButtonProperties(signButton);
    resetButton = new QPushButton("reset to\noriginal");
    setButtonProperties(resetButton);

    s1Button = new QPushButton(".01");
    setButtonProperties(s1Button);
    s5Button = new QPushButton(".05");
    setButtonProperties(s5Button);
    s10Button = new QPushButton(".1");
    setButtonProperties(s10Button);
    s20Button = new QPushButton(".2");
    setButtonProperties(s20Button);
    s50Button = new QPushButton(".5");
    setButtonProperties(s50Button);
    s100Button = new QPushButton("1");
    setButtonProperties(s100Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(resetButton);
    addToButtonGroup(s1Button);
    addToButtonGroup(s5Button);
    addToButtonGroup(s10Button);
    addToButtonGroup(s20Button);
    addToButtonGroup(s50Button);
    addToButtonGroup(s100Button);

    buttonGroup->setExclusive(true);
}

void CursorWidgetScale::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

//-------------------------------------------------------
CursorWidgetStretch::CursorWidgetStretch()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    signButton = new QPushButton("+");
    setButtonProperties(signButton);
    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);
    st0005Button = new QPushButton(".005");
    setButtonProperties(st0005Button);
    st001Button = new QPushButton(".01");
    setButtonProperties(st001Button);
    st005Button = new QPushButton(".05");
    setButtonProperties(st005Button);
    st01Button = new QPushButton(".1");
    setButtonProperties(st01Button);
    st02Button = new QPushButton(".2");
    setButtonProperties(st02Button);
    st05Button = new QPushButton(".5");
    setButtonProperties(st05Button);
    st1Button = new QPushButton("1");
    setButtonProperties(st1Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(st0005Button);
    addToButtonGroup(st001Button);
    addToButtonGroup(st005Button);
    addToButtonGroup(st01Button);
    addToButtonGroup(st02Button);
    addToButtonGroup(st05Button);
    addToButtonGroup(st1Button);

    buttonGroup->setExclusive(true);
}

void CursorWidgetStretch::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

void CursorWidgetStretch::toggleDirection(bool directionHorizontal)
{
    if(directionHorizontal == true) {
        directionButton->setText("horizontal");
    } else {
        directionButton->setText("vertical");
    }
}
//--------------------------------------------------------------
CursorWidgetRotate::CursorWidgetRotate()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    signButton = new QPushButton("+");
    setButtonProperties(signButton);
    resetButton = new QPushButton("reset\nto 0");
    setButtonProperties(resetButton);
    r01Button = new QPushButton("0.1");
    setButtonProperties(r01Button);
    r05Button = new QPushButton("0.5");
    setButtonProperties(r05Button);
    r1Button = new QPushButton("1");
    setButtonProperties(r1Button);
    r5Button = new QPushButton("5");
    setButtonProperties(r5Button);
    r10Button = new QPushButton("10");
    setButtonProperties(r10Button);
    r20Button = new QPushButton("20");
    setButtonProperties(r20Button);
    r30Button = new QPushButton("30");
    setButtonProperties(r30Button);
    r45Button = new QPushButton("45");
    setButtonProperties(r45Button);
    r60Button = new QPushButton("60");
    setButtonProperties(r60Button);
    r72Button = new QPushButton("72");
    setButtonProperties(r72Button);
    r90Button = new QPushButton("90");
    setButtonProperties(r90Button);;
    r120Button = new QPushButton("120");
    setButtonProperties(r120Button);
    r180Button = new QPushButton("180");
    setButtonProperties(r180Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(resetButton);
    addToButtonGroup(r01Button);
    addToButtonGroup(r05Button);
    addToButtonGroup(r1Button);
    addToButtonGroup(r5Button);
    addToButtonGroup(r10Button);
    addToButtonGroup(r20Button);
    addToButtonGroup(r30Button);
    addToButtonGroup(r45Button);
    addToButtonGroup(r60Button);
    addToButtonGroup(r72Button);
    addToButtonGroup(r90Button);
    addToButtonGroup(r120Button);
    addToButtonGroup(r180Button);

    buttonGroup->setExclusive(true);
}

void CursorWidgetRotate::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

//-----------------------------------------------------
CursorWidgetShear::CursorWidgetShear()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    signButton = new QPushButton("+");
    setButtonProperties(signButton);
    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);
    sh001Button = new QPushButton(".01");
    setButtonProperties(sh001Button);
    sh005Button = new QPushButton(".05");
    setButtonProperties(sh005Button);
    sh01Button = new QPushButton(".1");
    setButtonProperties(sh01Button);
    sh02Button = new QPushButton(".2");
    setButtonProperties(sh02Button);
    sh05Button = new QPushButton(".5");
    setButtonProperties(sh05Button);
    sh1Button = new QPushButton("1");
    setButtonProperties(sh1Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(sh001Button);
    addToButtonGroup(sh005Button);
    addToButtonGroup(sh01Button);
    addToButtonGroup(sh02Button);
    addToButtonGroup(sh05Button);
    addToButtonGroup(sh1Button);

    buttonGroup->setExclusive(true);
}

void CursorWidgetShear::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

void CursorWidgetShear::toggleDirection(bool directionHorizontal)
{
    if(directionHorizontal == true) {
        directionButton->setText("horizontal");
    } else {
        directionButton->setText("vertical");
    }
}

CursorWidgetDepth::CursorWidgetDepth()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);
    dn1Button = new QPushButton("-1");
    setButtonProperties(dn1Button);
    dp1Button = new QPushButton("+1");
    setButtonProperties(dp1Button);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

    buttonGroup = new QButtonGroup();
    addToButtonGroup(dn1Button);
    addToButtonGroup(dp1Button);

    buttonGroup->setExclusive(true);
}

CursorWidgetBack::CursorWidgetBack()
{
    backButton = new QPushButton(QIcon(":/ButtonIcons/ButtonIcons/back.png"), tr(""));
    setButtonProperties(backButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
