#include "mainwindow.h"
#include "getingqustions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    GetingQustions getQustion;
    w.show();
    return a.exec();
}
