#include "basewidget.h"
#include <QDebug>

BaseWidget::BaseWidget(QWidget *parent) :
    QWidget(parent)
{
    buttonWidth = 60;
    buttonHeight = 60;
    id = 0;
    hLayout = new FlowLayout;
    horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
}

void BaseWidget::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void BaseWidget::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}

void BaseWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(buttonWidth);
    b->setFixedHeight(buttonHeight);
    b->setIconSize(QSize(buttonWidth-6,buttonHeight-6));

    buttons.push_back(b);
    hLayout->addWidget(b);
}

void BaseWidget::addToButtonGroup(QPushButton *b)
{
    b->setCheckable(true);
    buttonGroup->addButton(b);
    buttonGroup->setId(b,id);
    ++id;
}

void BaseWidget::changeButtonProperties(int newButtonWidth, int newButtonHeight)
{
    for(int i = 0; i < buttons.size();++i) {
        buttons[i]->setFixedWidth(newButtonWidth);
        buttons[i]->setFixedHeight(newButtonHeight);
        buttons[i]->setIconSize(QSize(newButtonWidth-6,newButtonHeight-6));
    }
    repaint();
    update();
}
