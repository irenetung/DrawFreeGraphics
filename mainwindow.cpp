#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QAbstractButton>

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

//Tool Widgets
    //Prompt
    prompt = new Prompt();
    //Cursor
    cursorWidgetRotate = new CursorWidgetRotate();
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

    //Stamps
    stampsWidgetCategories = new StampsWidgetCategories();
    stampsWidgetSilhouette = new StampsWidgetSilhouette();

    connect(stampsWidgetCategories->silhouetteButton, SIGNAL(clicked()), this, SLOT(silhouetteButtonClicked()));
        // Silhouette Stamps
        connect(stampsWidgetSilhouette->goBack, SIGNAL(clicked()), this, SLOT(goBackButtonClicked()));
        QSignalMapper* silhouetteSignalMapper = new QSignalMapper (this) ;
        connect(stampsWidgetSilhouette->dogStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->catStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->birdStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->turtleStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->ratStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->giraffeStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->alienStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->manStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->womanStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->cameraStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->mailStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->cupStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->giftStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->umbrellaStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->securityCamStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->wrenchStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->heartStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->airplaneStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->helicopterStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->carStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->truckStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->busStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->gasPumpStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->factoryStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->buildingStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->capitolStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->homeStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->sunStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->treeStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->tree2Stamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->cloudStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->snowStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));
        connect(stampsWidgetSilhouette->rainStamp, SIGNAL(clicked()), silhouetteSignalMapper, SLOT(map()));


        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->dogStamp, "dog_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->catStamp, "cat_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->birdStamp, "bird_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->turtleStamp, "turtle_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->ratStamp, "rat_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->giraffeStamp, "giraffe_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->alienStamp, "alien_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->manStamp, "man_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->womanStamp, "woman_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->cameraStamp, "camera_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->mailStamp, "mail_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->cupStamp, "cup_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->giftStamp, "gift_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->umbrellaStamp, "umbrella_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->securityCamStamp, "security_cam_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->wrenchStamp, "wrench_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->heartStamp, "heart_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->airplaneStamp, "airplane_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->helicopterStamp, "helicopter_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->carStamp, "car_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->truckStamp, "truck_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->busStamp, "bus_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->gasPumpStamp, "gas_pump_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->factoryStamp, "factory_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->buildingStamp, "building_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->capitolStamp, "capitol_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->homeStamp, "home_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->sunStamp, "sun_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->treeStamp, "tree_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->tree2Stamp, "tree2_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->cloudStamp, "cloud_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->snowStamp, "snow_stamp");
        silhouetteSignalMapper->setMapping(stampsWidgetSilhouette->rainStamp, "rain_stamp");
        connect(silhouetteSignalMapper, SIGNAL(mapped(const QString)), this, SLOT(silhouetteStampClicked(const QString)));



    //Canvas
    canvas = new Canvas();

    //Application Layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(prompt);
    vLayout->addWidget(cursorWidgetRotate);
    vLayout->addWidget(shapesWidgetShapes);
    vLayout->addWidget(shapesWidgetEndPath);
    vLayout->addWidget(stampsWidgetCategories);
    vLayout->addWidget(stampsWidgetSilhouette);
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
    cursorWidgetRotate->hide();
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->hide();

    stampsWidgetCategories->hide();
    stampsWidgetSilhouette->hide();

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
    QMessageBox::information(this, "title", "Open");
}

void MainWindow::saveButtonClicked()
{
    QMessageBox::information(this, "title", "Save");
}

void MainWindow::undoButtonClicked()
{
    QMessageBox::information(this, "title", "Undo");
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
    QMessageBox::information(this, "title", "Brush Effects");
}

void MainWindow::drawButtonClicked()
{
    QMessageBox::information(this, "title", "Draw");
}

void MainWindow::eraserButtonClicked()
{
    QMessageBox::information(this, "title", "Eraser");
}

void MainWindow::insertPictureButtonClicked()
{
    QMessageBox::information(this, "title", "Insert Picture");
}

//Cursor
void MainWindow::rotateSignButtonClicked()
{
    canvas->rotateSignPositive = !canvas->rotateSignPositive;
    cursorWidgetRotate->toggleSign(canvas->rotateSignPositive);
}

void MainWindow::reset0ButtonClicked()
{
    canvas->rotateAngle = -1;
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


// STAMPS
void MainWindow::silhouetteButtonClicked()
{
    hideWidgets();

    prompt->promptLabel->setText("Select a stamp. The color tool can be used as well:");
    stampsWidgetSilhouette->show();
}



// SILHOUETTE STAMPS
void MainWindow::goBackButtonClicked()
{
    hideWidgets();
    prompt->promptLabel->setText("Select a stamp category:");
    stampsWidgetCategories->show();
}
void MainWindow::silhouetteStampClicked(const QString stamp_name)
{
    QString path = ":/Stamps/solidcolorstamps/Stamps/";
    QString stamp_path = path.append(stamp_name).append(".png");
    canvas->setCurrentStamp(stamp_path);
}


