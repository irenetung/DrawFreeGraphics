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
/*#define N_POINTS 1000
// Clear Button
#define CB_X    0
#define CB_Y    0
#define CB_WIDTH    200
#define CB_HEIGHT 50

//Exit Button
#define EB_X 201
#define EB_Y 0
#define EB_WIDTH 200
#define EB_HEIGHT 50

//Button Text Offsets
#define BT_X 30
#define BT_Y 30

// Message Location
#define MESS_X 30
#define MESS_Y 380*/
class Canvas : public QGraphicsView
{
public:
    enum DrawState {NONE,CURSOR,SHAPE,STAMP,DRAW,ERASER,PICTURE};
    enum CursorState {NOCURSOR,PREVCURSOR,SCALE,STRETCH,ROTATE,SHEAR,TRANSLATE};
    enum ShapeState {NOSHAPE,PREVSHAPE,LINE,POINT,CIRCLE,RECT,ROUNDRECT,POLYGON,ARC,CHORD,PIE,PATH,TEXTTYPE};
    enum StampState {NOSTAMP, SILHOUETTE, STANDARD};

    Canvas(QUndoStack* undoStack_);
    QGraphicsScene *scene;
    int mousePressCount;
    QPen *pen;
    QBrush *brush;
    QColor color;
    QList<QPointF> points;
    QUndoStack *undoStack;

    DrawState drawState;
    CursorState cursorState;
    ShapeState shapeState;
    StampState stampState;
    //Cursor
    bool translateSignPositive;
    bool translateDirectionHorizontal;
    double translateValue;
    bool scaleSignPositive;
    double scaleFactor;
    bool stretchSignPositive;
    bool stretchDirectionHorizontal;
    double stretchValue;
    bool rotateSignPositive;
    double rotateAngle;
    bool shearSignPositive;
    bool shearDirectionHorizontal;
    double shearAngle;

    //Shapes
    QGraphicsItem *prevShape;
    void drawItem(QGraphicsItem *item);
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
private:
    /*int gx[N_POINTS],gy[N_POINTS];
    int gi;*/
};

#endif // CANVAS_H
