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
    void setToolButtonProperties(QToolButton *b);
    void hideWidgets();

    int buttonWidth;
    int buttonHeight;
    QVector<QToolButton *> tools;
    QVector<BaseWidget *> popUps;
    //Toolbar
    QToolButton *settingsButton;
    QToolButton *newButton;
    QToolButton *openButton;
    QToolButton *saveButton;
    QToolButton *undoButton;
    QToolButton *cursorButton;
    QToolButton *colorsButton;
    QToolButton *shapesButton;
    QToolButton *stampsButton;
    QToolButton *brushEffectsButton;
    QToolButton *insertPictureButton;
    QToolButton *closeButton;

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
    ColorsWidgetColors *colorsWidgetColorsOutline;
    ColorsWidgetColors *colorsWidgetColorsFill;
    ColorsWidgetColors *colorsWidgetColorsSilhouette;
    ColorsWidgetColors *colorsWidgetColorsBrush;
    ColorsWidgetColors *colorsWidgetColorsBackground;\
    //Shapes
    ShapesWidgetShapes *shapesWidgetShapes;
    ShapesWidgetEndPath *shapesWidgetEndPath;
    ShapesWidgetOutlineSizes *shapesWidgetOutlineSizes;

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
    void changeOutlineColorButtonClicked();
    void changeFillColorButtonClicked();
    void changeBrushColorButtonClicked();
    void changeOutlineSizeButtonClicked();
    void changeBrushSizeButtonClicked();
    void copyButtonClicked();
    void deleteButtonClicked();

    void translateSignButtonClicked();
    void translateDirectionButtonClicked();
    void cursorTranslateButtonGroupClicked(int id);

    void scaleSignButtonClicked();
    void cursorScaleButtonGroupClicked(int id);

    void stretchSignButtonClicked();
    void stretchDirectionButtonClicked();
    void cursorStretchButtonGroupClicked(int id);

    void rotateSignButtonClicked();
    void cursorRotateButtonGroupClicked(int id);

    void shearSignButtonClicked();
    void shearDirectionButtonClicked();
    void cursorShearButtonGroupClicked(int id);

    void cursorDepthButtonGroupClicked(int id);

    //Shapes
    void outlineSizeButtonClicked();
    void shapesButtonGroupClicked(int id);

    void shapesBackButtonClicked();
    void endPathButtonClicked();

    void outlineSizesBackButtonClicked();
    void on1ButtonClicked();
    void op1ButtonClicked();

    //Colors
    void outlineButtonClicked();
    void fillButtonClicked();
    void silhouetteColorButtonClicked();
    void brushButtonClicked();
    void backgroundButtonClicked();

    void colorsButtonGroupClicked(int id);
    void colorsBackButtonClicked();
    void customColorButtonClicked();

    //Brush Effects
    void brushEffectsButtonGroupClicked(int id);

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

    void changeButtonProperties(const int &newButtonWidth,const int &newButtonHeight);
    void changeTranslateValue(int v);
    void changeStretchValue(double v);
    void changeShearValue(double v);
    void changePaintToolColor(QColor color);
};

#endif // MAINWINDOW_H
