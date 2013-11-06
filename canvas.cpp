#include "canvas.h"

#include <QMessageBox>
#include <QDebug>

Canvas::Canvas()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->frameSize().width(),this->frameSize().height());

    this->setScene(scene);
    this->setRenderHint(QPainter::Antialiasing);

    brush = new QBrush(Qt::green);
    pen = new QPen(Qt::red);
    drawState = NONE;
    shapeState = LINE;
    mousePressCount = 0;
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    QPointF clickPoint = mapToScene(e->pos());
    QGraphicsItem *selectedItem = itemAt(e->pos());
    if(drawState == CURSOR) {
        if(selectedItem != NULL) {
            selectedItem->setRotation(selectedItem->rotation()+45);
        }
    }
    if(drawState == SHAPE) {
        points.append(clickPoint);
        qDebug() << "shapestate" << shapeState;
        qDebug() << "mousePressCount" << mousePressCount;
        qDebug() << "clicks " << clickPoint.x() << " " << clickPoint.y() <<"\n";
        mousePressCount++;

        switch(shapeState) {
            case LINE:
                if(mousePressCount == 2) {
                    QLineF line(points[0],points[1]);
                    QGraphicsLineItem *lineItem = scene->addLine(line,*pen);
                    lineItem->setTransformOriginPoint(lineItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    points.clear();
                    mousePressCount = 0;
                }
                break;
            case POINT:
                if(mousePressCount == 1) {
                    PointItem *pointItem = new PointItem(points,*pen,*brush);
                    scene->addItem(pointItem);
                    pointItem->setTransformOriginPoint(pointItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
                break;
            case CIRCLE:
                if(mousePressCount == 2) {
                    QGraphicsEllipseItem *ellipseItem = scene->addEllipse(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y(),*pen,*brush);
                    ellipseItem->setTransformOriginPoint(ellipseItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    points.clear();
                    mousePressCount = 0;
                }
                break;
            case RECT:
                if(mousePressCount == 2) {
                    QRectF rect(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y());
                    QGraphicsRectItem *rectItem = scene->addRect(rect,*pen,*brush);
                    rectItem->setTransformOriginPoint(rectItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
                break;
            case ROUNDRECT:
                if(mousePressCount == 2) {
                    RoundRectangleItem *roundRectItem = new RoundRectangleItem(points,*pen,*brush);
                    scene->addItem(roundRectItem);
                    roundRectItem->setTransformOriginPoint(roundRectItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
                break;
            case ARC:
                if(mousePressCount == 2) {
                    ArcItem *arcItem = new ArcItem(points,*pen,*brush);
                    scene->addItem(arcItem);
                    arcItem->setTransformOriginPoint(arcItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
                break;
            case CHORD:
                if(mousePressCount == 2) {
                    ChordItem *chordItem = new ChordItem(points,*pen,*brush);
                    scene->addItem(chordItem);
                    chordItem->setTransformOriginPoint(chordItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
                break;
            case PIE:
                if(mousePressCount == 2) {
                    PieItem *pieItem = new PieItem(points,*pen,*brush);
                    scene->addItem(pieItem);
                    pieItem->setTransformOriginPoint(pieItem->boundingRect().center());
                    update();

                    shapeState = NOSHAPE;

                    mousePressCount = 0;
                    points.clear();
                }
            break;
                break;
            case POLYGON:
            case PATH:
                break;
            default:
                mousePressCount = 0;
                break;

        }
        repaint();
    }
}
