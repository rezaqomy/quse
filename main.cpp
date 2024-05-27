#include "mainwindow.h"
#include "getingqustions.h"
#include "getingcategory.h"
#include "bkendcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BkendController controller;
    MainWindow w;

    w.show();
    return a.exec();
}
