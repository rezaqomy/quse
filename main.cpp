#include "mainwindow.h"
#include "apiclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString path = "https://opentdb.com/api.php?amount=10";
    ApiClient apiclient(path);
    w.show();
    return a.exec();
}
