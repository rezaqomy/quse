#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QSoundEffect *efx = new QSoundEffect(this);
//    efx->setSource(QUrl::fromLocalFile(":Sounds/Background/Angize.mp3"));
//    efx->setVolume(0.90);
//    efx->setLoopCount(2);
//    efx->play();

    on_pushButton_2_clicked();


    ptrabout = new AboutUs();
}

void MainWindow::setCategory(QVector<Category *> &categorys)
{
    QWidget* window = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    for (int i{}; i < categorys.size(); i++){
        CategoryView* catview = new CategoryView(categorys[i]);
        catview->connect(catview, &CategoryView::categorySelected, this, &MainWindow::setCategoryQuestion);
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

void MainWindow::setAllScore(QVector<QPair<int, QString>> easy, QVector<QPair<int, QString>> medium, QVector<QPair<int, QString>> hard)
{
    QWidget* widget = new QWidget();
    QGridLayout *layout = new QGridLayout();
    QLabel* label_easy = new QLabel("Score (easy)");
    QLabel* label_medium = new QLabel("Score (medium)");
    QLabel* label_hard = new QLabel("Score (hard)");
    QLabel* name = new QLabel("name (easy)");
    QLabel* name_medium = new QLabel("name (medium)");
    QLabel* name_hard = new QLabel("name (hard)");
    layout->addWidget(label_easy, 0, 2);
    layout->addWidget(name, 0, 1);
    layout->addWidget(label_medium, 0, 4);
    layout->addWidget(name_medium, 0, 3);
    layout->addWidget(label_hard, 0, 6);
    layout->addWidget(name_hard, 0, 5);


    for (int i{}; i < easy.size(); i++) {
        QLabel* score = new QLabel(QString::number(easy[i].first));
        QLabel* name = new QLabel(easy[i].second);
        layout->addWidget(score,i + 1, 2);
        layout->addWidget(name, i + 1, 1);
    }
    for (int i{}; i < medium.size(); i++) {
        QLabel* score = new QLabel(QString::number(medium[i].first));
        QLabel* name = new QLabel(medium[i].second);
        layout->addWidget(score,i + 1, 4);
        layout->addWidget(name, i + 1, 3);
    }

    for (int i{}; i < hard.size(); i++) {
        QLabel* score = new QLabel(QString::number(hard[i].first));
        QLabel* name = new QLabel(hard[i].second);
        layout->addWidget(score,i + 1, 6);
        layout->addWidget(name, i + 1, 5);
    }
    widget->setLayout(layout);
    ui->score_scrollArea->setWidget(widget);
    ui->main_stacked_widget->setCurrentIndex(5);
}

void MainWindow::startLoading()
{
    ui->main_stacked_widget->setCurrentIndex(1);

}

void MainWindow::setQuestion(Question *question)
{
    if (mode == 1) {
//        ui->correct_response_label->setText(QString::number(ressponsed_single));
//        ui->wrong_response_label->setText(QString::number(wrong_ressponse_single));
    } else if (mode == 2) {
//        ui->wrong_response_label->setText(QString::number(player_one_responsed));
//        ui->correct_response_label->setText(QString::number(player_two_responsed));
    }
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
        emit getCategoryRequest(0 , diffcaly);
    }
    else {
        emit getCategoryRequest(id, diffcaly);
    }
    startLoading();
}

void MainWindow::updateQuestions()
{
    if (mode == 1) {
        startSurvivalMode();
    }
    if (mode == 2) {
        startMultyMode();
        qDebug() << "Ok";
    }
    number_question++;
}

void MainWindow::checkAnswer()
{
    QMessageBox msgbox;
    if (mode == 1) {
        ressponsed_single++;
    }
    if (correctAnswer == userAnswer){

        if (mode == 2) {
            if (first_player != part_of_round) {
                player_one_responsed++;
                msgbox.setText(" You're Correct! \nTotal correct answer: " + QString::number(player_one_responsed));
            } else {
                player_two_responsed++;
                msgbox.setText(" You're Correct! \nTotal correct answer: " + QString::number(player_two_responsed));
            }

        }else{
        msgbox.setText(" You're Correct! \nTotal streak: " + QString::number(ressponsed_single));
        }
        QSound::play(":/Images/Resources/17.Correct-Answer.wav");
        
    } else {

        if (mode == 1){
            wrong_ressponse_single++;
            msgbox.setText(" Wrong Answer :( \n" + QString::number(wrong_ressponse_single) + " out of 3");
        }else {
        msgbox.setText(" Wrong Answer :( ");
        }
        QSound::play(":/Images/Resources/24.Wrong-Answer.wav");

    }

    msgbox.exec();
}

void MainWindow::checkMultyMode()
{
    number_question = 0;

    if (round == 3 && part_of_round == 2){
        QMessageBox msgbox;
        if (player_one_responsed > player_two_responsed) {
            msgbox.setText("\" " + name_player_one + " \" is won !!!");
        } else if (player_one_responsed == player_two_responsed) {
            msgbox.setText("Tie!!!");
        } else {
            msgbox.setText("\" " + name_player_two + " \" is wone !!!");
        }
        QSound::play(":/Images/Resources/42.Kids-Cheering.wav");
        msgbox.exec();
        ui->main_stacked_widget->setCurrentIndex(0);
        ui->menu_stackedWidget->setCurrentIndex(0);
        return;
    }
    if (round % 2 == 0){
        first_player = 1;
    } else {
        first_player = 2;
    }


    // this code set player name in the all name label in ui
    if (first_player == part_of_round) {
        setNamePlayer(name_player_one);
    } else {
        setNamePlayer(name_player_two);
    }
    if (part_of_round == 1) {
        ui->main_stacked_widget->setCurrentIndex(2);
        part_of_round++;
    } else {
        handelGetQuestion(category);
        part_of_round = 1;
        round++;
    }
}

void MainWindow::setNamePlayer(QString name)
{
    ui->playerNameCategorylabel->setText(name);
    ui->playerNameDifficalyLabel->setText(name);
    ui->playerNameQuestionLabel->setText(name);
}

void MainWindow::startMultyMode()
{
    userAnswer = "";
    if (questions.size() != 5){
        qDebug() << "The questions size lastes 1. This mean question not received";
        ui->main_stacked_widget->setCurrentIndex(3);
        QMessageBox qmsgbox;
        qmsgbox.setText("اشکال در دریافت سوال");
        qmsgbox.exec();
        return;
    }
    setQuestion(questions[number_question]);
    correctAnswer = questions[number_question]->getCorrectAnswer();
    ui->main_stacked_widget->setCurrentIndex(3);
}

void MainWindow::setCategoryQuestion(int category)
{
    this->category = category;
    ui->main_stacked_widget->setCurrentIndex(4);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete ptrabout;
}


void MainWindow::on_btnAbout_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    ptrabout -> show();
}


void MainWindow::on_btnExit_clicked()
{

        this -> close();


}



void MainWindow::on_btnMulti_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    ui->menu_stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnBack2_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    ui->menu_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->answer1_radioButton->isChecked()) userAnswer = ui->answer1_radioButton->text();
    else if (ui->answer2_radioButton->isChecked()) userAnswer = ui->answer2_radioButton->text();
    else if (ui->answer3_radioButton->isChecked()) userAnswer = ui->answer3_radioButton->text();
    else if (ui->answer4_radioButton->isChecked()) userAnswer = ui->answer4_radioButton->text();
    else {
        qDebug() << "Please choose an answer";

        return;
    }

    isResponsed = true;
    checkAnswer();
    if (mode == 1 && wrong_ressponse_single >= 3){
        QMessageBox msgbox;
        msgbox.setText("You loose !!!");
        QSound::play(":/Images/Resources/16.WahWahWah.wav");
        msgbox.exec();
        emit sendScore(ressponsed_single, diffcaly, nameSingle);
        ui->main_stacked_widget->setCurrentIndex(0);
        ui->menu_stackedWidget->setCurrentIndex(0);
        return;
    }
    if (mode == 1) {
        handelGetQuestion();
    }
    else if (mode == 2) {
        if (number_question >= 5) {
            checkMultyMode();
        }
        else {
            updateQuestions();
        }
    }
}


void MainWindow::on_easy_pushButton_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    diffcaly = "easy";
    if (mode == 1){
        handelGetQuestion();
    } else if (mode == 2) {
        handelGetQuestion(category);
    }
}


void MainWindow::on_medium_pushButton_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    diffcaly = "medium";
    if (mode == 1){
        handelGetQuestion();
    } else if (mode == 2){
        handelGetQuestion(category);
    }
}


void MainWindow::on_hard_pushButton_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    diffcaly = "hard";
    if (mode == 1){
        handelGetQuestion();
    } else if (mode == 2) {
        handelGetQuestion(category);
    }
}


void MainWindow::on_btnScoreBoard_clicked()
{
    QSound::play(":/Images/Resources/82.Tadah.wav");
    emit getAllScore();
}


void MainWindow::on_btnStartMulti_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    mode = 2;
    name_player_one = ui->txtNameFirst->text();
    name_player_two = ui->txtNameSecond->text();
    part_of_round = 1;
    checkMultyMode();
}


void MainWindow::on_btnBack2_2_clicked()
{
    QSound::play(":/Images/Resources/aspose_Click.wav");
    ui->main_stacked_widget->setCurrentIndex(0);
    ui->menu_stackedWidget->setCurrentIndex(0);
}







void MainWindow::on_pushButton_2_clicked()
{
// Using QSound
//            QSound sound(":/Images/Resources/aspose_Angize.wav");
//            sound.play();

//        QSound::play(":/Images/Resources/aspose_Angize.wav");


// Using QMediaPlayer
//            QMediaPlayer *backSound = new QMediaPlayer;
//            backSound->setMedia(QUrl::fromLocalFile("Sounds/Background/Angize.mp3"));
//            backSound->setVolume(50);
//            backSound->play();

//    QMediaPlayer mediaPlayer;
//    mediaPlayer.setMedia(QUrl(":/Images/Resources/aspose_Angize.wav"));
//    mediaPlayer.play();

// Using QSoundEffect
//        QSoundEffect soundEffect(":/Images/Resources/Angize.mp3");
//        soundEffect.setVolume(0.5);
//        soundEffect.setLoop(true);
//        soundEffect.setFadeInTime(500);
//        soundEffect.play();
//        soundEffect.stop();




//      QMessageBox zartbox;


      if (!isPlaying) {
         music = new QSound(":/Images/Resources/Angize.wav");

         music->play();
         isPlaying = true;
         qDebug() << "ok";
      }else {
//         zartbox.setText("Just Listen To The Music!!!");
//         zartbox.exec();
         music->stop();
         isPlaying = false;


}








}

