#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QList>



class RectangleItem : public QGraphicsItem
{
public:
    RectangleItem(QList<QPointF> & vertices);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

protected:
    void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QList<QPointF> vertices;
};



#endif // ITEM_H
