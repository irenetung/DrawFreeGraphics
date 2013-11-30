#include "textwidget.h"

TextWidget::TextWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(184,184,233));
    this->setStyleSheet(tr("QPushButton{background-color:#CCCCFF; border-color:#6666FF; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}"));

    layout = new QVBoxLayout();
    textEdit = new QTextEdit();
    textEdit->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    layout->addWidget(textEdit);
}

TextWidgetLetters::TextWidgetLetters()
{
    specialKeysButton = new QPushButton(tr("123"));
    specialKeysButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(specialKeysButton);
    changeFontButton = new QPushButton(tr("Change\nFont"));
    changeFontButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(changeFontButton);

    shiftButton= new QPushButton(tr("Shift"));
    shiftButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    shiftButton->setCheckable(true);
    shiftButton->setChecked(true);
    setButtonProperties(shiftButton);

    aButton = new QPushButton(tr("A"));
    setButtonProperties(aButton);
    bButton = new QPushButton(tr("B"));
    setButtonProperties(bButton);
    cButton = new QPushButton(tr("C"));
    setButtonProperties(cButton);
    dButton = new QPushButton(tr("D"));
    setButtonProperties(dButton);
    eButton = new QPushButton(tr("E"));
    setButtonProperties(eButton);
    fButton = new QPushButton(tr("F"));
    setButtonProperties(fButton);
    gButton = new QPushButton(tr("G"));
    setButtonProperties(gButton);
    hButton = new QPushButton(tr("H"));
    setButtonProperties(hButton);
    iButton = new QPushButton(tr("I"));
    setButtonProperties(iButton);
    jButton = new QPushButton(tr("J"));
    setButtonProperties(jButton);
    kButton = new QPushButton(tr("K"));
    setButtonProperties(kButton);
    lButton = new QPushButton(tr("L"));
    setButtonProperties(lButton);
    mButton = new QPushButton(tr("M"));
    setButtonProperties(mButton);
    nButton = new QPushButton(tr("N"));
    setButtonProperties(nButton);
    oButton = new QPushButton(tr("O"));
    setButtonProperties(oButton);
    pButton = new QPushButton(tr("P"));
    setButtonProperties(pButton);
    qButton = new QPushButton(tr("Q"));
    setButtonProperties(qButton);
    rButton = new QPushButton(tr("R"));
    setButtonProperties(rButton);
    sButton = new QPushButton(tr("S"));
    setButtonProperties(sButton);
    tButton = new QPushButton(tr("T"));
    setButtonProperties(tButton);
    uButton = new QPushButton(tr("U"));
    setButtonProperties(uButton);
    vButton = new QPushButton(tr("V"));
    setButtonProperties(vButton);
    wButton = new QPushButton(tr("W"));
    setButtonProperties(wButton);
    xButton = new QPushButton(tr("X"));
    setButtonProperties(xButton);
    yButton = new QPushButton(tr("Y"));
    setButtonProperties(yButton);
    zButton = new QPushButton(tr("Z"));
    setButtonProperties(zButton);

    periodButton = new QPushButton(tr("."));
    setButtonProperties(periodButton);
    commaButton = new QPushButton(tr(","));
    setButtonProperties(commaButton);
    questionButton = new QPushButton(tr("?"));
    setButtonProperties(questionButton);
    exclamationButton = new QPushButton(tr("!"));
    setButtonProperties(exclamationButton);
    apostropheButton = new QPushButton(tr("\'"));
    setButtonProperties(apostropheButton);
    spaceButton = new QPushButton(tr("Space"));
    setButtonProperties(spaceButton);
    enterButton = new QPushButton(tr("Enter"));
    setButtonProperties(enterButton);
    backSpaceButton = new QPushButton(tr("Backspace"));
    backSpaceButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(backSpaceButton);
    clearButton = new QPushButton(tr("Clear"));
    clearButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(clearButton);
    okButton = new QPushButton(tr("OK"));
    okButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(okButton);

    hLayout->addItem(horizSpacer);
    layout->addLayout(hLayout);
    this->setLayout(layout);

    buttonGroup = new QButtonGroup();
    addToGroup(aButton);
    addToGroup(bButton);
    addToGroup(cButton);
    addToGroup(dButton);
    addToGroup(eButton);
    addToGroup(fButton);
    addToGroup(gButton);
    addToGroup(hButton);
    addToGroup(iButton);
    addToGroup(jButton);
    addToGroup(kButton);
    addToGroup(lButton);
    addToGroup(mButton);
    addToGroup(nButton);
    addToGroup(oButton);
    addToGroup(pButton);
    addToGroup(qButton);
    addToGroup(rButton);
    addToGroup(sButton);
    addToGroup(tButton);
    addToGroup(uButton);
    addToGroup(vButton);
    addToGroup(wButton);
    addToGroup(xButton);
    addToGroup(yButton);
    addToGroup(zButton);

    addToGroup(periodButton);
    addToGroup(commaButton);
    addToGroup(questionButton);
    addToGroup(exclamationButton);
    addToGroup(apostropheButton);
    addToGroup(spaceButton);
    addToGroup(enterButton);
}

TextWidgetSpecialKeys::TextWidgetSpecialKeys()
{
    lettersButton = new QPushButton(tr("Letters"));
    lettersButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(lettersButton);
    changeFontButton = new QPushButton(tr("Change\nFont"));
    changeFontButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(changeFontButton);

    n1Button = new QPushButton(tr("1"));
    setButtonProperties(n1Button);
    n2Button = new QPushButton(tr("2"));
    setButtonProperties(n2Button);
    n3Button = new QPushButton(tr("3"));
    setButtonProperties(n3Button);
    n4Button = new QPushButton(tr("4"));
    setButtonProperties(n4Button);
    n5Button = new QPushButton(tr("5"));
    setButtonProperties(n5Button);
    n6Button = new QPushButton(tr("6"));
    setButtonProperties(n6Button);
    n7Button = new QPushButton(tr("7"));
    setButtonProperties(n7Button);
    n8Button = new QPushButton(tr("8"));
    setButtonProperties(n8Button);
    n9Button = new QPushButton(tr("9"));
    setButtonProperties(n9Button);
    n0Button = new QPushButton(tr("0"));
    setButtonProperties(n0Button);
    minusButton = new QPushButton(tr("-"));
    setButtonProperties(minusButton);
    plusButton = new QPushButton(tr("+"));
    setButtonProperties(plusButton);
    equalsButton = new QPushButton(tr("="));
    setButtonProperties(equalsButton);

    tildaButton = new QPushButton(tr("~"));
    setButtonProperties(tildaButton);
    atButton = new QPushButton(tr("@"));
    setButtonProperties(atButton);
    hashButton = new QPushButton(tr("#"));
    setButtonProperties(hashButton);
    dollarButton = new QPushButton(tr("$"));
    setButtonProperties(dollarButton);
    percentButton = new QPushButton(tr("%"));
    setButtonProperties(percentButton);
    caratButton = new QPushButton(tr("^"));
    setButtonProperties(caratButton);
    ampersandButton = new QPushButton(tr("&"));
    setButtonProperties(ampersandButton);
    leftParenthasesButton = new QPushButton(tr("("));
    setButtonProperties(leftParenthasesButton);
    rightParenthasesButton = new QPushButton(tr(")"));
    setButtonProperties(rightParenthasesButton);
    underscoreButton = new QPushButton(tr("_"));
    setButtonProperties(underscoreButton);

    leftCurlyBracketButton = new QPushButton(tr("{"));
    setButtonProperties(leftCurlyBracketButton);
    rightCurlyBracketButton = new QPushButton(tr("}"));
    setButtonProperties(rightCurlyBracketButton);
    leftBracketButton = new QPushButton(tr("["));
    setButtonProperties(leftBracketButton);
    rightBracketButton = new QPushButton(tr("]"));
    setButtonProperties(rightBracketButton);
    straightLineButton = new QPushButton(tr("|"));
    setButtonProperties(straightLineButton);
    backSlashButton = new QPushButton(tr("\\"));
    setButtonProperties(backSlashButton);
    colonButton = new QPushButton(tr(":"));
    setButtonProperties(colonButton);
    semicolonButton = new QPushButton(tr(";"));
    setButtonProperties(semicolonButton);
    quoteButton = new QPushButton(tr("\""));
    setButtonProperties(quoteButton);

    leftArrowButton = new QPushButton(tr("<"));
    setButtonProperties(leftArrowButton);
    rightArrowButton = new QPushButton(tr(">"));
    setButtonProperties(rightArrowButton);
    forwardSlashButton = new QPushButton(tr("/"));
    setButtonProperties(forwardSlashButton);

    periodButton = new QPushButton(tr("."));
    setButtonProperties(periodButton);
    commaButton = new QPushButton(tr(","));
    setButtonProperties(commaButton);
    questionButton = new QPushButton(tr("?"));
    setButtonProperties(questionButton);
    exclamationButton = new QPushButton(tr("!"));
    setButtonProperties(exclamationButton);
    apostropheButton = new QPushButton(tr("\'"));
    setButtonProperties(apostropheButton);
    spaceButton = new QPushButton(tr("Space"));
    setButtonProperties(spaceButton);
    enterButton = new QPushButton(tr("Enter"));
    setButtonProperties(enterButton);
    backSpaceButton = new QPushButton(tr("Backspace"));
    backSpaceButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(backSpaceButton);
    clearButton = new QPushButton(tr("Clear"));
    clearButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(clearButton);
    okButton = new QPushButton(tr("OK"));
    okButton->setStyleSheet(tr("QPushButton{background-color:#E0E0E0;}"));
    setButtonProperties(okButton);

    hLayout->addItem(horizSpacer);
    layout->addLayout(hLayout);
    this->setLayout(layout);

    buttonGroup = new QButtonGroup();
    addToGroup(n1Button);
    addToGroup(n2Button);
    addToGroup(n3Button);
    addToGroup(n4Button);
    addToGroup(n5Button);
    addToGroup(n6Button);
    addToGroup(n7Button);
    addToGroup(n8Button);
    addToGroup(n9Button);
    addToGroup(n0Button);
    addToGroup(minusButton);
    addToGroup(plusButton);

    addToGroup(tildaButton);
    addToGroup(atButton);
    addToGroup(hashButton);
    addToGroup(dollarButton);
    addToGroup(percentButton);
    addToGroup(caratButton);
    addToGroup(ampersandButton);
    addToGroup(leftParenthasesButton);
    addToGroup(rightParenthasesButton);
    addToGroup(underscoreButton);
    addToGroup(equalsButton);

    addToGroup(leftCurlyBracketButton);
    addToGroup(rightCurlyBracketButton);
    addToGroup(leftBracketButton);
    addToGroup(rightBracketButton);
    addToGroup(straightLineButton);
    addToGroup(backSlashButton);
    addToGroup(colonButton);
    addToGroup(semicolonButton);
    addToGroup(quoteButton);

    addToGroup(leftArrowButton);
    addToGroup(rightArrowButton);
    addToGroup(forwardSlashButton);

    addToGroup(periodButton);
    addToGroup(commaButton);
    addToGroup(questionButton);
    addToGroup(exclamationButton);
    addToGroup(apostropheButton);
    addToGroup(spaceButton);
    addToGroup(enterButton);
}
