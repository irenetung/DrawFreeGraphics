#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>

#include "prompt.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    //w.show();

    return a.exec();
}
