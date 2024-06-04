#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <aboutus.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAbout_clicked();

    void on_btnExit_clicked();

    void on_btnSingle_clicked();

    void on_btnBack1_clicked();

    void on_btnBack2_clicked();

    void on_btnMulti_clicked();

private:
    Ui::MainWindow *ui;
    AboutUs *ptrabout;
};
#endif // MAINWINDOW_H
