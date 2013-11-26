#ifndef SHAPESWIDGET_H
#define SHAPESWIDGET_H

#include "basewidget.h"

class ShapesWidget : public BaseWidget
{
public:
    explicit ShapesWidget();
};

//Select a shape
class ShapesWidgetShapes : public ShapesWidget
{
public:
    explicit ShapesWidgetShapes();

    QPixmap *lineButtonIcon;
    QPixmap *pointButtonIcon;
    QPixmap *circleButtonIcon;
    QPixmap *rectangleButtonIcon;
    QPixmap *roundedRectangleButtonIcon;
    QPixmap *polygonButtonIcon;
    QPixmap *arcButtonIcon;
    QPixmap *chordButtonIcon;
    QPixmap *pieButtonIcon;
    QPixmap *pathButtonIcon;
    QPixmap *textButtonIcon;

    QPushButton *outlineSizeButton;
    QPushButton *outlineColorButton;
    QPushButton *fillColorButton;
    QPushButton *lineButton;
    QPushButton *pointButton;
    QPushButton *circleButton;
    QPushButton *rectangleButton;
    QPushButton *roundedRectangleButton;
    QPushButton *polygonButton;
    QPushButton *arcButton;
    QPushButton *chordButton;
    QPushButton *pieButton;
    QPushButton *pathButton;
    QPushButton *textButton;
};

//End path
class ShapesWidgetEndPath : public ShapesWidget
{
public:
    explicit ShapesWidgetEndPath();
    QPushButton *backButton;
    QPushButton *endPathButton;
};

class ShapesWidgetOutlineSizes : public ShapesWidget
{
public:
    explicit ShapesWidgetOutlineSizes();
    QString currentSize;
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *si1Button;
    QPushButton *si5Button;
    QPushButton *si10Button;
    QPushButton *si20Button;
    QPushButton *si50Button;
    QPushButton *si100Button;
};

class ShapesWidgetKeyboardLetters : public ShapesWidget
{
public:
    explicit ShapesWidgetKeyboardLetters();
    QPushButton *qButton;
    QPushButton *wButton;
    QPushButton *eButton;
    QPushButton *rButton;
    QPushButton *tButton;
    QPushButton *yButton;
    QPushButton *uButton;
    QPushButton *iButton;
    QPushButton *oButton;
    QPushButton *pButton;

    QPushButton *aButton;
    QPushButton *sButton;
    QPushButton *dButton;
    QPushButton *fButton;
    QPushButton *gButton;
    QPushButton *hButton;
    QPushButton *jButton;
    QPushButton *kButton;
    QPushButton *lButton;

    QPushButton *shiftButton;
    QPushButton *zButton;
    QPushButton *xButton;
    QPushButton *cButton;
    QPushButton *vButton;
    QPushButton *bButton;
    QPushButton *nButton;
    QPushButton *mButton;
    QPushButton *backSpaceButton;

    QPushButton *numbersButton;
    QPushButton *spaceButton;
    QPushButton *enterButton;
};

class ShapesWidgetKeyboardNumbers : public ShapesWidget
{
public:
    explicit ShapesWidgetKeyboardNumbers();
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
    QPushButton *forwardSlashButton;
    QPushButton *colonButton;
    QPushButton *semicolonButton;
    QPushButton *leftParenthasesButton;
    QPushButton *rightParenthasesButton;
    QPushButton *dollarButton;
    QPushButton *ampersandButton;
    QPushButton *atButton;
    QPushButton *quoteButton;

    QPushButton *symbolsButton;
    QPushButton *periodButton;
    QPushButton *commaButton;
    QPushButton *questionButton;
    QPushButton *exclamationButton;
    QPushButton *apostropheButton;
    QPushButton *backSpaceButton;

    QPushButton *lettersButton;
    QPushButton *spaceButton;
    QPushButton *enterButton;
};

class ShapesWidgetKeyboardSymbols : public ShapesWidget
{
public:
    explicit ShapesWidgetKeyboardSymbols();
    QPushButton *leftBracketButton;
    QPushButton *rightBracketButton;
    QPushButton *leftCurlyBracketButton;
    QPushButton *rightCurlyBracketButton;
    QPushButton *hashButton;
    QPushButton *percentButton;
    QPushButton *caratButton;
    QPushButton *starButton;
    QPushButton *plusButton;
    QPushButton *equalsButton;

    QPushButton *underscoreButton;
    QPushButton *backSlashButton;
    QPushButton *colonButton;
    QPushButton *straightLineButton;
    QPushButton *tildaButton;
    QPushButton *rightParenthasesButton;
    QPushButton *leftArrowButton;
    QPushButton *rightArrowButton;

    QPushButton *numbersButton;
    QPushButton *periodButton;
    QPushButton *commaButton;
    QPushButton *questionButton;
    QPushButton *exclamationButton;
    QPushButton *apostropheButton;
    QPushButton *backSpaceButton;

    QPushButton *lettersButton;
    QPushButton *spaceButton;
    QPushButton *enterButton;
};



#endif // SHAPESWIDGET_H
