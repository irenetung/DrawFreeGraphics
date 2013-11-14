#ifndef BRUSHEFFECTSWIDGET_H
#define BRUSHEFFECTSWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QHBoxLayout>

class BrushEffectsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrushEffectsWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
    int dim;
    QHBoxLayout *hLayout;
    void setButtonProperties(QPushButton *b);

private:
    QPixmap *parea;
};

class BrushEffectsWidgetBrushEffects : public BrushEffectsWidget
{
public:
    explicit BrushEffectsWidgetBrushEffects(QWidget *parent = 0);
    QPushButton *paintButton;
    QPushButton *waterColorButton;
    QPushButton *calligraphyButton;
    QPushButton *pencilButton;
    QPushButton *sprayPaintButton;
};

#endif // BRUSHEFFECTSWIDGET_H
