#include "canvas.h"

#include <QMessageBox>
#include <QDebug>

Canvas::Canvas()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->frameSize().width(),this->frameSize().height());
    qDebug() <<"view "<< this->frameSize().width() << this->frameSize().height() << "\n";


    this->setScene(scene);
    this->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::black);
    brush.setColor(Qt::blue);
    drawState = NONE;
    shapeState = NOSHAPE;
    mousePressCount = 0;
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    if(drawState == SHAPE) {
        QPointF clickPoint = mapToScene(e->pos());
        /*clickPoint.setX(e->x());
        clickPoint.setY(e->y());*/
        points.append(clickPoint);
        qDebug() << "clicks " << clickPoint.x() << " " << clickPoint.y() <<"\n";
        mousePressCount++;
        if(mousePressCount > 0) {
            //QLineF dash(points[points.size()-2],points[points.size()-1]);

            //scene->addLine(dash,pen);

        }
        switch(shapeState) {
            case LINE:
               // painter.drawRect(pStart.x(), pStart.y(), pEnd.x()-pStart.x(), pEnd.y()-pStart.y());
            if(mousePressCount == 2) {
                QGraphicsLineItem *line = new QGraphicsLineItem(points[0].x(),points[0].y(),points[1].x(),points[1].y());
                scene->addItem(line);

                points.clear();
                mousePressCount = 0;
            }
                 break;
            case CIRCLE:
               // painter.drawLine(p==Start,pEnd);
                //ellipse = scene->addEllipse(10,10,100,100,blackPen,redBrush);
                break;
            case RECT:
                if(mousePressCount == 2) {
                    RectangleItem *rect = new RectangleItem(points);
                    scene->addItem(rect);

                    points.clear();
                    mousePressCount = 0;
                }
               // painter.drawEllipse(pStart.x(), pStart.y(), pEnd.x()-pStart.x(), pEnd.y()-pStart.y());
                break;
            case NOSHAPE:
                QGraphicsItem *selectedItem = scene->itemAt(clickPoint);
                selectedItem->rotate(45);
                break;
            default:
                break;
        }
        repaint();
    }
}
