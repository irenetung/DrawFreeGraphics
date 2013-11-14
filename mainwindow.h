#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QToolButton>
#include <QIcon>

#include "prompt.h"
#include "cursorwidget.h"
#include "shapeswidget.h"
#include "brusheffectswidget.h"
#include "stampswidget.h"
#include "item.h"
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setToolButtonProperties(QToolButton *b);
    void hideWidgets();

    int dim;
    //Toolbar
    QToolButton *newButton;
    QToolButton *openButton;
    QToolButton *saveButton;
    QToolButton *undoButton;
    QToolButton *cursorButton;
    QToolButton *colorsButton;
    QToolButton *shapesButton;
    QToolButton *stampsButton;
    QToolButton *brushEffectsButton;
    QToolButton *drawButton;
    QToolButton *eraserButton;
    QToolButton *insertPictureButton;
    QToolButton *closeButton;

 //Tool Widgets
    Prompt *prompt;
    //Cursor
    CursorWidgetRotate *cursorWidgetRotate;
    //Shapes
    ShapesWidgetShapes *shapesWidgetShapes;
    ShapesWidgetEndPath *shapesWidgetEndPath;

    //Brush Effects
    BrushEffectsWidgetBrushEffects *brushEffectsWidgetBrushEffects;

    //Stamps
    StampsWidgetCategories *stampsWidgetCategories;
    StampsWidgetSilhouette *stampsWidgetSilhouette;
    StampsWidgetAnimals *stampsWidgetAnimals;
    StampsWidgetBuildings *stampsWidgetBuildings;
    StampsWidgetScenery *stampsWidgetScenery;

    //Canvas
    Canvas *canvas;

    //Application Layout
    QVBoxLayout *vLayout;

private slots:
//Toolbar
    void newButtonClicked();
    void openButtonClicked();
    void saveButtonClicked();
    void undoButtonClicked();
    void cursorButtonClicked();
    void colorsButtonClicked();
    void shapesButtonClicked();
    void stampsButtonClicked();
    void brushEffectsButtonClicked();
    void drawButtonClicked();
    void eraserButtonClicked();
    void insertPictureButtonClicked();

//Tool Buttons
    //Cursor
    void rotateSignButtonClicked();
    void reset0ButtonClicked();
    void r01ButtonClicked();
    void r05ButtonClicked();
    void r1ButtonClicked();
    void r5ButtonClicked();
    void r10ButtonClicked();
    void r20ButtonClicked();
    void r30ButtonClicked();
    void r45ButtonClicked();
    void r60ButtonClicked();
    void r72ButtonClicked();
    void r90ButtonClicked();
    void r120ButtonClicked();
    void r180ButtonClicked();
    void r270ButtonClicked();

    //Shapes
    void previousShapeButtonClicked();
    void lineButtonClicked();
    void pointButtonClicked();
    void circleButtonClicked();
    void rectangleButtonClicked();
    void roundedRectangleButtonClicked();
    void polygonButtonClicked();
    void arcButtonClicked();
    void chordButtonClicked();
    void pieButtonClicked();
    void pathButtonClicked();
    void textButtonClicked();

    void endPathButtonClicked();

    //Brush Effects
    void paintButtonClicked();
    void waterColorButtonClicked();
    void calligraphyButtonClicked();
    void pencilButtonClicked();
    void sprayPaintButtonClicked();

    //Stamps
    void goBackButtonClicked();
    void silhouetteButtonClicked();
    void animalsButtonClicked();
    void buildingsButtonClicked();
    void sceneryButtonClicked();

    void silhouetteStampClicked(const QString stamp_name);
    void standardStampClicked(const QString stamp_name);


};

#endif // MAINWINDOW_H
