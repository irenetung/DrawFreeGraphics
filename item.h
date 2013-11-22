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

class PointItem : public QGraphicsItem
{
public:
   //PointItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    PointItem(QPointF &point,QPen &curPen);

    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

protected:
    //QList<QPointF> vertices;
    QPointF vertex;
    QPen *pen;
    //QBrush *brush;
};

class RoundRectangleItem : public QGraphicsItem
{
public:
    RoundRectangleItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

protected:
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

protected:
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

protected:
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

protected:
    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float startAngle;
    float spanAngle;
};

class PathItem : public QGraphicsItem
{
public:
    PathItem(QPolygonF &curPolygon,QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

protected:
    QPolygonF *polygon;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};

// DRAW ITEM
class DrawItem : public QGraphicsItem
{
public:
    explicit DrawItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must

    void addWaterColorEffect(int size, float perc);

protected:
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

protected:
    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};


#endif // ITEM_H
