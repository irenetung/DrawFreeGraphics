#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <qfiledialog.h>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonWidth = 60;
    buttonHeight = 60;
    hidePopup = true;
    curPopup = NULL;
    id = 0;

//Toolbar
    ui->mainToolBar->setIconSize(QSize(buttonWidth,buttonHeight));

    settingsButton = new QToolButton();
    settingsButton->setIcon(QIcon(":/Icons/Icons/settings.png"));
    settingsButton->setText("Settings");
    setToolButtonProperties(settingsButton);

    newButton = new QToolButton();
    newButton->setIcon(QIcon(":/Icons/Icons/new.png"));
    newButton->setText("New");
    setToolButtonProperties(newButton);

    openButton = new QToolButton();
    openButton->setIcon(QIcon(":/Icons/Icons/open.png"));
    openButton->setText("Open");
    setToolButtonProperties(openButton);

    saveButton = new QToolButton();
    saveButton->setIcon(QIcon(":/Icons/Icons/save.png"));
    saveButton->setText("Save");
    setToolButtonProperties(saveButton);

    undoButton = new QToolButton();
    undoButton->setIcon(QIcon(":/Icons/Icons/undo.png"));
    undoButton->setText("Undo");
    setToolButtonProperties(undoButton);

    cursorButton = new QToolButton();
    cursorButton->setIcon(QIcon(":/Icons/Icons/cursor.png"));
    cursorButton->setText("Cursor");
    setToolButtonProperties(cursorButton);

    colorsButton = new QToolButton();
    colorsButton->setIcon(QIcon(":/Icons/Icons/colors.png"));
    colorsButton->setText("Colors");
    setToolButtonProperties(colorsButton);

    shapesButton = new QToolButton();
    shapesButton->setIcon(QIcon(":/Icons/Icons/shapes.png"));
    shapesButton->setText("Shapes");
    setToolButtonProperties(shapesButton);

    stampsButton = new QToolButton();
    stampsButton->setIcon(QIcon(":/Icons/Icons/stamps.png"));
    stampsButton->setText("Stamps");
    setToolButtonProperties(stampsButton);

    brushEffectsButton = new QToolButton();
    brushEffectsButton->setIcon(QIcon(":/Icons/Icons/brushEffects.png"));
    brushEffectsButton->setText("Brush Effects");
    setToolButtonProperties(brushEffectsButton);

    insertPictureButton = new QToolButton();
    insertPictureButton->setIcon(QIcon(":/Icons/Icons/insertPicture.png"));
    insertPictureButton->setText("Insert Picture");
    setToolButtonProperties(insertPictureButton);

    closeButton = new QToolButton();
    closeButton->setIcon(QIcon(":/Icons/Icons/close.png"));
    closeButton->setText("Close");
    setToolButtonProperties(closeButton);

    showHidePopupButton = new QToolButton();
    showHidePopupButton->setIcon(QIcon(":/Icons/Icons/hidePopup.png"));
    showHidePopupButton->setText("Hide Popup");
    setToolButtonProperties(showHidePopupButton);

    toolGroup = new QButtonGroup();
    addToToolGroup(settingsButton);
    addToToolGroup(cursorButton);
    addToToolGroup(colorsButton);
    addToToolGroup(shapesButton);
    addToToolGroup(stampsButton);
    addToToolGroup(brushEffectsButton);

    toolGroup->setExclusive(true);

    connect(newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    connect(undoButton, SIGNAL(clicked()), this, SLOT(undoButtonClicked()));
    connect(insertPictureButton, SIGNAL(clicked()), this, SLOT(insertPictureButtonClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(showHidePopupButton, SIGNAL(clicked()), this, SLOT(showHidePopupButtonClicked()));
    connect(toolGroup, SIGNAL(buttonClicked(int)), this, SLOT(toolButtonGroupClicked(int)));

//Prompt
    prompt = new Prompt();
//Undo
    undoStack = new QUndoStack();
//Settings
    settingsWidgetButtonSize = new SettingsWidgetButtonSize();
    popUps.push_back(settingsWidgetButtonSize);
    connect(settingsWidgetButtonSize->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(settingsButtonSizeButtonGroupClicked(int)));
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
    //Cursors
    connect(cursorWidgetCursors->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorCursorsButtonGroupClicked(int)));
    //Translate
    connect(cursorWidgetTranslate->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetTranslate->directionButton, SIGNAL(clicked()), this, SLOT(cursorDirectionButtonClicked()));
    connect(cursorWidgetTranslate->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorTranslateButtonGroupClicked(int)));
    //Scale
    connect(cursorWidgetScale->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetScale->directionButton, SIGNAL(clicked()), this, SLOT(cursorDirectionButtonClicked()));
    connect(cursorWidgetScale->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorScaleButtonGroupClicked(int)));
    //Stretch
    connect(cursorWidgetStretch->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetStretch->directionButton, SIGNAL(clicked()), this, SLOT(cursorDirectionButtonClicked()));
    connect(cursorWidgetStretch->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorStretchButtonGroupClicked(int)));
    //Rotate
    connect(cursorWidgetRotate->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetRotate->directionButton, SIGNAL(clicked()), this, SLOT(cursorDirectionButtonClicked()));
    connect(cursorWidgetRotate->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorRotateButtonGroupClicked(int)));
    //Shear
    connect(cursorWidgetShear->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetShear->directionButton, SIGNAL(clicked()), this, SLOT(cursorDirectionButtonClicked()));
    connect(cursorWidgetShear->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorShearButtonGroupClicked(int)));
    //Depth
    connect(cursorWidgetDepth->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
    connect(cursorWidgetDepth->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(cursorDepthButtonGroupClicked(int)));

    //Back
    connect(cursorWidgetBack->backButton, SIGNAL(clicked()), this, SLOT(cursorBackButtonClicked()));
//Shapes
    shapesWidgetShapes = new ShapesWidgetShapes();
    popUps.push_back(shapesWidgetShapes);
    shapesWidgetEndPath = new ShapesWidgetEndPath();
    popUps.push_back(shapesWidgetEndPath);
    shapesWidgetOutlineSizes = new ShapesWidgetOutlineSizes();
    popUps.push_back(shapesWidgetOutlineSizes);

    connect(shapesWidgetShapes->outlineSizeButton, SIGNAL(clicked()), this, SLOT(outlineSizeButtonClicked()));
    connect(shapesWidgetShapes->outlineColorButton, SIGNAL(clicked()), this, SLOT(outlineColorButtonClicked()));
    connect(shapesWidgetShapes->fillColorButton, SIGNAL(clicked()), this, SLOT(fillColorButtonClicked()));
    connect(shapesWidgetShapes->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(shapesButtonGroupClicked(int)));

    connect(shapesWidgetEndPath->backButton, SIGNAL(clicked()), this, SLOT(shapesBackButtonClicked()));
    connect(shapesWidgetEndPath->endPathButton, SIGNAL(clicked()), this, SLOT(endPathButtonClicked()));

    connect(shapesWidgetOutlineSizes->backButton, SIGNAL(clicked()), this, SLOT(shapesBackButtonClicked()));
    connect(shapesWidgetOutlineSizes->on1Button, SIGNAL(clicked()), this, SLOT(on1ButtonClicked()));
    connect(shapesWidgetOutlineSizes->op1Button, SIGNAL(clicked()), this, SLOT(op1ButtonClicked()));
//Colors
    colorsWidgetPaintTools = new ColorsWidgetPaintTools();
    popUps.push_back(colorsWidgetPaintTools);
    colorsWidgetColorsOutline = new ColorsWidgetColors(ColorsWidgetColors::SHAPES);
    popUps.push_back(colorsWidgetColorsOutline);
    colorsWidgetColorsFill = new ColorsWidgetColors(ColorsWidgetColors::SHAPES);
    popUps.push_back(colorsWidgetColorsFill);
    colorsWidgetColorsSilhouette = new ColorsWidgetColors(ColorsWidgetColors::STAMPS);
    popUps.push_back(colorsWidgetColorsSilhouette);
    colorsWidgetColorsBrush = new ColorsWidgetColors(ColorsWidgetColors::BRUSHEFFECTS);
    popUps.push_back(colorsWidgetColorsBrush);
    colorsWidgetColorsBackground = new ColorsWidgetColors(ColorsWidgetColors::BACKGROUND);
    popUps.push_back(colorsWidgetColorsBackground);

    connect(colorsWidgetPaintTools->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsPaintToolsButtonGroupClicked(int)));

    connect(colorsWidgetColorsOutline->colorsBackButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColorsOutline->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsButtonGroupClicked(int)));
    connect(colorsWidgetColorsOutline->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    connect(colorsWidgetColorsFill->colorsBackButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColorsFill->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsButtonGroupClicked(int)));
    connect(colorsWidgetColorsFill->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    connect(colorsWidgetColorsSilhouette->colorsBackButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColorsSilhouette->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsButtonGroupClicked(int)));
    connect(colorsWidgetColorsSilhouette->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    connect(colorsWidgetColorsBrush->colorsBackButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColorsBrush->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsButtonGroupClicked(int)));
    connect(colorsWidgetColorsBrush->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    connect(colorsWidgetColorsBackground->colorsBackButton, SIGNAL(clicked()), this, SLOT(colorsBackButtonClicked()));
    connect(colorsWidgetColorsBackground->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(colorsButtonGroupClicked(int)));
    connect(colorsWidgetColorsBackground->customColorButton, SIGNAL(clicked()), this, SLOT(customColorButtonClicked()));

    QSignalMapper *otherBackButtonSignalMapper = new QSignalMapper(this);
    connect(colorsWidgetColorsOutline->otherBackButton, SIGNAL(clicked()), otherBackButtonSignalMapper, SLOT(map()));
    connect(colorsWidgetColorsFill->otherBackButton, SIGNAL(clicked()), otherBackButtonSignalMapper, SLOT(map()));
    connect(colorsWidgetColorsSilhouette->otherBackButton, SIGNAL(clicked()), otherBackButtonSignalMapper, SLOT(map()));
    connect(colorsWidgetColorsBrush->otherBackButton, SIGNAL(clicked()), otherBackButtonSignalMapper, SLOT(map()));

    otherBackButtonSignalMapper->setMapping(colorsWidgetColorsOutline->otherBackButton, ColorsWidgetColors::SHAPES);
    otherBackButtonSignalMapper->setMapping(colorsWidgetColorsFill->otherBackButton, ColorsWidgetColors::SHAPES);
    otherBackButtonSignalMapper->setMapping(colorsWidgetColorsSilhouette->otherBackButton, ColorsWidgetColors::STAMPS);
    otherBackButtonSignalMapper->setMapping(colorsWidgetColorsBrush->otherBackButton, ColorsWidgetColors::BRUSHEFFECTS);

    connect(otherBackButtonSignalMapper, SIGNAL(mapped(int)), this, SLOT(otherBackButtonClicked(int)));

//Brush Effects
    brushEffectsWidgetBrushEffects = new BrushEffectsWidgetBrushEffects();
    popUps.push_back(brushEffectsWidgetBrushEffects);
    connect(brushEffectsWidgetBrushEffects->brushSizeButton, SIGNAL(clicked()), this, SLOT(brushSizeButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->brushColorButton, SIGNAL(clicked()), this, SLOT(brushColorButtonClicked()));
    connect(brushEffectsWidgetBrushEffects->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(brushEffectsButtonGroupClicked(int)));

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
        connect(stampsWidgetSilhouette->silhouetteColorButton, SIGNAL(clicked()), this, SLOT(silhouetteColorButtonClicked()));

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

void MainWindow::setToolButtonProperties(QToolButton *b)
{
    b->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   // b->setFixedSize(QSize(100,100));
   // b->setIconSize(QSize(100,100));
    ui->mainToolBar->addWidget(b);
    tools.push_back(b);
}

void MainWindow::addToToolGroup(QToolButton *b)
{
    b->setCheckable(true);
    toolGroup->addButton(b);
    toolGroup->setId(b,id);
    ++id;
}

void MainWindow::hideWidgets()
{
    int size = popUps.size();
    for(int i = 0; i < size; ++i) {
        popUps[i]->hide();
    }
}
//Toolbar------------------------------------------------------------------------------------------------
void MainWindow::toolButtonGroupClicked(int id)
{
    hideWidgets();
    resetDrawState();
    switch(id) {
        case 0:
            //Settings
            prompt->promptLabel->setText("Adjust the button size. The minimum button size is 60x60 pixels.");
            showPopup(settingsWidgetButtonSize);
            break;
        case 1:
            //Cursor
            canvas->drawState = canvas->CURSOR;
            canvas->cursorState = canvas->NOCURSOR;
            prompt->promptLabel->setText("Select a cursor type.");
            showPopup(cursorWidgetCursors);
            break;
        case 2:
            //Colors
            canvas->drawState = canvas->COLOR;
            canvas->colorState = canvas->NOCOLOR;
            prompt->promptLabel->setText("Select a paint tool to modify.");
            showPopup(colorsWidgetPaintTools);
            break;
        case 3:
            //Shapes
            canvas->drawState = canvas->SHAPE;
            setShapesPrompt(canvas->shapeState);
            showPopup(shapesWidgetShapes);
            break;
        case 4:
            //Stamps
            canvas->drawState = canvas->STAMP;
            prompt->promptLabel->setText("Select a stamp category.");
            showPopup(stampsWidgetCategories);
            break;
        case 5:
            //Brush Effects
            canvas->drawState = canvas->BRUSHEFFECTS;
            prompt->promptLabel->setText("Select a brush effect.");
            showPopup(brushEffectsWidgetBrushEffects);
            break;
        default:
            break;
    }
}

void MainWindow::newButtonClicked()
{
    resetDrawState();
    /*MainWindow *newApplication;
    newApplication = new MainWindow();
    newApplication -> show();*/
    canvas->scene->clear();
}

void MainWindow::openButtonClicked()
{
    resetDrawState();
    QString s = QFileDialog::getOpenFileName(
                    0,
                    "Open File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->loadScene(s);
}

void MainWindow::saveButtonClicked()
{
    resetDrawState();
    QString s = QFileDialog::getSaveFileName(
                    0,
                    "Save File",
                    "/home",
                    "Images (*.png *.xpm *.jpg)");
    canvas->saveScene(s);
}

void MainWindow::undoButtonClicked()
{
    resetDrawState();
    undoStack->undo();
}

void MainWindow::insertPictureButtonClicked()
{
    resetDrawState();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),QDir::currentPath());
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
            return;
        }
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        item->setPos(0,0);
        canvas->drawPixmapItem(item);
    }
}

void MainWindow::showHidePopupButtonClicked()
{
    if(hidePopup) {
        if(curPopup) {
        hideWidgets();
        showHidePopupButton->setIcon(QIcon(":/Icons/Icons/showPopup.png"));
        showHidePopupButton->setText("Show Popup");
        }
    }else {
        if(curPopup) {
            curPopup->show();
            showHidePopupButton->setIcon(QIcon(":/Icons/Icons/hidePopup.png"));
            showHidePopupButton->setText("Hide Popup");
        }
    }
    hidePopup = !hidePopup;
    repaint();
}

//Settings--------------------------------------------------------
void MainWindow::settingsButtonSizeButtonGroupClicked(int id)
{
    switch(id) {
        case 0:
            if(buttonWidth - 5 >= 60) {
                buttonWidth -= 5;
            }
            break;
        case 1:
                buttonWidth += 5;
            break;
        case 2:
            if(buttonHeight - 5 >= 60) {
                buttonHeight -= 5;
            }
            break;
        case 3:
            buttonHeight += 5;
            break;
        default:
            break;
    }
    changeButtonProperties(buttonWidth,buttonHeight);
}

//Cursor--------------------------------------------------------
void MainWindow::cursorBackButtonClicked()
{
    hideWidgets();
    canvas->cursorState = canvas->NOCURSOR;
    prompt->promptLabel->setText("Select a cursor type.");
    showPopup(cursorWidgetCursors);
}

void MainWindow::cursorCursorsButtonGroupClicked(int id)
{
    hideWidgets();
    switch(id) {
        case 0:
            //Translate
            canvas->cursorState = canvas->TRANSLATE;
            prompt->promptLabel->setText("Select a translation value. Then click an item on the canvas to apply the translation. Toggle the direction button to change the translation direction.");
            showPopup(cursorWidgetTranslate);
            break;
        case 1:
            //Scale
            canvas->cursorState = canvas->SCALE;
            prompt->promptLabel->setText("Select a scale factor. Then click an item on the canvas to apply the scaling. Toggle the direction button to change the scaling direction.");
            showPopup(cursorWidgetScale);
            break;
        case 2:
            //Stretch
            canvas->cursorState = canvas->STRETCH;
            prompt->promptLabel->setText("Select a stretch value. Then click an item on the canvas to apply the stretch. Toggle the direction button to change the stretch direction.");
            showPopup(cursorWidgetStretch);
            break;
        case 3:
            //Rotate
            canvas->cursorState = canvas->ROTATE;
            prompt->promptLabel->setText("Select a rotation angle. Then click an item on the canvas to apply the rotation. Toggle the direction button to change the rotation direction.");
            showPopup(cursorWidgetRotate);
            break;
        case 4:
            //Shear
            canvas->cursorState = canvas->SHEAR;
            prompt->promptLabel->setText("Select a shear angle. Then click an item on the canvas to apply the shear. Toggle the direction button to change the shear direction.");
            showPopup(cursorWidgetShear);
            break;
        case 5:
            //Depth
            canvas->cursorState = canvas->DEPTH;
            prompt->promptLabel->setText("Select a depth change. Then click an item on the canvas to apply the depth change.");
            showPopup(cursorWidgetDepth);
            break;
        case 6:
            //Copy
            canvas->cursorState = canvas->COPY;
            prompt->promptLabel->setText("Click an item on the canvas to copy.");
            showPopup(cursorWidgetBack);
            break;
        case 7:
            //Delete
            canvas->cursorState = canvas->DELETEITEM;
            prompt->promptLabel->setText("Click an item on the canvas to delete.");
            showPopup(cursorWidgetBack);
            break;
        default:
            break;
    }
}

void MainWindow::cursorDirectionButtonClicked()
{
    switch(canvas->cursorState) {
        case canvas->TRANSLATE:
            switch(canvas->translateDirection) {
            case canvas->RIGHT:
                canvas->translateDirection = canvas->LEFT;
                cursorWidgetTranslate->directionButton->setText("Left");
                break;
            case canvas->LEFT:
                canvas->translateDirection = canvas->UP;
                cursorWidgetTranslate->directionButton->setText("Up");
                break;
            case canvas->UP:
                canvas->translateDirection = canvas->DOWN;
                cursorWidgetTranslate->directionButton->setText("Down");
                break;
            case canvas->DOWN:
                canvas->translateDirection = canvas->RIGHT;
                cursorWidgetTranslate->directionButton->setText("Right");
                break;
            default:
                break;
            }
            break;
        case canvas->SCALE:
            switch(canvas->scaleDirection) {
                case canvas->RIGHT:
                    canvas->scaleDirection = canvas->LEFT;
                    cursorWidgetScale->directionButton->setText("Decrease");
                    break;
                case canvas->LEFT:
                    canvas->scaleDirection = canvas->RIGHT;
                    cursorWidgetScale->directionButton->setText("Increase");
                    break;
                default:
                    break;
            }
            break;
        case canvas->STRETCH:
            switch(canvas->stretchDirection) {
            case canvas->RIGHT:
                canvas->stretchDirection = canvas->LEFT;
                cursorWidgetStretch->directionButton->setText("Decrease\nHorizontally");
                break;
            case canvas->LEFT:
                canvas->stretchDirection = canvas->UP;
                cursorWidgetStretch->directionButton->setText("Increase\nVertically");
                break;
            case canvas->UP:
                canvas->stretchDirection = canvas->DOWN;
                cursorWidgetStretch->directionButton->setText("Decrease\nVertically");
                break;
            case canvas->DOWN:
                canvas->stretchDirection = canvas->RIGHT;
                cursorWidgetStretch->directionButton->setText("Increase\nHorizontally");
                break;
            default:
                break;
            }
            break;
        case canvas->ROTATE:
            switch(canvas->rotateDirection) {
            case canvas->RIGHT:
                canvas->rotateDirection = canvas->LEFT;
                cursorWidgetRotate->directionButton->setText("Counter-\nClockwise");
                break;
            case canvas->LEFT:
                canvas->rotateDirection = canvas->RIGHT;
                cursorWidgetRotate->directionButton->setText("Clockwise");
                break;
            default:
                break;
            }
            break;
        case canvas->SHEAR:
            switch(canvas->shearDirection) {
            case canvas->RIGHT:
                canvas->shearDirection = canvas->LEFT;
                cursorWidgetShear->directionButton->setText("Left");
                break;
            case canvas->LEFT:
                canvas->shearDirection = canvas->UP;
                cursorWidgetShear->directionButton->setText("Up");
                break;
            case canvas->UP:
                canvas->shearDirection = canvas->DOWN;
                cursorWidgetShear->directionButton->setText("Down");
                break;
            case canvas->DOWN:
                canvas->shearDirection = canvas->RIGHT;
                cursorWidgetShear->directionButton->setText("Right");
                break;
            default:
                break;
            }
            break;
        default:
            break;
    }
}
//Translate
void MainWindow::cursorTranslateButtonGroupClicked(int id)
{
    int v = 0;
    switch(id) {
        case 0:
            v=1;
            break;
        case 1:
            v=5;
            break;
        case 2:
            v=10;
            break;
        case 3:
            v=20;
            break;
        case 4:
            v=50;
            break;
        case 5:
            v=100;
            break;
        default:
            break;
    }
    canvas->translateV = v;
}

//Scale
void MainWindow::cursorScaleButtonGroupClicked(int id)
{
    double v = 0;
    switch(id) {
        case 0:
            v=-1;
            break;
        case 1:
            v=0.001;
            break;
        case 2:
            v=0.005;
            break;
        case 3:
            v=0.01;
            break;
        case 4:
            v=0.05;
            break;
        case 5:
            v=0.1;
            break;
        case 6:
            v=0.5;
            break;
        case 7:
            v=1.0;
            break;
        default:
            break;
    }
    canvas->scaleFactor = v;
}

void MainWindow::cursorStretchButtonGroupClicked(int id)
{
    double v = 0;
    switch(id) {
        case 0:
            v=0.005;
            break;
        case 1:
            v=0.01;
            break;
        case 2:
            v=0.05;
            break;
        case 3:
            v=0.1;
            break;
        case 4:
            v=0.2;
            break;
        case 5:
            v=0.5;
            break;
        case 6:
            v=1;
            break;
        default:
            break;
    }
    canvas->stretchV = v;
}

void MainWindow::cursorRotateButtonGroupClicked(int id)
{
    double v = 0;
    switch(id) {
        case 0:
            v=-1;
            break;
        case 1:
            v=0.1;
            break;
        case 2:
            v=0.5;
            break;
        case 3:
            v=1;
            break;
        case 4:
            v=5;
            break;
        case 5:
            v=10;
            break;
        case 6:
            v=20;
            break;
        case 7:
            v=30;
            break;
        case 8:
            v=45;
            break;
        case 9:
            v=60;
            break;
        case 10:
            v=72;
            break;
        case 11:
            v=90;
            break;
        case 12:
            v=120;
            break;
        case 13:
            v=180;
            break;
        default:
            break;
    }
    canvas->rotateAngle = v;
}

void MainWindow::cursorShearButtonGroupClicked(int id)
{
    double v=0;
    switch(id) {
        case 0:
            v=0.01;
            break;
        case 1:
            v=0.05;
            break;
        case 2:
            v=0.1;
            break;
        case 3:
            v=0.2;
            break;
        case 4:
            v=0.5;
            break;
        case 5:
            v=1;
            break;
        default:
            break;
    }
    canvas->shearV = v;
}

void MainWindow::cursorDepthButtonGroupClicked(int id)
{
    switch(id) {
        case 0:
            canvas->depthPositive = false;
            break;
        case 1:
            canvas->depthPositive = true;
            break;
        default:
            break;
    }
}

//Shapes
void MainWindow::outlineSizeButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    prompt->promptLabel->setText(tr("Adjust the outline size."));
    showPopup(shapesWidgetOutlineSizes);
}

void MainWindow::outlineColorButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    shapesButton->setChecked(false);
    canvas->drawState = canvas->COLOR;
    canvas->colorState = canvas->OUTLINE;
    colorsButton->setChecked(true);

    setColorsPrompt(canvas->colorState);
    showPopup(colorsWidgetColorsOutline);
}

void MainWindow::fillColorButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    shapesButton->setChecked(false);
    canvas->drawState = canvas->COLOR;
    canvas->colorState = canvas->FILL;
    colorsButton->setChecked(true);

    setColorsPrompt(canvas->colorState);
    showPopup(colorsWidgetColorsFill);
}

void MainWindow::shapesButtonGroupClicked(int id)
{
    canvas->resetShapeState();
    switch(id) {
        case 0:
            canvas->shapeState = canvas->LINE;
            break;
        case 1:
            canvas->shapeState = canvas->POINT;
            break;
        case 2:
            canvas->shapeState = canvas->CIRCLE;
            break;
        case 3:
            canvas->shapeState = canvas->RECT;
            break;
        case 4:
            canvas->shapeState = canvas->ROUNDRECT;
            break;
        case 5:
            canvas->shapeState = canvas->POLYGON;
            shapesWidgetShapes->hide();
            showPopup(shapesWidgetEndPath);
            break;
        case 6:
            canvas->shapeState = canvas->ARC;
            break;
        case 7:
            canvas->shapeState = canvas->CHORD;
            break;
        case 8:
            canvas->shapeState = canvas->PIE;
            break;
        case 9:
            canvas->shapeState = canvas->PATH;
            shapesWidgetShapes->hide();
            showPopup(shapesWidgetEndPath);
            break;
        case 10:
            QMessageBox::information(this, "title", "Text");
            break;
        default:
            break;
    }
    setShapesPrompt(canvas->shapeState);
}

void MainWindow::shapesBackButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    if(shapesWidgetShapes->polygonButton->isChecked() || shapesWidgetShapes->pathButton->isChecked()) {
        shapesWidgetShapes->polygonButton->setChecked(false);
        shapesWidgetShapes->pathButton->setChecked(false);
        shapesWidgetShapes->lineButton->setChecked(true);
        canvas->shapeState = canvas->LINE;
    }
    setShapesPrompt(canvas->shapeState);
    showPopup(shapesWidgetShapes);
}

void MainWindow::endPathButtonClicked()
{
    QPolygonF polygon;
    for(int i = 0; i < canvas->mousePressCount; i++){
        polygon << canvas->points[i];
    }
    if(canvas->shapeState == canvas->POLYGON) {
        QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(polygon);
        polygonItem->setPen(*(canvas->shapesPen));
        polygonItem->setBrush(*(canvas->shapesBrush));
        canvas->drawItem(polygonItem);
    } else if(canvas->shapeState == canvas->PATH) {
        PathItem *pathItem = new PathItem(polygon,*(canvas->shapesPen),*(canvas->shapesBrush));
        canvas->drawItem(pathItem);
    } else {
    }

    update();
}

void MainWindow::colorsButtonGroupClicked(int id)
{
    switch(id) {
        case 0:
            //WHITE
            changePaintToolColor(QColor(255,255,255));
            break;
        case 1:
            //PEACH
            changePaintToolColor(QColor(255,239,213));
            break;
        case 2:
            //PINK
            changePaintToolColor(QColor(255,102,178));
            break;
        case 3:
            //RED
            changePaintToolColor(QColor(255,51,51));
            break;
        case 4:
            //ORANGE
            changePaintToolColor(QColor(255,128,0));
            break;
        case 5:
            //YELLOW
            changePaintToolColor(QColor(255,255,51));
            break;
        case 6:
            //GREEN
            changePaintToolColor(QColor(102,204,0));
            break;
        case 7:
            //BLUE
            changePaintToolColor(QColor(0,128,255));
            break;
        case 8:
            //PURPLE
            changePaintToolColor(QColor(153,0,153));
            break;
        case 9:
            //BROWN
            changePaintToolColor(QColor(102,51,0));
            break;
        case 10:
            //BLACK
            changePaintToolColor(QColor(0,0,0));
            break;
        case 11:
            //GRAY
            changePaintToolColor(QColor(192,192,192));
            break;
        case 12:
            //PREV CUSTOM
            changePaintToolColor(canvas->prevCustomColor);

            break;
        default:
            break;
    }
}

void MainWindow::colorsBackButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a paint tool to modify");
    showPopup(colorsWidgetPaintTools);
}

void MainWindow::otherBackButtonClicked(int widgetType)
{
    hideWidgets();
    colorsButton->setChecked(false);
    switch(widgetType) {
        case ColorsWidgetColors::SHAPES:
            canvas->drawState = canvas->SHAPE;
            setShapesPrompt(canvas->shapeState);
            showPopup(shapesWidgetShapes);
            shapesButton->setChecked(true);
            break;
        case ColorsWidgetColors::STAMPS:
            canvas->drawState = canvas->STAMP;
            //setShapesPrompt(canvas->shapeState);
            showPopup(stampsWidgetSilhouette);
            stampsButton->setChecked(true);
            break;
        case ColorsWidgetColors::BRUSHEFFECTS:
            canvas->drawState = canvas->BRUSHEFFECTS;
            showPopup(brushEffectsWidgetBrushEffects);
            brushEffectsButton->setChecked(true);
            break;
        default:
            break;
    }
}

void MainWindow::customColorButtonClicked()
{
    QColorDialog colorDialog;
    QColor color = colorDialog.getColor(Qt::white,this);
    changePaintToolColor(color);
    canvas->prevCustomColor = color;
    colorsWidgetColorsOutline->prevCustomButtonIcon->fill(canvas->prevCustomColor);
    colorsWidgetColorsOutline->prevCustomButton->setIcon(QIcon(*colorsWidgetColorsOutline->prevCustomButtonIcon));
    colorsWidgetColorsFill->prevCustomButtonIcon->fill(canvas->prevCustomColor);
    colorsWidgetColorsFill->prevCustomButton->setIcon(QIcon(*colorsWidgetColorsFill->prevCustomButtonIcon));
    colorsWidgetColorsSilhouette->prevCustomButtonIcon->fill(canvas->prevCustomColor);
    colorsWidgetColorsSilhouette->prevCustomButton->setIcon(QIcon(*colorsWidgetColorsSilhouette->prevCustomButtonIcon));
    colorsWidgetColorsBrush->prevCustomButtonIcon->fill(canvas->prevCustomColor);
    colorsWidgetColorsBrush->prevCustomButton->setIcon(QIcon(*colorsWidgetColorsBrush->prevCustomButtonIcon));
    colorsWidgetColorsBackground->prevCustomButtonIcon->fill(canvas->prevCustomColor);
    colorsWidgetColorsBackground->prevCustomButton->setIcon(QIcon(*colorsWidgetColorsBackground->prevCustomButtonIcon));
}

void MainWindow::brushSizeButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    prompt->promptLabel->setText(tr("Adjust the brush size."));
    //shapesWidgetOutlineSizes->show();
}

void MainWindow::brushColorButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    shapesButton->setChecked(false);
    canvas->drawState = canvas->COLOR;
    canvas->colorState = canvas->BRUSH;
    colorsButton->setChecked(true);

    setColorsPrompt(canvas->colorState);
    showPopup(colorsWidgetColorsBrush);
}

void MainWindow::brushEffectsButtonGroupClicked(int id)
{
    switch(id) {
        case 0:
            canvas->brushEffectsState = canvas->PAINT;
            break;
        case 1:
            canvas->brushEffectsState = canvas->WATERCOLOR;
            break;
        case 2:
            canvas->brushEffectsState = canvas->CALLIGRAPHY;
            break;
        case 3:
            canvas->brushEffectsState = canvas->PENCIL;
            break;
        case 4:
            canvas->brushEffectsState = canvas->SPRAYPAINT;
            break;
        case 5:
            canvas->brushEffectsState = canvas->DUST;
            break;
        default:
            break;
    }
}

void MainWindow::on1ButtonClicked()
{
    canvas->setPenWidth(-1);
}

void MainWindow::op1ButtonClicked()
{
    canvas->setPenWidth(1);
}

void MainWindow::colorsPaintToolsButtonGroupClicked(int id)
{
    hideWidgets();
    switch(id) {
        case 0:
            canvas->colorState = canvas->OUTLINE;
            showPopup(colorsWidgetColorsOutline);
            break;
        case 1:
            canvas->colorState = canvas->FILL;
            showPopup(colorsWidgetColorsFill);
            break;
        case 2:
            canvas->colorState = canvas->SILHOUETTESTAMP;
            showPopup(colorsWidgetColorsSilhouette);
            break;
        case 3:
            canvas->colorState = canvas->BRUSH;
            showPopup(colorsWidgetColorsBrush);
            break;
        case 4:
            canvas->colorState = canvas->BACKGROUND;
            showPopup(colorsWidgetColorsBackground);
            break;
        default:
            break;
    }
    setColorsPrompt(canvas->colorState);
}

// STAMPS
void MainWindow::silhouetteButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp. The color tool can be used as well.");
    showPopup(stampsWidgetSilhouette);
}
void MainWindow::peopleButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp.");
    showPopup(stampsWidgetPeople);
}

void MainWindow::animalsButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp.");
    showPopup(stampsWidgetAnimals);
}
void MainWindow::buildingsButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp.");
    showPopup(stampsWidgetBuildings);
}
void MainWindow::sceneryButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    showPopup(stampsWidgetScenery);
}
void MainWindow::facesButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp. The color tool can be used as well:");
    showPopup(stampsWidgetFaces);
}

void MainWindow::vehiclesButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp:");
    showPopup(stampsWidgetVehicles);
}

void MainWindow::silhouetteColorButtonClicked()
{
    hideWidgets();
    canvas->resetShapeState();
    shapesButton->setChecked(false);
    canvas->drawState = canvas->COLOR;
    canvas->colorState = canvas->SILHOUETTESTAMP;
    colorsButton->setChecked(true);

    setColorsPrompt(canvas->colorState);
    showPopup(colorsWidgetColorsSilhouette);
}

// STAMPS ACTIONS
void MainWindow::goBackButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a stamp category:");
    showPopup(stampsWidgetCategories);
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

void MainWindow::resetDrawState()
{
    canvas->mousePressCount = 0;
    canvas->points.clear();
}

void MainWindow::showPopup(BaseWidget *p)
{
    hidePopup = true;
    showHidePopupButton->setIcon(QIcon(":/Icons/Icons/hidePopup.png"));
    showHidePopupButton->setText("Hide Popup");
    curPopup = p;
    p->show();
}

void MainWindow::changeButtonProperties(const int &newButtonWidth,const int &newButtonHeight)
{
    ui->mainToolBar->setIconSize(QSize(newButtonWidth,newButtonHeight));
    settingsButton->setIcon(QIcon(":/Icons/Icons/settings.png"));
    newButton->setIcon(QIcon(":/Icons/Icons/new.png"));
    openButton->setIcon(QIcon(":/Icons/Icons/open.png"));
    saveButton->setIcon(QIcon(":/Icons/Icons/save.png"));
    undoButton->setIcon(QIcon(":/Icons/Icons/undo.png"));
    cursorButton->setIcon(QIcon(":/Icons/Icons/cursor.png"));
    colorsButton->setIcon(QIcon(":/Icons/Icons/colors.png"));
    shapesButton->setIcon(QIcon(":/Icons/Icons/shapes.png"));
    stampsButton->setIcon(QIcon(":/Icons/Icons/stamps.png"));
    brushEffectsButton->setIcon(QIcon(":/Icons/Icons/brushEffects.png"));
    insertPictureButton->setIcon(QIcon(":/Icons/Icons/insertPicture.png"));
    closeButton->setIcon(QIcon(":/Icons/Icons/close.png"));
    showHidePopupButton->setIcon(QIcon(":/Icons/Icons/hidePopup.png"));

    int size = popUps.size();
    for(int i = 0; i < size; ++i) {
        popUps[i]->changeButtonProperties(newButtonWidth, newButtonHeight);
    }
    repaint();
}

void MainWindow::changePaintToolColor(QColor color)
{
    switch (canvas->colorState) {
        case canvas->OUTLINE:
            canvas->setPenColor(color);
            colorsWidgetPaintTools->outlineButton->setStyleSheet(colorsWidgetPaintTools->borderColor.arg(color.name()));
            break;
        case canvas->FILL:
            canvas->setBrushColor(color);
            colorsWidgetPaintTools->fillButton->setStyleSheet(colorsWidgetPaintTools->borderColor.arg(color.name()));
            break;
        case canvas->SILHOUETTESTAMP:
            canvas->silhouetteColor = color;
            colorsWidgetPaintTools->silhouetteButton->setStyleSheet(colorsWidgetPaintTools->borderColor.arg(color.name()));
            break;
        case canvas->BRUSH:
            colorsWidgetPaintTools->brushButton->setStyleSheet(colorsWidgetPaintTools->borderColor.arg(color.name()));
            break;
        case canvas->BACKGROUND:
            colorsWidgetPaintTools->backgroundButton->setStyleSheet(colorsWidgetPaintTools->borderColor.arg(color.name()));
            canvas->setBackgroundBrush(color);
            break;
        default:
            break;
    }
}

void MainWindow::setShapesPrompt(Canvas::ShapeState shapeState)
{
    switch(shapeState) {
        case canvas->LINE:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render a line: 1)First endpoint 2)Second endpoint. Or select a shape."));
            break;
        case canvas->POINT:
            prompt->promptLabel->setText(tr("Click one point on the canvas to render a point. Or select a shape."));
            break;
        case canvas->CIRCLE:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render a circle: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->RECT:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render a rectangle: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->ROUNDRECT:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render a rounded rectangle: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->POLYGON:
            prompt->promptLabel->setText(tr("Click points on the canvas to be included in your polygon path and click the 'end path' button to render the polygon. Or go back to shapes."));
            break;
        case canvas->ARC:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render an arc: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->CHORD:
            prompt->promptLabel->setText(tr("Click two points on the canvas to render a chord: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->PIE:
             prompt->promptLabel->setText(tr("Click two points on the canvas to render a pie segment: 1)Top left corner 2)Bottom right corner. Or select a shape."));
            break;
        case canvas->PATH:
             prompt->promptLabel->setText(tr("Click points on the canvas to be included in your polyline path and click the 'end path' button to render the polyline. Or go back to shapes."));
            break;
        case canvas->TEXTTYPE:
            break;
        default:
            break;
    }
}

void MainWindow::setColorsPrompt(Canvas::ColorState colorState)
{
    switch(colorState) {
        case canvas->OUTLINE:
            prompt->promptLabel->setText("Set the outline color. Or click a shape on the canvas to change its outline color.");
            break;
        case canvas->FILL:
            prompt->promptLabel->setText("Set the fill color. Or click a shape on the canvas to change its fill color.");
            break;
        case canvas->SILHOUETTESTAMP:
            prompt->promptLabel->setText("Set the silhouette stamp color. Or click a silhouette stamp on the canvas to change its color.");
            break;
        case canvas->BRUSH:
            prompt->promptLabel->setText("Set the brush effect color. Or click a brush stroke on the canvas to change its color.");
            break;
        case canvas->BACKGROUND:
            prompt->promptLabel->setText("Set the background color.");
            break;
        default:
            break;
    }
}
