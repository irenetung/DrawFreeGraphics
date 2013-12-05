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
#include <QCursor>
#include <QFontDialog>

#include "prompt.h"
#include "settingswidget.h"
#include "cursorwidget.h"
#include "colorswidget.h"
#include "shapeswidget.h"
#include "brusheffectswidget.h"
#include "stampswidget.h"
#include "textwidget.h"
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
    int buttonWidth;
    int buttonHeight;
    int id;
    bool hidePopup;
    BaseWidget *curPopup;
    QVector<QToolButton *> tools;
    QVector<BaseWidget *> popUps;
    QButtonGroup *toolGroup;
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
    QToolButton *textButton;
    QToolButton *insertPictureButton;
    QToolButton *closeButton;
    QToolButton *showHidePopupButton;
//Prompt
    Prompt *prompt;
//Settings
    SettingsWidgetButtonSize *settingsWidgetButtonSize;
//Undo
    QUndoStack *undoStack;
//Cursor
    CursorWidgetCursors *cursorWidgetCursors;
    CursorWidgetTranslate *cursorWidgetTranslate;
    CursorWidgetScale *cursorWidgetScale;
    CursorWidgetStretch *cursorWidgetStretch;
    CursorWidgetRotate *cursorWidgetRotate;
    CursorWidgetShear *cursorWidgetShear;
    CursorWidgetDepth *cursorWidgetDepth;
    CursorWidgetBack *cursorWidgetBack;
    CursorWidgetFlip * cursorWidgetFlip;
//Colors
    ColorsWidgetPaintTools *colorsWidgetPaintTools;
    ColorsWidgetColors *colorsWidgetColorsOutline;
    ColorsWidgetColors *colorsWidgetColorsFill;
    ColorsWidgetColors *colorsWidgetColorsSilhouette;
    ColorsWidgetColors *colorsWidgetColorsBrush;
    ColorsWidgetColors *colorsWidgetColorsBackground;

    ColorsWidgetAlpha *colorsWidgetAlphaOutline;
    ColorsWidgetAlpha *colorsWidgetAlphaFill;
    ColorsWidgetAlpha *colorsWidgetAlphaSilhouette;
    ColorsWidgetAlpha *colorsWidgetAlphaBrush;

//Shapes
    ShapesWidgetShapes *shapesWidgetShapes;
    ShapesWidgetEndPath *shapesWidgetEndPath;
    ShapesWidgetOutlineSizes *shapesWidgetOutlineSizes;
//Stamps
    StampsWidgetRecents *stampsWidgetRecents;
    StampsWidgetCategories *stampsWidgetCategories;
    StampsWidgetSilhouette *stampsWidgetSilhouette;
    StampsWidgetPeople *stampsWidgetPeople;
    StampsWidgetAnimals *stampsWidgetAnimals;
    StampsWidgetBuildings *stampsWidgetBuildings;
    StampsWidgetScenery *stampsWidgetScenery;
    StampsWidgetFaces *stampsWidgetFaces;
    StampsWidgetVehicles *stampsWidgetVehicles;
    StampsWidgetFood *stampsWidgetFood;

//Brush Effects
    BrushEffectsWidgetBrushEffects *brushEffectsWidgetBrushEffects;
    BrushEffectsWidgetBrushSizes *brushEffectsWidgetBrushSizes;
//Text
    TextWidgetLetters *textWidgetLetters;
    TextWidgetSpecialKeys *textWidgetSpecialKeys;
//Canvas
    Canvas *canvas;
//Application Layout
    QVBoxLayout *vLayout;

    void setToolButtonProperties(QToolButton *b);
    void addToToolGroup(QToolButton *b);
    void hideWidgets();

private slots:
//Toolbar
    void newButtonClicked();
    void openButtonClicked();
    void saveButtonClicked();
    void undoButtonClicked();
    void toolButtonGroupClicked(int id);

    void insertPictureButtonClicked();
    void showHidePopupButtonClicked();
//Settings
    void settingsButtonSizeButtonGroupClicked(int id);
//Cursor
    void cursorBackButtonClicked();
    void cursorCursorsButtonGroupClicked(int id);
    void cursorDirectionButtonClicked();
    void cursorTranslateButtonGroupClicked(int id);
    void cursorScaleButtonGroupClicked(int id);
    void cursorStretchButtonGroupClicked(int id);
    void cursorRotateButtonGroupClicked(int id);
    void cursorShearButtonGroupClicked(int id);
    void cursorDepthButtonGroupClicked(int id);
    void cursorFlipButtonGroupClicked(int id);
//Shapes
    //Shapes
    void outlineSizeButtonClicked();
    void outlineColorButtonClicked();
    void fillColorButtonClicked();
    void shapesButtonGroupClicked(int id);

    void shapesBackButtonClicked();
    //EndPath
    void endPathButtonClicked();
    //OutlineSizes
    void sizeBackButtonClicked();
    void sizeSignButtonClicked();
    void sizeButtonGroupClicked(int id);
//Colors
    //PaintTools
    void colorsPaintToolsButtonGroupClicked(int id);
    //Colors
    void colorsButtonGroupClicked(int id);
    void colorsBackButtonClicked();
    void colorsAlphaButtonClicked(int widgetType);
    void otherBackButtonClicked(int widgetType);
    void customColorButtonClicked();

    void alphaBackButtonClicked();
    void alphaSignButtonClicked();
    void alphaButtonGroupClicked(int id);
//Brush Effects
    void brushSizeButtonClicked();
    void brushColorButtonClicked();
    void brushEffectsButtonGroupClicked(int id);
 //Stamps
    void goBackButtonClicked();
    void recentsButtonClicked();
    void silhouetteButtonClicked();
    void peopleButtonClicked();
    void animalsButtonClicked();
    void buildingsButtonClicked();
    void sceneryButtonClicked();
    void facesButtonClicked();
    void vehiclesButtonClicked();
    void foodButtonClicked();

    void silhouetteColorButtonClicked();
    void silhouetteStampClicked(const QString stamp_name);
    void standardStampClicked(const QString stamp_name);
//Text
    void lettersSpecialKeysButtonClicked();
    void textChangeFontButtonClicked();
    void lettersShiftButtonClicked();
    void lettersButtonGroupClicked(int id);
    void textBackSpaceButtonClicked();
    void textClearButtonClicked();
    void textOkButtonClicked();

    void specialKeysLettersButtonClicked();
    void specialKeysButtonGroupClicked(int id);
private:
    void resetDrawState();
    void showPopup(BaseWidget *p);
    void changeButtonProperties(const int &newButtonWidth,const int &newButtonHeight);
    void changeCursorDirectionValue(double v);
    void changePaintToolColor(QColor color);
    void changePaintToolAlpha(int alpha);
    void changePaintToolSize(int size);
    void changeKeyboard();
    void setShapesPrompt(Canvas::ShapeState shapeState);
    void setColorsPrompt(Canvas::ColorState colorState);
};

#endif // MAINWINDOW_H
