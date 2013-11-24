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
#include <QVector>

#include "prompt.h"
#include "settingswidget.h"
#include "cursorwidget.h"
#include "colorswidget.h"
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
    void setToolButtonProperties(QToolButton &b);
    void hideWidgets();

    int buttonWidth;
    int buttonHeight;
    QVector<BaseWidget *> popUps;
    //Toolbar
    QToolButton settingsButton;
    QToolButton newButton;
    QToolButton openButton;
    QToolButton saveButton;
    QToolButton undoButton;
    QToolButton cursorButton;
    QToolButton colorsButton;
    QToolButton shapesButton;
    QToolButton stampsButton;
    QToolButton brushEffectsButton;
    QToolButton drawButton;
    QToolButton eraserButton;
    QToolButton insertPictureButton;
    QToolButton closeButton;

    QUndoStack *undoStack;

 //Tool Widgets

    Prompt *prompt;
    //Settings
    SettingsWidgetButtonSize *settingsWidgetButtonSize;
    //Cursor
    CursorWidgetCursors *cursorWidgetCursors;
    CursorWidgetTranslate *cursorWidgetTranslate;
    CursorWidgetScale *cursorWidgetScale;
    CursorWidgetStretch *cursorWidgetStretch;
    CursorWidgetRotate *cursorWidgetRotate;
    CursorWidgetShear *cursorWidgetShear;
    CursorWidgetDepth *cursorWidgetDepth;
    CursorWidgetBack *cursorWidgetBack;
    //Colors
    ColorsWidgetPaintTools *colorsWidgetPaintTools;
    ColorsWidgetColors *colorsWidgetColors;
    ColorsWidgetOutlineSizes *colorsWidgetOutlineSizes;
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
    StampsWidgetFood *stampsWidgetFood;

    //Canvas
    Canvas *canvas;

    //Application Layout
    QVBoxLayout *vLayout;

private slots:
//Toolbar
    void settingsButtonClicked();
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
    //Settings
    void bwn5ButtonClicked();
    void bwp5ButtonClicked();
    void bhn5ButtonClicked();
    void bhp5ButtonClicked();
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
    void translateValueButtonClicked(int v);

    void scaleSignButtonClicked();
    void scaleResetButtonClicked();
    void scaleValueButtonClicked(int v);

    void stretchSignButtonClicked();
    void stretchDirectionButtonClicked();
    void stretchValueButtonClicked(int v);

    void rotateSignButtonClicked();
    void reset0ButtonClicked();
    void rotateValueButtonClicked(int v);

    void shearSignButtonClicked();
    void shearDirectionButtonClicked();
    void shearValueButtonClicked(int v);

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

    //Colors
    void outlineButtonClicked();
    void fillButtonClicked();
    void brushButtonClicked();
    void backgroundButtonClicked();

    void colorsBackButtonClicked();
    void peachButtonClicked();
    void pinkButtonClicked();
    void redButtonClicked();
    void orangeButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();
    void purpleButtonClicked();
    void brownButtonClicked();
    void blackButtonClicked();
    void grayButtonClicked();
    void whiteButtonClicked();
    void customColorButtonClicked();

    void outlinSizesBackButtonClicked();
    void on1ButtonClicked();
    void op1ButtonClicked();

    //Brush Effects
    void paintButtonClicked();
    void waterColorButtonClicked();
    void calligraphyButtonClicked();
    void pencilButtonClicked();
    void sprayPaintButtonClicked();
    void dustButtonClicked();

    //Stamps
    void goBackButtonClicked();
    void silhouetteButtonClicked();
    void peopleButtonClicked();
    void animalsButtonClicked();
    void buildingsButtonClicked();
    void sceneryButtonClicked();
    void facesButtonClicked();
    void vehiclesButtonClicked();
    void foodButtonClicked();

    void silhouetteStampClicked(const QString stamp_name);
    void standardStampClicked(const QString stamp_name);

private:
    void changeButtonProperties(const int &newButtonWidth,const int &newButtonHeight);
    void changeTranslateValue(int v);
    void changeStretchValue(double v);
    void changeShearValue(double v);
    void changePaintToolColor(QColor color);
};

#endif // MAINWINDOW_H
