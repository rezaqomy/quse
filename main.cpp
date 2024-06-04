#include "mainwindow.h"
#include "getingqustions.h"
#include "getingcategory.h"
#include "controller.h"
#include <QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Controller controller(&w);
    w.show();
    return a.exec();
}
