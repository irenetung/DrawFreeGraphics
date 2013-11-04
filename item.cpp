#include "item.h"
#include <QDebug>

RectangleItem::RectangleItem(QList<QPointF> &points)
{
    for(int i = 0; i < points.size(); i++) {
        vertices.append(points[i]);
        qDebug() <<"vertices "<< vertices[i].x() << vertices[i].y() << "\n";
    }
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
}

QRectF RectangleItem::boundingRect() const
{
    return QRectF(vertices[0].x(),vertices[0].y(), vertices[1].x()-vertices[0].x(), vertices[1].y()-vertices[0].y());
}

void RectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);

    painter->fillRect(rect,brush);
    painter->drawRect(rect);
}



