#ifndef PROMPT_H
#define PROMPT_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QSpacerItem>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class Prompt : public QWidget
{
    Q_OBJECT
public:
    explicit Prompt(QWidget *parent = 0);
    QLabel *promptLabel;

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    QPixmap *parea;
    QHBoxLayout *promptLayout;
};

#endif // PROMPT_H
