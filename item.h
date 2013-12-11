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
             PathItemType = QGraphicsItem::UserType+6,
             PaintItemType = QGraphicsItem::UserType+7,
             WaterColorItemType = QGraphicsItem::UserType+8,
             CalligraphyItemType = QGraphicsItem::UserType+9,
             SprayPaintItemType = QGraphicsItem::UserType+10,
             PencilItemType = QGraphicsItem::UserType+11,
             DustItemType = QGraphicsItem::UserType+12,
             };

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
    int type() const {return DustItemType;}

    void addWaterColorEffect(int size, float perc);
    //void calligraphy(int skew);
    //void spray();

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
    int type() const {return PaintItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};

class CalligraphyItem : public QGraphicsItem
{
public:
    explicit CalligraphyItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return CalligraphyItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};

class SprayPaintItem : public QGraphicsItem
{
public:
    explicit SprayPaintItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return SprayPaintItemType;}

    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;
};

class WatercolorItem : public QGraphicsItem
{
public:
    explicit WatercolorItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return WaterColorItemType;}



    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;

};

class PencilItem : public QGraphicsItem
{
public:
    explicit PencilItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush);
    QRectF boundingRect() const; //must
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //must
    int type() const {return PencilItemType;}



    QList<QPointF> vertices;
    QPen *pen;
    QBrush *brush;
    float left;
    float right;
    float top;
    float bottom;

};

#endif // ITEM_H
