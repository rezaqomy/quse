#include "controller.h"

Controller::Controller(MainWindow* w)
{
    window = w;
    getCategory = new GetingCategory();
    getQuestion = new GetingQustions();
    getCategory->connect(getCategory, &GetingCategory::categoryIsReady, this, &Controller::categoryIsReady);
    getQuestion->connect(getQuestion, &GetingQustions::questionIsReady, this, &Controller::questionIsReady);
    w->connect(w, &MainWindow::getCategoryRecuest, this, &Controller::sendQuestionRequest);
    repository = new Repository();
}

void Controller::sendQuestionRequest(int category)
{
    getQuestion->getQuestion(5, category, "hard");
}

void Controller::addScore(Score score)
{
    repository->addScore(score);
}

QVector<Score *> Controller::getAllScore()
{
    return repository->getScore();
}

void Controller::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
    window->setCategory(category);
}

void Controller::questionIsReady(QVector<Question *> &questions)
{
    qDebug() << questions[0]->getQuestion() << questions.size();
    window->setQuestiions(questions);
}



