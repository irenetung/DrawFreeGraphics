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
#include <cmath>

class Canvas : public QGraphicsView
{
public:
    enum DrawState {NONE,CURSOR,SHAPE,STAMP,DRAW,ERASER,PICTURE};
    enum CursorState {NOCURSOR,PREVCURSOR,SCALE,ROTATE,SHEAR,TRANSLATE};
    enum ShapeState {NOSHAPE,PREVSHAPE,LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH,TEXTTYPE};

    Canvas();
    QGraphicsScene *scene;
    int mousePressCount;
    QPen *pen;
    QBrush *brush;
    QColor color;
    QList<QPointF> points;

    DrawState drawState;
    CursorState cursorState;
    ShapeState shapeState;
    //Cursor
    bool rotateSignPositive;
    float rotateAngle;
    //Shapes
    QGraphicsItem *prevShape;

    void drawItem(QGraphicsItem *item);

    //Stamps
    QString currentStampPath;
    void setCurrentStamp(QString path);
    void drawPixmapItem(QGraphicsPixmapItem *item);

protected:
    void mousePressEvent(QMouseEvent *e);
private:

};

#endif // CANVAS_H
