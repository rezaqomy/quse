#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMap>
#include <QMessageBox>
#include "aboutus.h"
#include "categoryview.h"
#include "question.h"

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
    void setQuestiions(QVector<Question*> questions);
Q_SIGNALS:
    void getCategoryRequest(int id = 0, QString difficaly = "easy");

private slots:
    void on_btnAbout_clicked();

    void on_btnExit_clicked();

    void on_btnSingle_clicked();

    void on_btnMulti_clicked();

    void on_btnBack2_clicked();

    void on_btnStartSingle_clicked();

    void on_pushButton_clicked();

    void on_easy_pushButton_clicked();

    void on_medium_pushButton_clicked();

    void on_hard_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AboutUs *ptrabout;
    QVector<Category*> categorys;


    void startLoading();
    void setQuestion(Question* question);
    void handelGetQuestion(int id);
    void startSurvivalMode();
    void updateQuestions();
    void checkAnswer();


    int ressponsed_single{};
    int wrong_ressponse_single{};
    QString diffcaly{};

    bool isResponsed{};
    QString userAnswer{};
    QString correctAnswer{};
    QVector<Question *> questions;
    int mode{};
    QMap<int, bool> survivalQuestions{};
};
#endif // MAINWINDOW_H
