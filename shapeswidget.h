#ifndef SHAPESWIDGET_H
#define SHAPESWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>

class ShapesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShapesWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

protected:
    int dim;

private:
    QPixmap *parea;
};

//Select a shape
class ShapesWidgetShapes : public ShapesWidget
{
public:
    explicit ShapesWidgetShapes();
    QPushButton *previousShapeButton;
    QPushButton *lineButton;
    QPushButton *pointButton;
    QPushButton *circleButton;
    QPushButton *rectangleButton;
    QPushButton *roundedRectangleButton;
    QPushButton *polygonButton;
    QPushButton *arcButton;
    QPushButton *chordButton;
    QPushButton *pieButton;
    QPushButton *pathButton;
    QPushButton *textButton;

private:
    QHBoxLayout *hLayout;
};

//End path
class ShapesWidgetEndPath : public ShapesWidget
{
public:
    explicit ShapesWidgetEndPath();
    QPushButton *endPathButton;

private:
    QHBoxLayout *hLayout;
};
#endif // SHAPESWIDGET_H
