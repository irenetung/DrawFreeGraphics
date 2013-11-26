#ifndef SHAPESWIDGET_H
#define SHAPESWIDGET_H

#include "basewidget.h"

class ShapesWidget : public BaseWidget
{
public:
    explicit ShapesWidget();
};

//Select a shape
class ShapesWidgetShapes : public ShapesWidget
{
public:
    explicit ShapesWidgetShapes();

    QPixmap *lineButtonIcon;
    QPixmap *pointButtonIcon;
    QPixmap *circleButtonIcon;
    QPixmap *rectangleButtonIcon;
    QPixmap *roundedRectangleButtonIcon;
    QPixmap *polygonButtonIcon;
    QPixmap *arcButtonIcon;
    QPixmap *chordButtonIcon;
    QPixmap *pieButtonIcon;
    QPixmap *pathButtonIcon;
    QPixmap *textButtonIcon;

    QPushButton *outlineSizeButton;
    QPushButton *outlineColorButton;
    QPushButton *fillColorButton;
    QPushButton *lineButton;
    QPushButton *pointButton;
    QPushButton *circleButton;
    QPushButton *rectangleButton;
    QPushButton *roundedRectangleButton;
    QPushButton *polygonButton;
    QPushButton *arcButton;
    QPushButton *chordButton;
    QPushButton *pieButton;
    QPushButton *pathButton;
    QPushButton *textButton;
};

//End path
class ShapesWidgetEndPath : public ShapesWidget
{
public:
    explicit ShapesWidgetEndPath();
    QPushButton *backButton;
    QPushButton *endPathButton;
};

class ShapesWidgetOutlineSizes : public ShapesWidget
{
public:
    explicit ShapesWidgetOutlineSizes();
    QPushButton *backButton;
    QPushButton *on1Button;
    QPushButton *op1Button;

};

#endif // SHAPESWIDGET_H
