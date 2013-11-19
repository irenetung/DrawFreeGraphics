#include "canvas.h"
#include "commanditem.h"

#include <QMessageBox>
#include <QDebug>

Canvas::Canvas(QUndoStack* undoStack_)
{
    setMouseTracking(true);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->frameSize().width(),this->frameSize().height());
    this->setScene(scene);
    this->setRenderHint(QPainter::Antialiasing);

    brush = new QBrush(Qt::green);
    pen = new QPen(Qt::black);
    pen->setWidth(6);
    pen->setStyle(Qt::SolidLine);
    pen->setCapStyle(Qt::RoundCap);
    pen->setJoinStyle(Qt::RoundJoin);
    color = Qt::black;
    drawState = NOSTATE;
    cursorState = ROTATE;
    shapeState = LINE;
    mousePressCount = 0;

    translateHorizontalValue = 0;
    translateVerticalValue = 0;
    translateSignPositive = true;
    translateDirectionHorizontal = true;

    scaleFactor = 1.0;
    scaleSignPositive = true;

    stretchSignPositive = true;
    stretchDirectionHorizontal = true;
    stretchHorizontalValue = 1;
    stretchVerticalValue = 1;

    rotateAngle = 0;
    rotateSignPositive = true;

    shearSignPositive = true;
    shearDirectionHorizontal = true;
    shearHorizontalValue = 0;
    shearVerticalValue = 0;

    depthPositive = true;

    prevShape = NULL;

    currentStampPath = "";
    stampState = NOSTAMP;

    undoStack = undoStack_;
}

void Canvas::resetDrawState()
{
    drawState = NOSTATE;
    mousePressCount = 0;
    points.clear();
}

void Canvas::resetTranslateStretchShear()
{
    translateHorizontalValue=0;
    translateVerticalValue=0;
    stretchHorizontalValue=1;
    stretchVerticalValue=1;
    shearHorizontalValue=0;
    shearVerticalValue=0;
}

void Canvas::drawItem(QGraphicsItem *item)
{
    item->setTransformOriginPoint(item->boundingRect().center());
    undoStack->push(new CommandItem(item, scene));
    update();
    prevShape = item;
    mousePressCount = 0;
    points.clear();
}

void Canvas::resetShapeState()
{
    mousePressCount=0;
    points.clear();
}

void Canvas::setCurrentStamp(QString item)
{
    currentStampPath = item;
}

void Canvas::drawPixmapItem(QGraphicsPixmapItem *item)
{
    undoStack->push(new CommandItem(item, scene));
    update();
    mousePressCount = 0;
    points.clear();
}

void Canvas::saveScene(QString filename)
{
    scene->clearSelection();                                                  // Selections would also render to the file
    scene->setSceneRect(scene->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::transparent);                                              // Start all pixels transparent

    QPainter painter(&image);
    scene->render(&painter);
    image.save(filename);
}

void Canvas::loadScene(QString filename)
{
    qDebug() << "Loading file: " <<  filename;
    QPixmap bg(filename);
    scene->addPixmap(bg);
}

void Canvas::mouseMoveEvent(QMouseEvent *e)
{
    if(drawState == DRAW) {
        if(mousePressCount == 1) {
            QPointF movePoint = mapToScene(e->pos());
            points.append(movePoint);
            /*PointItem *pointItem = new PointItem(points[points.size()-1],*pen);
            drawItem(pointItem);
            update();
            int rad = (pen->width()/2) + 2;*/

            //update(QRect(points[points.size()-2].toPoint(),(QPoint)points[points.size()-1].toPoint()).normalized().adjusted(-rad,-rad,+rad,+rad));
        }
    }
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    QPointF clickPoint = mapToScene(e->pos());
    QGraphicsItem *selectedItem = itemAt(e->pos());
    if(drawState == DRAW) {
        mousePressCount++;
        points.append(clickPoint);
        //PointItem *pointItem = new PointItem(points[points.size()-1],*pen);
        //drawItem(pointItem);
        if(mousePressCount == 2) {
            DrawItem *draw = new DrawItem(points,*pen,*brush);
            draw->addWaterColorEffect(100, 0.1);
            drawItem(draw);
            mousePressCount = 0;
        }
    }
    if(drawState == CURSOR) {
        if(selectedItem != NULL) {
            switch(cursorState) {
                case TRANSLATE:
                    selectedItem->moveBy(translateHorizontalValue,translateVerticalValue);
                    qDebug() << selectedItem->transformOriginPoint().x()<< " "<< selectedItem->transformOriginPoint().y();
                    break;
                case STRETCH:
                    selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).scale(stretchHorizontalValue,stretchVerticalValue).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                case SHEAR:
                    //selectedItem->setTransform((QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).scale(stretchHorizontalValue,stretchVerticalValue).shear(shearHorizontalValue,shearVerticalValue).translate(translateHorizontalValue,translateVerticalValue).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).shear(shearHorizontalValue,shearVerticalValue).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    break;
                case SCALE:
                    if(scaleFactor < 0) {
                        selectedItem->setScale(1.0);
                        break;
                    }
                    if(scaleSignPositive == true) {

                        selectedItem->setScale(selectedItem->scale()+scaleFactor);
                    } else {
                        if(selectedItem->scale()-scaleFactor > 0) {
                            selectedItem->setScale(selectedItem->scale()-scaleFactor);
                        }
                    }
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
                case DEPTH:
                    if(depthPositive == true) {
                        selectedItem->setZValue(selectedItem->zValue()+1);
                    } else {
                        selectedItem->setZValue(selectedItem->zValue()-1);
                    }
                    break;
                case COPY:
                    break;
                case DELETEITEM:
                        scene->removeItem(selectedItem);
                    break;
                default:
                    break;
            }
        }
    }
    if(drawState == SHAPE) {
        qDebug()<<"eh" <<" "<<shapeState;
        points.append(clickPoint);
        mousePressCount++;

        switch(shapeState) {
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
                    PointItem *pointItem = new PointItem(points[points.size()-1],*pen);
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
            qDebug()<<"wah";
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
            item->setScale(0.5);
            item->setPos(clickPoint - item->boundingRect().center());
            drawPixmapItem(item);
        }
        else if (stampState == STANDARD)
        {
            points.append(clickPoint);
            QImage im(currentStampPath);
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(im));
            item->setScale(0.5);
            item->setPos(clickPoint - 0.5 * item->boundingRect().center());
            drawPixmapItem(item);
        }
        else
        {
            qDebug() << "EXCEPTION: draw stamp occurred without stamp state being set";
        }
    }
}

/*void Canvas::drawForeground(QPainter *painter, const QRectF &rect)
{
    /*int startAngle = 30*16;
    int spanAngle = 120*16;
    painter->drawArc(rect, startAngle, spanAngle);
}*/


