#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "aboutus.h"
#include "categoryview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setCategory(QVector<Category*>& categorys);
    void getQuestionRecuestSended();
Q_SIGNALS:
    void getCategoryRecuest(int id);

private slots:
    void on_btnAbout_clicked();

    void on_btnExit_clicked();

    void on_btnSingle_clicked();

    void on_btnMulti_clicked();

    void on_btnBack2_clicked();

    void on_btnStartSingle_clicked();

private:
    Ui::MainWindow *ui;
    AboutUs *ptrabout;
    QVector<Category*> categorys;
    void startLoading();
    void handelGetQuestion(int id);
};
#endif // MAINWINDOW_H
