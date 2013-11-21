#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <qfiledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonWidth = 60;
    buttonHeight = 60;

//Toolbar
    ui->mainToolBar->setIconSize(QSize(buttonWidth,buttonHeight));

    settingsButton.setIcon(QIcon(":/Icons/Icons/settings.png"));
    settingsButton.setText("Settings");
    setToolButtonProperties(settingsButton);
    connect(&settingsButton, SIGNAL(clicked()), this, SLOT(settingsButtonClicked()));

    newButton.setIcon(QIcon(":/Icons/Icons/new.png"));
    newButton.setText("New");
    setToolButtonProperties(newButton);
    connect(&newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));

    openButton.setIcon(QIcon(":/Icons/Icons/open.png"));
    openButton.setText("Open");
    setToolButtonProperties(openButton);
    connect(&openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));

    saveButton.setIcon(QIcon(":/Icons/Icons/save.png"));
    saveButton.setText("Save");
    setToolButtonProperties(saveButton);
    connect(&saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));

    undoButton.setIcon(QIcon(":/Icons/Icons/undo.png"));
    undoButton.setText("Undo");
    setToolButtonProperties(undoButton);
    connect(&undoButton, SIGNAL(clicked()), this, SLOT(undoButtonClicked()));

    cursorButton.setIcon(QIcon(":/Icons/Icons/cursor.png"));
    cursorButton.setText("Cursor");
    setToolButtonProperties(cursorButton);
    connect(&cursorButton, SIGNAL(clicked()), this, SLOT(cursorButtonClicked()));

    colorsButton.setIcon(QIcon(":/Icons/Icons/colors.png"));
    colorsButton.setText("Colors");
    setToolButtonProperties(colorsButton);
    connect(&colorsButton, SIGNAL(clicked()), this, SLOT(colorsButtonClicked()));

    shapesButton.setIcon(QIcon(":/Icons/Icons/shapes.png"));
    shapesButton.setText("Shapes");
    setToolButtonProperties(shapesButton);
    connect(&shapesButton, SIGNAL(clicked()), this, SLOT(shapesButtonClicked()));

    stampsButton.setIcon(QIcon(":/Icons/Icons/stamps.png"));
    stampsButton.setText("Stamps");
    setToolButtonProperties(stampsButton);
    connect(&stampsButton, SIGNAL(clicked()), this, SLOT(stampsButtonClicked()));

    brushEffectsButton.setIcon(QIcon(":/Icons/Icons/brushEffects.png"));
    brushEffectsButton.setText("Brush Effects");
    setToolButtonProperties(brushEffectsButton);
    connect(&brushEffectsButton, SIGNAL(clicked()), this, SLOT(brushEffectsButtonClicked()));

    drawButton.setIcon(QIcon(":/Icons/Icons/draw.png"));
    drawButton.setText("Draw");
    setToolButtonProperties(drawButton);
    connect(&drawButton, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));

    eraserButton.setIcon(QIcon(":/Icons/Icons/eraser.png"));
    eraserButton.setText("Eraser");
    setToolButtonProperties(eraserButton);
    connect(&eraserButton, SIGNAL(clicked()), this, SLOT(eraserButtonClicked()));

    insertPictureButton.setIcon(QIcon(":/Icons/Icons/insertPicture.png"));
    insertPictureButton.setText("Insert Picture");
    setToolButtonProperties(insertPictureButton);
    connect(&insertPictureButton, SIGNAL(clicked()), this, SLOT(insertPictureButtonClicked()));

    closeButton.setIcon(QIcon(":/Icons/Icons/close.png"));
    closeButton.setText("Close");
    setToolButtonProperties(closeButton);
    connect(&closeButton, SIGNAL(clicked()), this, SLOT(close()));

    undoStack = new QUndoStack();

//Tool Widgets
    //Prompt
    prompt = new Prompt();
//Cursor
    //Settings
    settingsWidgetButtonSize = new SettingsWidgetButtonSize();
    popUps.push_back(settingsWidgetButtonSize);
    connect(settingsWidgetButtonSize->bwn5Button, SIGNAL(clicked()), this, SLOT(bwn5ButtonClicked()));
    connect(settingsWidgetButtonSize->bwp5Button, SIGNAL(clicked()), this, SLOT(bwp5ButtonClicked()));
    connect(settingsWidgetButtonSize->bhn5Button, SIGNAL(clicked()), this, SLOT(bhn5ButtonClicked()));
    connect(settingsWidgetButtonSize->bhp5Button, SIGNAL(clicked()), this, SLOT(bhp5ButtonClicked()));
    //Cursors
    cursorWidgetCursors = new CursorWidgetCursors();
    popUps.push_back(cursorWidgetCursors);
    cursorWidgetTranslate = new CursorWidgetTranslate();
    popUps.push_back(cursorWidgetTranslate);
    cursorWidgetScale = new CursorWidgetScale();
    popUps.push_back(cursorWidgetScale);
    cursorWidgetRotate = new CursorWidgetRotate();
    popUps.push_back(cursorWidgetRotate);
    cursorWidgetShear = new CursorWidgetShear();
    popUps.push_back(cursorWidgetShear);
    cursorWidgetStretch = new CursorWidgetStretch();
    popUps.push_back(cursorWidgetStretch);
    cursorWidgetDepth = new CursorWidgetDepth();
    popUps.push_back(cursorWidgetDepth);
    cursorWidgetBack = new CursorWidgetBack();
    popUps.push_back(cursorWidgetBack);

    connect(cursorWidgetCursors->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonClicked()));
    connect(cursorWidgetCursors->scaleButton, SIGNAL(clicked()), this, SLOT(scaleButtonClicked()));
    connect(cursorWidgetCursors->stretchButton, SIGNAL(clicked()), this, SLOT(stretchButtonClicked()));
    connect(cursorWidgetCursors->rotateButton, SIGNAL(clicked()), this, SLOT(rotateButtonClicked()));
    connect(cursorWidgetCursors->shearButton, SIGNAL(clicked()), this, SLOT(shearButtonClicked()));
    connect(cursorWidgetCursors->depthButton, SIGNAL(clicked()), this, SLOT(depthButtonClicked()));
    connect(cursorWidgetCursors->copyButton, SIGNAL(clicked()), this, SLOT(copyButtonClicked()));
    connect(cursorWidgetCursors->deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
    //Translate
    connect(cursorWidgetTranslate->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetTranslate->signButton, SIGNAL(clicked()), this, SLOT(translateSignButtonClicked()));
    connect(cursorWidgetTranslate->directionButton, SIGNAL(clicked()), this, SLOT(translateDirectionButtonClicked()));

    QSignalMapper* translateSignalMapper = new QSignalMapper (this) ;
    connect(cursorWidgetTranslate->t1Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));
    connect(cursorWidgetTranslate->t5Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));
    connect(cursorWidgetTranslate->t10Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));
    connect(cursorWidgetTranslate->t20Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));
    connect(cursorWidgetTranslate->t50Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));
    connect(cursorWidgetTranslate->t100Button, SIGNAL(clicked()), translateSignalMapper, SLOT(map()));

    translateSignalMapper->setMapping(cursorWidgetTranslate->t1Button, 1);
    translateSignalMapper->setMapping(cursorWidgetTranslate->t5Button, 5);
    translateSignalMapper->setMapping(cursorWidgetTranslate->t10Button, 10);
    translateSignalMapper->setMapping(cursorWidgetTranslate->t20Button, 20);
    translateSignalMapper->setMapping(cursorWidgetTranslate->t50Button, 50);
    translateSignalMapper->setMapping(cursorWidgetTranslate->t100Button, 100);

    connect(translateSignalMapper, SIGNAL(mapped(int)), this, SLOT(translateValueButtonClicked(int)));
    //Scale
    connect(cursorWidgetScale->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetScale->signButton, SIGNAL(clicked()), this, SLOT(scaleSignButtonClicked()));
    connect(cursorWidgetScale->resetButton, SIGNAL(clicked()), this, SLOT(scaleResetButtonClicked()));

    QSignalMapper* scaleSignalMapper = new QSignalMapper (this) ;
    connect(cursorWidgetScale->s05Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s1Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s5Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s10Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s20Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s50Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));
    connect(cursorWidgetScale->s100Button, SIGNAL(clicked()), scaleSignalMapper, SLOT(map()));

    scaleSignalMapper->setMapping(cursorWidgetScale->s05Button, 5);
    scaleSignalMapper->setMapping(cursorWidgetScale->s1Button, 10);
    scaleSignalMapper->setMapping(cursorWidgetScale->s5Button, 50);
    scaleSignalMapper->setMapping(cursorWidgetScale->s10Button, 100);
    scaleSignalMapper->setMapping(cursorWidgetScale->s20Button, 200);
    scaleSignalMapper->setMapping(cursorWidgetScale->s50Button, 500);
    scaleSignalMapper->setMapping(cursorWidgetScale->s100Button, 1000);

    connect(scaleSignalMapper, SIGNAL(mapped(int)), this, SLOT(scaleValueButtonClicked(int)));
    //Stretch
    connect(cursorWidgetStretch->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetStretch->signButton, SIGNAL(clicked()), this, SLOT(stretchSignButtonClicked()));
    connect(cursorWidgetStretch->directionButton, SIGNAL(clicked()), this, SLOT(stretchDirectionButtonClicked()));

    QSignalMapper* stretchSignalMapper = new QSignalMapper (this) ;
    connect(cursorWidgetStretch->st0005Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st001Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st005Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st01Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st02Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st05Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));
    connect(cursorWidgetStretch->st1Button, SIGNAL(clicked()), stretchSignalMapper, SLOT(map()));

    stretchSignalMapper->setMapping(cursorWidgetStretch->st0005Button, 5);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st001Button, 10);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st005Button, 50);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st01Button, 100);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st02Button, 200);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st05Button, 500);
    stretchSignalMapper->setMapping(cursorWidgetStretch->st1Button, 1000);

    connect(stretchSignalMapper, SIGNAL(mapped(int)), this, SLOT(stretchValueButtonClicked(int)));

    //Rotate
    connect(cursorWidgetRotate->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetRotate->signButton, SIGNAL(clicked()), this, SLOT(rotateSignButtonClicked()));
    connect(cursorWidgetRotate->resetButton, SIGNAL(clicked()), this, SLOT(reset0ButtonClicked()));

    QSignalMapper* rotateSignalMapper = new QSignalMapper (this) ;
    connect(cursorWidgetRotate->r01Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r05Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r1Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r5Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r10Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r20Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r30Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r45Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r60Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r72Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r90Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r120Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));
    connect(cursorWidgetRotate->r180Button, SIGNAL(clicked()), rotateSignalMapper, SLOT(map()));

    rotateSignalMapper->setMapping(cursorWidgetRotate->r01Button, 1);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r05Button, 5);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r1Button, 10);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r5Button, 50);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r10Button, 100);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r20Button, 200);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r30Button, 300);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r45Button, 450);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r60Button, 600);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r72Button, 720);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r90Button, 900);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r120Button, 1200);
    rotateSignalMapper->setMapping(cursorWidgetRotate->r180Button, 1800);

    connect(rotateSignalMapper, SIGNAL(mapped(int)), this, SLOT(rotateValueButtonClicked(int)));
    //Shear
    connect(cursorWidgetShear->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetShear->signButton, SIGNAL(clicked()), this, SLOT(shearSignButtonClicked()));
    connect(cursorWidgetShear->directionButton, SIGNAL(clicked()), this, SLOT(shearDirectionButtonClicked()));

    QSignalMapper* shearSignalMapper = new QSignalMapper (this) ;
    connect(cursorWidgetShear->sh001Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));
    connect(cursorWidgetShear->sh005Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));
    connect(cursorWidgetShear->sh01Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));
    connect(cursorWidgetShear->sh02Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));
    connect(cursorWidgetShear->sh05Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));
    connect(cursorWidgetShear->sh1Button, SIGNAL(clicked()), shearSignalMapper, SLOT(map()));

    shearSignalMapper->setMapping(cursorWidgetShear->sh001Button, 10);
    shearSignalMapper->setMapping(cursorWidgetShear->sh005Button, 50);
    shearSignalMapper->setMapping(cursorWidgetShear->sh01Button, 100);
    shearSignalMapper->setMapping(cursorWidgetShear->sh02Button, 200);
    shearSignalMapper->setMapping(cursorWidgetShear->sh05Button, 500);
    shearSignalMapper->setMapping(cursorWidgetShear->sh1Button, 1000);

    connect(shearSignalMapper, SIGNAL(mapped(int)), this, SLOT(shearValueButtonClicked(int)));
    //Depth
    connect(cursorWidgetDepth->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetDepth->dp1Button, SIGNAL(clicked()), this, SLOT(dp1ButtonClicked()));
    connect(cursorWidgetDepth->dn1Button, SIGNAL(clicked()), this, SLOT(dn1ButtonClicked()));
    //Back
    connect(cursorWidgetBack->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
//Shapes
    shapesWidgetShapes = new ShapesWidgetShapes();
    popUps.push_back(shapesWidgetShapes);
    shapesWidgetEndPath = new ShapesWidgetEndPath();
    popUps.push_back(shapesWidgetEndPath);

    connect(shapesWidgetShapes->lineButton, SIGNAL(clicked()), this, SLOT(lineButtonClicked()));
    connect(shapesWidgetShapes->pointButton, SIGNAL(clicked()), this, SLOT(pointButtonClicked()));
    connect(shapesWidgetShapes->circleButton, SIGNAL(clicked()), this, SLOT(circleButtonClicked()));
    connect(shapesWidgetShapes->rectangleButton, SIGNAL(clicked()), this, SLOT(rectangleButtonClicked()));
    connect(shapesWidgetShapes->roundedRectangleButton, SIGNAL(clicked()), this, SLOT(roundedRectangleButtonClicked()));
    connect(shapesWidgetShapes->polygonButton, SIGNAL(clicked()), this, SLOT(polygonButtonClicked()));
    connect(shapesWidgetShapes->arcButton, SIGNAL(clicked()), this, SLOT(arcButtonClicked()));
    connect(shapesWidgetShapes->chordButton, SIGNAL(clicked()), this, SLOT(chordButtonClicked()));
    connect(shapesWidgetShapes->pieButton, SIGNAL(clicked()), this, SLOT(pieButtonClicked()));
    connect(shapesWidgetShapes->pathButton, SIGNAL(clicked()), this, SLOT(pathButtonClicked()));
    connect(shapesWidgetShapes->textButton, SIGNAL(clicked()), this, SLOT(textButtonClicked()));

    connect(shapesWidgetEndPath->backButton, SIGNAL(clicked()), this, SLOT(shapesBackButtonClicked()));
    connect(shapesWidgetEndPath->endPathButton, SIGNAL(clicked()), this, SLOT(endPathButtonClicked()));
//Colors
    colorsWidgetColors = new ColorsWidgetColors();
    popUps.push_back(colorsWidgetColors);
    colorsWidgetPaintTools = new ColorsWidgetPaintTools();
    popUps.push_back(colorsWidgetPaintTools);
    colorsWidgetOutlineSizes = new ColorsWidgetOutlineSizes();
    popUps.push_back(colorsWidgetOutlineSizes);

    connect(colorsWidgetPaintTools->outlineButton, SIGNAL(clicked()), this, SLOT(outlineButtonClicked()));
    connect(colorsWidgetPaintTools->fillButton, SIGNAL(clicked()), this, SLOT(fillButtonClicked()));
    connect(colorsWidgetPaintTools->brushButton, SIGNAL(clicked()), this, SLOT(brushButtonClicked()));
    connect(colorsWidgetPaintTools->backgroundButton, SIGNAL(clicked()), this, SLOT(backgroundButtonClicked()));

    connect(colorsWidgetColors->backButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColors->peachButton, SIGNAL(clicked()), this, SLOT(peachButtonClicked()));
    connect(colorsWidgetColors->pinkButton, SIGNAL(clicked()), this, SLOT(pinkButtonClicked()));
    connect(colorsWidgetColors->redButton, SIGNAL(clicked()), this, SLOT(redButtonClicked()));
    connect(colorsWidgetColors->orangeButton, SIGNAL(clicked()), this, SLOT(orangeButtonClicked()));
    connect(colorsWidgetColors->yellowButton, SIGNAL(clicked()), this, SLOT(yellowButtonClicked()));
    connect(colorsWidgetColors->greenButton, SIGNAL(clicked()), this, SLOT(greenButtonClicked()));
    connect(colorsWidgetColors->blueButton, SIGNAL(clicked()), this, SLOT(blueButtonClicked()));
    connect(colorsWidgetColors->purpleButton, SIGNAL(clicked()), this, SLOT(purpleButtonClicked()));
    connect(colorsWidgetColors->brownButton, SIGNAL(clicked()), this, SLOT(brownButtonClicked()));
    connect(colorsWidgetColors->blackButton, SIGNAL(clicked()), this, SLOT(blackButtonClicked()));
    connect(colorsWidgetColors->grayButton, SIGNAL(clicked()), this, SLOT(grayButtonClicked()));
    connect(colorsWidgetColors->whiteButton, SIGNAL(clicked()), this, SLOT(whiteButtonClicked()));
    connect(colorsWidgetColors->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    connect(colorsWidgetOutlineSizes->backButton, SIGNAL(clicked()), this, SLOT(outlinSizesBackButtonClicked()));
    connect(colorsWidgetOutlineSizes->on1Button, SIGNAL(clicked()), this, SLOT(on1ButtonClicked()));
    connect(colorsWidgetOutlineSizes->op1Button, SIGNAL(clicked()), this, SLOT(op1ButtonClicked()));
//Brush Effects
    brushEffectsWidgetBrushEffects = new BrushEffectsWidgetBrushEffects();
    popUps.push_back(brushEffectsWidgetBrushEffects);
    connect(brushEffectsWidgetBrushEffects->paintButton, SIGNAL(clicked()), this, SLOT(paintButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->waterColorButton, SIGNAL(clicked()), this, SLOT(waterColorButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->calligraphyButton, SIGNAL(clicked()), this, SLOT(calligraphyButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->pencilButton, SIGNAL(clicked()), this, SLOT(pencilButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->sprayPaintButton, SIGNAL(clicked()), this, SLOT(sprayPaintButtonClicked()));

//Stamps
    stampsWidgetCategories = new StampsWidgetCategories();
    popUps.push_back(stampsWidgetCategories);
    stampsWidgetSilhouette = new StampsWidgetSilhouette();
    popUps.push_back(stampsWidgetSilhouette);
    stampsWidgetPeople = new StampsWidgetPeople();
    popUps.push_back(stampsWidgetPeople);
    stampsWidgetAnimals = new StampsWidgetAnimals();
    popUps.push_back(stampsWidgetAnimals);
    stampsWidgetBuildings = new StampsWidgetBuildings();
    popUps.push_back(stampsWidgetBuildings);
    stampsWidgetScenery = new StampsWidgetScenery();
    popUps.push_back(stampsWidgetScenery);
    stampsWidgetFaces = new StampsWidgetFaces();
    popUps.push_back(stampsWidgetFaces);
    stampsWidgetVehicles = new StampsWidgetVehicles();
    popUps.push_back(stampsWidgetVehicles);

    connect(stampsWidgetCategories->silhouetteButton, SIGNAL(clicked()), this, SLOT(silhouetteButtonClicked()));
        // Silhouette Stamps
        connect(stampsWidgetSilhouette->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper* silhouetteSignalMapper = new QSignalMapper (this) ;
        connect(stampsWidgetSilhouette->stampOne, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwo, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThree, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampFour, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampFive, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampSix, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampSeven, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampEight, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampNine, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampEleven, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwelve, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThirteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampFourteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampFifteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampSixteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampSeventeen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampEighteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampNineteen, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwenty, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyOne, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyTwo, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyThree, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyFour, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyFive, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentySix, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentySeven, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyEight, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampTwentyNine, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThirty, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThirtyOne, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThirtyTwo, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->stampThirtyThree, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));


        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampOne, ":/Stamps/solidcolorstamps/Stamps/solid_dog_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwo, ":/Stamps/solidcolorstamps/Stamps/solid_cat_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThree, ":/Stamps/solidcolorstamps/Stamps/solid_bird_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampFour, ":/Stamps/solidcolorstamps/Stamps/solid_turtle_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampFive, ":/Stamps/solidcolorstamps/Stamps/solid_rat_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampSix, ":/Stamps/solidcolorstamps/Stamps/solid_giraffe_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampSeven, ":/Stamps/solidcolorstamps/Stamps/solid_alien_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampEight, ":/Stamps/solidcolorstamps/Stamps/solid_man_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampNine, ":/Stamps/solidcolorstamps/Stamps/solid_woman_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTen, ":/Stamps/solidcolorstamps/Stamps/solid_camera_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampEleven, ":/Stamps/solidcolorstamps/Stampssolid_/mail_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwelve, ":/Stamps/solidcolorstamps/Stamps/solid_cup_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThirteen, ":/Stamps/solidcolorstamps/Stamps/solid_gift_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampFourteen, ":/Stamps/solidcolorstamps/Stamps/solid_umbrella_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampFifteen, ":/Stamps/solidcolorstamps/Stamps/solid_security_cam_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampSixteen, ":/Stamps/solidcolorstamps/Stamps/solid_wrench_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampSeventeen, ":/Stamps/solidcolorstamps/Stamps/solid_heart_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampEighteen, ":/Stamps/solidcolorstamps/Stamps/solid_airplane_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampNineteen, ":/Stamps/solidcolorstamps/Stamps/solid_helicopter_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwenty, ":/Stamps/solidcolorstamps/Stamps/solid_car_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyOne, ":/Stamps/solidcolorstamps/Stamps/solid_truck_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyTwo, ":/Stamps/solidcolorstamps/Stamps/solid_bus_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyThree, ":/Stamps/solidcolorstamps/Stamps/solid_gas_pump_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyFour, ":/Stamps/solidcolorstamps/Stamps/solid_factory_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyFive, ":/Stamps/solidcolorstamps/Stamps/solid_building_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentySix, ":/Stamps/solidcolorstamps/Stamps/solid_capitol_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentySeven, ":/Stamps/solidcolorstamps/Stamps/solid_home_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyEight, ":/Stamps/solidcolorstamps/Stamps/solid_sun_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampTwentyNine, ":/Stamps/solidcolorstamps/Stamps/solid_forest_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThirty, ":/Stamps/solidcolorstamps/Stamps/solid_tree_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThirtyOne, ":/Stamps/solidcolorstamps/Stamps/solid_cloud_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThirtyTwo, ":/Stamps/solidcolorstamps/Stamps/solid_snow_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->stampThirtyThree, ":/Stamps/solidcolorstamps/Stamps/solid_rain_stamp");
        connect(silhouetteSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(silhouetteStampClicked(const QString)));

    connect(stampsWidgetCategories->peopleButton, SIGNAL(clicked()), this, SLOT(peopleButtonClicked()));
        // People Stamps
        connect(stampsWidgetPeople->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *peopleSignalMapper = new QSignalMapper(this);
        connect(stampsWidgetPeople->stampOne, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwo, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThree, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampFour, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampFive, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampSix, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampSeven, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampEight, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampNine, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampEleven, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwelve, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThirteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampFourteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampFifteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampSixteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampSeventeen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampEighteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampNineteen, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwenty, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyOne, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyTwo, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyThree, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyFour, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyFive, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentySix, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentySeven, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyEight, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampTwentyNine, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThirty, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThirtyOne, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThirtyTwo, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));
        connect(stampsWidgetPeople->stampThirtyThree, SIGNAL(clicked()), peopleSignalMapper, SLOT(map()));


        peopleSignalMapper->setMapping(stampsWidgetPeople->stampOne, ":/Stamps/people/Stamps/people_angel_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwo, ":/Stamps/people/Stamps/people_baby_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThree, ":/Stamps/people/Stamps/people_chef_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampFour, ":/Stamps/people/Stamps/people_clown_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampFive, ":/Stamps/people/Stamps/people_dad_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampSix, ":/Stamps/people/Stamps/people_devil_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampSeven, ":/Stamps/people/Stamps/people_doctor_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampEight, ":/Stamps/people/Stamps/people_fireman_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampNine, ":/Stamps/people/Stamps/people_ghost_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTen, ":/Stamps/people/Stamps/people_girl_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampEleven, ":/Stamps/people/Stamps/people_kid_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwelve, ":/Stamps/people/Stamps/people_king_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThirteen, ":/Stamps/people/Stamps/people_knight_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampFourteen, ":/Stamps/people/Stamps/people_lawyer_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampFifteen, ":/Stamps/people/Stamps/people_leprechaun_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampSixteen, ":/Stamps/people/Stamps/people_man_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampSeventeen, ":/Stamps/people/Stamps/people_mermaid_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampEighteen, ":/Stamps/people/Stamps/people_ninja_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampNineteen, ":/Stamps/people/Stamps/people_nurse_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwenty, ":/Stamps/people/Stamps/people_pirate_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyOne, ":/Stamps/people/Stamps/people_policeman_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyTwo, ":/Stamps/people/Stamps/people_prince_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyThree, ":/Stamps/people/Stamps/people_princess_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyFour, ":/Stamps/people/Stamps/people_queen_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyFive, ":/Stamps/people/Stamps/people_robot_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentySix, ":/Stamps/people/Stamps/people_santa_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentySeven, ":/Stamps/people/Stamps/people_snowman_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyEight, ":/Stamps/people/Stamps/people_superhero_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampTwentyNine, ":/Stamps/people/Stamps/people_teacher_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThirty, ":/Stamps/people/Stamps/people_troll_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThirtyOne, ":/Stamps/people/Stamps/people_vampire_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThirtyTwo, ":/Stamps/people/Stamps/people_witch_stamp");
        peopleSignalMapper->setMapping(stampsWidgetPeople->stampThirtyThree, ":/Stamps/people/Stamps/people_zombie_stamp");
        connect(peopleSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));

    connect(stampsWidgetCategories->animalsButton, SIGNAL(clicked()), this, SLOT(animalsButtonClicked()));
        // Animals Stamps
        connect(stampsWidgetAnimals->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *animalSignalMapper = new QSignalMapper(this);
        connect(stampsWidgetAnimals->bearStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->beeStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->birdStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->bullStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->catStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->cowStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->crabStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->crocodileStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->deerStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->dogStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->donkeyStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->eagleStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->elephantStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->foxStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->giraffeStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->gorillaStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->hippoStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->horseStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->lionStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->monkeyStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->mooseStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->mouseStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->owlStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->pandaStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->penguinStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->pigStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->rabbitStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->rhinoStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->roosterStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->sheepStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->snakeStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->turkeyStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));
        connect(stampsWidgetAnimals->wolfStamp, SIGNAL(clicked()), animalSignalMapper, SLOT(map()));


        animalSignalMapper->setMapping(stampsWidgetAnimals->bearStamp, ":/Stamps/animals/Stamps/animal_bear_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->beeStamp, ":/Stamps/animals/Stamps/animal_bee_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->birdStamp, ":/Stamps/animals/Stamps/animal_bird_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->bullStamp, ":/Stamps/animals/Stamps/animal_bull_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->catStamp, ":/Stamps/animals/Stamps/animal_cat_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->cowStamp, ":/Stamps/animals/Stamps/animal_cow_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->crabStamp, ":/Stamps/animals/Stamps/animal_crab_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->crocodileStamp, ":/Stamps/animals/Stamps/animal_crocodile_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->deerStamp, ":/Stamps/animals/Stamps/animal_deer_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->dogStamp, ":/Stamps/animals/Stamps/animal_dog_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->donkeyStamp, ":/Stamps/animals/Stamps/animal_donkey_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->eagleStamp, ":/Stamps/animals/Stamps/animal_eagle_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->elephantStamp, ":/Stamps/animals/Stamps/animal_elephant_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->foxStamp, ":/Stamps/animals/Stamps/animal_fox_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->giraffeStamp, ":/Stamps/animals/Stamps/animal_giraffe_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->gorillaStamp, ":/Stamps/animals/Stamps/animal_gorilla_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->hippoStamp, ":/Stamps/animals/Stamps/animal_hippo_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->horseStamp, ":/Stamps/animals/Stamps/animal_horse_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->lionStamp, ":/Stamps/animals/Stamps/animal_lion_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->monkeyStamp, ":/Stamps/animals/Stamps/animal_monkey_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->mooseStamp, ":/Stamps/animals/Stamps/animal_moose_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->mouseStamp, ":/Stamps/animals/Stamps/animal_mouse_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->owlStamp, ":/Stamps/animals/Stamps/animal_owl_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->pandaStamp, ":/Stamps/animals/Stamps/animal_panda_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->penguinStamp, ":/Stamps/animals/Stamps/animal_penguin_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->pigStamp, ":/Stamps/animals/Stamps/animal_pig_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->rabbitStamp, ":/Stamps/animals/Stamps/animal_rabbit_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->rhinoStamp, ":/Stamps/animals/Stamps/animal_rhino_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->roosterStamp, ":/Stamps/animals/Stamps/animal_rooster_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->sheepStamp, ":/Stamps/animals/Stamps/animal_sheep_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->snakeStamp, ":/Stamps/animals/Stamps/animal_snake_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->turkeyStamp, ":/Stamps/animals/Stamps/animal_turkey_stamp");
        animalSignalMapper->setMapping(stampsWidgetAnimals->wolfStamp, ":/Stamps/animals/Stamps/animal_wolf_stamp");
        connect(animalSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));

    connect(stampsWidgetCategories->buildingsButton, SIGNAL(clicked()), this, SLOT(buildingsButtonClicked()));
        // Buildings Stamps
        connect(stampsWidgetBuildings->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *buildingsSignalMapper = new QSignalMapper(this);
        connect(stampsWidgetBuildings->homeOneStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->homeTwoStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->homeThreeStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->homeFourStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->bankStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->schoolStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->hospitalStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->skyscraperStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->buildingStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->multiplexStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->shopOneStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->shopTwoStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->shopThreeStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->shopFourStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));
        connect(stampsWidgetBuildings->castleStamp, SIGNAL(clicked()), buildingsSignalMapper, SLOT(map()));


        buildingsSignalMapper->setMapping(stampsWidgetBuildings->homeOneStamp, ":/Stamps/buildings/Stamps/buildings_home_one_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->homeTwoStamp, ":/Stamps/buildings/Stamps/buildings_home_two_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->homeThreeStamp, ":/Stamps/buildings/Stamps/buildings_home_three_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->homeFourStamp, ":/Stamps/buildings/Stamps/buildings_home_four_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->bankStamp, ":/Stamps/buildings/Stamps/buildings_bank_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->schoolStamp, ":/Stamps/buildings/Stamps/buildings_school_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->hospitalStamp, ":/Stamps/buildings/Stamps/buildings_hospital_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->skyscraperStamp, ":/Stamps/buildings/Stamps/buildings_skyscraper_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->buildingStamp, ":/Stamps/buildings/Stamps/buildings_building_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->multiplexStamp, ":/Stamps/buildings/Stamps/buildings_multiplex_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->shopOneStamp, ":/Stamps/buildings/Stamps/buildings_shop_one_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->shopTwoStamp, ":/Stamps/buildings/Stamps/buildings_shop_two_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->shopThreeStamp, ":/Stamps/buildings/Stamps/buildings_shop_three_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->shopFourStamp, ":/Stamps/buildings/Stamps/buildings_shop_four_stamp");
        buildingsSignalMapper->setMapping(stampsWidgetBuildings->castleStamp, ":/Stamps/buildings/Stamps/buildings_castle_stamp");
        connect(buildingsSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));

    connect(stampsWidgetCategories->sceneryButton, SIGNAL(clicked()), this, SLOT(sceneryButtonClicked()));
        // Scenery Stamps
        connect(stampsWidgetScenery->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *scenerySignalMapper = new QSignalMapper(this);
        connect(stampsWidgetScenery->palmTreeStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->treeOneStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->treeTwoStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->christmasTreeStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->sunStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->moonStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->cloudStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->stormyCloudStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->starsStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->balloonStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->flowerOneStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->flowerTwoStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->flowerThreeStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->bouquetStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));
        connect(stampsWidgetScenery->statueStamp, SIGNAL(clicked()), scenerySignalMapper, SLOT(map()));

        scenerySignalMapper->setMapping(stampsWidgetScenery->palmTreeStamp, ":/Stamps/scenery/Stamps/scenery_palm_tree_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->treeOneStamp, ":/Stamps/scenery/Stamps/scenery_tree_one_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->treeTwoStamp, ":/Stamps/scenery/Stamps/scenery_tree_two_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->christmasTreeStamp, ":/Stamps/scenery/Stamps/scenery_christmas_tree_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->sunStamp, ":/Stamps/scenery/Stamps/scenery_sun_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->moonStamp, ":/Stamps/scenery/Stamps/scenery_moon_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->cloudStamp, ":/Stamps/scenery/Stamps/scenery_cloud_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->stormyCloudStamp, ":/Stamps/scenery/Stamps/scenery_stormy_cloud_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->starsStamp, ":/Stamps/scenery/Stamps/scenery_stars_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->balloonStamp, ":/Stamps/scenery/Stamps/scenery_balloon_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->flowerOneStamp, ":/Stamps/scenery/Stamps/scenery_flower_one_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->flowerTwoStamp, ":/Stamps/scenery/Stamps/scenery_flower_two_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->flowerThreeStamp, ":/Stamps/scenery/Stamps/scenery_flower_three_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->bouquetStamp, ":/Stamps/scenery/Stamps/scenery_bouquet_stamp");
        scenerySignalMapper->setMapping(stampsWidgetScenery->statueStamp, ":/Stamps/scenery/Stamps/scenery_statue_stamp");
        connect(scenerySignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));

    connect(stampsWidgetCategories->facesButton, SIGNAL(clicked()), this, SLOT(facesButtonClicked()));
        // Faces Stamps
        connect(stampsWidgetFaces->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *facesSignalMapper = new QSignalMapper(this);
        connect(stampsWidgetFaces->stampOne, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwo, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampThree, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampFour, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampFive, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampSix, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampSeven, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampEight, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampNine, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampEleven, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwelve, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampThirteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampFourteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampFifteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampSixteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampSeventeen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampEighteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampNineteen, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwenty, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyOne, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyTwo, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyThree, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyFour, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyFive, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentySix, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentySeven, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyEight, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampTwentyNine, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampThirty, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampThirtyOne, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));
        connect(stampsWidgetFaces->stampThirtyTwo, SIGNAL(clicked()), facesSignalMapper, SLOT(map()));


        facesSignalMapper->setMapping(stampsWidgetFaces->stampOne, ":/Stamps/faces/Stamps/faces_one_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwo, ":/Stamps/faces/Stamps/faces_two_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampThree, ":/Stamps/faces/Stamps/faces_three_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampFour, ":/Stamps/faces/Stamps/faces_four_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampFive, ":/Stamps/faces/Stamps/faces_five_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampSix, ":/Stamps/faces/Stamps/faces_six_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampSeven, ":/Stamps/faces/Stamps/faces_seven_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampEight, ":/Stamps/faces/Stamps/faces_eight_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampNine, ":/Stamps/faces/Stamps/faces_nine_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTen, ":/Stamps/faces/Stamps/faces_ten_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampEleven, ":/Stamps/faces/Stamps/faces_eleven_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwelve, ":/Stamps/faces/Stamps/faces_twelve_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampThirteen, ":/Stamps/faces/Stamps/faces_thirteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampFourteen, ":/Stamps/faces/Stamps/faces_fourteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampFifteen, ":/Stamps/faces/Stamps/faces_fifteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampSixteen, ":/Stamps/faces/Stamps/faces_sixteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampSeventeen, ":/Stamps/faces/Stamps/faces_seventeen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampEighteen, ":/Stamps/faces/Stamps/faces_eighteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampNineteen, ":/Stamps/faces/Stamps/faces_nineteen_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwenty, ":/Stamps/faces/Stamps/faces_twenty_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyOne, ":/Stamps/faces/Stamps/faces_twentyone_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyTwo, ":/Stamps/faces/Stamps/faces_twentytwo_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyThree, ":/Stamps/faces/Stamps/faces_twentythree_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyFour, ":/Stamps/faces/Stamps/faces_twentyfour_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyFive, ":/Stamps/faces/Stamps/faces_twentyfive_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentySix, ":/Stamps/faces/Stamps/faces_twentysix_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentySeven, ":/Stamps/faces/Stamps/faces_twentyseven_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyEight, ":/Stamps/faces/Stamps/faces_twentyeight_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampTwentyNine, ":/Stamps/faces/Stamps/faces_twentynine_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampThirty, ":/Stamps/faces/Stamps/faces_thirty_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampThirtyOne, ":/Stamps/faces/Stamps/faces_thirtyone_stamp");
        facesSignalMapper->setMapping(stampsWidgetFaces->stampThirtyTwo, ":/Stamps/faces/Stamps/faces_thirtytwo_stamp");
        connect(facesSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(silhouetteStampClicked(const QString)));

    connect(stampsWidgetCategories->vehiclesButton, SIGNAL(clicked()), this, SLOT(vehiclesButtonClicked()));
        // Vehicle Stamps
        connect(stampsWidgetVehicles->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper *vehiclesSignalMapper = new QSignalMapper(this);
        connect(stampsWidgetVehicles->stampOne, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwo, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampThree, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampFour, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampFive, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampSix, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampSeven, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampEight, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampNine, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampEleven, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwelve, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampThirteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampFourteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampFifteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampSixteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampSeventeen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampEighteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampNineteen, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwenty, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwentyOne, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwentyTwo, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwentyThree, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwentyFour, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));
        connect(stampsWidgetVehicles->stampTwentyFive, SIGNAL(clicked()), vehiclesSignalMapper, SLOT(map()));


        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampOne, ":/Stamps/vehicles/Stamps/vehicles_one_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwo, ":/Stamps/vehicles/Stamps/vehicles_two_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampThree, ":/Stamps/vehicles/Stamps/vehicles_three_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampFour, ":/Stamps/vehicles/Stamps/vehicles_four_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampFive, ":/Stamps/vehicles/Stamps/vehicles_five_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampSix, ":/Stamps/vehicles/Stamps/vehicles_six_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampSeven, ":/Stamps/vehicles/Stamps/vehicles_seven_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampEight, ":/Stamps/vehicles/Stamps/vehicles_eight_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampNine, ":/Stamps/vehicles/Stamps/vehicles_nine_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTen, ":/Stamps/vehicles/Stamps/vehicles_ten_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampEleven, ":/Stamps/vehicles/Stamps/vehicles_eleven_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwelve, ":/Stamps/vehicles/Stamps/vehicles_twelve_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampThirteen, ":/Stamps/vehicles/Stamps/vehicles_thirteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampFourteen, ":/Stamps/vehicles/Stamps/vehicles_fourteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampFifteen, ":/Stamps/vehicles/Stamps/vehicles_fifteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampSixteen, ":/Stamps/vehicles/Stamps/vehicles_sixteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampSeventeen, ":/Stamps/vehicles/Stamps/vehicles_seventeen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampEighteen, ":/Stamps/vehicles/Stamps/vehicles_eighteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampNineteen, ":/Stamps/vehicles/Stamps/vehicles_nineteen_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwenty, ":/Stamps/vehicles/Stamps/vehicles_twenty_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwentyOne, ":/Stamps/vehicles/Stamps/vehicles_twentyone_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwentyTwo, ":/Stamps/vehicles/Stamps/vehicles_twentytwo_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwentyThree, ":/Stamps/vehicles/Stamps/vehicles_twentythree_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwentyFour, ":/Stamps/vehicles/Stamps/vehicles_twentyfour_stamp");
        vehiclesSignalMapper->setMapping(stampsWidgetVehicles->stampTwentyFive, ":/Stamps/vehicles/Stamps/vehicles_twentyfive_stamp");
        connect(vehiclesSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));


    //Canvas
    canvas = new Canvas(undoStack);

    //Application Layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(prompt);

    int size = popUps.size();
    for(int i = 0; i < size; ++i) {
        vLayout->addWidget(popUps[i]);
    }

    vLayout->addWidget(canvas);
    this->centralWidget()->setLayout(vLayout);

    hideWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setToolButtonProperties(QToolButton &b)
{
    b.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->mainToolBar->addWidget(&b);
}

void MainWindow::hideWidgets()
{
    int size = popUps.size();
    for(int i = 0; i < size; ++i) {
        popUps[i]->hide();
    }
}

void MainWindow::settingsButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    prompt->promptLabel->setText("Adjust the button size");
    settingsWidgetButtonSize->show();
}

//Toolbar
void MainWindow::newButtonClicked()
{
    canvas->resetDrawState();
    MainWindow *newApplication;
    newApplication = new MainWindow();
    newApplication -> show();
}

void MainWindow::openButtonClicked()
{
    canvas->resetDrawState();
    QMessageBox::information(this, "title", "Open");
    QString s = QFileDialog::getOpenFileName(
                    0,
                    "Open File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->loadScene(s);
}

void MainWindow::saveButtonClicked()
{
    canvas->resetDrawState();
    QMessageBox::information(this, "title", "Save");
    QString s = QFileDialog::getSaveFileName(
                    0,
                    "Save File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->saveScene(s);
}

void MainWindow::undoButtonClicked()
{
    canvas->resetDrawState();
    QMessageBox::information(this, "title", "Undo");
    undoStack->undo();
}

void MainWindow::cursorButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    canvas->drawState = canvas->CURSOR;
    canvas->cursorState = canvas->NOCURSOR;
    prompt->promptLabel->setText("Click a cursor type");
    cursorWidgetCursors->show();
}

void MainWindow::colorsButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    prompt->promptLabel->setText("Select a paint tool to modify");
    colorsWidgetPaintTools->show();
}

void MainWindow::shapesButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    canvas->drawState = canvas->SHAPE;
    canvas->shapeState = canvas->NOSHAPE;

    prompt->promptLabel->setText("Select a shape");
    shapesWidgetShapes->show();
}

void MainWindow::stampsButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    canvas->drawState = canvas->STAMP;

    prompt->promptLabel->setText("Select a stamp category:");
    stampsWidgetCategories->show();

}

void MainWindow::brushEffectsButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    canvas->drawState = canvas->BRUSHEFFECTS;

    prompt->promptLabel->setText("Select a brush effect");
    brushEffectsWidgetBrushEffects->show();
}

void MainWindow::drawButtonClicked()
{
    hideWidgets();
    canvas->resetDrawState();
    //canvas->drawState = canvas->DRAW;

    prompt->promptLabel->setText("Click on the canvas to start drawing. Click a second time on the canvas to end drawing.");
}

void MainWindow::eraserButtonClicked()
{
    QMessageBox::information(this, "title", "Eraser");
    canvas->resetDrawState();
}

void MainWindow::insertPictureButtonClicked()
{
    QMessageBox::information(this, "title", "Insert Picture");
    canvas->resetDrawState();
}



//Settings--------------------------------------------------------
void MainWindow::bwn5ButtonClicked()
{
    if(buttonWidth - 5 >= 60) {
        buttonWidth -= 5;
    }
    changeButtonProperties(buttonWidth,buttonHeight);
}

void MainWindow::bwp5ButtonClicked()
{
    buttonWidth += 5;
    changeButtonProperties(buttonWidth,buttonHeight);
}

void MainWindow::bhn5ButtonClicked()
{
    if(buttonHeight - 5 >= 60) {
        buttonHeight -= 5;
    }
    changeButtonProperties(buttonWidth,buttonHeight);
}

void MainWindow::bhp5ButtonClicked()
{
    buttonHeight += 5;
    changeButtonProperties(buttonWidth,buttonHeight);
}

//Cursor--------------------------------------------------------
void MainWindow::cursorBackButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->NOCURSOR;
    prompt->promptLabel->setText("Select a cursor type");
    cursorWidgetCursors->show();
}

void MainWindow::translateButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->TRANSLATE;
    prompt->promptLabel->setText("Select a translation value.  Then click an item on the canvas to change its properties");
    cursorWidgetTranslate->show();
}

void MainWindow::scaleButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->SCALE;
    prompt->promptLabel->setText("Select a scale factor.  Then click an item on the canvas to change its properties");
    cursorWidgetScale->show();
}

void MainWindow::rotateButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->ROTATE;
    prompt->promptLabel->setText("Select a rotation angle.  Then click an item on the canvas to change its properties");
    cursorWidgetRotate->show();
}

void MainWindow::shearButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->SHEAR;
    prompt->promptLabel->setText("Select a shear angle.  Then click an item on the canvas to change its properties");
    cursorWidgetShear->show();
}

void MainWindow::stretchButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->STRETCH;
    prompt->promptLabel->setText("Select a stretch value.  Then click an item on the canvas to change its properties");
    cursorWidgetStretch->show();
}

void MainWindow::depthButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->DEPTH;
    prompt->promptLabel->setText("Select a depth value.  Then click an item on the canvas to change its properties");
    cursorWidgetDepth->show();
}

void MainWindow::copyButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->COPY;
    prompt->promptLabel->setText("Click an item on the canvas to copy");
    cursorWidgetBack->show();
}

void MainWindow::deleteButtonClicked()
{
     hideWidgets();
     canvas->cursorState = canvas->DELETEITEM;
     prompt->promptLabel->setText("Click an item on the canvas to delete");
     cursorWidgetBack->show();
}
//Translate
void MainWindow::translateSignButtonClicked()
{
    canvas->translateSignPositive = !(canvas->translateSignPositive);
    cursorWidgetTranslate->toggleSign(canvas->translateSignPositive);
}

void MainWindow::translateDirectionButtonClicked()
{
    canvas->translateDirectionHorizontal = !(canvas->translateDirectionHorizontal);
    cursorWidgetTranslate->toggleDirection(canvas->translateDirectionHorizontal);
}

void MainWindow::translateValueButtonClicked(int v)
{
    canvas->resetTranslateStretchShear();
    changeTranslateValue(v);
}

//Scale
void MainWindow::scaleSignButtonClicked()
{
    canvas->scaleSignPositive = !(canvas->scaleSignPositive);
    cursorWidgetScale->toggleSign(canvas->scaleSignPositive);
}

void MainWindow::scaleResetButtonClicked()
{
    canvas->scaleFactor = -1.0;
}

void MainWindow::scaleValueButtonClicked(int v)
{
    canvas->scaleFactor = ((double)v)/1000.0;
}

void MainWindow::stretchSignButtonClicked()
{
    canvas->stretchSignPositive = !(canvas->stretchSignPositive);
    cursorWidgetStretch->toggleSign(canvas->stretchSignPositive);
}

void MainWindow::stretchDirectionButtonClicked()
{
    canvas->stretchDirectionHorizontal = !(canvas->stretchDirectionHorizontal);
    cursorWidgetStretch->toggleDirection(canvas->stretchDirectionHorizontal);
}

void MainWindow::stretchValueButtonClicked(int v)
{
    canvas->resetTranslateStretchShear();
    changeStretchValue(((double)v)/1000.0);
}

void MainWindow::rotateSignButtonClicked()
{
    canvas->rotateSignPositive = !(canvas->rotateSignPositive);
    cursorWidgetRotate->toggleSign(canvas->rotateSignPositive);
}

void MainWindow::reset0ButtonClicked()
{
    canvas->rotateAngle = -1.0;
}

void MainWindow::rotateValueButtonClicked(int v)
{
    canvas->rotateAngle = ((double)v)/10.0;
}

void MainWindow::shearSignButtonClicked()
{
    canvas->shearSignPositive = !(canvas->shearSignPositive);
    cursorWidgetShear->toggleSign(canvas->shearSignPositive);
}

void MainWindow::shearDirectionButtonClicked()
{
    canvas->shearDirectionHorizontal = !(canvas->shearDirectionHorizontal);
    cursorWidgetShear->toggleDirection(canvas->shearDirectionHorizontal);
}

void MainWindow::shearValueButtonClicked(int v)
{
    canvas->resetTranslateStretchShear();
    changeShearValue(((double)v)/1000.0);
}

void MainWindow::dp1ButtonClicked()
{
    QMessageBox::information(this, "title", "dp");
    canvas->depthPositive = true;
}

void MainWindow::dn1ButtonClicked()
{
    QMessageBox::information(this, "title", "dn");
    canvas->depthPositive = false;
}

//Shapes
void MainWindow::lineButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->LINE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)First endpoint 2)Second endpoint"));
}

void MainWindow::pointButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->POINT;
    prompt->promptLabel->setText(tr("Click one point on the canvas"));
}

void MainWindow::circleButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->CIRCLE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::rectangleButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->RECT;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::roundedRectangleButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->ROUNDRECT;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::polygonButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->POLYGON;
    prompt->promptLabel->setText(tr("Click points on the canvas to be your polygon path and click the 'end path' button to draw the polygon"));
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->show();
}

void MainWindow::arcButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->ARC;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::chordButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->CHORD;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::pieButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->PIE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::pathButtonClicked()
{
    canvas->resetShapeState();
    canvas->shapeState = canvas->PATH;
    prompt->promptLabel->setText(tr("Click points on the canvas to be your path and click the 'end path' button to draw the path"));
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->show();
}

void MainWindow::textButtonClicked()
{
    QMessageBox::information(this, "title", "Text");
}

void MainWindow::shapesBackButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    canvas->shapeState = canvas->NOSHAPE;
    prompt->promptLabel->setText("Select a shape");
    shapesWidgetShapes->show();
}

void MainWindow::endPathButtonClicked()
{
    QPolygonF polygon;
    for(int i = 0; i < canvas->mousePressCount; i++){
        polygon << canvas->points[i];
    }
    if(canvas->shapeState == canvas->POLYGON) {
        QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(polygon);
        polygonItem->setPen(*(canvas->pen));
        polygonItem->setBrush(*(canvas->brush));
        canvas->drawItem(polygonItem);
    } else if(canvas->shapeState == canvas->PATH) {
        PathItem *pathItem = new PathItem(polygon,canvas->points,*(canvas->pen),*(canvas->brush));
        canvas->drawItem(pathItem);
    } else {
    }

    update();
}

void MainWindow::outlineButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a color");
    canvas->colorState = canvas->OUTLINE;
    colorsWidgetColors->show();
}

void MainWindow::fillButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a color");
    canvas->colorState = canvas->FILL;
    colorsWidgetColors->show();
}

void MainWindow::brushButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a color");
    canvas->colorState = canvas->BRUSH;
    colorsWidgetColors->show();
}

void MainWindow::backgroundButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a color");
    canvas->colorState = canvas->BACKGROUND;
    colorsWidgetColors->show();
}

void MainWindow::colorsBackButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a paint tool to modify");
    colorsWidgetPaintTools->show();
}

void MainWindow::peachButtonClicked()
{
    changePaintToolColor(QColor(255,239,213));
}

void MainWindow::pinkButtonClicked()
{
    changePaintToolColor(QColor(255,102,178));
}

void MainWindow::redButtonClicked()
{
    changePaintToolColor(QColor(255,51,51));
}

void MainWindow::orangeButtonClicked()
{
    changePaintToolColor(QColor(255,128,0));
}

void MainWindow::yellowButtonClicked()
{
    changePaintToolColor(QColor(255,255,51));
}

void MainWindow::greenButtonClicked()
{
    changePaintToolColor(QColor(102,204,0));
}

void MainWindow::blueButtonClicked()
{
    changePaintToolColor(QColor(0,128,255));
}

void MainWindow::purpleButtonClicked()
{
    changePaintToolColor(QColor(153,51,255));
}

void MainWindow::brownButtonClicked()
{
    changePaintToolColor(QColor(102,51,0));
}

void MainWindow::blackButtonClicked()
{
    changePaintToolColor(QColor(0,0,0));
}

void MainWindow::grayButtonClicked()
{
    changePaintToolColor(QColor(192,192,192));
}

void MainWindow::whiteButtonClicked()
{
    changePaintToolColor(QColor(255,255,255));
}

void MainWindow::customColorButtonClicked()
{
    QMessageBox::information(this, "title", "custom");
}

void MainWindow::outlinSizesBackButtonClicked()
{
    QMessageBox::information(this, "title", "back colors");
}

void MainWindow::on1ButtonClicked()
{
    canvas->setPenWidth(-1);
}

void MainWindow::op1ButtonClicked()
{
    canvas->setPenWidth(1);
}

void MainWindow::paintButtonClicked()
{
    QMessageBox::information(this, "title", "paint");
    canvas->brushEffectsState = canvas->PAINT;
}

void MainWindow::waterColorButtonClicked()
{
    QMessageBox::information(this, "title", "water color");
    canvas->brushEffectsState = canvas->WATERCOLOR;
}

void MainWindow::calligraphyButtonClicked()
{
    QMessageBox::information(this, "title", "calligraphy");
    canvas->brushEffectsState = canvas->CALLIGRAPHY;
}

void MainWindow::pencilButtonClicked()
{
    QMessageBox::information(this, "title", "pencil");
    canvas->brushEffectsState = canvas->PENCIL;
}

void MainWindow::sprayPaintButtonClicked()
{
    enum BrushEffectsState {NOBRUSH,PAINT,WATERCOLOR,CALLIGRAPHY,PENCIL,SPRAYPAINT};
    canvas->brushEffectsState = canvas->SPRAYPAINT;
}


// STAMPS
void MainWindow::silhouetteButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp. The color tool can be used as well:");
    stampsWidgetSilhouette->show();
}
void MainWindow::peopleButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    stampsWidgetPeople->show();
}

void MainWindow::animalsButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    stampsWidgetAnimals->show();
}
void MainWindow::buildingsButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    stampsWidgetBuildings->show();
}
void MainWindow::sceneryButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    stampsWidgetScenery->show();
}
void MainWindow::facesButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp. The color tool can be used as well:");
    stampsWidgetFaces->show();
}

void MainWindow::vehiclesButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    stampsWidgetVehicles->show();
}

// STAMPS ACTIONS
void MainWindow::goBackButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a stamp category:");
    stampsWidgetCategories->show();
}
void MainWindow::silhouetteStampClicked(const QString stamp_name)
{
    QString stamp_path = stamp_name;
    stamp_path.append(".png");
    canvas->stampState = canvas->SILHOUETTE;
    canvas->setCurrentStamp(stamp_path);
}
void MainWindow::standardStampClicked(const QString stamp_name)
{
    QString stamp_path = stamp_name;
    stamp_path.append(".png");
    canvas->stampState = canvas->STANDARD;
    canvas->setCurrentStamp(stamp_path);
}

void MainWindow::changeButtonProperties(const int &newButtonWidth,const int &newButtonHeight)
{
    int size = popUps.size();
    for(int i = 0; i < size; ++i) {
        popUps[i]->changeButtonProperties(newButtonWidth, newButtonHeight);
    }
}

void MainWindow::changeTranslateValue(int v)
{
    if(canvas->translateSignPositive) {
        if(canvas->translateDirectionHorizontal) {
            canvas->translateHorizontalValue += v;
        } else {
            canvas->translateVerticalValue -= v;
        }
    } else {
        if(canvas->translateDirectionHorizontal) {
            canvas->translateHorizontalValue -= v;
        } else {
            canvas->translateVerticalValue += v;
        }
    }
}

void MainWindow::changeStretchValue(double v)
{
    if(canvas->stretchSignPositive) {
        if(canvas->stretchDirectionHorizontal) {
            canvas->stretchHorizontalValue += v;
        } else {
            canvas->stretchVerticalValue += v;
        }
    } else {
        if(canvas->stretchDirectionHorizontal) {
            if(canvas->stretchHorizontalValue - v >= 0.01) {
                canvas->stretchHorizontalValue -= v;
            }
        } else {
            if(canvas->stretchVerticalValue - v >= 0.01) {
                canvas->stretchVerticalValue -= v;
            }
        }
    }
}

void MainWindow::changeShearValue(double v)
{
    if(canvas->shearSignPositive) {
        if(canvas->shearDirectionHorizontal) {
            canvas->shearHorizontalValue += v;
        } else {
            canvas->shearVerticalValue += v;
        }
    } else {
        if(canvas->shearDirectionHorizontal) {
            canvas->shearHorizontalValue -= v;
        } else {
            canvas->shearVerticalValue -= v;
        }
    }
}

void MainWindow::changePaintToolColor(QColor color)
{

    switch (canvas->colorState) {
        case canvas->OUTLINE:
            hideWidgets();
            canvas->setPenColor(color);
            colorsWidgetOutlineSizes->show();
            break;
        case canvas->FILL:
            canvas->setBrushColor(color);
            break;
        case canvas->BRUSH:
            break;
        case canvas->BACKGROUND:
            canvas->setBackgroundBrush(color);
            break;
        default:
            break;
    }
}
