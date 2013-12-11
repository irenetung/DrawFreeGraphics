#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPathItem>
#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QUndoStack>
#include "item.h"
#include <cmath>

class Canvas : public QGraphicsView
{
public:
    enum DrawState {NOSTATE,CURSOR,COLOR,SHAPE,STAMP,BRUSHEFFECTS,TEXTTYPE};
    enum CursorState {NOCURSOR,SCALE,STRETCH,ROTATE,SHEAR,TRANSLATE,DEPTH,FLIP,COPY,DELETEITEM};
    enum ColorState {NOCOLOR,OUTLINE,FILL,BRUSH,SILHOUETTESTAMP,BACKGROUND,OUTLINESIZE,BRUSHSIZE};
    enum ShapeState {LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH};
    enum StampState {NOSTAMP, SILHOUETTE, STANDARD};
    enum BrushEffectsState {NOBRUSH,PAINT,WATERCOLOR,CALLIGRAPHY,PENCIL,SPRAYPAINT,DUST};
    enum Direction {RIGHT,LEFT,UP,DOWN};

    Canvas(QUndoStack* undoStack_);

    QGraphicsScene *scene;
    QPen *shapesPen;
    QBrush *shapesBrush;
    QPen *brushPen;
    QBrush *brushBrush;
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

    bool flipY;

    void resetTranslateStretchShear();
    //Colors
    QColor prevCustomColor;
    QColor silhouetteColor;
    void setPenWidth(int width);

    bool alphaOutlineSignPositive;
    bool alphaFillSignPositive;
    bool alphaSilhouetteSignPositive;
    bool alphaBrushSignPositive;

    //Shapes
    void drawItem(QGraphicsItem *item);
    void resetShapeState();

    int outlineIncrement;
    bool outlineSignPositive;

    QList<QPointF> shapePoints;
    QPen shapePointsPen;
    QGraphicsPathItem clickPath;
    //Stamps
    QString currentStampPath;
    void setCurrentStamp(QString path);
    void drawPixmapItem(QGraphicsPixmapItem *item);

    void saveScene(QString filename);
    void loadScene(QString filename);
    //Brush Effects
    int brushIncrement;
    bool brushSignPositive;

    QPointF previous;
    QGraphicsPathItem *myPath;
//Text
    QString text;
    QFont font;
    bool shiftOn;

protected:
    //void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    //void drawForeground(QPainter *painter, const QRectF &rect);
private:
    void copyTransforms(QGraphicsItem *copyItem,QGraphicsItem *selectedItem);

};

#endif // CANVAS_H
