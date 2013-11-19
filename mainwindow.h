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
    CursorWidgetCursors *cursorWidgetCursors;
    CursorWidgetTranslate *cursorWidgetTranslate;
    CursorWidgetScale *cursorWidgetScale;
    CursorWidgetStretch *cursorWidgetStretch;
    CursorWidgetRotate *cursorWidgetRotate;
    CursorWidgetShear *cursorWidgetShear;
    CursorWidgetDepth *cursorWidgetDepth;
    CursorWidgetBack *cursorWidgetBack;
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
    void cursorBackButtonClicked();

    void translateButtonClicked();
    void scaleButtonClicked();
    void rotateButtonClicked();
    void shearButtonClicked();
    void stretchButtonClicked();
    void depthButtonClicked();
    void copyButtonClicked();
    void deleteButtonClicked();

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
    void st0001ButtonClicked();
    void st0005ButtonClicked();
    void st001ButtonClicked();
    void st005ButtonClicked();
    void st01ButtonClicked();
    void st02ButtonClicked();
    void st05ButtonClicked();
    void st1ButtonClicked();

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
    void sh001ButtonClicked();
    void sh005ButtonClicked();
    void sh01ButtonClicked();
    void sh02ButtonClicked();
    void sh05ButtonClicked();
    void sh1ButtonClicked();

    void dp1ButtonClicked();
    void dn1ButtonClicked();

    //Shapes
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

    void shapesBackButtonClicked();
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

private:
    void changeTranslateValue(double v);
    void changeStretchValue(double v);
    void changeShearValue(double v);
};

#endif // MAINWINDOW_H
