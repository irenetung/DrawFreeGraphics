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
    enum DrawState {NOSTATE,CURSOR,SHAPE,STAMP,DRAW,ERASER,PICTURE};
    enum CursorState {NOCURSOR,SCALE,STRETCH,ROTATE,SHEAR,TRANSLATE,DEPTH,COPY,DELETEITEM};
    enum ShapeState {NOSHAPE,LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH,TEXTTYPE};
    enum StampState {NOSTAMP, SILHOUETTE, STANDARD};

    Canvas();
    QGraphicsScene *scene;
    int mousePressCount;
    QPen *pen;
    QBrush *brush;
    QColor color;
    QList<QPointF> points;

    DrawState drawState;
    void resetDrawState();
    CursorState cursorState;
    ShapeState shapeState;
    StampState stampState;

    //Cursor
    bool translateSignPositive;
    bool translateDirectionHorizontal;
    double translateHorizontalValue;
    double translateVerticalValue;

    bool scaleSignPositive;
    double scaleFactor;

    bool stretchSignPositive;
    bool stretchDirectionHorizontal;
    double stretchHorizontalValue;
    double stretchVerticalValue;

    bool rotateSignPositive;
    double rotateAngle;

    bool shearSignPositive;
    bool shearDirectionHorizontal;
    double shearHorizontalValue;
    double shearVerticalValue;

    bool depthPositive;

    void resetTranslateStretchShear();

    //Shapes
    QGraphicsItem *prevShape;
    void drawItem(QGraphicsItem *item);
    void resetShapeState();
    //Stamps
    QString currentStampPath;
    void setCurrentStamp(QString path);
    void drawPixmapItem(QGraphicsPixmapItem *item);


protected:
    //void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    //void drawForeground(QPainter *painter, const QRectF &rect);
private:

};

#endif // CANVAS_H
