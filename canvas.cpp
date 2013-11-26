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
    this->setRenderHint(QPainter::SmoothPixmapTransform);

    shapesPen = new QPen(Qt::black);
    shapesPen->setStyle(Qt::SolidLine);
    shapesPen->setCapStyle(Qt::RoundCap);
    shapesPen->setJoinStyle(Qt::RoundJoin);
    shapesPen->setCosmetic(true);
    shapesBrush = new QBrush(Qt::white);

    silhouetteColor = Qt::black;

    brushPen = new QPen(Qt::black);
    shapesPen->setCosmetic(true);
    brushBrush = new QBrush(Qt::black);

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
    scaleFactor = 0;

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
    flipY = true;
//Colors
    prevCustomColor = QColor(255,255,255);
//Shapes
    outlineIncrement=0;
    outlineSignPositive = true;
//Stamps
    currentStampPath = "";
//Brush effects
    brushIncrement=0;
    brushSignPositive = true;
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
    mousePressCount = 0;
    points.clear();
    scene->update();
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
    undoStack->push(new CommandItem(item, scene));
    update();
    mousePressCount = 0;
    points.clear();
    scene->update();
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
    //qDebug() << "Loading file: " <<  filename;
   /* QPixmap bg(filename);
    scene->addPixmap(bg);*/
    QImage image(filename);
    if (image.isNull()) {
        //QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(filename));
        return;
    }
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item->setPos(mapToScene(QPoint(0,0)));
    drawPixmapItem(item);
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
                    PaintItem *paintItem = new PaintItem(points,*brushPen,*brushBrush);
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
                    DrawItem *draw = new DrawItem(points,*brushPen,*brushBrush);
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
                case FLIP:
                    if(flipY) {
                        selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).scale(-1,1).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    } else {
                        selectedItem->setTransform(selectedItem->transform()*(QTransform().translate(selectedItem->transformOriginPoint().x(),selectedItem->transformOriginPoint().y()).scale(1,-1).translate(-selectedItem->transformOriginPoint().x(),-selectedItem->transformOriginPoint().y())));
                    }
                    break;
                case DEPTH: {
                    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();
                    qreal maxZValue = 0;
                    qreal minZValue = 0;
                    foreach(QGraphicsItem *item, overlapItems) {
                        if(item->zValue() >= maxZValue) {
                            maxZValue = item->zValue()+0.1;
                        } else {
                            minZValue = item->zValue()-0.1;
                        }
                    }

                    if(depthPositive == true) {
                        selectedItem->setZValue(maxZValue);
                    } else {
                        selectedItem->setZValue(minZValue);
                    }
                    break;
                    }
                case COPY:
                    if(selectedItem) {
                        switch(selectedItem->type()) {
                        case 7:{
                            //PIXMAP
                            QGraphicsPixmapItem *selectedPixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(selectedItem);
                            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(selectedPixmapItem->pixmap());
                            drawPixmapItem(pixmapItem);
                            copyTransforms(pixmapItem,selectedPixmapItem);
                            break;
                            }
                        case 6: {
                            //LINE
                            QGraphicsLineItem *selectedLineItem = qgraphicsitem_cast<QGraphicsLineItem *>(selectedItem);
                            QGraphicsLineItem *lineItem = new QGraphicsLineItem(selectedLineItem->line());
                            lineItem->setPen(selectedLineItem->pen());
                            drawItem(lineItem);
                            copyTransforms(lineItem,selectedLineItem);
                            break;
                            }
                        case PointItemType: {
                            //ROUND RECT
                            PointItem *selectedPointItem = qgraphicsitem_cast<PointItem *>(selectedItem);
                            PointItem *pointItem = new PointItem(selectedPointItem->vertex,*(selectedPointItem->pen));
                            drawItem(pointItem);
                            copyTransforms(pointItem,selectedPointItem);
                            break;
                            }
                        case 4:{
                            //CIRCLE
                            QGraphicsEllipseItem *selectedEllipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);
                            QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(selectedEllipseItem->rect());
                            ellipseItem->setPen(selectedEllipseItem->pen());
                            ellipseItem->setBrush(selectedEllipseItem->brush());
                            drawItem(ellipseItem);
                            copyTransforms(ellipseItem,selectedEllipseItem);
                            break;
                            }
                        case 3: {
                            //RECT
                            QGraphicsRectItem *selectedRectItem = qgraphicsitem_cast<QGraphicsRectItem *>(selectedItem);
                            QGraphicsRectItem *rectItem = new QGraphicsRectItem(selectedRectItem->rect());
                            rectItem->setPen(selectedRectItem->pen());
                            rectItem->setBrush(selectedRectItem->brush());
                            drawItem(rectItem);
                            copyTransforms(rectItem,selectedRectItem);
                            break;
                            }
                        case 5:{
                            //POLYGON
                            QGraphicsPolygonItem *selectedPolygonItem = qgraphicsitem_cast<QGraphicsPolygonItem *>(selectedItem);
                            QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(selectedPolygonItem->polygon());
                            polygonItem->setPen(selectedPolygonItem->pen());
                            polygonItem->setBrush(selectedPolygonItem->brush());
                            drawItem(polygonItem);
                            copyTransforms(polygonItem,selectedPolygonItem);
                            break;
                            }
                        case RoundRectangleItemType: {
                            //ROUND RECT
                            RoundRectangleItem *selectedRoundRectItem = qgraphicsitem_cast<RoundRectangleItem *>(selectedItem);
                            RoundRectangleItem *roundRectItem = new RoundRectangleItem(selectedRoundRectItem->vertices,*(selectedRoundRectItem->pen),*(selectedRoundRectItem->brush));
                            drawItem(roundRectItem);
                            copyTransforms(roundRectItem,selectedRoundRectItem);
                            break;
                            }
                        case ArcItemType:{
                            //ARC
                            ArcItem *selectedArcItem = qgraphicsitem_cast<ArcItem *>(selectedItem);
                            ArcItem *arcItem = new ArcItem(selectedArcItem->vertices,*(selectedArcItem->pen),*(selectedArcItem->brush));
                            drawItem(arcItem);
                            copyTransforms(arcItem,selectedArcItem);
                            break;
                            }
                        case ChordItemType:{
                            //CHORD
                            ChordItem *selectedChordItem = qgraphicsitem_cast<ChordItem *>(selectedItem);
                            ChordItem *chordItem = new ChordItem(selectedChordItem->vertices,*(selectedChordItem->pen),*(selectedChordItem->brush));
                            drawItem(chordItem);
                            copyTransforms(chordItem,selectedChordItem);
                            break;
                            }
                        case PieItemType:{
                            //PIE
                            PieItem *selectedPieItem = qgraphicsitem_cast<PieItem *>(selectedItem);
                            PieItem *pieItem = new PieItem(selectedPieItem->vertices,*(selectedPieItem->pen),*(selectedPieItem->brush));
                            drawItem(pieItem);
                            copyTransforms(pieItem,selectedPieItem);
                            break;
                            }
                        case PathItemType:{
                            //PIE
                            PathItem *selectedPathItem = qgraphicsitem_cast<PathItem *>(selectedItem);
                            PathItem *pathItem = new PathItem(*(selectedPathItem->polygon),*(selectedPathItem->pen),*(selectedPathItem->brush));
                            drawItem(pathItem);
                            copyTransforms(pathItem,selectedPathItem);
                            break;
                            }
                        case PaintItemType: {
                            PaintItem *selectedPaintItem = qgraphicsitem_cast<PaintItem *>(selectedItem);
                            PaintItem *paintItem = new PaintItem(selectedPaintItem->vertices,*(selectedPaintItem->pen),*(selectedPaintItem->brush));
                            drawItem(paintItem);
                            copyTransforms(paintItem,selectedPaintItem);
                            break;
                            }
                        case DustItemType: {
                            DrawItem *selectedDrawItem = qgraphicsitem_cast<DrawItem *>(selectedItem);
                            DrawItem *dustItem = new DrawItem(selectedDrawItem->vertices,*(selectedDrawItem->pen),*(selectedDrawItem->brush));
                            drawItem(dustItem);
                            copyTransforms(dustItem,selectedDrawItem);
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
                QPen pen = selectedLineItem->pen();
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    selectedLineItem->setPen(pen);
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    selectedLineItem->setPen(pen);
                    break;
                    }
                default:
                    break;
                }
                break;
            }
            case PointItemType: {
                //POINT
                PointItem *selectedPointItem = qgraphicsitem_cast<PointItem *>(selectedItem);
                QPen pen = *(selectedPointItem->pen);
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    *(selectedPointItem->pen) = pen;
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                     *(selectedPointItem->pen) = pen;
                    break;
                    }
                default:
                    break;
                }
                selectedPointItem->update();
                break;
            }
            case ArcItemType: {
                //ARC
                ArcItem *selectedArcItem = qgraphicsitem_cast<ArcItem *>(selectedItem);
                QPen pen = *(selectedArcItem->pen);
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    *(selectedArcItem->pen) = pen;
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    *(selectedArcItem->pen) = pen;
                    break;
                    }
                default:
                    break;
                }
                selectedArcItem->update();
                break;
            }
            case PathItemType: {
                //PATH
                PathItem *selectedPathItem = qgraphicsitem_cast<PathItem *>(selectedItem);
                QPen pen = *(selectedPathItem->pen);
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    *(selectedPathItem->pen) = pen;
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    *(selectedPathItem->pen) = pen;
                    break;
                    }
                default:
                    break;
                }
                selectedPathItem->update();
                break;
            }
            case 4: {
                //CIRCLE
                QGraphicsEllipseItem *selectedEllipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedItem);
                QPen pen = selectedEllipseItem->pen();
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    selectedEllipseItem->setPen(pen);
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    selectedEllipseItem->setPen(pen);
                    break;
                    }
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
                QPen pen = selectedRectItem->pen();
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    selectedRectItem->setPen(pen);
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    selectedRectItem->setPen(pen);
                    break;
                    }
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
                QPen pen = selectedPolygonItem->pen();
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    selectedPolygonItem->setPen(pen);
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    selectedPolygonItem->setPen(pen);
                    break;
                    }
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
                QPen pen = *(selectedRoundRectItem->pen);
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    *(selectedRoundRectItem->pen) = pen;
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    *(selectedRoundRectItem->pen) = pen;
                    break;
                    }
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
                QPen pen = *(selectedChordItem->pen);
                switch(colorState) {
                case OUTLINE: {
                    pen.setColor(shapesPen->color());
                    *(selectedChordItem->pen) = pen;
                    break;
                    }
                case OUTLINESIZE: {
                    pen.setWidth(shapesPen->width());
                    *(selectedChordItem->pen) = pen;
                    break;
                    }
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
                 QPen pen = *(selectedPieItem->pen);
                 switch(colorState) {
                 case OUTLINE: {
                     pen.setColor(shapesPen->color());
                     *(selectedPieItem->pen) = pen;
                     break;
                    }
                 case OUTLINESIZE: {
                     pen.setWidth(shapesPen->width());
                     *(selectedPieItem->pen) = pen;
                     break;
                     }
                 case FILL:
                     *(selectedPieItem->brush) = *shapesBrush;
                     break;
                 default:
                     break;
                 }
                 selectedPieItem->update();
                 break;
            }
            case PaintItemType: {
                 PaintItem *selectedPaintItem = qgraphicsitem_cast<PaintItem *>(selectedItem);
                 QPen pen = *(selectedPaintItem->pen);
                 QBrush brush = *(selectedPaintItem->brush);
                 switch(colorState) {
                 case BRUSH: {
                     pen.setColor(brushPen->color());
                     brush.setColor(brushBrush->color());
                     *(selectedPaintItem->pen) = pen;
                     *(selectedPaintItem->brush) = brush;
                     break;
                    }
                 case BRUSHSIZE: {
                     pen.setWidth(brushPen->width());
                     //WHAT TO DO WITH BRUSH
                     *(selectedPaintItem->pen) = pen;
                     *(selectedPaintItem->brush) = brush;
                     break;
                     }
                 default:
                     break;
                 }
                 selectedPaintItem->update();
                 break;
            }
            case DustItemType: {
                 DrawItem *selectedDrawItem = qgraphicsitem_cast<DrawItem *>(selectedItem);
                 QPen pen = *(selectedDrawItem->pen);
                 QBrush brush = *(selectedDrawItem->brush);
                 switch(colorState) {
                 case BRUSH: {
                     pen.setColor(brushPen->color());
                     brush.setColor(brushBrush->color());
                     *(selectedDrawItem->pen) = pen;
                     *(selectedDrawItem->brush) = brush;
                     break;
                    }
                 case BRUSHSIZE: {
                     pen.setWidth(brushPen->width());
                     //WHAT TO DO WITH BRUSH
                     *(selectedDrawItem->pen) = pen;
                     *(selectedDrawItem->brush) = brush;
                     break;
                     }
                 default:
                     break;
                 }
                 selectedDrawItem->update();
                 break;
            }
            default:
                 break;
            }
        }
        scene->update();
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

void Canvas::copyTransforms(QGraphicsItem *copyItem, QGraphicsItem *selectedItem)
{
    copyItem->setPos(selectedItem->pos().x()+10,selectedItem->pos().y()+10);
    copyItem->setRotation(selectedItem->rotation());
    copyItem->setScale(selectedItem->scale());
    copyItem->setTransform(selectedItem->transform());
}

/*void Canvas::drawForeground(QPainter *painter, const QRectF &rect)
{
    /*int startAngle = 30*16;
    int spanAngle = 120*16;
    painter->drawArc(rect, startAngle, spanAngle);
}*/


