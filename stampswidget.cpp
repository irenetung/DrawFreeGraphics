#include "stampswidget.h"
#include <QDebug>


// STAMPS WIDGET
StampsWidget::StampsWidget()
{
    int h = this->size().height();
    int w = this->size().width();
    parea = new QPixmap(w,h);
    parea->fill(QColor(153,255,204));
    this->setStyleSheet("QPushButton{background-color:#CCFFFF; border-color:#009999; border-style:solid; border-width:3px; border-radius:3px;}"
                        "QPushButton:checked{background-color:#E5CCFF; border-color:#9933FF;}"
                        "QPushButton:hover{background-color:#FF99FF; border-color:#CC00CC;}");
}

// STAMPS WIDGET CATEGORIES
StampsWidgetCategories::StampsWidgetCategories()
{

    hLayout = new FlowLayout;

    recentsButton = new QPushButton("Recent\nStamps");
    setButtonProperties(recentsButton);
    silhouetteButton = new QPushButton("Silhouette\nStamps");
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
    foodButton = new QPushButton("Food");
    setButtonProperties(foodButton);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET RECENTS
StampsWidgetRecents::StampsWidgetRecents()
{
    buttonCount = 0;
    buttonLimit = 20;

    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}
void StampsWidgetRecents::refresh()
{

    // cycle through buttons to test for duplicates

    int index = recentStampsPathList.indexOf(recentStampsPathList.front(), 2);
    if (index != -1)
    {
        qDebug() << "Duplicate Found...";
        int layout_index = hLayout->indexOf(recentStampsButtonList.at(index));
        QLayoutItem *item = hLayout->takeAt(layout_index);
        delete item->widget();
        delete item;

        recentStampsButtonList.removeAt(index);
        recentStampsPathList.removeAt(index);
        recentStampsTypeList.removeAt(index);
        buttons.remove(index);
    }

    buttonCount = recentStampsButtonList.size();
    qDebug() << buttonCount;

    // test button limit
    if (buttonCount > buttonLimit)
    {
        qDebug() << "Button Count is greater than limit. Popping back...";
        int index = hLayout->indexOf(recentStampsButtonList.back());
        QLayoutItem *item = hLayout->takeAt(index);
        delete item->widget();
        delete item;
        recentStampsButtonList.removeLast();
        recentStampsPathList.removeLast();
        recentStampsTypeList.removeLast();
        buttons.removeFirst();

    }

    // rebuild layout
    for (int i = 0; i < recentStampsButtonList.size(); i++)
    {
        qDebug() << recentStampsPathList.at(i);
        setButtonProperties(recentStampsButtonList.at(i));
    }
    this->setLayout(hLayout);

}


// STAMPS WIDGET SILHOUETTE
StampsWidgetSilhouette::StampsWidgetSilhouette()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    silhouetteColorButton = new QPushButton("Set\nSilhouette\nColor");
    silhouetteColorButton->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(silhouetteColorButton);
    stampOne = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_dog_stamp.png"), tr(""));
    setButtonProperties(stampOne);
    stampTwo = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_cat_stamp.png"), tr(""));
    setButtonProperties(stampTwo);
    stampThree = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_bird_stamp.png"), tr(""));
    setButtonProperties(stampThree);
    stampFour = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_turtle_stamp.png"), tr(""));
    setButtonProperties(stampFour);
    stampFive = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_rat_stamp.png"), tr(""));
    setButtonProperties(stampFive);
    stampSix = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_giraffe_stamp.png"), tr(""));
    setButtonProperties(stampSix);
    stampSeven = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_alien_stamp.png"), tr(""));
    setButtonProperties(stampSeven);
    stampEight = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_man_stamp.png"), tr(""));
    setButtonProperties(stampEight);
    stampNine = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_woman_stamp.png"), tr(""));
    setButtonProperties(stampNine);
    stampTen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_camera_stamp.png"), tr(""));
    setButtonProperties(stampTen);
    stampEleven = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_mail_stamp.png"), tr(""));
    setButtonProperties(stampEleven);
    stampTwelve = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_cup_stamp.png"), tr(""));
    setButtonProperties(stampTwelve);
    stampThirteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_gift_stamp.png"), tr(""));
    setButtonProperties(stampThirteen);
    stampFourteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_umbrella_stamp.png"), tr(""));
    setButtonProperties(stampFourteen);
    stampFifteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_security_cam_stamp.png"), tr(""));
    setButtonProperties(stampFifteen);
    stampSixteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_wrench_stamp.png"), tr(""));
    setButtonProperties(stampSixteen);
    stampSeventeen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_heart_stamp.png"), tr(""));
    setButtonProperties(stampSeventeen);
    stampEighteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_airplane_stamp.png"), tr(""));
    setButtonProperties(stampEighteen);
    stampNineteen = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_helicopter_stamp.png"), tr(""));
    setButtonProperties(stampNineteen);
    stampTwenty = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_car_stamp.png"), tr(""));
    setButtonProperties(stampTwenty);
    stampTwentyOne = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_truck_stamp.png"), tr(""));
    setButtonProperties(stampTwentyOne);
    stampTwentyTwo = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_bus_stamp.png"), tr(""));
    setButtonProperties(stampTwentyTwo);
    stampTwentyThree = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_gas_pump_stamp.png"), tr(""));
    setButtonProperties(stampTwentyThree);
    stampTwentyFour = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_factory_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFour);
    stampTwentyFive = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_building_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFive);
    stampTwentySix = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_capitol_stamp.png"), tr(""));
    setButtonProperties(stampTwentySix);
    stampTwentySeven = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_home_stamp.png"), tr(""));
    setButtonProperties(stampTwentySeven);
    stampTwentyEight = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_sun_stamp.png"), tr(""));
    setButtonProperties(stampTwentyEight);
    stampTwentyNine = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_forest_stamp.png"), tr(""));
    setButtonProperties(stampTwentyNine);
    stampThirty = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_tree_stamp.png"), tr(""));
    setButtonProperties(stampThirty);
    stampThirtyOne = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_cloud_stamp.png"), tr(""));
    setButtonProperties(stampThirtyOne);
    stampThirtyTwo = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_snow_stamp.png"), tr(""));
    setButtonProperties(stampThirtyTwo);
    stampThirtyThree = new QPushButton(QIcon(":/Stamps/solidcolorstamps/Stamps/solid_rain_stamp.png"), tr(""));
    setButtonProperties(stampThirtyThree);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET ANIMALS
StampsWidgetAnimals::StampsWidgetAnimals()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    bearStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_bear_stamp.png"), tr(""));
    setButtonProperties(bearStamp);
    beeStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_bee_stamp.png"), tr(""));
    setButtonProperties(beeStamp);
    birdStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_bird_stamp.png"), tr(""));
    setButtonProperties(birdStamp);
    bullStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_bull_stamp.png"), tr(""));
    setButtonProperties(bullStamp);
    catStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_cat_stamp.png"), tr(""));
    setButtonProperties(catStamp);
    cowStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_cow_stamp.png"), tr(""));
    setButtonProperties(cowStamp);
    crabStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_crab_stamp.png"), tr(""));
    setButtonProperties(crabStamp);
    crocodileStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_crocodile_stamp.png"), tr(""));
    setButtonProperties(crocodileStamp);
    deerStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_deer_stamp.png"), tr(""));
    setButtonProperties(deerStamp);
    dogStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_dog_stamp.png"), tr(""));
    setButtonProperties(dogStamp);
    donkeyStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_donkey_stamp.png"), tr(""));
    setButtonProperties(donkeyStamp);
    eagleStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_eagle_stamp.png"), tr(""));
    setButtonProperties(eagleStamp);
    elephantStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_elephant_stamp.png"), tr(""));
    setButtonProperties(elephantStamp);
    foxStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_fox_stamp.png"), tr(""));
    setButtonProperties(foxStamp);
    giraffeStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_giraffe_stamp.png"), tr(""));
    setButtonProperties(giraffeStamp);
    gorillaStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_gorilla_stamp.png"), tr(""));
    setButtonProperties(gorillaStamp);
    hippoStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_hippo_stamp.png"), tr(""));
    setButtonProperties(hippoStamp);
    horseStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_horse_stamp.png"), tr(""));
    setButtonProperties(horseStamp);
    lionStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_lion_stamp.png"), tr(""));
    setButtonProperties(lionStamp);
    monkeyStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_monkey_stamp.png"), tr(""));
    setButtonProperties(monkeyStamp);
    mooseStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_moose_stamp.png"), tr(""));
    setButtonProperties(mooseStamp);
    mouseStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_mouse_stamp.png"), tr(""));
    setButtonProperties(mouseStamp);
    owlStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_owl_stamp.png"), tr(""));
    setButtonProperties(owlStamp);
    pandaStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_panda_stamp.png"), tr(""));
    setButtonProperties(pandaStamp);
    penguinStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_penguin_stamp.png"), tr(""));
    setButtonProperties(penguinStamp);
    pigStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_pig_stamp.png"), tr(""));
    setButtonProperties(pigStamp);
    rabbitStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_rabbit_stamp.png"), tr(""));
    setButtonProperties(rabbitStamp);
    rhinoStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_rhino_stamp.png"), tr(""));
    setButtonProperties(rhinoStamp);
    roosterStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_rooster_stamp.png"), tr(""));
    setButtonProperties(roosterStamp);
    sheepStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_sheep_stamp.png"), tr(""));
    setButtonProperties(sheepStamp);
    snakeStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_snake_stamp.png"), tr(""));
    setButtonProperties(snakeStamp);
    turkeyStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_turkey_stamp.png"), tr(""));
    setButtonProperties(turkeyStamp);
    wolfStamp = new QPushButton(QIcon(":/Stamps/animals/Stamps/animal_wolf_stamp.png"), tr(""));
    setButtonProperties(wolfStamp);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET PEOPLE
StampsWidgetPeople::StampsWidgetPeople(){
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    stampOne = new QPushButton(QIcon(":/Stamps/people/Stamps/people_angel_stamp.png"), tr(""));
    setButtonProperties(stampOne);
    stampTwo = new QPushButton(QIcon(":/Stamps/people/Stamps/people_baby_stamp.png"), tr(""));
    setButtonProperties(stampTwo);
    stampThree = new QPushButton(QIcon(":/Stamps/people/Stamps/people_chef_stamp.png"), tr(""));
    setButtonProperties(stampThree);
    stampFour = new QPushButton(QIcon(":/Stamps/people/Stamps/people_clown_stamp.png"), tr(""));
    setButtonProperties(stampFour);
    stampFive = new QPushButton(QIcon(":/Stamps/people/Stamps/people_dad_stamp.png"), tr(""));
    setButtonProperties(stampFive);
    stampSix = new QPushButton(QIcon(":/Stamps/people/Stamps/people_devil_stamp.png"), tr(""));
    setButtonProperties(stampSix);
    stampSeven = new QPushButton(QIcon(":/Stamps/people/Stamps/people_doctor_stamp.png"), tr(""));
    setButtonProperties(stampSeven);
    stampEight = new QPushButton(QIcon(":/Stamps/people/Stamps/people_fireman_stamp.png"), tr(""));
    setButtonProperties(stampEight);
    stampNine = new QPushButton(QIcon(":/Stamps/people/Stamps/people_ghost_stamp.png"), tr(""));
    setButtonProperties(stampNine);
    stampTen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_girl_stamp.png"), tr(""));
    setButtonProperties(stampTen);
    stampEleven = new QPushButton(QIcon(":/Stamps/people/Stamps/people_kid_stamp.png"), tr(""));
    setButtonProperties(stampEleven);
    stampTwelve = new QPushButton(QIcon(":/Stamps/people/Stamps/people_king_stamp.png"), tr(""));
    setButtonProperties(stampTwelve);
    stampThirteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_knight_stamp.png"), tr(""));
    setButtonProperties(stampThirteen);
    stampFourteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_lawyer_stamp.png"), tr(""));
    setButtonProperties(stampFourteen);
    stampFifteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_leprechaun_stamp.png"), tr(""));
    setButtonProperties(stampFifteen);
    stampSixteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_man_stamp.png"), tr(""));
    setButtonProperties(stampSixteen);
    stampSeventeen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_mermaid_stamp.png"), tr(""));
    setButtonProperties(stampSeventeen);
    stampEighteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_ninja_stamp.png"), tr(""));
    setButtonProperties(stampEighteen);
    stampNineteen = new QPushButton(QIcon(":/Stamps/people/Stamps/people_nurse_stamp.png"), tr(""));
    setButtonProperties(stampNineteen);
    stampTwenty = new QPushButton(QIcon(":/Stamps/people/Stamps/people_pirate_stamp.png"), tr(""));
    setButtonProperties(stampTwenty);
    stampTwentyOne = new QPushButton(QIcon(":/Stamps/people/Stamps/people_policeman_stamp.png"), tr(""));
    setButtonProperties(stampTwentyOne);
    stampTwentyTwo = new QPushButton(QIcon(":/Stamps/people/Stamps/people_prince_stamp.png"), tr(""));
    setButtonProperties(stampTwentyTwo);
    stampTwentyThree = new QPushButton(QIcon(":/Stamps/people/Stamps/people_princess_stamp.png"), tr(""));
    setButtonProperties(stampTwentyThree);
    stampTwentyFour = new QPushButton(QIcon(":/Stamps/people/Stamps/people_queen_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFour);
    stampTwentyFive = new QPushButton(QIcon(":/Stamps/people/Stamps/people_robot_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFive);
    stampTwentySix = new QPushButton(QIcon(":/Stamps/people/Stamps/people_santa_stamp.png"), tr(""));
    setButtonProperties(stampTwentySix);
    stampTwentySeven = new QPushButton(QIcon(":/Stamps/people/Stamps/people_snowman_stamp.png"), tr(""));
    setButtonProperties(stampTwentySeven);
    stampTwentyEight = new QPushButton(QIcon(":/Stamps/people/Stamps/people_superhero_stamp.png"), tr(""));
    setButtonProperties(stampTwentyEight);
    stampTwentyNine = new QPushButton(QIcon(":/Stamps/people/Stamps/people_teacher_stamp.png"), tr(""));
    setButtonProperties(stampTwentyNine);
    stampThirty = new QPushButton(QIcon(":/Stamps/people/Stamps/people_troll_stamp.png"), tr(""));
    setButtonProperties(stampThirty);
    stampThirtyOne = new QPushButton(QIcon(":/Stamps/people/Stamps/people_vampire_stamp.png"), tr(""));
    setButtonProperties(stampThirtyOne);
    stampThirtyTwo = new QPushButton(QIcon(":/Stamps/people/Stamps/people_witch_stamp.png"), tr(""));
    setButtonProperties(stampThirtyTwo);
    stampThirtyThree = new QPushButton(QIcon(":/Stamps/people/Stamps/people_zombie_stamp.png"), tr(""));
    setButtonProperties(stampThirtyThree);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET BUILDINGS
StampsWidgetBuildings::StampsWidgetBuildings()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    homeOneStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_home_one_stamp.png"), tr(""));
    setButtonProperties(homeOneStamp);
    homeTwoStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_home_two_stamp.png"), tr(""));
    setButtonProperties(homeTwoStamp);
    homeThreeStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_home_three_stamp.png"), tr(""));
    setButtonProperties(homeThreeStamp);
    homeFourStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_home_four_stamp.png"), tr(""));
    setButtonProperties(homeFourStamp);
    bankStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_bank_stamp.png"), tr(""));
    setButtonProperties(bankStamp);
    schoolStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_school_stamp.png"), tr(""));
    setButtonProperties(schoolStamp);
    hospitalStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_hospital_stamp.png"), tr(""));
    setButtonProperties(hospitalStamp);
    skyscraperStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_skyscraper_stamp.png"), tr(""));
    setButtonProperties(skyscraperStamp);
    buildingStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_building_stamp.png"), tr(""));
    setButtonProperties(buildingStamp);
    multiplexStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_multiplex_stamp.png"), tr(""));
    setButtonProperties(multiplexStamp);
    shopOneStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_shop_one_stamp.png"), tr(""));
    setButtonProperties(shopOneStamp);
    shopTwoStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_shop_two_stamp.png"), tr(""));
    setButtonProperties(shopTwoStamp);
    shopThreeStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_shop_three_stamp.png"), tr(""));
    setButtonProperties(shopThreeStamp);
    shopFourStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_shop_four_stamp.png"), tr(""));
    setButtonProperties(shopFourStamp);
    castleStamp = new QPushButton(QIcon(":/Stamps/buildings/Stamps/buildings_castle_stamp.png"), tr(""));
    setButtonProperties(castleStamp);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET SCENERY
StampsWidgetScenery::StampsWidgetScenery()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    palmTreeStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_palm_tree_stamp.png"), tr(""));
    setButtonProperties(palmTreeStamp);
    treeOneStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_tree_one_stamp.png"), tr(""));
    setButtonProperties(treeOneStamp);
    treeTwoStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_tree_two_stamp.png"), tr(""));
    setButtonProperties(treeTwoStamp);
    christmasTreeStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_christmas_tree_stamp.png"), tr(""));
    setButtonProperties(christmasTreeStamp);
    sunStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_sun_stamp.png"), tr(""));
    setButtonProperties(sunStamp);
    moonStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_moon_stamp.png"), tr(""));
    setButtonProperties(moonStamp);
    cloudStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_cloud_stamp.png"), tr(""));
    setButtonProperties(cloudStamp);
    stormyCloudStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_stormy_cloud_stamp.png"), tr(""));
    setButtonProperties(stormyCloudStamp);
    starsStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_stars_stamp.png"), tr(""));
    setButtonProperties(starsStamp);
    balloonStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_balloon_stamp.png"), tr(""));
    setButtonProperties(balloonStamp);
    flowerOneStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_flower_one_stamp.png"), tr(""));
    setButtonProperties(flowerOneStamp);
    flowerTwoStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_flower_two_stamp.png"), tr(""));
    setButtonProperties(flowerTwoStamp);
    flowerThreeStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_flower_three_stamp.png"), tr(""));
    setButtonProperties(flowerThreeStamp);
    bouquetStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_bouquet_stamp.png"), tr(""));
    setButtonProperties(bouquetStamp);
    statueStamp = new QPushButton(QIcon(":/Stamps/scenery/Stamps/scenery_statue_stamp.png"), tr(""));
    setButtonProperties(statueStamp);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}


// STAMPS WIDGET FACES
StampsWidgetFaces::StampsWidgetFaces()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    stampOne = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_one_stamp.png"), tr(""));
    setButtonProperties(stampOne);
    stampTwo = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_two_stamp.png"), tr(""));
    setButtonProperties(stampTwo);
    stampThree = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_three_stamp.png"), tr(""));
    setButtonProperties(stampThree);
    stampFour = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_four_stamp.png"), tr(""));
    setButtonProperties(stampFour);
    stampFive = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_five_stamp.png"), tr(""));
    setButtonProperties(stampFive);
    stampSix = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_six_stamp.png"), tr(""));
    setButtonProperties(stampSix);
    stampSeven = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_seven_stamp.png"), tr(""));
    setButtonProperties(stampSeven);
    stampEight = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_eight_stamp.png"), tr(""));
    setButtonProperties(stampEight);
    stampNine = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_nine_stamp.png"), tr(""));
    setButtonProperties(stampNine);
    stampTen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_ten_stamp.png"), tr(""));
    setButtonProperties(stampTen);
    stampEleven = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_eleven_stamp.png"), tr(""));
    setButtonProperties(stampEleven);
    stampTwelve = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twelve_stamp.png"), tr(""));
    setButtonProperties(stampTwelve);
    stampThirteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_thirteen_stamp.png"), tr(""));
    setButtonProperties(stampThirteen);
    stampFourteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_fourteen_stamp.png"), tr(""));
    setButtonProperties(stampFourteen);
    stampFifteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_fifteen_stamp.png"), tr(""));
    setButtonProperties(stampFifteen);
    stampSixteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_sixteen_stamp.png"), tr(""));
    setButtonProperties(stampSixteen);
    stampSeventeen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_seventeen_stamp.png"), tr(""));
    setButtonProperties(stampSeventeen);
    stampEighteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_eighteen_stamp.png"), tr(""));
    setButtonProperties(stampEighteen);
    stampNineteen = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_nineteen_stamp.png"), tr(""));
    setButtonProperties(stampNineteen);
    stampTwenty = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twenty_stamp.png"), tr(""));
    setButtonProperties(stampTwenty);
    stampTwentyOne = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentyone_stamp.png"), tr(""));
    setButtonProperties(stampTwentyOne);
    stampTwentyTwo = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentytwo_stamp.png"), tr(""));
    setButtonProperties(stampTwentyTwo);
    stampTwentyThree = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentythree_stamp.png"), tr(""));
    setButtonProperties(stampTwentyThree);
    stampTwentyFour = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentyfour_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFour);
    stampTwentyFive = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentyfive_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFive);
    stampTwentySix = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentysix_stamp.png"), tr(""));
    setButtonProperties(stampTwentySix);
    stampTwentySeven = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentyseven_stamp.png"), tr(""));
    setButtonProperties(stampTwentySeven);
    stampTwentyEight = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentyeight_stamp.png"), tr(""));
    setButtonProperties(stampTwentyEight);
    stampTwentyNine = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_twentynine_stamp.png"), tr(""));
    setButtonProperties(stampTwentyNine);
    stampThirty = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_thirty_stamp.png"), tr(""));
    setButtonProperties(stampThirty);
    stampThirtyOne = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_thirtyone_stamp.png"), tr(""));
    setButtonProperties(stampThirtyOne);
    stampThirtyTwo = new QPushButton(QIcon(":/Stamps/faces/Stamps/faces_thirtytwo_stamp.png"), tr(""));
    setButtonProperties(stampThirtyTwo);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

// STAMPS WIDGET VEHICLES
StampsWidgetVehicles::StampsWidgetVehicles()
{
    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);
    stampOne = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_one_stamp.png"), tr(""));
    setButtonProperties(stampOne);
    stampTwo = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_two_stamp.png"), tr(""));
    setButtonProperties(stampTwo);
    stampThree = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_three_stamp.png"), tr(""));
    setButtonProperties(stampThree);
    stampFour = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_four_stamp.png"), tr(""));
    setButtonProperties(stampFour);
    stampFive = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_five_stamp.png"), tr(""));
    setButtonProperties(stampFive);
    stampSix = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_six_stamp.png"), tr(""));
    setButtonProperties(stampSix);
    stampSeven = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_seven_stamp.png"), tr(""));
    setButtonProperties(stampSeven);
    stampEight = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_eight_stamp.png"), tr(""));
    setButtonProperties(stampEight);
    stampNine = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_nine_stamp.png"), tr(""));
    setButtonProperties(stampNine);
    stampTen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_ten_stamp.png"), tr(""));
    setButtonProperties(stampTen);
    stampEleven = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_eleven_stamp.png"), tr(""));
    setButtonProperties(stampEleven);
    stampTwelve = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twelve_stamp.png"), tr(""));
    setButtonProperties(stampTwelve);
    stampThirteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_thirteen_stamp.png"), tr(""));
    setButtonProperties(stampThirteen);
    stampFourteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_fourteen_stamp.png"), tr(""));
    setButtonProperties(stampFourteen);
    stampFifteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_fifteen_stamp.png"), tr(""));
    setButtonProperties(stampFifteen);
    stampSixteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_sixteen_stamp.png"), tr(""));
    setButtonProperties(stampSixteen);
    stampSeventeen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_seventeen_stamp.png"), tr(""));
    setButtonProperties(stampSeventeen);
    stampEighteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_eighteen_stamp.png"), tr(""));
    setButtonProperties(stampEighteen);
    stampNineteen = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_nineteen_stamp.png"), tr(""));
    setButtonProperties(stampNineteen);
    stampTwenty = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twenty_stamp.png"), tr(""));
    setButtonProperties(stampTwenty);
    stampTwentyOne = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twentyone_stamp.png"), tr(""));
    setButtonProperties(stampTwentyOne);
    stampTwentyTwo = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twentytwo_stamp.png"), tr(""));
    setButtonProperties(stampTwentyTwo);
    stampTwentyThree = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twentythree_stamp.png"), tr(""));
    setButtonProperties(stampTwentyThree);
    stampTwentyFour = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twentyfour_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFour);
    stampTwentyFive = new QPushButton(QIcon(":/Stamps/vehicles/Stamps/vehicles_twentyfive_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFive);

    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);
}

//STAMPS WIDGET FOOD
StampsWidgetFood::StampsWidgetFood()
{
    hLayout = new FlowLayout;

    goBack = new QPushButton(tr("< Stamps"));
    goBack->setStyleSheet("QPushButton{background-color:#99CCFF;}");
    setButtonProperties(goBack);

    stampOne = new QPushButton(QIcon(":/Stamps/food/Stamps/food_one_stamp.png"), tr(""));
    setButtonProperties(stampOne);
    stampTwo = new QPushButton(QIcon(":/Stamps/food/Stamps/food_two_stamp.png"), tr(""));
    setButtonProperties(stampTwo);
    stampThree = new QPushButton(QIcon(":/Stamps/food/Stamps/food_three_stamp.png"), tr(""));
    setButtonProperties(stampThree);
    stampFour = new QPushButton(QIcon(":/Stamps/food/Stamps/food_four_stamp.png"), tr(""));
    setButtonProperties(stampFour);
    stampFive = new QPushButton(QIcon(":/Stamps/food/Stamps/food_five_stamp.png"), tr(""));
    setButtonProperties(stampFive);
    stampSix = new QPushButton(QIcon(":/Stamps/food/Stamps/food_six_stamp.png"), tr(""));
    setButtonProperties(stampSix);
    stampSeven = new QPushButton(QIcon(":/Stamps/food/Stamps/food_seven_stamp.png"), tr(""));
    setButtonProperties(stampSeven);
    stampEight = new QPushButton(QIcon(":/Stamps/food/Stamps/food_eight_stamp.png"), tr(""));
    setButtonProperties(stampEight);
    stampNine = new QPushButton(QIcon(":/Stamps/food/Stamps/food_nine_stamp.png"), tr(""));
    setButtonProperties(stampNine);
    stampTen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_ten_stamp.png"), tr(""));
    setButtonProperties(stampTen);
    stampEleven = new QPushButton(QIcon(":/Stamps/food/Stamps/food_eleven_stamp.png"), tr(""));
    setButtonProperties(stampEleven);
    stampTwelve = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twelve_stamp.png"), tr(""));
    setButtonProperties(stampTwelve);
    stampThirteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_thirteen_stamp.png"), tr(""));
    setButtonProperties(stampThirteen);
    stampFourteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_fourteen_stamp.png"), tr(""));
    setButtonProperties(stampFourteen);
    stampFifteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_fifteen_stamp.png"), tr(""));
    setButtonProperties(stampFifteen);
    stampSixteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_sixteen_stamp.png"), tr(""));
    setButtonProperties(stampSixteen);
    stampSeventeen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_seventeen_stamp.png"), tr(""));
    setButtonProperties(stampSeventeen);
    stampEighteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_eighteen_stamp.png"), tr(""));
    setButtonProperties(stampEighteen);
    stampNineteen = new QPushButton(QIcon(":/Stamps/food/Stamps/food_nineteen_stamp.png"), tr(""));
    setButtonProperties(stampNineteen);
    stampTwenty = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twenty_stamp.png"), tr(""));
    setButtonProperties(stampTwenty);
    stampTwentyOne = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentyone_stamp.png"), tr(""));
    setButtonProperties(stampTwentyOne);
    stampTwentyTwo = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentytwo_stamp.png"), tr(""));
    setButtonProperties(stampTwentyTwo);
    stampTwentyThree = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentythree_stamp.png"), tr(""));
    setButtonProperties(stampTwentyThree);
    stampTwentyFour = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentyfour_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFour);
    stampTwentyFive = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentyfive_stamp.png"), tr(""));
    setButtonProperties(stampTwentyFive);
    stampTwentySix = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentysix_stamp.png"), tr(""));
    setButtonProperties(stampTwentySix);
    stampTwentySeven = new QPushButton(QIcon(":/Stamps/food/Stamps/food_twentyseven_stamp.png"), tr(""));
    setButtonProperties(stampTwentySeven);


    QSpacerItem *horizSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayout->addItem(horizSpacer);
    this->setLayout(hLayout);

}
