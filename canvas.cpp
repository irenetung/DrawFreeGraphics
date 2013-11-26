#include "canvas.h"
#include "commanditem.h"

#include <QDebug>

Canvas::Canvas(QUndoStack* undoStack_)
{
    setMouseTracking(true);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,this->frameSize().width(),this->frameSize().height());
    this->setScene(scene);
    this->setRenderHint(QPainter::Antialiasing);

    shapesPen = new QPen(Qt::black);
    shapesBrush = new QBrush(Qt::white);
    silhouetteColor = Qt::black;
    brushColor = Qt::black;
    mousePressCount = 0;
    selectedItem = NULL;

    drawState = NOSTATE;
    cursorState = TRANSLATE;
    shapeState = LINE;
    brushEffectsState = PAINT;

//Undo
    undoStack = undoStack_;
//Cursor
    translateDirection = RIGHT;
    translateV = 0;
    translateHorizontalValue = 0;
    translateVerticalValue = 0;

    scaleDirection = RIGHT;
    scaleFactor = 1.0;

    stretchDirection = RIGHT;
    stretchV = 0;
    stretchHorizontalValue = 1;
    stretchVerticalValue = 1;

    rotateDirection = RIGHT;
    rotateAngle = 0;

    shearDirection = RIGHT;
    shearV = 0;
    shearHorizontalValue = 0;
    shearVerticalValue = 0;

    depthPositive = true;
//Stamps
    currentStampPath = "";
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

void Canvas::setPenColor(QColor color)
{
    shapesPen->setColor(color);
}

void Canvas::setBrushColor(QColor color)
{
    shapesBrush->setColor(color);
}

void Canvas::setPenWidth(int width)
{
    if((shapesPen->width())+width > 0) {
        shapesPen->setWidth(shapesPen->width()+width);
    }
}

void Canvas::drawItem(QGraphicsItem *item)
{
    item->setTransformOriginPoint(item->boundingRect().center());
    undoStack->push(new CommandItem(item, scene));
    update();
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
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setScale(0.5);
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
    if(drawState == BRUSHEFFECTS) {
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

    if(drawState == BRUSHEFFECTS) {
        mousePressCount++;
        points.append(clickPoint);
        //PointItem *pointItem = new PointItem(points[points.size()-1],*pen);
        //drawItem(pointItem);
        if(mousePressCount == 2) {
            switch(brushEffectsState) {
                case PAINT: {
                    PaintItem *paintItem = new PaintItem(points,*shapesPen,*shapesBrush);
                    drawItem(paintItem);
                    break;
                    }
                case WATERCOLOR:
                    break;
                case CALLIGRAPHY:
                    break;
                case PENCIL:
                    break;
                case SPRAYPAINT:
                    break;
            case DUST: {
                    DrawItem *draw = new DrawItem(points,*shapesPen,*shapesBrush);
                    drawItem(draw);
                    break;
                    }
                default:
                    break;

                 //draw->addWaterColorEffect(100, 0.1);
            }
            mousePressCount = 0;
        }
    }
    if(drawState == CURSOR) {
        if(selectedItem != NULL) {
            resetTranslateStretchShear();
            switch(cursorState) {
                case TRANSLATE:
                    switch(translateDirection) {
                    case RIGHT:
                        translateHorizontalValue += translateV;
                        break;
                    case LEFT:
                        translateHorizontalValue -= translateV;
                        break;
                    case UP:
                        translateVerticalValue -= translateV;
                        break;
                    case DOWN:
                        translateVerticalValue += translateV;
                        break;
                    default:
                        break;
                    }
                    selectedItem->moveBy(translateHorizontalValue,translateVerticalValue);
                    break;
                case STRETCH:
                    switch(stretchDirection) {
                    case RIGHT:
                        stretchHorizontalValue += stretchV;
                        break;
                    case LEFT:
                        if(stretchHorizontalValue - stretchV >= 0.01) {
                            stretchHorizontalValue -= stretchV;
                        }
                        break;
                    case UP:
                        stretchVerticalValue += stretchV;
                        break;
                    case DOWN:
                        if(stretchVerticalValue - stretchV >= 0.01) {
                            stretchVerticalValue -= stretchV;
                        }
                        break;
                    default:
                        break;
                    }
                    selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).scale(stretchHorizontalValue,stretchVerticalValue).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    break;
                case SHEAR:
                    switch(shearDirection) {
                    case RIGHT:
                        shearHorizontalValue -= shearV;
                        break;
                    case LEFT:
                        shearHorizontalValue += shearV;
                        break;
                    case UP:
                        shearVerticalValue += shearV;
                        break;
                    case DOWN:
                        shearVerticalValue -= shearV;
                        break;
                    default:
                        break;
                    }
                    selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).shear(shearHorizontalValue,shearVerticalValue).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    break;
                case SCALE:
                    if(scaleFactor < 0) {
                        selectedItem->setScale(1.0);
                        break;
                    }
                    if(scaleDirection == RIGHT) {
                        selectedItem->setScale(selectedItem->scale()+scaleFactor);
                    } else {
                        if(selectedItem->scale()-scaleFactor > 0.01) {
                            selectedItem->setScale(selectedItem->scale()-scaleFactor);
                        }
                    }
                    break;
                case ROTATE:
                    if(rotateAngle < 0) {
                        selectedItem->setRotation(0);
                    }
                    selectedItem->setRotation(fmod(selectedItem->rotation(),360));
                    if(rotateDirection == RIGHT) {
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
                case OUTLINESIZE:
                    break;
                case BRUSHSIZE:
                    break;
                case COPY:
                    if(selectedItem) {
                        switch(selectedItem->type()) {
                        case 7:{
                            //PIXMAP
                            QGraphicsPixmapItem *selectedPixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(selectedItem);
                            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(selectedPixmapItem->pixmap());
                            drawPixmapItem(pixmapItem);
                            pixmapItem->setPos(selectedPixmapItem->pos().x()+10,selectedPixmapItem->pos().y()+10);

                            break;
                            }
                        case 6: {
                            //LINE
                            QGraphicsLineItem *selectedLineItem = qgraphicsitem_cast<QGraphicsLineItem *>(selectedItem);
                            QGraphicsLineItem *lineItem = new QGraphicsLineItem(selectedLineItem->line());
                            lineItem->setPen(selectedLineItem->pen());
                            drawItem(lineItem);
                            lineItem->setPos(selectedLineItem->pos().x()+10,selectedLineItem->pos().y()+10);
                            break;
                            }
                        case PointItemType: {
                            //ROUND RECT
                            PointItem *selectedPointItem = qgraphicsitem_cast<PointItem *>(selectedItem);
                            PointItem *pointItem = new PointItem(selectedPointItem->vertex,*(selectedPointItem->pen));
                            drawItem(pointItem);
                            pointItem->setPos(selectedPointItem->pos().x()+10,selectedPointItem->pos().y()+10);
                            break;
                            }
                        case 4:{
                            //CIRCLE
                            QGraphicsEllipseItem *selectedEllipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);
                            QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(selectedEllipseItem->rect());
                            ellipseItem->setPen(selectedEllipseItem->pen());
                            ellipseItem->setBrush(selectedEllipseItem->brush());
                            drawItem(ellipseItem);
                            ellipseItem->setPos(selectedEllipseItem->pos().x()+10,selectedEllipseItem->pos().y()+10);
                            ellipseItem->setRotation(selectedEllipseItem->rotation());
                            ellipseItem->setScale(selectedEllipseItem->scale());
                            break;
                            }
                        case 3: {
                            //RECT
                            QGraphicsRectItem *selectedRectItem = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem);
                            QGraphicsRectItem *rectItem = new QGraphicsRectItem(selectedRectItem->rect());
                            rectItem->setPen(selectedRectItem->pen());
                            rectItem->setBrush(selectedRectItem->brush());
                            drawItem(rectItem);
                            rectItem->setPos(selectedRectItem->pos().x()+10,selectedRectItem->pos().y()+10);
                            break;
                            }
                        case 5:{
                            //POLYGON
                            QGraphicsPolygonItem *selectedPolygonItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem);
                            QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(selectedPolygonItem->polygon());
                            polygonItem->setPen(selectedPolygonItem->pen());
                            polygonItem->setBrush(selectedPolygonItem->brush());
                            drawItem(polygonItem);
                            polygonItem->setPos(selectedPolygonItem->pos().x()+10,selectedPolygonItem->pos().y()+10);
                            break;
                            }
                        case RoundRectangleItemType: {
                            //ROUND RECT
                            RoundRectangleItem *selectedRoundRectItem = qgraphicsitem_cast<RoundRectangleItem *>(selectedItem);
                            RoundRectangleItem *roundRectItem = new RoundRectangleItem(selectedRoundRectItem->vertices,*(selectedRoundRectItem->pen),*(selectedRoundRectItem->brush));
                            drawItem(roundRectItem);
                            roundRectItem->setPos(selectedRoundRectItem->pos().x()+10,selectedRoundRectItem->pos().y()+10);
                            break;
                            }
                        case ArcItemType:{
                            //ARC
                            ArcItem *selectedArcItem = qgraphicsitem_cast<ArcItem *>(selectedItem);
                            ArcItem *arcItem = new ArcItem(selectedArcItem->vertices,*(selectedArcItem->pen),*(selectedArcItem->brush));
                            drawItem(arcItem);
                            arcItem->setPos(selectedArcItem->pos().x()+10,selectedArcItem->pos().y()+10);
                            break;
                            }
                        case ChordItemType:{
                            //CHORD
                            ChordItem *selectedChordItem = qgraphicsitem_cast<ChordItem *>(selectedItem);
                            ChordItem *chordItem = new ChordItem(selectedChordItem->vertices,*(selectedChordItem->pen),*(selectedChordItem->brush));
                            drawItem(chordItem);
                            chordItem->setPos(selectedChordItem->pos().x()+10,selectedChordItem->pos().y()+10);
                            break;
                            }
                        case PieItemType:{
                            //PIE
                            PieItem *selectedPieItem = qgraphicsitem_cast<PieItem *>(selectedItem);
                            PieItem *pieItem = new PieItem(selectedPieItem->vertices,*(selectedPieItem->pen),*(selectedPieItem->brush));
                            drawItem(pieItem);
                            pieItem->setPos(selectedPieItem->pos().x()+10,selectedPieItem->pos().y()+10);
                            break;
                            }
                        case PathItemType:{
                            //PIE
                            PathItem *selectedPathItem = qgraphicsitem_cast<PathItem *>(selectedItem);
                            PathItem *pathItem = new PathItem(*(selectedPathItem->polygon),*(selectedPathItem->pen),*(selectedPathItem->brush));
                            drawItem(pathItem);
                            pathItem->setPos(selectedPathItem->pos().x()+10,selectedPathItem->pos().y()+10);
                            break;
                            }
                        default:
                            qDebug() << "cool";
                            break;
                        }
                    }
                    break;
                case DELETEITEM:
                        scene->removeItem(selectedItem);
                    break;
                default:
                    break;
            }
        }
    }
    if(drawState == COLOR) {
        if(selectedItem != NULL) {
            switch(selectedItem->type()) {
            case 7:{
                //PIXMAP
                switch(colorState) {
                case SILHOUETTESTAMP: {
                    QGraphicsPixmapItem *selectedPixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(selectedItem);
                    QImage im = selectedPixmapItem->pixmap().toImage();
                    QImage alpha = im.alphaChannel();
                    for(int x=0; x<im.width();x++)
                    {
                        for(int y=0; y<im.height();y++)
                        {
                            if (qRed(alpha.pixel(x,y)) > 1)
                            {
                                im.setPixel( x, y, silhouetteColor.rgb());
                            }
                        }
                    }
                    selectedPixmapItem->setPixmap(QPixmap::fromImage(im));
                    break;
                }
                default:
                    break;
                }
                break;
            }
            case 6: {
                //LINE;
                QGraphicsLineItem *selectedLineItem = qgraphicsitem_cast<QGraphicsLineItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    selectedLineItem->setPen(*shapesPen);
                    break;
                default:
                    break;
                }
                break;
            }
            case PointItemType: {
                //POINT
                PointItem *selectedPointItem = qgraphicsitem_cast<PointItem *>(selectedItem);
                *(selectedPointItem->pen) = *shapesPen;
                switch(colorState) {
                case OUTLINE:
                    *(selectedPointItem->pen) = *shapesPen;
                    break;
                default:
                    break;
                }
                selectedPointItem->update();
                break;
            }
            case ArcItemType: {
                //ARC
                ArcItem *selectedArcItem = qgraphicsitem_cast<ArcItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    *(selectedArcItem->pen) = *shapesPen;
                    break;
                default:
                    break;
                }
                selectedArcItem->update();
                break;
            }
            case PathItemType: {
                //PATH
                PathItem *selectedPathItem = qgraphicsitem_cast<PathItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    *(selectedPathItem->pen) = *shapesPen;
                    break;
                default:
                    break;
                }
                selectedPathItem->update();
                break;
            }
            case 4: {
                //CIRCLE
                qDebug() << "circle";
                QGraphicsEllipseItem *selectedEllipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    selectedEllipseItem->setPen(*shapesPen);
                    break;
                case FILL:
                    selectedEllipseItem->setBrush(*shapesBrush);
                    break;
                default:
                    break;
                }
                break;
            }
            case 3: {
                //RECT
                QGraphicsRectItem *selectedRectItem = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    selectedRectItem->setPen(*shapesPen);
                    break;
                case FILL:
                    selectedRectItem->setBrush(*shapesBrush);
                    break;
                default:
                    break;
                }
                break;
            }
            case 5:{
                //POLYGON
                QGraphicsPolygonItem *selectedPolygonItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    selectedPolygonItem->setPen(*shapesPen);
                    break;
                case FILL:
                    selectedPolygonItem->setBrush(*shapesBrush);
                    break;
                default:
                    break;
                }
                break;
                }
            case RoundRectangleItemType: {
                //ROUND RECT
                RoundRectangleItem *selectedRoundRectItem = qgraphicsitem_cast<RoundRectangleItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    *(selectedRoundRectItem->pen) = *shapesPen;
                    break;
                case FILL:
                    *(selectedRoundRectItem->brush) = *shapesBrush;
                    break;
                default:
                    break;
                }
                selectedRoundRectItem->update();
                break;
            }
            case ChordItemType: {
                //CHORD
                ChordItem *selectedChordItem = qgraphicsitem_cast<ChordItem *>(selectedItem);
                switch(colorState) {
                case OUTLINE:
                    *(selectedChordItem->pen) = *shapesPen;
                    break;
                case FILL:
                    *(selectedChordItem->brush) = *shapesBrush;
                    break;
                default:
                    break;
                }
                selectedChordItem->update();
                break;
            }
            case PieItemType: {
                 //PIE
                 PieItem *selectedPieItem = qgraphicsitem_cast<PieItem *>(selectedItem);
                 switch(colorState) {
                 case OUTLINE:
                     *(selectedPieItem->pen) = *shapesPen;
                     break;
                 case FILL:
                     *(selectedPieItem->brush) = *shapesBrush;
                     break;
                 default:
                     break;
                 }
                 selectedPieItem->update();
                 break;
            }
            default:
                 break;
            }
        }
    }
    if(drawState == SHAPE) {
        points.append(clickPoint);
        mousePressCount++;

        switch(shapeState) {
            case LINE:
                if(mousePressCount == 2) {
                    QLineF line(points[0],points[1]);
                    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
                    lineItem->setPen(*shapesPen);
                    drawItem(lineItem);
                }
                break;
            case POINT:
                if(mousePressCount == 1) {
                    PointItem *pointItem = new PointItem(points[points.size()-1],*shapesPen);
                    drawItem(pointItem);
                }
                break;
            case CIRCLE:
                if(mousePressCount == 2) {
                    QRectF rect(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y());
                    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
                    ellipseItem->setPen(*shapesPen);
                    ellipseItem->setBrush(*shapesBrush);
                    drawItem(ellipseItem);
                }
                break;
            case RECT:
                if(mousePressCount == 2) {
                    QRectF rect(points[0].x(),points[0].y(),points[1].x()-points[0].x(),points[1].y()-points[0].y());
                    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
                    rectItem->setPen(*shapesPen);
                    rectItem->setBrush(*shapesBrush);
                    drawItem(rectItem);
                }
                break;
            case ROUNDRECT:
                if(mousePressCount == 2) {
                    RoundRectangleItem *roundRectItem = new RoundRectangleItem(points,*shapesPen,*shapesBrush);
                    drawItem(roundRectItem);
                }
                break;
            case ARC:
                if(mousePressCount == 2) {
                    ArcItem *arcItem = new ArcItem(points,*shapesPen,*shapesBrush);
                    drawItem(arcItem);
                }
                break;
            case CHORD:
                if(mousePressCount == 2) {
                    ChordItem *chordItem = new ChordItem(points,*shapesPen,*shapesBrush);
                    drawItem(chordItem);
                }
                break;
            case PIE:
                if(mousePressCount == 2) {
                    PieItem *pieItem = new PieItem(points,*shapesPen,*shapesBrush);
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
                        im.setPixel( x, y, silhouetteColor.rgb());
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

/*void Canvas::drawForeground(QPainter *painter, const QRectF &rect)
{
    /*int startAngle = 30*16;
    int spanAngle = 120*16;
    painter->drawArc(rect, startAngle, spanAngle);
}*/


