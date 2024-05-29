#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ptrabout = new AboutUs();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrabout;
}


void MainWindow::on_btnAbout_clicked()
{
    ptrabout -> show();
}


void MainWindow::on_btnExit_clicked()
{
    this -> close();
}


void MainWindow::on_btnSingle_clicked()
{
    ui -> stackedWidget-> setCurrentIndex(1);
}


void MainWindow::on_btnBack1_clicked()
{
    ui -> stackedWidget-> setCurrentIndex(0);
}


void MainWindow::on_btnBack2_clicked()
{
    ui -> stackedWidget-> setCurrentIndex(0);
}


void MainWindow::on_btnMulti_clicked()
{
    ui -> stackedWidget-> setCurrentIndex(2);
}

