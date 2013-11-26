#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QUndoStack>
#include "item.h"
#include <cmath>

class Canvas : public QGraphicsView
{
public:
    enum DrawState {NOSTATE,CURSOR,COLOR,SHAPE,STAMP,BRUSHEFFECTS,PICTURE};
    enum CursorState {NOCURSOR,SCALE,STRETCH,ROTATE,SHEAR,TRANSLATE,DEPTH,OUTLINECOLOR,FILLCOLOR,BRUSHCOLOR,OUTLINESIZE,BRUSHSIZE,COPY,DELETEITEM};
    enum ColorState {NOCOLOR,OUTLINE,FILL,BRUSH,SILHOUETTESTAMP,BACKGROUND};
    enum ShapeState {LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH,TEXTTYPE};
    enum StampState {NOSTAMP, SILHOUETTE, STANDARD};
    enum BrushEffectsState {NOBRUSH,PAINT,WATERCOLOR,CALLIGRAPHY,PENCIL,SPRAYPAINT,DUST};
    enum Direction {RIGHT,LEFT,UP,DOWN};

    Canvas(QUndoStack* undoStack_);

    QGraphicsScene *scene;
    QPen *shapesPen;
    QBrush *shapesBrush;
    QColor color;
    int mousePressCount;
    QList<QPointF> points;
    QGraphicsItem *selectedItem;

    DrawState drawState;
    CursorState cursorState;
    ColorState colorState;
    ShapeState shapeState;
    StampState stampState;
    BrushEffectsState brushEffectsState;

    //Undo
    QUndoStack *undoStack;
    //Cursor
    Direction translateDirection;
    int translateV;
    int translateHorizontalValue;
    int translateVerticalValue;

    Direction scaleDirection;
    double scaleFactor;

    Direction stretchDirection;
    double stretchV;
    double stretchHorizontalValue;
    double stretchVerticalValue;

    Direction rotateDirection;
    double rotateAngle;

    Direction shearDirection;
    double shearV;
    double shearHorizontalValue;
    double shearVerticalValue;

    bool depthPositive;

    void resetTranslateStretchShear();
    //Colors
    QColor prevCustomColor;
    void setPenColor(QColor color);
    void setBrushColor(QColor color);
    QColor silhouetteColor;
    QColor brushColor;
    void setPenWidth(int width);
    //Shapes
    void drawItem(QGraphicsItem *item);
    void resetShapeState();
    //Stamps
    QString currentStampPath;
    void setCurrentStamp(QString path);
    void drawPixmapItem(QGraphicsPixmapItem *item);

    void saveScene(QString filename);
    void loadScene(QString filename);

protected:
    //void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    //void drawForeground(QPainter *painter, const QRectF &rect);
private:
    void copyTransforms(QGraphicsItem *copyItem,QGraphicsItem *selectedItem);

};

#endif // CANVAS_H
