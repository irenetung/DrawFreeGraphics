#include "prompt.h"

Prompt::Prompt(QWidget *parent) :
    QWidget(parent)
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(229,204,255));

    promptLabel = new QLabel();
    promptLabel->setText("Welcome to DrawFree!");

    promptLayout = new QHBoxLayout;
    promptLayout -> addWidget(promptLabel, Qt::AlignLeft);

    this->setLayout(promptLayout);

}

void Prompt::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void Prompt::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}
