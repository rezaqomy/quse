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
    ui->main_stacked_widget->setCurrentIndex(3);
    setQuestion(questions[0]);
}

void MainWindow::startLoading()
{
    ui->main_stacked_widget->setCurrentIndex(2);
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


void MainWindow::handelGetQuestion(int id)
{
    emit getCategoryRecuest(id);
    ui->main_stacked_widget->setCurrentIndex(1);
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
    qDebug() << "okk";
    ui->main_stacked_widget->setCurrentIndex(2);
}

