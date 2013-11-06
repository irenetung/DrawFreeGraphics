#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include "item.h"

class Canvas : public QGraphicsView
{
public:
    enum DrawState {NONE,CURSOR,SHAPE,STAMP,DRAW,ERASER,PICTURE};
    enum ShapeState {NOSHAPE,PREVSHAPE,LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH,TEXTTYPE};

    Canvas();
    QPen *pen;
    QBrush *brush;
    DrawState drawState;
    ShapeState shapeState;
    QGraphicsItem *prevShape;
    QGraphicsItem *curShape;
    QList<QPointF> points;
    QGraphicsRectItem *rectangle;

    QGraphicsScene *scene;
    int mousePressCount;

protected:
    void mousePressEvent(QMouseEvent *e);
private:

};

#endif // CANVAS_H
