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
    painter->drawRoundRect(rect,20,20);
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

WatercolorItem::WatercolorItem(QList<QPointF> &points,QPen &curPen,QBrush &curBrush)
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
    pen->setStyle(Qt::DashLine);
    pen->setCapStyle(Qt::RoundCap);
    pen->setJoinStyle(Qt::RoundJoin);
    //pen->setWidth(10);
    brush = new QBrush(curBrush);
    brush->setStyle(Qt::CrossPattern);
}

QRectF WatercolorItem::boundingRect() const
{
    return QRectF(left,top,right-left,bottom-top);
}

void WatercolorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << pen->width();
    int size = pen->width();
    float perc = 0.3;

    painter->setBrush(*brush);
    painter->setPen(*pen);

    // init
    QPen *newPen = new QPen(*pen);
    newPen->setStyle(Qt::DashLine);
    newPen->setCapStyle(Qt::RoundCap);
    newPen->setJoinStyle(Qt::RoundJoin);
    newPen->setWidth(1);
    painter->setPen(*newPen);
    int numRowsCols = floor((float)(perc * size));
    int divide = floor((float)(size / 2));
    int numCenters = vertices.size();

    for (int i = 0; i < numCenters; i++)
    {
        // generate random rows/columns to be included
        int *rows = new int[numRowsCols];
        int *cols = new int[numRowsCols];
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
            QPointF startPoint;
            startPoint.setX(center.x() - divide);
            startPoint.setY(pixelRow);
            QPointF endPoint;
            endPoint.setX(center.x() + size - divide);
            endPoint.setY(pixelRow);
            painter->drawLine(startPoint ,endPoint);

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
            startPoint.setX(pixelCol);
            startPoint.setY(center.y() - divide);
            endPoint.setX(pixelCol);
            endPoint.setY(center.y() - divide + size);
            painter->drawLine(startPoint ,endPoint);

        }


    }






    int final_size = vertices.size();

    for(int i = 1; i < final_size; i++) {
        painter->drawPoint(vertices[i]);
    }
}

CalligraphyItem::CalligraphyItem(QList<QPointF> &points, QPen &curPen, QBrush &curBrush)
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

QRectF CalligraphyItem::boundingRect() const
{
    return QRectF(left,top,right-left,bottom-top);
}

void CalligraphyItem::paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int skew = 5;
    p->setBrush(*brush);
    p->setPen(*pen);
    int size = vertices.size();

    for(int i = 1; i < size; i++) {
        QPointF xy1=vertices.at(i-1);
        QPointF xy2=vertices.at(i);
        //p->drawLine(xy1.x()-skew,xy1.y()-skew,xy1.x()+skew,xy1.y()+skew);
        p->drawLine(xy1.x()-skew,xy1.y()-skew,xy1.x()+skew,xy1.y()+skew);// by narrowing the skew it becomes less caligraphy more pen
        int counter;
        counter=10;
        int begin1;
        begin1=xy1.x()-5;
        int end1;
        end1=xy2.x()-5;
        int begin2;
        begin2=xy1.y()-5;
        int end2;
        end2=xy2.y()-5;
        while(counter>=0)
        {
            p->drawLine(begin1,begin2,end1,end2);
            begin1++;
            end1++;
            begin2++;
            end2++;
            counter--;
        }
    }

}

SprayPaintItem::SprayPaintItem(QList<QPointF> &points, QPen &curPen, QBrush &curBrush)
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

QRectF SprayPaintItem::boundingRect() const
{
return QRectF(left,top,right-left,bottom-top);
}

void SprayPaintItem::paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
p->setBrush(*brush);
p->setPen(*pen);
int size = vertices.size();

for(int i = 1; i < size; i++) {
    QPointF xy1=vertices.at(i-1);
    int gx=xy1.x();
    int gy=xy1.y();
            int randVal;
            int counter;
             randVal=rand()+1;
             counter=0;
             while(counter!=100)
             {
                // int random=rand();
               if(randVal%2==0)
                 {
                   p->drawPoint(gx,gy);
                   p->drawPoint(gx-2,gy-9);
                   p->drawPoint(gx-5,gy-7);
                   p->drawPoint(gx-9,gy-2);
                   p->drawPoint(gx-7,gy-2);
                   p->drawPoint(gx-2,gy-5);
                   p->drawPoint(gx+2,gy+9);
                   p->drawPoint(gx+5,gy+7);
                   p->drawPoint(gx+9,gy+2);
                   p->drawPoint(gx+7,gy+2);
                   p->drawPoint(gx+2,gy+5);
                   p->drawPoint(gx-2,gy+9);
                   p->drawPoint(gx-5,gy+7);
                   p->drawPoint(gx-9,gy+2);
                   p->drawPoint(gx-7,gy+2);
                   p->drawPoint(gx-2,gy+5);
                   p->drawPoint(gx+2,gy-9);
                   p->drawPoint(gx+5,gy-7);
                   p->drawPoint(gx+9,gy-2);
                   p->drawPoint(gx+7,gy-2);
                   p->drawPoint(gx+2,gy-5);
                   p->drawPoint(gx+7,gy+7);
                   p->drawPoint(gx-7,gy-7);
                   p->drawPoint(gx+7,gy-7);
                   p->drawPoint(gx-7,gy+7);
                   p->drawPoint(gx+4,gy+4);
                   p->drawPoint(gx-4,gy-4);
                   p->drawPoint(gx+4,gy-4);
                   p->drawPoint(gx-4,gy+4);
                   p->drawPoint(gx+2,gy);
                   p->drawPoint(gx+5,gy);
                   p->drawPoint(gx+9,gy);
                   p->drawPoint(gx,gy+2);
                   p->drawPoint(gx,gy+5);
                   p->drawPoint(gx,gy+9);
                   p->drawPoint(gx-2,gy);
                   p->drawPoint(gx-5,gy);
                   p->drawPoint(gx-9,gy);
                   p->drawPoint(gx,gy-2);
                   p->drawPoint(gx,gy-5);
                   p->drawPoint(gx,gy-9);
                  }
                 else if(randVal%2==1)
                   {
                   p->drawPoint(gx,gy);
                   p->drawPoint(gx-1,gy-2);
                   p->drawPoint(gx-3,gy-8);
                   p->drawPoint(gx-6,gy-6);
                   p->drawPoint(gx-8,gy-3);
                   p->drawPoint(gx-2,gy-1);
                   p->drawPoint(gx+1,gy+2);
                   p->drawPoint(gx+3,gy+8);
                   p->drawPoint(gx+6,gy+6);
                   p->drawPoint(gx+8,gy+3);
                   p->drawPoint(gx+2,gy+1);
                   p->drawPoint(gx-1,gy+2);
                   p->drawPoint(gx-3,gy+8);
                   p->drawPoint(gx-6,gy+6);
                   p->drawPoint(gx-8,gy+3);
                   p->drawPoint(gx-2,gy+1);
                   p->drawPoint(gx+1,gy-2);
                   p->drawPoint(gx+3,gy-8);
                   p->drawPoint(gx+6,gy-6);
                   p->drawPoint(gx+8,gy-3);
                   p->drawPoint(gx+2,gy-1);
                   p->drawPoint(gx+7,gy+7);
                   p->drawPoint(gx-7,gy-7);
                   p->drawPoint(gx+7,gy-7);
                   p->drawPoint(gx-7,gy+7);
                   p->drawPoint(gx+4,gy+4);
                   p->drawPoint(gx-4,gy-4);
                   p->drawPoint(gx+4,gy-4);
                   p->drawPoint(gx-4,gy+4);
                   p->drawPoint(gx+2,gy);
                   p->drawPoint(gx+5,gy);
                   p->drawPoint(gx+9,gy);
                   p->drawPoint(gx,gy+2);
                   p->drawPoint(gx,gy+5);
                   p->drawPoint(gx,gy+9);
                   p->drawPoint(gx-2,gy);
                   p->drawPoint(gx-5,gy);
                   p->drawPoint(gx-9,gy);
                   p->drawPoint(gx,gy-2);
                   p->drawPoint(gx,gy-5);
                   p->drawPoint(gx,gy-9);
                   }
                 counter++;
             }
}
}


