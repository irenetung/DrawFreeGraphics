#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QVector>
#include <QButtonGroup>
#include <QLabel>
#include "flowlayout.h"

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = 0);
    void changeButtonProperties(int newButtonWidth, int newButtonHeight);
    QButtonGroup *buttonGroup;
signals:

public slots:
protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

    int buttonWidth;
    int buttonHeight;
    int id;
    QVector<QPushButton*> buttons;
    FlowLayout *hLayout;
    QSpacerItem *horizSpacer;
    void setButtonProperties(QPushButton *b);
    void addToButtonGroup(QPushButton *b);
    void addToGroup(QPushButton *b);
    QPixmap *parea;
};

#endif // BASEWIDGET_H
