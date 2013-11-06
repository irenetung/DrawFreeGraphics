#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dim = 60;

    //Toolbar
    ui->mainToolBar->setIconSize(QSize(dim,dim));

    newButton = new QToolButton;
    newButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    newButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/new.png"));
    newButton->setText("New");
    connect(newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));

    openButton = new QToolButton;
    openButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    openButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/open.png"));
    openButton->setText("Open");
    connect(openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));

    saveButton = new QToolButton;
    saveButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    saveButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/save.png"));
    saveButton->setText("Save");
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));

    undoButton = new QToolButton;
    undoButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    undoButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/undo.png"));
    undoButton->setText("Undo");
    connect(undoButton, SIGNAL(clicked()), this, SLOT(undoButtonClicked()));

    cursorButton = new QToolButton;
    cursorButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    cursorButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/cursor.png"));
    cursorButton->setText("Cursor");
    connect(cursorButton, SIGNAL(clicked()), this, SLOT(cursorButtonClicked()));

    colorsButton = new QToolButton;
    colorsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    colorsButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/colors.png"));
    colorsButton->setText("Colors");
    connect(colorsButton, SIGNAL(clicked()), this, SLOT(colorsButtonClicked()));

    shapesButton = new QToolButton;
    shapesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    shapesButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/shapes.png"));
    shapesButton->setText("Shapes");
    connect(shapesButton, SIGNAL(clicked()), this, SLOT(shapesButtonClicked()));

    stampsButton = new QToolButton;
    stampsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    stampsButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/stamps.png"));
    stampsButton->setText("Stamps");
    connect(stampsButton, SIGNAL(clicked()), this, SLOT(stampsButtonClicked()));

    brushEffectsButton = new QToolButton;
    brushEffectsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    brushEffectsButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/brushEffects.png"));
    brushEffectsButton->setText("Brush Effects");
    connect(brushEffectsButton, SIGNAL(clicked()), this, SLOT(brushEffectsButtonClicked()));

    drawButton = new QToolButton;
    drawButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    drawButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/draw.png"));
    drawButton->setText("Draw");
    connect(drawButton, SIGNAL(clicked()), this, SLOT(drawButtonClicked()));

    eraserButton = new QToolButton;
    eraserButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    eraserButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/eraser.png"));
    eraserButton->setText("Eraser");
    connect(eraserButton, SIGNAL(clicked()), this, SLOT(eraserButtonClicked()));

    insertPictureButton = new QToolButton;
    insertPictureButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    insertPictureButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/insertPicture.png"));
    insertPictureButton->setText("Insert Picture");
    connect(insertPictureButton, SIGNAL(clicked()), this, SLOT(insertPictureButtonClicked()));

    closeButton = new QToolButton;
    closeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    closeButton->setIcon(QIcon("C:/Qt/Tools/QtCreator/bin/DrawFreeApplication/Icons/close.png"));
    closeButton->setText("Close");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    ui->mainToolBar->addWidget(newButton);
    ui->mainToolBar->addWidget(openButton);
    ui->mainToolBar->addWidget(saveButton);
    ui->mainToolBar->addWidget(undoButton);
    ui->mainToolBar->addWidget(cursorButton);
    ui->mainToolBar->addWidget(colorsButton);
    ui->mainToolBar->addWidget(shapesButton);
    ui->mainToolBar->addWidget(stampsButton);
    ui->mainToolBar->addWidget(brushEffectsButton);
    ui->mainToolBar->addWidget(drawButton);
    ui->mainToolBar->addWidget(eraserButton);
    ui->mainToolBar->addWidget(insertPictureButton);
    ui->mainToolBar->addWidget(closeButton);

//Tool Widgets
    //Prompt
    prompt = new Prompt();
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

    //Canvas
    canvas = new Canvas();

    //Application Layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(prompt);
    vLayout->addWidget(shapesWidgetShapes);
    vLayout->addWidget(shapesWidgetEndPath);
    vLayout->addWidget(canvas);
    this->centralWidget()->setLayout(vLayout);

    hideWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideWidgets()
{
    shapesWidgetShapes->hide();
    shapesWidgetEndPath->hide();
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
    QMessageBox::information(this, "title", "Stamps");
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

//Shapes
void MainWindow::previousShapeButtonClicked()
{
    QMessageBox::information(this, "title", "Previous Shape");
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
        QGraphicsPolygonItem *polygonItem = canvas->scene->addPolygon(polygon,*(canvas->pen),*(canvas->brush));
        polygonItem->setTransformOriginPoint(polygonItem->boundingRect().center());
    } else if(canvas->shapeState == canvas->PATH) {
        PathItem *pathItem = new PathItem(polygon,canvas->points,*(canvas->pen),*(canvas->brush));
        canvas->scene->addItem(pathItem);
        pathItem->setTransformOriginPoint(pathItem->boundingRect().center());

    } else {
    }

    update();
    canvas->shapeState = canvas->NOSHAPE;

    canvas->mousePressCount = 0;
    canvas->points.clear();

}


