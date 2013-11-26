#include "item.h"
#include <QDebug>

//POINT
PointItem::PointItem(QPointF &point, QPen &curPen)
{
    vertex = point;
    pen = new QPen(curPen);
}

QRectF PointItem::boundingRect() const
{
    return QRectF(vertex.x()-5,vertex.y()-5,10,10);
}

void PointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // QRectF rect = boundingRect();

   // painter->setBrush(*brush);
    painter->setPen(*pen);
    //painter->drawPoint(vertices[0]);
    painter->drawPoint(vertex);
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

PathItem::PathItem(QPolygonF &curPolygon,QPen &curPen,QBrush &curBrush)
{
    polygon = new QPolygonF(curPolygon);

    /*left = points[0].x();
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
    }*/
    pen = new QPen(curPen);
    brush = new QBrush(curBrush);
}

QRectF PathItem::boundingRect() const
{
    return polygon->boundingRect();
}

void PathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawPolyline(*polygon);
}

DrawItem::DrawItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    left = points[0].x();
    right = points[0].x();
    top = points[0].y();
    bottom = points[0].y();

    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
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

QRectF DrawItem::boundingRect() const
{
    return QRectF(left,top,right-left,bottom-top);
}

void DrawItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    int size = vertices.size();

    for(int i = 1; i < size; i++) {
        painter->drawPoint(vertices[i]);
    }

}

PaintItem::PaintItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
{
    left = points[0].x();
    right = points[0].x();
    top = points[0].y();
    bottom = points[0].y();

    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
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
    pen->setStyle(Qt::SolidLine);
    pen->setCapStyle(Qt::RoundCap);
    pen->setJoinStyle(Qt::RoundJoin);
    brush = new QBrush(curBrush);
}

QRectF PaintItem::boundingRect() const
{
    return QRectF(left,top,right-left,bottom-top);
}

void PaintItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    int size = vertices.size();
    if(size >1) {
        for(int i = 1; i < size; i++) {
            painter->drawLine(vertices[i-1],vertices[i]);
        }
    }
}

// WATER COLOR METHOD
/*void DrawItem::addWaterColorEffect(int size, float perc)
{
    // init
    QList<QPointF> pointList;
    int numRowsCols = floor((float)(perc * size));
    int divide = floor((float)(size / 2));
    int numCenters = vertices.size();

    for (int i = 0; i < numCenters; i++)
    {
        // generate random rows/columns to be included
        int rows[numRowsCols];
        int cols[numRowsCols];
        for (int r = 0; r < numRowsCols; r++)
        {
            rows[r] = rand() % size;
            cols[r] = rand() % size;
        }

        // deque center point
        QPointF center = vertices.at(i);
        // add surrounding points
        for (int r = 0; r < numRowsCols; r++)
        {
            // add row
            int curRow = rows[r];
            int pixelRow = 0;
            if (curRow > divide)
            {
                pixelRow = center.y() + (curRow - divide);
            }
            else
            {
                pixelRow = center.y() - (divide - curRow);
            }
            for (int c = 0; c < size; c++)
            {
                QPointF newPoint;
                if (c < divide)
                {
                    newPoint.setX(center.x() - (divide - c));
                    newPoint.setY(pixelRow);
                    vertices.append(newPoint);
                }
                else
                {
                    newPoint.setX(center.x() + (c - divide));
                    newPoint.setY(pixelRow);
                    vertices.append(newPoint);
                }
            }

            // add col
            int curCol = cols[r];
            int pixelCol = 0;
            if (pixelCol > divide)
            {
                pixelCol = center.x() + (curCol - divide);
            }
            else
            {
                pixelCol = center.x() - (divide - curCol);
            }
            for (int c = 0; c < size; c++)
            {
                QPointF newPoint;
                if (c < divide)
                {
                    newPoint.setX(pixelCol);
                    newPoint.setY(center.y() - (divide - c));
                    vertices.append(newPoint);
                }
                else
                {
                    newPoint.setX(pixelCol);
                    newPoint.setY(center.y() + (c - divide));
                    vertices.append(newPoint);
                }
            }
        }


    }

}*/


