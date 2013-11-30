#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include "basewidget.h"
#include <QVBoxLayout>

class TextWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit TextWidget();
    QTextEdit *textEdit;
protected:
    QVBoxLayout *layout;
};

class TextWidgetLetters : public TextWidget
{
public:
    explicit TextWidgetLetters();

    QPushButton *specialKeysButton;
    QPushButton *shiftButton;
    QPushButton *changeFontButton;

    QPushButton *aButton;
    QPushButton *bButton;
    QPushButton *cButton;
    QPushButton *dButton;
    QPushButton *eButton;
    QPushButton *fButton;
    QPushButton *gButton;
    QPushButton *hButton;
    QPushButton *iButton;
    QPushButton *jButton;
    QPushButton *kButton;
    QPushButton *lButton;
    QPushButton *mButton;
    QPushButton *nButton;
    QPushButton *oButton;
    QPushButton *pButton;
    QPushButton *qButton;
    QPushButton *rButton;
    QPushButton *sButton;
    QPushButton *tButton;
    QPushButton *uButton;
    QPushButton *vButton;
    QPushButton *wButton;
    QPushButton *xButton;
    QPushButton *yButton;
    QPushButton *zButton;

    QPushButton *periodButton;
    QPushButton *commaButton;
    QPushButton *questionButton;
    QPushButton *exclamationButton;
    QPushButton *apostropheButton;
    QPushButton *spaceButton;
    QPushButton *enterButton;
    QPushButton *backSpaceButton;
    QPushButton *okButton;
    QPushButton *clearButton;
};

class TextWidgetSpecialKeys : public TextWidget
{
public:
    explicit TextWidgetSpecialKeys();
    QPushButton *lettersButton;
    QPushButton *changeFontButton;

    QPushButton *n1Button;
    QPushButton *n2Button;
    QPushButton *n3Button;
    QPushButton *n4Button;
    QPushButton *n5Button;
    QPushButton *n6Button;
    QPushButton *n7Button;
    QPushButton *n8Button;
    QPushButton *n9Button;
    QPushButton *n0Button;
    QPushButton *minusButton;
    QPushButton *plusButton;

    QPushButton *tildaButton;
    QPushButton *atButton;
    QPushButton *hashButton;
    QPushButton *dollarButton;
    QPushButton *percentButton;
    QPushButton *caratButton;
    QPushButton *ampersandButton;
    QPushButton *leftParenthasesButton;
    QPushButton *rightParenthasesButton;
    QPushButton *underscoreButton;
    QPushButton *equalsButton;

    QPushButton *leftCurlyBracketButton;
    QPushButton *rightCurlyBracketButton;
    QPushButton *leftBracketButton;
    QPushButton *rightBracketButton;
    QPushButton *straightLineButton;
    QPushButton *backSlashButton;
    QPushButton *colonButton;
    QPushButton *semicolonButton;
    QPushButton *quoteButton;

    QPushButton *leftArrowButton;
    QPushButton *rightArrowButton;
    QPushButton *forwardSlashButton;

    QPushButton *periodButton;
    QPushButton *commaButton;
    QPushButton *questionButton;
    QPushButton *exclamationButton;
    QPushButton *apostropheButton;
    QPushButton *spaceButton;
    QPushButton *enterButton;
    QPushButton *backSpaceButton;
    QPushButton *okButton;
    QPushButton *clearButton;
};

#endif // TEXTWIDGET_H
