#include "item.h"
#include <QDebug>

//POINT
PointItem::PointItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
}

QRectF PointItem::boundingRect() const
{
    return QRectF(vertices[0].x()-2.5,vertices[0].y()-2.5,5,5);
}

void PointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawEllipse(rect);
}

//ROUNDRECT
RoundRectangleItem::RoundRectangleItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
}

QRectF RoundRectangleItem::boundingRect() const
{
    return QRectF(vertices[0].x(),vertices[0].y(), vertices[1].x()-vertices[0].x(), vertices[1].y()-vertices[0].y());
}

void RoundRectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawRoundRect(rect);

}

ArcItem::ArcItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
    startAngle = 30;
    spanAngle = 120;
}

QRectF ArcItem::boundingRect() const
{
    return QRectF(vertices[0].x(),vertices[0].y(), vertices[1].x()-vertices[0].x(), vertices[1].y()-vertices[0].y());
}

void ArcItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawArc(rect,startAngle*16,spanAngle*16);

}

ChordItem::ChordItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
    startAngle = 30;
    spanAngle = 120;
}

QRectF ChordItem::boundingRect() const
{
    return QRectF(vertices[0].x(),vertices[0].y(), vertices[1].x()-vertices[0].x(), vertices[1].y()-vertices[0].y());
}

void ChordItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawChord(rect,startAngle*16,spanAngle*16);
}

PieItem::PieItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
    startAngle = 30;
    spanAngle = 120;
}

QRectF PieItem::boundingRect() const
{
    return QRectF(vertices[0].x(),vertices[0].y(), vertices[1].x()-vertices[0].x(), vertices[1].y()-vertices[0].y());
}

void PieItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawPie(rect,startAngle*16,spanAngle*16);
}

PathItem::PathItem(QPolygonF &curPolygon,QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    polygon = new QPolygonF(curPolygon);

    left = points[0].x();
    right = points[0].x();
    top = points[0].y();
    bottom = points[0].y();

    for(int i = 0; i < points.size(); i++) {
        if(points[i].x() < left) {
            left = points[i].x();
        }
        if(points[i].x() > right) {
            right = points[i].x();
        }
        if(points[i].y() < top) {
            top = points[i].y();
        }
        if(points[i].y() > bottom) {
            bottom = points[i].y();
        }
    }
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
}

QRectF PathItem::boundingRect() const
{
    return QRectF(left,top,right-left,bottom-top);
}

void PathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawPolyline(*polygon);
}
