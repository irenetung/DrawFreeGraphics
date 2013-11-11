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
    color = Qt::black;
    drawState = NONE;
    cursorState = ROTATE;
    shapeState = LINE;
    mousePressCount = 0;

    rotateAngle = 0;
    rotateSignPositive = true;

    prevShape = NULL;

    currentStampPath = "";
    stampState = NOSTAMP;
}

void Canvas::drawItem(QGraphicsItem *item)
{
    item->setTransformOriginPoint(item->boundingRect().center());
    scene->addItem(item);
    update();
    prevShape = item;
    mousePressCount = 0;
    points.clear();

    if(drawState == SHAPE) {
        shapeState = NOSHAPE;
        prevShape = item;
    } else {

    }
}

void Canvas::setCurrentStamp(QString item)
{
    currentStampPath = item;
}

void Canvas::drawPixmapItem(QGraphicsPixmapItem *item)
{
    scene->addItem(item);
    update();
    mousePressCount = 0;
    points.clear();
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    QPointF clickPoint = mapToScene(e->pos());
    QGraphicsItem *selectedItem = itemAt(e->pos());

    if(drawState == CURSOR) {
        if(selectedItem != NULL) {
            switch(cursorState) {
                case SCALE:
                    break;
                case ROTATE:
                    if(rotateAngle < 0) {
                        selectedItem->setRotation(0.000);
                    }
                    selectedItem->setRotation(fmod(selectedItem->rotation(),360));
                    if(rotateSignPositive == true) {
                        selectedItem->setRotation(selectedItem->rotation()+rotateAngle);
                    } else {
                        selectedItem->setRotation(selectedItem->rotation()-rotateAngle);
                    }
                    break;
                case SHEAR:
                    break;
                case TRANSLATE:
                    break;
                default:
                    break;
            }
        }
    }
    if(drawState == SHAPE) {
        points.append(clickPoint);
        qDebug() << "shapestate" << shapeState;
        qDebug() << "mousePressCount" << mousePressCount;
        qDebug() << "clicks " << clickPoint.x() << " " << clickPoint.y() <<"\n";
        mousePressCount++;

        switch(shapeState) {
            case PREVSHAPE:
            qDebug() << "err" << shapeState;
                /*prevShape = new QGraphicsItem(prevShape);
                prevShape->setTransform(prevShape->transform()*(QTransform().translate(10,10)));
                drawItem(prevShape);*/
                break;
            case LINE:
                if(mousePressCount == 2) {
                    QLineF line(points[0],points[1]);
                    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
                    lineItem->setPen(*pen);
                    drawItem(lineItem);
                }
                break;
            case POINT:
                if(mousePressCount == 1) {
                    PointItem *pointItem = new PointItem(points,*pen,*brush);
                    drawItem(pointItem);
                }
                break;
            case CIRCLE:
                if(mousePressCount == 2) {
                    QRectF rect(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y());
                    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
                    ellipseItem->setPen(*pen);
                    ellipseItem->setBrush(*brush);
                    drawItem(ellipseItem);
                }
                break;
            case RECT:
                if(mousePressCount == 2) {
                    QRectF rect(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y());
                    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
                    rectItem->setPen(*pen);
                    rectItem->setBrush(*brush);
                    drawItem(rectItem);
                }
                break;
            case ROUNDRECT:
                if(mousePressCount == 2) {
                    RoundRectangleItem *roundRectItem = new RoundRectangleItem(points,*pen,*brush);
                    drawItem(roundRectItem);
                }
                break;
            case ARC:
                if(mousePressCount == 2) {
                    ArcItem *arcItem = new ArcItem(points,*pen,*brush);
                    drawItem(arcItem);
                }
                break;
            case CHORD:
                if(mousePressCount == 2) {
                    ChordItem *chordItem = new ChordItem(points,*pen,*brush);
                    drawItem(chordItem);
                }
                break;
            case PIE:
                if(mousePressCount == 2) {
                    PieItem *pieItem = new PieItem(points,*pen,*brush);
                    drawItem(pieItem);
                }
                break;
            case POLYGON:
            case PATH:
                break;
            default:
                mousePressCount = 0;
                break;
        }
    }
    if (drawState == STAMP)
    {
        if (stampState == SILHOUETTE)
        {
            points.append(clickPoint);
            QImage im(currentStampPath);
            QImage alpha = im.alphaChannel();
            for(int x=0; x<im.width();x++)
            {
                for(int y=0; y<im.height();y++)
                {
                    if (qRed(alpha.pixel(x,y)) > 1)
                    {
                        im.setPixel( x, y, color.rgb());
                    }
                }
            }
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(im));
            item->setPos(clickPoint - item->boundingRect().center());
            drawPixmapItem(item);
        }
        else if (stampState == STANDARD)
        {
            points.append(clickPoint);
            QImage im(currentStampPath);
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(im));
            item->setPos(clickPoint - item->boundingRect().center());
            drawPixmapItem(item);
        }
        else
        {
            qDebug() << "EXCEPTION: draw stamp occurred without stamp state being set";
        }
    }
}
