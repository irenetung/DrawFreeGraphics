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

void CursorWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(dim);
    b->setFixedHeight(dim);
    hLayout->addWidget(b);
}
//-------------------------------------------------------
CursorWidgetRotate::CursorWidgetRotate()
{
    hLayout = new QHBoxLayout;

    signButton = new QPushButton("+");
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

void CursorWidgetRotate::toggleSign(bool signPositive)
{
    if(signPositive == true) {
        signButton->setText("-");
    } else {
        signButton->setText("+");
    }
}
