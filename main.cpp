#include "mainwindow.h"
#include "getingqustions.h"
#include "getingcategory.h"
#include "bkendcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    BkendController controller(&w);
    controller.sendQuestionRequest(5, 9, "hard");

    w.show();
    return a.exec();
}
