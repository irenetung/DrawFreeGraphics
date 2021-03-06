#ifndef STAMPSWIDGET_H
#define STAMPSWIDGET_H

#include "basewidget.h"
#include "canvas.h"

class StampsWidget : public BaseWidget
{
public:
    explicit StampsWidget();
};

//Select a stamp category
class StampsWidgetCategories : public StampsWidget
{
public:
    explicit StampsWidgetCategories();
    QPushButton *recentsButton;
    QPushButton *silhouetteButton;
    QPushButton *animalsButton;
    QPushButton *peopleButton;
    QPushButton *buildingsButton;
    QPushButton *sceneryButton;
    QPushButton *facesButton;
    QPushButton *vehiclesButton;
    QPushButton *foodButton;

};

//Stamp Category: Recents
class StampsWidgetRecents : public StampsWidget
{
public:
    explicit StampsWidgetRecents();
    QPushButton *goBack;
    QList<QPushButton*> recentStampsButtonList;
    QList<QString> recentStampsPathList;
    QList<Canvas::StampState> recentStampsTypeList;

    int buttonCount;
    int buttonLimit;

    void refresh();

};


//Stamp Category: Silhouette
class StampsWidgetSilhouette : public StampsWidget
{
public:
    explicit StampsWidgetSilhouette();
    QPushButton *goBack;
    QPushButton *silhouetteColorButton;
    QPushButton *stampOne;
    QPushButton *stampTwo;
    QPushButton *stampThree;
    QPushButton *stampFour;
    QPushButton *stampFive;
    QPushButton *stampSix;
    QPushButton *stampSeven;
    QPushButton *stampEight;
    QPushButton *stampNine;
    QPushButton *stampTen;
    QPushButton *stampEleven;
    QPushButton *stampTwelve;
    QPushButton *stampThirteen;
    QPushButton *stampFourteen;
    QPushButton *stampFifteen;
    QPushButton *stampSixteen;
    QPushButton *stampSeventeen;
    QPushButton *stampEighteen;
    QPushButton *stampNineteen;
    QPushButton *stampTwenty;
    QPushButton *stampTwentyOne;
    QPushButton *stampTwentyTwo;
    QPushButton *stampTwentyThree;
    QPushButton *stampTwentyFour;
    QPushButton *stampTwentyFive;
    QPushButton *stampTwentySix;
    QPushButton *stampTwentySeven;
    QPushButton *stampTwentyEight;
    QPushButton *stampTwentyNine;
    QPushButton *stampThirty;
    QPushButton *stampThirtyOne;
    QPushButton *stampThirtyTwo;
    QPushButton *stampThirtyThree;
    QPushButton *invisibleButton;
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
    QPushButton *invisibleButton;

};

//Stamp Category: People
class StampsWidgetPeople : public StampsWidget
{
public:
    explicit StampsWidgetPeople();
    QPushButton *goBack;
    QPushButton *stampOne;
    QPushButton *stampTwo;
    QPushButton *stampThree;
    QPushButton *stampFour;
    QPushButton *stampFive;
    QPushButton *stampSix;
    QPushButton *stampSeven;
    QPushButton *stampEight;
    QPushButton *stampNine;
    QPushButton *stampTen;
    QPushButton *stampEleven;
    QPushButton *stampTwelve;
    QPushButton *stampThirteen;
    QPushButton *stampFourteen;
    QPushButton *stampFifteen;
    QPushButton *stampSixteen;
    QPushButton *stampSeventeen;
    QPushButton *stampEighteen;
    QPushButton *stampNineteen;
    QPushButton *stampTwenty;
    QPushButton *stampTwentyOne;
    QPushButton *stampTwentyTwo;
    QPushButton *stampTwentyThree;
    QPushButton *stampTwentyFour;
    QPushButton *stampTwentyFive;
    QPushButton *stampTwentySix;
    QPushButton *stampTwentySeven;
    QPushButton *stampTwentyEight;
    QPushButton *stampTwentyNine;
    QPushButton *stampThirty;
    QPushButton *stampThirtyOne;
    QPushButton *stampThirtyTwo;
    QPushButton *stampThirtyThree;
    QPushButton *invisibleButton;
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
    QPushButton *invisibleButton;
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
    QPushButton *invisibleButton;
};

//Stamp Category: Faces
class StampsWidgetFaces : public StampsWidget
{
public:
    explicit StampsWidgetFaces();
    QPushButton *goBack;
    QPushButton *stampOne;
    QPushButton *stampTwo;
    QPushButton *stampThree;
    QPushButton *stampFour;
    QPushButton *stampFive;
    QPushButton *stampSix;
    QPushButton *stampSeven;
    QPushButton *stampEight;
    QPushButton *stampNine;
    QPushButton *stampTen;
    QPushButton *stampEleven;
    QPushButton *stampTwelve;
    QPushButton *stampThirteen;
    QPushButton *stampFourteen;
    QPushButton *stampFifteen;
    QPushButton *stampSixteen;
    QPushButton *stampSeventeen;
    QPushButton *stampEighteen;
    QPushButton *stampNineteen;
    QPushButton *stampTwenty;
    QPushButton *stampTwentyOne;
    QPushButton *stampTwentyTwo;
    QPushButton *stampTwentyThree;
    QPushButton *stampTwentyFour;
    QPushButton *stampTwentyFive;
    QPushButton *stampTwentySix;
    QPushButton *stampTwentySeven;
    QPushButton *stampTwentyEight;
    QPushButton *stampTwentyNine;
    QPushButton *stampThirty;
    QPushButton *stampThirtyOne;
    QPushButton *stampThirtyTwo;
    QPushButton *invisibleButton;
};

//Stamp Category: Vehicles
class StampsWidgetVehicles : public StampsWidget
{
public:
    explicit StampsWidgetVehicles();
    QPushButton *goBack;
    QPushButton *stampOne;
    QPushButton *stampTwo;
    QPushButton *stampThree;
    QPushButton *stampFour;
    QPushButton *stampFive;
    QPushButton *stampSix;
    QPushButton *stampSeven;
    QPushButton *stampEight;
    QPushButton *stampNine;
    QPushButton *stampTen;
    QPushButton *stampEleven;
    QPushButton *stampTwelve;
    QPushButton *stampThirteen;
    QPushButton *stampFourteen;
    QPushButton *stampFifteen;
    QPushButton *stampSixteen;
    QPushButton *stampSeventeen;
    QPushButton *stampEighteen;
    QPushButton *stampNineteen;
    QPushButton *stampTwenty;
    QPushButton *stampTwentyOne;
    QPushButton *stampTwentyTwo;
    QPushButton *stampTwentyThree;
    QPushButton *stampTwentyFour;
    QPushButton *stampTwentyFive;
    QPushButton *invisibleButton;
};


//Stamp Category: Food
class StampsWidgetFood : public StampsWidget
{
public:
    explicit StampsWidgetFood();
    QPushButton *goBack;
    QPushButton *stampOne;
    QPushButton *stampTwo;
    QPushButton *stampThree;
    QPushButton *stampFour;
    QPushButton *stampFive;
    QPushButton *stampSix;
    QPushButton *stampSeven;
    QPushButton *stampEight;
    QPushButton *stampNine;
    QPushButton *stampTen;
    QPushButton *stampEleven;
    QPushButton *stampTwelve;
    QPushButton *stampThirteen;
    QPushButton *stampFourteen;
    QPushButton *stampFifteen;
    QPushButton *stampSixteen;
    QPushButton *stampSeventeen;
    QPushButton *stampEighteen;
    QPushButton *stampNineteen;
    QPushButton *stampTwenty;
    QPushButton *stampTwentyOne;
    QPushButton *stampTwentyTwo;
    QPushButton *stampTwentyThree;
    QPushButton *stampTwentyFour;
    QPushButton *stampTwentyFive;
    QPushButton *stampTwentySix;
    QPushButton *stampTwentySeven;
    QPushButton *invisibleButton;
};


#endif // STAMPSWIDGET_H
