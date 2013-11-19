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
#include <QUndoStack>

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

    QUndoStack *undoStack;

 //Tool Widgets
    Prompt *prompt;
    //Cursor
    CursorWidgetTranslate *cursorWidgetTranslate;
    CursorWidgetScale *cursorWidgetScale;
    CursorWidgetStretch *cursorWidgetStretch;
    CursorWidgetRotate *cursorWidgetRotate;
    CursorWidgetShear *cursorWidgetShear;
    //Shapes
    ShapesWidgetShapes *shapesWidgetShapes;
    ShapesWidgetEndPath *shapesWidgetEndPath;

    //Brush Effects
    BrushEffectsWidgetBrushEffects *brushEffectsWidgetBrushEffects;

    //Stamps
    StampsWidgetCategories *stampsWidgetCategories;
    StampsWidgetSilhouette *stampsWidgetSilhouette;
    StampsWidgetPeople *stampsWidgetPeople;
    StampsWidgetAnimals *stampsWidgetAnimals;
    StampsWidgetBuildings *stampsWidgetBuildings;
    StampsWidgetScenery *stampsWidgetScenery;
    StampsWidgetFaces *stampsWidgetFaces;
    StampsWidgetVehicles *stampsWidgetVehicles;

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
    void translateButtonClicked();
    void scaleButtonClicked();
    void rotateButtonClicked();
    void shearButtonClicked();
    void stretchButtonClicked();

    void translateSignButtonClicked();
    void translateDirectionButtonClicked();
    void t05ButtonButtonClicked();
    void t1ButtonButtonClicked();
    void t5ButtonButtonClicked();
    void t10ButtonButtonClicked();
    void t20ButtonButtonClicked();
    void t50ButtonButtonClicked();
    void t100ButtonButtonClicked();

    void scaleSignButtonClicked();
    void scaleResetButtonClicked();
    void s05ButtonClicked();
    void s1ButtonClicked();
    void s5ButtonClicked();
    void s10ButtonClicked();
    void s20ButtonClicked();
    void s50ButtonClicked();
    void s100ButtonClicked();

    void stretchSignButtonClicked();
    void stretchDirectionButtonClicked();
    void st05ButtonButtonClicked();
    void st1ButtonButtonClicked();

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

    void shearSignButtonClicked();
    void shearDirectionButtonClicked();
    void sh1ButtonButtonClicked();

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
    void peopleButtonClicked();
    void animalsButtonClicked();
    void buildingsButtonClicked();
    void sceneryButtonClicked();
    void facesButtonClicked();
    void vehiclesButtonClicked();

    void silhouetteStampClicked(const QString stamp_name);
    void standardStampClicked(const QString stamp_name);


};

#endif // MAINWINDOW_H
