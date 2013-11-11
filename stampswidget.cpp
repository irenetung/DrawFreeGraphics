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

    goBack = new QPushButton(QIcon(":/Icons/Icons/undo.png"), tr(""));
    setButtonProperties(goBack);
    dogStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/dog_stamp.png"), tr(""));
    setButtonProperties(dogStamp);
    catStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/cat_stamp.png"), tr(""));
    setButtonProperties(catStamp);
    birdStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/bird_stamp.png"), tr(""));
    setButtonProperties(birdStamp);
    turtleStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/turtle_stamp.png"), tr(""));
    setButtonProperties(turtleStamp);
    ratStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/rat_stamp.png"), tr(""));
    setButtonProperties(ratStamp);
    giraffeStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/giraffe_stamp.png"), tr(""));
    setButtonProperties(giraffeStamp);
    alienStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/alien_stamp.png"), tr(""));
    setButtonProperties(alienStamp);
    manStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/man_stamp.png"), tr(""));
    setButtonProperties(manStamp);
    womanStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/woman_stamp.png"), tr(""));
    setButtonProperties(womanStamp);
    cameraStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/camera_stamp.png"), tr(""));
    setButtonProperties(cameraStamp);
    mailStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/mail_stamp.png"), tr(""));
    setButtonProperties(mailStamp);
    cupStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/cup_stamp.png"), tr(""));
    setButtonProperties(cupStamp);
    giftStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/gift_stamp.png"), tr(""));
    setButtonProperties(giftStamp);
    umbrellaStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/umbrella_stamp.png"), tr(""));
    setButtonProperties(umbrellaStamp);
    securityCamStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/security_cam_stamp.png"), tr(""));
    setButtonProperties(securityCamStamp);
    wrenchStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/wrench_stamp.png"), tr(""));
    setButtonProperties(wrenchStamp);
    heartStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/heart_stamp.png"), tr(""));
    setButtonProperties(heartStamp);
    airplaneStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/airplane_stamp.png"), tr(""));
    setButtonProperties(airplaneStamp);
    helicopterStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/helicopter_stamp.png"), tr(""));
    setButtonProperties(helicopterStamp);
    carStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/car_stamp.png"), tr(""));
    setButtonProperties(carStamp);
    truckStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/truck_stamp.png"), tr(""));
    setButtonProperties(truckStamp);
    busStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/bus_stamp.png"), tr(""));
    setButtonProperties(busStamp);
    gasPumpStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/gas_pump_stamp.png"), tr(""));
    setButtonProperties(gasPumpStamp);
    factoryStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/factory_stamp.png"), tr(""));
    setButtonProperties(factoryStamp);
    buildingStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/building_stamp.png"), tr(""));
    setButtonProperties(buildingStamp);
    capitolStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/capitol_stamp.png"), tr(""));
    setButtonProperties(capitolStamp);
    homeStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/home_stamp.png"), tr(""));
    setButtonProperties(homeStamp);
    sunStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/sun_stamp.png"), tr(""));
    setButtonProperties(sunStamp);
    treeStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/tree_stamp.png"), tr(""));
    setButtonProperties(treeStamp);
    tree2Stamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/tree2_stamp.png"), tr(""));
    setButtonProperties(tree2Stamp);
    cloudStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/cloud_stamp.png"), tr(""));
    setButtonProperties(cloudStamp);
    snowStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/snow_stamp.png"), tr(""));
    setButtonProperties(snowStamp);
    rainStamp = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/rain_stamp.png"), tr(""));
    setButtonProperties(rainStamp);

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);

}


// STAMPS WIDGET ANIMALS
StampsWidgetAnimals::StampsWidgetAnimals()
{
    hLayout = new QHBoxLayout;
    button_length = 60;

    goBack = new QPushButton(QIcon(":/Icons/Icons/undo.png"), tr(""));
    setButtonProperties(goBack);

    // ADD BUTTONS HERE

    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addSpacerItem(horizSpacer);
    this->setLayout(hLayout);

}



