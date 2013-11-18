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

    dim = 60;

    //Toolbar
    ui->mainToolBar->setIconSize(QSize(dim,dim));

    newButton = new QToolButton;
    newButton->setIcon(QIcon(":/Icons/Icons/new.png"));
    newButton->setText("New");
    setToolButtonProperties(newButton);
    connect(newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));

    openButton = new QToolButton;
    openButton->setIcon(QIcon(":/Icons/Icons/open.png"));
    openButton->setText("Open");
    setToolButtonProperties(openButton);
    connect(openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));

    saveButton = new QToolButton;
    saveButton->setIcon(QIcon(":/Icons/Icons/save.png"));
    saveButton->setText("Save");
    setToolButtonProperties(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));

    undoButton = new QToolButton;
    undoButton->setIcon(QIcon(":/Icons/Icons/undo.png"));
    undoButton->setText("Undo");
    setToolButtonProperties(undoButton);
    connect(undoButton, SIGNAL(clicked()), this, SLOT(undoButtonClicked()));

    cursorButton = new QToolButton;
    cursorButton->setIcon(QIcon(":/Icons/Icons/cursor.png"));
    cursorButton->setText("Cursor");
    setToolButtonProperties(cursorButton);
    connect(cursorButton, SIGNAL(clicked()), this, SLOT(cursorButtonClicked()));

    colorsButton = new QToolButton;
    colorsButton->setIcon(QIcon(":/Icons/Icons/colors.png"));
    colorsButton->setText("Colors");
    setToolButtonProperties(colorsButton);
    connect(colorsButton, SIGNAL(clicked()), this, SLOT(colorsButtonClicked()));

    shapesButton = new QToolButton;
    shapesButton->setIcon(QIcon(":/Icons/Icons/shapes.png"));
    shapesButton->setText("Shapes");
    setToolButtonProperties(shapesButton);
    connect(shapesButton, SIGNAL(clicked()), this, SLOT(shapesButtonClicked()));

    stampsButton = new QToolButton;
    stampsButton->setIcon(QIcon(":/Icons/Icons/stamps.png"));
    stampsButton->setText("Stamps");
    setToolButtonProperties(stampsButton);
    connect(stampsButton, SIGNAL(clicked()), this, SLOT(stampsButtonClicked()));

    brushEffectsButton = new QToolButton;
    brushEffectsButton->setIcon(QIcon(":/Icons/Icons/brushEffects.png"));
    brushEffectsButton->setText("Brush Effects");
    setToolButtonProperties(brushEffectsButton);
    connect(brushEffectsButton, SIGNAL(clicked()), this, SLOT(brushEffectsButtonClicked()));

    drawButton = new QToolButton;
    drawButton->setIcon(QIcon(":/Icons/Icons/draw.png"));
    drawButton->setText("Draw");
    setToolButtonProperties(drawButton);
    connect(drawButton, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));

    eraserButton = new QToolButton;
    eraserButton->setIcon(QIcon(":/Icons/Icons/eraser.png"));
    eraserButton->setText("Eraser");
    setToolButtonProperties(eraserButton);
    connect(eraserButton, SIGNAL(clicked()), this, SLOT(eraserButtonClicked()));

    insertPictureButton = new QToolButton;
    insertPictureButton->setIcon(QIcon(":/Icons/Icons/insertPicture.png"));
    insertPictureButton->setText("Insert Picture");
    setToolButtonProperties(insertPictureButton);
    connect(insertPictureButton, SIGNAL(clicked()), this, SLOT(insertPictureButtonClicked()));

    closeButton = new QToolButton;
    closeButton->setIcon(QIcon(":/Icons/Icons/close.png"));
    closeButton->setText("Close");
    setToolButtonProperties(closeButton);
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    undoStack = new QUndoStack();

//Tool Widgets
    //Prompt
    prompt = new Prompt();
//Cursor
    cursorWidgetTranslate = new CursorWidgetTranslate();
    cursorWidgetScale = new CursorWidgetScale();
    cursorWidgetRotate = new CursorWidgetRotate();
    cursorWidgetShear = new CursorWidgetShear();
    cursorWidgetStretch = new CursorWidgetStretch();
    //Translate
    connect(cursorWidgetTranslate->scaleButton, SIGNAL(clicked()), this, SLOT(scaleButtonClicked()));
    connect(cursorWidgetTranslate->stretchButton, SIGNAL(clicked()), this, SLOT(stretchButtonClicked()));
    connect(cursorWidgetTranslate->rotateButton, SIGNAL(clicked()), this, SLOT(rotateButtonClicked()));
    connect(cursorWidgetTranslate->shearButton, SIGNAL(clicked()), this, SLOT(shearButtonClicked()));

    connect(cursorWidgetTranslate->signButton, SIGNAL(clicked()), this, SLOT(translateSignButtonClicked()));
    connect(cursorWidgetTranslate->directionButton, SIGNAL(clicked()), this, SLOT(translateDirectionButtonClicked()));
    connect(cursorWidgetTranslate->t05Button, SIGNAL(clicked()), this, SLOT(t05ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t1Button, SIGNAL(clicked()), this, SLOT(t1ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t5Button, SIGNAL(clicked()), this, SLOT(t5ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t10Button, SIGNAL(clicked()), this, SLOT(t10ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t20Button, SIGNAL(clicked()), this, SLOT(t20ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t50Button, SIGNAL(clicked()), this, SLOT(t50ButtonButtonClicked()));
    connect(cursorWidgetTranslate->t100Button, SIGNAL(clicked()), this, SLOT(t100ButtonButtonClicked()));

    //Scale
    connect(cursorWidgetScale->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonClicked()));
    connect(cursorWidgetScale->stretchButton, SIGNAL(clicked()), this, SLOT(stretchButtonClicked()));
    connect(cursorWidgetScale->rotateButton, SIGNAL(clicked()), this, SLOT(rotateButtonClicked()));
    connect(cursorWidgetScale->shearButton, SIGNAL(clicked()), this, SLOT(shearButtonClicked()));

    connect(cursorWidgetScale->signButton, SIGNAL(clicked()), this, SLOT(scaleSignButtonClicked()));
    connect(cursorWidgetScale->sResetButton, SIGNAL(clicked()), this, SLOT(scaleResetButtonClicked()));
    connect(cursorWidgetScale->s05Button, SIGNAL(clicked()), this, SLOT(s05ButtonClicked()));
    connect(cursorWidgetScale->s1Button, SIGNAL(clicked()), this, SLOT(s1ButtonClicked()));
    connect(cursorWidgetScale->s5Button, SIGNAL(clicked()), this, SLOT(s5ButtonClicked()));
    connect(cursorWidgetScale->s10Button, SIGNAL(clicked()), this, SLOT(s10ButtonClicked()));
    connect(cursorWidgetScale->s20Button, SIGNAL(clicked()), this, SLOT(s20ButtonClicked()));
    connect(cursorWidgetScale->s50Button, SIGNAL(clicked()), this, SLOT(s50ButtonClicked()));
    connect(cursorWidgetScale->s100Button, SIGNAL(clicked()), this, SLOT(s100ButtonClicked()));
    //Stretch
    connect(cursorWidgetStretch->scaleButton, SIGNAL(clicked()), this, SLOT(scaleButtonClicked()));
    connect(cursorWidgetStretch->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonClicked()));
    connect(cursorWidgetStretch->rotateButton, SIGNAL(clicked()), this, SLOT(rotateButtonClicked()));
    connect(cursorWidgetStretch->shearButton, SIGNAL(clicked()), this, SLOT(shearButtonClicked()));

    connect(cursorWidgetStretch->signButton, SIGNAL(clicked()), this, SLOT(stretchSignButtonClicked()));
    connect(cursorWidgetStretch->directionButton, SIGNAL(clicked()), this, SLOT(stretchDirectionButtonClicked()));
    connect(cursorWidgetStretch->st05Button, SIGNAL(clicked()), this, SLOT(st05ButtonButtonClicked()));
    connect(cursorWidgetStretch->st1Button, SIGNAL(clicked()), this, SLOT(st1ButtonButtonClicked()));
    //Rotate
    connect(cursorWidgetRotate->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonClicked()));
    connect(cursorWidgetRotate->scaleButton, SIGNAL(clicked()), this, SLOT(scaleButtonClicked()));
    connect(cursorWidgetRotate->stretchButton, SIGNAL(clicked()), this, SLOT(stretchButtonClicked()));
    connect(cursorWidgetRotate->shearButton, SIGNAL(clicked()), this, SLOT(shearButtonClicked()));
    connect(cursorWidgetRotate->signButton, SIGNAL(clicked()), this, SLOT(rotateSignButtonClicked()));

    connect(cursorWidgetRotate->reset0Button, SIGNAL(clicked()), this, SLOT(reset0ButtonClicked()));
    connect(cursorWidgetRotate->r01Button, SIGNAL(clicked()), this, SLOT(r01ButtonClicked()));
    connect(cursorWidgetRotate->r05Button, SIGNAL(clicked()), this, SLOT(r05ButtonClicked()));
    connect(cursorWidgetRotate->r1Button, SIGNAL(clicked()), this, SLOT(r1ButtonClicked()));
    connect(cursorWidgetRotate->r5Button, SIGNAL(clicked()), this, SLOT(r5ButtonClicked()));
    connect(cursorWidgetRotate->r10Button, SIGNAL(clicked()), this, SLOT(r10ButtonClicked()));
    connect(cursorWidgetRotate->r20Button, SIGNAL(clicked()), this, SLOT(r20ButtonClicked()));
    connect(cursorWidgetRotate->r30Button, SIGNAL(clicked()), this, SLOT(r30ButtonClicked()));
    connect(cursorWidgetRotate->r45Button, SIGNAL(clicked()), this, SLOT(r45ButtonClicked()));
    connect(cursorWidgetRotate->r60Button, SIGNAL(clicked()), this, SLOT(r60ButtonClicked()));
    connect(cursorWidgetRotate->r72Button, SIGNAL(clicked()), this, SLOT(r72ButtonClicked()));
    connect(cursorWidgetRotate->r90Button, SIGNAL(clicked()), this, SLOT(r90ButtonClicked()));
    connect(cursorWidgetRotate->r120Button, SIGNAL(clicked()), this, SLOT(r120ButtonClicked()));
    connect(cursorWidgetRotate->r180Button, SIGNAL(clicked()), this, SLOT(r180ButtonClicked()));
    connect(cursorWidgetRotate->r270Button, SIGNAL(clicked()), this, SLOT(r270ButtonClicked()));
    //Shear
    connect(cursorWidgetShear->scaleButton, SIGNAL(clicked()), this, SLOT(scaleButtonClicked()));
    connect(cursorWidgetShear->stretchButton, SIGNAL(clicked()), this, SLOT(stretchButtonClicked()));
    connect(cursorWidgetShear->rotateButton, SIGNAL(clicked()), this, SLOT(rotateButtonClicked()));
    connect(cursorWidgetShear->translateButton, SIGNAL(clicked()), this, SLOT(translateButtonClicked()));

    connect(cursorWidgetShear->signButton, SIGNAL(clicked()), this, SLOT(shearSignButtonClicked()));
    connect(cursorWidgetShear->directionButton, SIGNAL(clicked()), this, SLOT(shearDirectionButtonClicked()));
    connect(cursorWidgetShear->sh1Button, SIGNAL(clicked()), this, SLOT(sh1ButtonButtonClicked()));
    //Shapes
    shapesWidgetShapes = new ShapesWidgetShapes();
    connect(shapesWidgetShapes->previousShapeButton, SIGNAL(clicked()), this, SLOT(previousShapeButtonClicked()));
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

    shapesWidgetEndPath = new ShapesWidgetEndPath();
    connect(shapesWidgetEndPath->endPathButton, SIGNAL(clicked()), this, SLOT(endPathButtonClicked()));

    //Brush Effects
    brushEffectsWidgetBrushEffects = new BrushEffectsWidgetBrushEffects();
    connect(brushEffectsWidgetBrushEffects->paintButton, SIGNAL(clicked()), this, SLOT(paintButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->waterColorButton, SIGNAL(clicked()), this, SLOT(waterColorButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->calligraphyButton, SIGNAL(clicked()), this, SLOT(calligraphyButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->pencilButton, SIGNAL(clicked()), this, SLOT(pencilButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->sprayPaintButton, SIGNAL(clicked()), this, SLOT(sprayPaintButtonClicked()));

    //Stamps
    stampsWidgetCategories = new StampsWidgetCategories();
    stampsWidgetSilhouette = new StampsWidgetSilhouette();
    stampsWidgetPeople = new StampsWidgetPeople();
    stampsWidgetAnimals = new StampsWidgetAnimals();
    stampsWidgetBuildings = new StampsWidgetBuildings();
    stampsWidgetScenery = new StampsWidgetScenery();
    stampsWidgetFaces = new StampsWidgetFaces();
    stampsWidgetVehicles = new StampsWidgetVehicles();

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
        connect(vehiclesSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(standardStampClicked(const QString)));


    //Canvas
    canvas = new Canvas(undoStack);

    //Application Layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(prompt);
    vLayout->addWidget(cursorWidgetTranslate);
    vLayout->addWidget(cursorWidgetRotate);
    vLayout->addWidget(cursorWidgetShear);
    vLayout->addWidget(cursorWidgetScale);
    vLayout->addWidget(cursorWidgetStretch);
    vLayout->addWidget(shapesWidgetShapes);
    vLayout->addWidget(shapesWidgetEndPath);
    vLayout->addWidget(brushEffectsWidgetBrushEffects);
    vLayout->addWidget(stampsWidgetCategories);
    vLayout->addWidget(stampsWidgetSilhouette);
    vLayout->addWidget(stampsWidgetPeople);
    vLayout->addWidget(stampsWidgetAnimals);
    vLayout->addWidget(stampsWidgetBuildings);
    vLayout->addWidget(stampsWidgetScenery);
    vLayout->addWidget(stampsWidgetFaces);
    vLayout->addWidget(stampsWidgetVehicles);
    vLayout->addWidget(canvas);
    this->centralWidget()->setLayout(vLayout);

    hideWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setToolButtonProperties(QToolButton *b)
{
    b->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->mainToolBar->addWidget(b);
}

void MainWindow::hideWidgets()
{
    cursorWidgetTranslate->hide();
    cursorWidgetScale->hide();
    cursorWidgetStretch->hide();
    cursorWidgetRotate->hide();
    cursorWidgetShear->hide();
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->hide();
    brushEffectsWidgetBrushEffects->hide();

    stampsWidgetCategories->hide();
    stampsWidgetSilhouette->hide();
    stampsWidgetPeople->hide();
    stampsWidgetAnimals->hide();
    stampsWidgetBuildings->hide();
    stampsWidgetScenery->hide();
    stampsWidgetFaces->hide();
    stampsWidgetVehicles->hide();

}

//Toolbar
void MainWindow::newButtonClicked()
{
    QMessageBox::information(this, "title", "New");
    MainWindow *newApplication;
    newApplication = new MainWindow();
    newApplication -> show();
}

void MainWindow::openButtonClicked()
{
    QString s = QFileDialog::getOpenFileName(
                    0,
                    "Open File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->loadScene(s);
}

void MainWindow::saveButtonClicked()
{
    QString s = QFileDialog::getSaveFileName(
                    0,
                    "Save File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->saveScene(s);
}

void MainWindow::undoButtonClicked()
{
    undoStack->undo();
}

void MainWindow::cursorButtonClicked()
{
    hideWidgets();
    canvas->drawState = canvas->CURSOR;

    prompt->promptLabel->setText("Click an item on the canvas to change its properties");
    cursorWidgetRotate->show();
}

void MainWindow::colorsButtonClicked()
{
    QMessageBox::information(this, "title", "Colors");
}

void MainWindow::shapesButtonClicked()
{
    hideWidgets();
    canvas->drawState = canvas->SHAPE;

    prompt->promptLabel->setText("Select a shape");
    shapesWidgetShapes->show();
}

void MainWindow::stampsButtonClicked()
{
    hideWidgets();
    canvas->drawState = canvas->STAMP;

    prompt->promptLabel->setText("Select a stamp category:");
    stampsWidgetCategories->show();

}

void MainWindow::brushEffectsButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a brush effect");
    brushEffectsWidgetBrushEffects->show();
}

void MainWindow::drawButtonClicked()
{
    hideWidgets();
    canvas->drawState = canvas->DRAW;

    prompt->promptLabel->setText("Click on the canvas to start drawing. Click a second time on the canvas to end drawing.");
}

void MainWindow::eraserButtonClicked()
{
    QMessageBox::information(this, "title", "Eraser");
}

void MainWindow::insertPictureButtonClicked()
{
    QMessageBox::information(this, "title", "Insert Picture");
}

//Cursor--------------------------------------------------------
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

void MainWindow::t05ButtonButtonClicked()
{
    canvas->translateValue = 0.5;
}

void MainWindow::t1ButtonButtonClicked()
{
    canvas->translateValue = 1;
}

void MainWindow::t5ButtonButtonClicked()
{
    canvas->translateValue = 5;
}

void MainWindow::t10ButtonButtonClicked()
{
    canvas->translateValue = 10;
}

void MainWindow::t20ButtonButtonClicked()
{
    canvas->translateValue = 20;
}

void MainWindow::t50ButtonButtonClicked()
{
    canvas->translateValue = 50;
}

void MainWindow::t100ButtonButtonClicked()
{
    canvas->translateValue = 100;
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

void MainWindow::s05ButtonClicked()
{
    canvas->scaleFactor = 0.005;
}

void MainWindow::s1ButtonClicked()
{
    canvas->scaleFactor = 0.01;
}

void MainWindow::s5ButtonClicked()
{
    canvas->scaleFactor = 0.05;
}

void MainWindow::s10ButtonClicked()
{
    canvas->scaleFactor = 0.1;
}

void MainWindow::s20ButtonClicked()
{
    canvas->scaleFactor = 0.2;
}

void MainWindow::s50ButtonClicked()
{
    canvas->scaleFactor = 0.5;
}

void MainWindow::s100ButtonClicked()
{
    canvas->scaleFactor = 1.0;
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

void MainWindow::st05ButtonButtonClicked()
{
    canvas->stretchValue = 0.5;
}

void MainWindow::st1ButtonButtonClicked()
{
    canvas->stretchValue = 1;
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

void MainWindow::r01ButtonClicked()
{
    canvas->rotateAngle = 0.1;
}

void MainWindow::r05ButtonClicked()
{
    canvas->rotateAngle = 0.5;
}

void MainWindow::r1ButtonClicked()
{
    canvas->rotateAngle = 1;
}

void MainWindow::r5ButtonClicked()
{
    canvas->rotateAngle = 5;
}

void MainWindow::r10ButtonClicked()
{
    canvas->rotateAngle = 10;
}

void MainWindow::r20ButtonClicked()
{
    canvas->rotateAngle = 20;
}

void MainWindow::r30ButtonClicked()
{
    canvas->rotateAngle = 30;
}

void MainWindow::r45ButtonClicked()
{
    canvas->rotateAngle = 45;
}

void MainWindow::r60ButtonClicked()
{
    canvas->rotateAngle = 60;
}

void MainWindow::r72ButtonClicked()
{
    canvas->rotateAngle = 72;
}

void MainWindow::r90ButtonClicked()
{
    canvas->rotateAngle = 90;
}

void MainWindow::r120ButtonClicked()
{
    canvas->rotateAngle = 120;
}

void MainWindow::r180ButtonClicked()
{
    canvas->rotateAngle = 180;
}

void MainWindow::r270ButtonClicked()
{
    canvas->rotateAngle = 270;
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

void MainWindow::sh1ButtonButtonClicked()
{
    canvas->shearAngle = 1;
}

//Shapes
void MainWindow::previousShapeButtonClicked()
{
     canvas->shapeState = canvas->PREVSHAPE;
     prompt->promptLabel->setText(tr("hmm"));
}

void MainWindow::lineButtonClicked()
{
    canvas->shapeState = canvas->LINE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)First endpoint 2)Second endpoint"));
}

void MainWindow::pointButtonClicked()
{
    canvas->shapeState = canvas->POINT;
    prompt->promptLabel->setText(tr("Click one point on the canvas"));
}

void MainWindow::circleButtonClicked()
{
    canvas->shapeState = canvas->CIRCLE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::rectangleButtonClicked()
{
    canvas->shapeState = canvas->RECT;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::roundedRectangleButtonClicked()
{
    canvas->shapeState = canvas->ROUNDRECT;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::polygonButtonClicked()
{
    canvas->shapeState = canvas->POLYGON;
    prompt->promptLabel->setText(tr("Click points on the canvas to be your polygon path and click the 'end path' button to draw the polygon"));
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->show();
}

void MainWindow::arcButtonClicked()
{
    canvas->shapeState = canvas->ARC;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::chordButtonClicked()
{
    canvas->shapeState = canvas->CHORD;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::pieButtonClicked()
{
    canvas->shapeState = canvas->PIE;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::pathButtonClicked()
{
    canvas->shapeState = canvas->PATH;
    prompt->promptLabel->setText(tr("Click points on the canvas to be your path and click the 'end path' button to draw the path"));
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->show();
}

void MainWindow::textButtonClicked()
{
    QMessageBox::information(this, "title", "Text");
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
    canvas->shapeState = canvas->NOSHAPE;

    canvas->mousePressCount = 0;
    canvas->points.clear();
}

void MainWindow::paintButtonClicked()
{
    QMessageBox::information(this, "title", "paint");
}

void MainWindow::waterColorButtonClicked()
{
    QMessageBox::information(this, "title", "water color");
}

void MainWindow::calligraphyButtonClicked()
{
    QMessageBox::information(this, "title", "calligraphy");
}

void MainWindow::pencilButtonClicked()
{
    QMessageBox::information(this, "title", "pencil");
}

void MainWindow::sprayPaintButtonClicked()
{
    QMessageBox::information(this, "title", "spray paint");
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
