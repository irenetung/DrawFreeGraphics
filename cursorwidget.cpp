#include "cursorwidget.h"
#include <QDebug>

CursorWidget::CursorWidget(QWidget *parent) :
    QWidget(parent)
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(255,204,229));

    dim = 60;

    translateButton = new QPushButton("go to\ntranslate");
    scaleButton = new QPushButton("go to\nscale");
    stretchButton = new QPushButton("go to\nstretch");
    rotateButton = new QPushButton("go to\nrotate");
    shearButton = new QPushButton("go to\nshear");
    signButton = new QPushButton("+");

}

void CursorWidget::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void CursorWidget::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}

void CursorWidget::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("+");
    } else {
        signButton->setText("-");
    }
}

void CursorWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(dim);
    b->setFixedHeight(dim);
    hLayout->addWidget(b);
}

//-------------------------------------------------------
CursorWidgetTranslate::CursorWidgetTranslate()
{
    hLayout = new QHBoxLayout;

    setButtonProperties(scaleButton);
    setButtonProperties(rotateButton);
    setButtonProperties(shearButton);
    setButtonProperties(stretchButton);
    setButtonProperties(signButton);

    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);
    t05Button = new QPushButton(".5");
    setButtonProperties(t05Button);
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

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
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
    hLayout = new QHBoxLayout;

    setButtonProperties(translateButton);
    setButtonProperties(rotateButton);
    setButtonProperties(shearButton);
    setButtonProperties(stretchButton);
    setButtonProperties(signButton);

    sResetButton = new QPushButton("reset to\noriginal");
    setButtonProperties(sResetButton);
    s05Button = new QPushButton(".005");
    setButtonProperties(s05Button);
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

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}

//-------------------------------------------------------
CursorWidgetStretch::CursorWidgetStretch()
{
    hLayout = new QHBoxLayout;

    setButtonProperties(translateButton);
    setButtonProperties(scaleButton);
    setButtonProperties(rotateButton);
    setButtonProperties(shearButton);
    setButtonProperties(signButton);

    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);
    st05Button = new QPushButton(".5");
    setButtonProperties(st05Button);
    st1Button = new QPushButton("1");
    setButtonProperties(st1Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}
void CursorWidgetStretch::toggleDirection(bool directionHorizontal)
{
    if(directionHorizontal == true) {
        directionButton->setText("horizontal");
    } else {
        directionButton->setText("vertical");
    }
}
//-----------------------------------------------------
CursorWidgetShear::CursorWidgetShear()
{
    hLayout = new QHBoxLayout;

    setButtonProperties(translateButton);
    setButtonProperties(scaleButton);
    setButtonProperties(stretchButton);
    setButtonProperties(rotateButton);
    setButtonProperties(signButton);

    directionButton = new QPushButton("horizontal");
    setButtonProperties(directionButton);
    sh1Button = new QPushButton("1");
    setButtonProperties(sh1Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}

void CursorWidgetShear::toggleDirection(bool directionHorizontal)
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
    hLayout = new QHBoxLayout;
    setButtonProperties(translateButton);
    setButtonProperties(scaleButton);
    setButtonProperties(stretchButton);
    setButtonProperties(shearButton);
    setButtonProperties(signButton);

    reset0Button = new QPushButton("reset\nto 0");
    setButtonProperties(reset0Button);
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
    r270Button = new QPushButton("270");
    setButtonProperties(r270Button);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}
