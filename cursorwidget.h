#ifndef CURSORWIDGET_H
#define CURSORWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSignalMapper>

class CursorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CursorWidget(QWidget *parent = 0);
    QPushButton *translateButton;
    QPushButton *scaleButton;
    QPushButton *stretchButton;
    QPushButton *rotateButton;
    QPushButton *shearButton;
    QPushButton *signButton;
    void toggleSign(bool signPositive);
signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

    int dim;
    QHBoxLayout *hLayout;
    void setButtonProperties(QPushButton *b);

private:
    QPixmap *parea;
};

class CursorWidgetTranslate : public CursorWidget
{
public:
    explicit CursorWidgetTranslate();
    QPushButton *directionButton;
    QPushButton *t05Button;
    QPushButton *t1Button;
    QPushButton *t5Button;
    QPushButton *t10Button;
    QPushButton *t20Button;
    QPushButton *t50Button;
    QPushButton *t100Button;
    void toggleDirection(bool directionHorizontal);
};

class CursorWidgetScale : public CursorWidget
{
public:
    explicit CursorWidgetScale();
    QPushButton *sResetButton;
    QPushButton *s05Button;
    QPushButton *s1Button;
    QPushButton *s5Button;
    QPushButton *s10Button;
    QPushButton *s20Button;
    QPushButton *s50Button;
    QPushButton *s100Button;
};

class CursorWidgetStretch : public CursorWidget
{
public:
    explicit CursorWidgetStretch();
    QPushButton *directionButton;
    QPushButton *st05Button;
    QPushButton *st1Button;

    void toggleDirection(bool directionHorizontal);
};

class CursorWidgetRotate : public CursorWidget
{
public:
    explicit CursorWidgetRotate();
    QPushButton *reset0Button;
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
};

class CursorWidgetShear : public CursorWidget
{
public:
    explicit CursorWidgetShear();
    QPushButton *directionButton;
    QPushButton *sh1Button;

    void toggleDirection(bool directionHorizontal);
};

#endif // CURSORWIDGET_H
