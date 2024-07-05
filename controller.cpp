#include "controller.h"

Controller::Controller(MainWindow* w)
{
    window = w;
    getCategory = new GetingCategory();
    getQuestion = new GetingQustions();
    getCategory->connect(getCategory, &GetingCategory::categoryIsReady, this, &Controller::categoryIsReady);
    getQuestion->connect(getQuestion, &GetingQustions::questionIsReady, this, &Controller::questionIsReady);
    w->connect(w, &MainWindow::getCategoryRequest, this, &Controller::sendQuestionRequest);
    w->connect(w, &MainWindow::sendScore, this, &Controller::addScore);
    repository = new Repository();
}

void Controller::sendQuestionRequest(int category, QString diffically)
{
    if (category == 0) {
        getQuestion->getRandomQuestion(diffically);
        return;
    }
}

void Controller::addScore(int score, QString difficaly, QString name)
{
    repository->addScore(score, difficaly, name);
}

QMap<int, QString> Controller::getAllScore(QString difficaly)
{
    return repository->getScore(difficaly);
}

void Controller::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
    window->setCategory(category);
}

void Controller::questionIsReady(QVector<Question *> &questions)
{
    window->setQuestiions(questions);
}



