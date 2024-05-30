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

void BkendController::addScore(Score score)
{
    repository->addScore(score);
}

QVector<Score *> BkendController::getAllScore()
{
    return repository->getScore();
}

void BkendController::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
}

void BkendController::questionIsReady(QVector<Question *> &questions)
{
    ;
}



