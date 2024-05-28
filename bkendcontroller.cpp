#include "bkendcontroller.h"

BkendController::BkendController(MainWindow* w)
{
    window = w;
    repository = new Repository();
}

void BkendController::sendQuestionRequest(int num, int category, QString difficalty)
{
    getQuestion(num, category, difficalty);
}

void BkendController::addScore(int score, QString name)
{
    repository->addScore(score, name, QDate::currentDate().toString("yyyy-MM-dd HH:MM"));
}

void BkendController::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
}

void BkendController::questionIsReady(QVector<Question *> &questions)
{
    qDebug() << "question is ready " << questions[0]->getQuestion();
}



