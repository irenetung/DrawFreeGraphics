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
    QPushButton *dogStamp;
    QPushButton *catStamp;
    QPushButton *birdStamp;
    QPushButton *manStamp;
    QPushButton *womanStamp;


};

#endif // STAMPSWIDGET_H
