#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::startSurvivalMode()
{


    userAnswer = "";
    if (questions.size() == 0){
        qDebug() << "the questions size lastes 1 this mean question not resived";
        ui->main_stacked_widget->setCurrentIndex(3);
        QMessageBox qmsgbox;
        qmsgbox.setText("اشکال در دریافت سوال");
        qmsgbox.exec();
        return;
    }
    setQuestion(questions[0]);
    correctAnswer = questions[0]->getCorrectAnswer();
    ui->main_stacked_widget->setCurrentIndex(3);
}

void MainWindow::on_btnSingle_clicked()
{
    ressponsed_single = 0;
    wrong_ressponse_single = 0;
    ui->menu_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnStartSingle_clicked()
{
    mode = 1;
    nameSingle = ui->txtName->text();
    ui->main_stacked_widget->setCurrentIndex(4);
}
