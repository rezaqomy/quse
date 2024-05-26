#include "mainwindow.h"
#include "getingqustions.h"
#include "getingcategory.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GetingCategory getCategory;
    GetingQustions getQustion;
    w.show();
    return a.exec();
}
