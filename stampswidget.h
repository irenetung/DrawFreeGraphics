#ifndef STAMPSWIDGET_H
#define STAMPSWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QHBoxLayout>

class StampsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StampsWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

protected:
    int dim, button_length;
    QHBoxLayout *hLayout;
    void setButtonProperties(QPushButton *b);

private:
    QPixmap *parea;

};

//Select a stamp category
class StampsWidgetCategories : public StampsWidget
{
public:
    explicit StampsWidgetCategories();
    QPushButton *silhouetteButton;
    QPushButton *animalsButton;
    QPushButton *peopleButton;
    QPushButton *buildingsButton;
    QPushButton *sceneryButton;
    QPushButton *facesButton;
    QPushButton *vehiclesButton;
    QPushButton *actionsButton;
    QPushButton *objectsOneButton;
    QPushButton *objectsTwoButton;
    QPushButton *objectsThreeButton;

};

//Stamp Category: Silhouette
class StampsWidgetSilhouette : public StampsWidget
{
public:
    explicit StampsWidgetSilhouette();
    QPushButton *goBack;
    QPushButton *dogStamp;
    QPushButton *catStamp;
    QPushButton *birdStamp;
    QPushButton *turtleStamp;
    QPushButton *ratStamp;
    QPushButton *giraffeStamp;
    QPushButton *alienStamp;
    QPushButton *manStamp;
    QPushButton *womanStamp;
    QPushButton *cameraStamp;
    QPushButton *mailStamp;
    QPushButton *cupStamp;
    QPushButton *giftStamp;
    QPushButton *umbrellaStamp;
    QPushButton *securityCamStamp;
    QPushButton *wrenchStamp;
    QPushButton *heartStamp;
    QPushButton *airplaneStamp;
    QPushButton *helicopterStamp;
    QPushButton *carStamp;
    QPushButton *truckStamp;
    QPushButton *busStamp;
    QPushButton *gasPumpStamp;
    QPushButton *factoryStamp;
    QPushButton *buildingStamp;
    QPushButton *capitolStamp;
    QPushButton *homeStamp;
    QPushButton *sunStamp;
    QPushButton *treeStamp;
    QPushButton *tree2Stamp;
    QPushButton *cloudStamp;
    QPushButton *snowStamp;
    QPushButton *rainStamp;


};

//Stamp Category: Animals
class StampsWidgetAnimals : public StampsWidget
{
public:
    explicit StampsWidgetAnimals();
    QPushButton *goBack;
    QPushButton *bearStamp;
    QPushButton *beeStamp;
    QPushButton *birdStamp;
    QPushButton *bullStamp;
    QPushButton *catStamp;
    QPushButton *cowStamp;
    QPushButton *crabStamp;
    QPushButton *crocodileStamp;
    QPushButton *deerStamp;
    QPushButton *dogStamp;
    QPushButton *donkeyStamp;
    QPushButton *eagleStamp;
    QPushButton *elephantStamp;
    QPushButton *foxStamp;
    QPushButton *giraffeStamp;
    QPushButton *gorillaStamp;
    QPushButton *hippoStamp;
    QPushButton *horseStamp;
    QPushButton *lionStamp;
    QPushButton *monkeyStamp;
    QPushButton *mooseStamp;
    QPushButton *mouseStamp;
    QPushButton *owlStamp;
    QPushButton *pandaStamp;
    QPushButton *penguinStamp;
    QPushButton *pigStamp;
    QPushButton *rabbitStamp;
    QPushButton *rhinoStamp;
    QPushButton *roosterStamp;
    QPushButton *sheepStamp;
    QPushButton *snakeStamp;
    QPushButton *turkeyStamp;
    QPushButton *wolfStamp;


};

//Stamp Category: Buildings
class StampsWidgetBuildings : public StampsWidget
{
public:
    explicit StampsWidgetBuildings();
    QPushButton *goBack;
    QPushButton *homeOneStamp;
    QPushButton *homeTwoStamp;
    QPushButton *homeThreeStamp;
    QPushButton *homeFourStamp;
    QPushButton *bankStamp;
    QPushButton *schoolStamp;
    QPushButton *hospitalStamp;
    QPushButton *skyscraperStamp;
    QPushButton *buildingStamp;
    QPushButton *multiplexStamp;
    QPushButton *shopOneStamp;
    QPushButton *shopTwoStamp;
    QPushButton *shopThreeStamp;
    QPushButton *shopFourStamp;
    QPushButton *castleStamp;

};

//Stamp Category: Scenery
class StampsWidgetScenery : public StampsWidget
{
public:
    explicit StampsWidgetScenery();
    QPushButton *goBack;
    QPushButton *palmTreeStamp;
    QPushButton *treeOneStamp;
    QPushButton *treeTwoStamp;
    QPushButton *christmasTreeStamp;
    QPushButton *sunStamp;
    QPushButton *moonStamp;
    QPushButton *cloudStamp;
    QPushButton *stormyCloudStamp;
    QPushButton *starsStamp;
    QPushButton *balloonStamp;
    QPushButton *flowerOneStamp;
    QPushButton *flowerTwoStamp;
    QPushButton *flowerThreeStamp;
    QPushButton *bouquetStamp;
    QPushButton *statueStamp;

};

#endif // STAMPSWIDGET_H
