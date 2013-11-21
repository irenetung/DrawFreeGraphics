#ifndef CURSORWIDGET_H
#define CURSORWIDGET_H

#include "basewidget.h"

class CursorWidget : public BaseWidget
{
public:
    explicit CursorWidget();
};

class CursorWidgetCursors : public CursorWidget
{
public:
    explicit CursorWidgetCursors();
    QPushButton *translateButton;
    QPushButton *scaleButton;
    QPushButton *stretchButton;
    QPushButton *rotateButton;
    QPushButton *depthButton;
    QPushButton *shearButton;
    QPushButton *copyButton;
    QPushButton *deleteButton;
};

class CursorWidgetTranslate : public CursorWidget
{
public:
    explicit CursorWidgetTranslate();
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *directionButton;
    QPushButton *t1Button;
    QPushButton *t5Button;
    QPushButton *t10Button;
    QPushButton *t20Button;
    QPushButton *t50Button;
    QPushButton *t100Button;
    void toggleSign(bool signPositive);
    void toggleDirection(bool directionHorizontal);
};

class CursorWidgetScale : public CursorWidget
{
public:
    explicit CursorWidgetScale();
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *resetButton;
    QPushButton *s05Button;
    QPushButton *s1Button;
    QPushButton *s5Button;
    QPushButton *s10Button;
    QPushButton *s20Button;
    QPushButton *s50Button;
    QPushButton *s100Button;
    void toggleSign(bool signPositive);
};

class CursorWidgetStretch : public CursorWidget
{
public:
    explicit CursorWidgetStretch();
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *directionButton;
    QPushButton *st0005Button;
    QPushButton *st001Button;
    QPushButton *st005Button;
    QPushButton *st01Button;
    QPushButton *st02Button;
    QPushButton *st05Button;
    QPushButton *st1Button;
    void toggleSign(bool signPositive);
    void toggleDirection(bool directionHorizontal);
};

class CursorWidgetRotate : public CursorWidget
{
public:
    explicit CursorWidgetRotate();
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *resetButton;
    QPushButton *r01Button;
    QPushButton *r05Button;
    QPushButton *r1Button;
    QPushButton *r5Button;
    QPushButton *r10Button;
    QPushButton *r20Button;
    QPushButton *r30Button;
    QPushButton *r45Button;
    QPushButton *r60Button;
    QPushButton *r72Button;
    QPushButton *r90Button;
    QPushButton *r120Button;
    QPushButton *r150Button;
    QPushButton *r180Button;
    QPushButton *r270Button;
    void toggleSign(bool signPositive);
};

class CursorWidgetShear : public CursorWidget
{
public:
    explicit CursorWidgetShear();
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *directionButton;
    QPushButton *sh001Button;
    QPushButton *sh005Button;
    QPushButton *sh01Button;
    QPushButton *sh02Button;
    QPushButton *sh05Button;
    QPushButton *sh1Button;
    void toggleSign(bool signPositive);
    void toggleDirection(bool directionHorizontal);
};

class CursorWidgetDepth : public CursorWidget
{
public:
    explicit CursorWidgetDepth();
    QPushButton *backButton;
    QPushButton *dn1Button;
    QPushButton *dp1Button;
};

class CursorWidgetBack : public CursorWidget
{
public:
    explicit CursorWidgetBack();
    QPushButton *backButton;
};

#endif // CURSORWIDGET_H
