#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) :
    QWidget(parent)
  {
      int h = this->size().height();
      int w = this->size().width();
      parea = new QPixmap(w,h);
      parea->fill(QColor(255,204,229));

      dim = 60;
  }

  void DrawWidget::resizeEvent(QResizeEvent *e)
  {
      int h = e->size().height();
      int w = e->size().width();
      QPixmap temp = this->parea->copy();
      parea = new QPixmap(w,h);
      *parea = temp.scaled(w,h);
  }

  void DrawWidget::paintEvent(QPaintEvent *e)
  {
      if(parea != NULL) {
          QPainter painter(this);
          painter.drawPixmap(0,0,*parea);
      }
  }

  void DrawWidget::setButtonProperties(QPushButton *b)
  {
      b->setFixedWidth(dim);
      b->setFixedHeight(dim);
      hLayout->addWidget(b);
  }
