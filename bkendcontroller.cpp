#include "bkendcontroller.h"

BkendController::BkendController()
{
    repository = new Repository();
}

void BkendController::categoryIsReady(QVector<Category*> &category)
{
    repository->addCategory(category);
}
