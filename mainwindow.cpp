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

    //Canvas
    canvas = new Canvas();

    //Application Layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(prompt);
    vLayout->addWidget(shapesWidgetShapes);
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
    QMessageBox::information(this, "title", "Line");

    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)First end point 2)Second end point"));

}

void MainWindow::pointButtonClicked()
{
    QMessageBox::information(this, "title", "Point");
    prompt->promptLabel->setText(tr("Click one point on the canvas"));
}

void MainWindow::circleButtonClicked()
{
    QMessageBox::information(this, "title", "Circle");
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::rectangleButtonClicked()
{
    canvas->shapeState = canvas->RECT;
    prompt->promptLabel->setText(tr("Click two points on the canvas: 1)Top left corner 2)Bottom right corner"));
}

void MainWindow::roundedRectangleButtonClicked()
{
    canvas->shapeState = canvas->NOSHAPE;
    QMessageBox::information(this, "title", "Rounded Rectangle");

}

void MainWindow::polygonButtonClicked()
{
    QMessageBox::information(this, "title", "Polygon");;
}

void MainWindow::arcButtonClicked()
{
    QMessageBox::information(this, "title", "Arc");
}

void MainWindow::chordButtonClicked()
{
    QMessageBox::information(this, "title", "Chord");
}

void MainWindow::pieButtonClicked()
{
    QMessageBox::information(this, "title", "Pie");
}

void MainWindow::pathButtonClicked()
{
    QMessageBox::information(this, "title", "Path");
}

void MainWindow::textButtonClicked()
{
    QMessageBox::information(this, "title", "Text");
}



