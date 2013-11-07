#ifndef CURSORWIDGET_H
#define CURSORWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSignalMapper>

class CursorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CursorWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

protected:
    int dim;
    QHBoxLayout *hLayout;
    void setButtonProperties(QPushButton *b);

private:
    QPixmap *parea;
};

class CursorWidgetRotate : public CursorWidget
{
public:
    explicit CursorWidgetRotate();
    QPushButton *signButton;
    QPushButton *reset0Button;
    QPushButton *r01Button;
    QPushButton *r05Button;
    QPushButton *r1Button;
    QPushButton *r5Button;
    QPushButton *r10Button;
    QPushButton *r20Button;
    QPushButton *r30Button;
    QPushButton *r45Button;
    QPushButton *r60Button;
    QPushButton *r72Button;
    QPushButton *r90Button;
    QPushButton *r120Button;
    QPushButton *r150Button;
    QPushButton *r180Button;
    QPushButton *r270Button;
    void toggleSign(bool signPositive);

};

#endif // CURSORWIDGET_H
