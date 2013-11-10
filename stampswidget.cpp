#include "stampswidget.h"

// STAMPS WIDGET
StampsWidget::StampsWidget(QWidget *parent) :
    QWidget(parent)
{

    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(229,255,204));

    dim = 60;
    button_length = 200;

}

void StampsWidget::resizeEvent(QResizeEvent *e)
{
    int h = e->size().height();
    int w = e->size().width();
    QPixmap temp = this->parea->copy();
    parea = new QPixmap(w,h);
    *parea = temp.scaled(w,h);
}

void StampsWidget::paintEvent(QPaintEvent *e)
{
    if(parea != NULL) {
        QPainter painter(this);
        painter.drawPixmap(0,0,*parea);
    }
}

void StampsWidget::setButtonProperties(QPushButton *b)
{
    b->setFixedWidth(button_length);
    b->setFixedHeight(dim);
    hLayout->addWidget(b);
}


// STAMPS WIDGET CATEGORIES
StampsWidgetCategories::StampsWidgetCategories()
{
    hLayout = new QHBoxLayout;

    silhouetteButton = new QPushButton("Solid Color Buttons");
    setButtonProperties(silhouetteButton);
    animalsButton = new QPushButton("Animals");
    setButtonProperties(animalsButton);
    peopleButton = new QPushButton("People");
    setButtonProperties(peopleButton);
    buildingsButton = new QPushButton("Buildings");
    setButtonProperties(buildingsButton);
    sceneryButton = new QPushButton("Scenery");
    setButtonProperties(sceneryButton);
    facesButton = new QPushButton("Faces");
    setButtonProperties(facesButton);
    vehiclesButton = new QPushButton("Vehicles");
    setButtonProperties(vehiclesButton);
    actionsButton = new QPushButton("Actions");
    setButtonProperties(actionsButton);
    objectsOneButton = new QPushButton("Objects 1");
    setButtonProperties(objectsOneButton);
    objectsTwoButton = new QPushButton("Objects 2");
    setButtonProperties(objectsTwoButton);
    objectsThreeButton = new QPushButton("Objects 3");
    setButtonProperties(objectsThreeButton);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);
}


// STAMPS WIDGET SILHOUETTE
StampsWidgetSilhouette::StampsWidgetSilhouette()
{
    hLayout = new QHBoxLayout;
    button_length = 60;

    dogStamp = new QPushButton(QIcon(":/Stamps/Stamps/dog_stamp.png"), tr(""));
    setButtonProperties(dogStamp);
    catStamp = new QPushButton(QIcon(":/Stamps/Stamps/cat_stamp.png"), tr(""));
    setButtonProperties(catStamp);
    birdStamp = new QPushButton(QIcon(":/Stamps/Stamps/bird_stamp.png"), tr(""));
    setButtonProperties(birdStamp);
    manStamp = new QPushButton(QIcon(":/Stamps/Stamps/man_stamp.png"), tr(""));
    setButtonProperties(manStamp);
    womanStamp = new QPushButton(QIcon(":/Stamps/Stamps/woman_stamp.png"), tr(""));
    setButtonProperties(womanStamp);s

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);

}



