#include "bkendcontroller.h"

BkendController::BkendController(MainWindow& w)
{
    repository = new Repository();
}

void BkendController::sendQuestionRequest(int num, int category, QString difficalty)
{
    getQuestion(num, category, difficalty);
}

void BkendController::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
}

void BkendController::questionIsReady(QVector<Question *> &questions)
{
    qDebug() << "question is ready " << questions[0]->getQuestion();
}



