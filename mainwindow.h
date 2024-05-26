#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
=======
#include "apiclient.h"
#include <iostream>
>>>>>>> connect-requests

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
=======

>>>>>>> connect-requests
};
#endif // MAINWINDOW_H
