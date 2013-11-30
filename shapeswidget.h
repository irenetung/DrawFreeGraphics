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
    QString currentSize;
    QPushButton *backButton;
    QPushButton *signButton;
    QPushButton *si1Button;
    QPushButton *si5Button;
    QPushButton *si10Button;
    QPushButton *si20Button;
    QPushButton *si50Button;
    QPushButton *si100Button;
};



#endif // SHAPESWIDGET_H
