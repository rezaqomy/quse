#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ptrabout = new AboutUs();
}

void MainWindow::setCategory(QVector<Category *> &categorys)
{
    QWidget* window = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    for (int i{}; i < categorys.size(); i++){
        CategoryView* catview = new CategoryView(categorys[i]);
        catview->connect(catview, &CategoryView::categorySelected, this, &MainWindow::handelGetQuestion);
        layout->addWidget(catview, i, 0);
    }
    window->setLayout(layout);

    ui->category_scrol_area->setWidget(window);

}

void MainWindow::setQuestiions(QVector<Question *> questions)
{
    this->questions = questions;
    updateQuestions();

}

void MainWindow::startLoading()
{
    ui->main_stacked_widget->setCurrentIndex(1);

}

void MainWindow::setQuestion(Question *question)
{
    ui->question_label->setText(question->getQuestion());
    QVector<QString> randomAnswer = question->getRandomAnswers();
    ui->answer1_radioButton->setText(randomAnswer[0]);
    ui->answer2_radioButton->setText(randomAnswer[1]);
    ui->answer3_radioButton->setText(randomAnswer[2]);
    ui->answer4_radioButton->setText(randomAnswer[3]);
}


void MainWindow::handelGetQuestion(int id = 0)
{
    if (id == 0) {
        emit getCategoryRequest();
    }
    else {
        emit getCategoryRequest(id);
    }
    startLoading();
}

void MainWindow::startSurvivalMode()
{
    if (isResponsed){
        ;
    }
    userAnswer = "";
    if (questions.size() == 0){
        qDebug() << "the questions size lastes 1 this mean question not resived";
        ui->main_stacked_widget->setCurrentIndex(3);
        QMessageBox qmsgbox;
        qmsgbox.setText("مگه سگ دنبالت کرده سریع می زنی");
        qmsgbox.exec();
        return;
    }
    setQuestion(questions[0]);
    correctAnswer = questions[0]->getCorrectAnswer();
    ui->main_stacked_widget->setCurrentIndex(3);
}

void MainWindow::updateQuestions()
{
    switch (mode) {
    case 1:
        startSurvivalMode();
    }
}

void MainWindow::checkAnswer()
{
    if (correctAnswer == userAnswer){
        QMessageBox msgbox;
        msgbox.setText("you response correct");
        msgbox.exec();
    } else {
        QMessageBox msgbox;
        msgbox.setText("you not responsed !!!");
        msgbox.exec();
    }
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
    ui->menu_stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnMulti_clicked()
{
    ui->menu_stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnBack2_clicked()
{
    ui->menu_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnStartSingle_clicked()
{
    mode = 1;
    handelGetQuestion();
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->answer1_radioButton->isChecked()) userAnswer = ui->answer1_radioButton->text();
    else if (ui->answer2_radioButton->isChecked()) userAnswer = ui->answer2_radioButton->text();
    else if (ui->answer3_radioButton->isChecked()) userAnswer = ui->answer3_radioButton->text();
    else if (ui->answer4_radioButton->isChecked()) userAnswer = ui->answer4_radioButton->text();
    else {
        qDebug() << "please select them";

        return;
    }

    isResponsed = true;
    checkAnswer();
    handelGetQuestion();
}

