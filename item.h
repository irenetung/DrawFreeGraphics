#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QList>
#include <cmath>

#include "math.h"

enum ItemType{PointItemType = QGraphicsItem::UserType+1,
             RoundRectangleItemType = QGraphicsItem::UserType+2,
             ArcItemType = QGraphicsItem::UserType+3,
             ChordItemType = QGraphicsItem::UserType+4,
             PieItemType = QGraphicsItem::UserType+5,
             PathItemType = QGraphicsItem::UserType+6};

class PointItem : public QGraphicsItem
{
public:
    PointItem(QPointF &point,QPen &curPen);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return PointItemType;}

    QPointF vertex;
    QPen *pen;
};

class RoundRectangleItem : public QGraphicsItem
{
public:
    RoundRectangleItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return RoundRectangleItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
};

class ArcItem : public QGraphicsItem
{
public:
    ArcItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return ArcItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float startAngle;
    float spanAngle;
};

class ChordItem : public QGraphicsItem
{
public:
    ChordItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return ChordItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float startAngle;
    float spanAngle;
};

class PieItem : public QGraphicsItem
{
public:
    PieItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return PieItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float startAngle;
    float spanAngle;
};

class PathItem : public QGraphicsItem
{
public:
    //PathItem(QPolygonF &curPolygon,QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    PathItem(QPolygonF &curPolygon,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return PathItemType;}

    QPolygonF *polygon;
    QPen *pen;
    QBrush *brush;
    /*float left;
    float right;
    float top;
    float bottom;*/
};

// DRAW ITEM
class DrawItem : public QGraphicsItem
{
public:
    explicit DrawItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

    void addWaterColorEffect(int size, float perc);

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};

class PaintItem : public QGraphicsItem
{
public:
    explicit PaintItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

    void addWaterColorEffect(int size, float perc);

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};


#endif // ITEM_H
