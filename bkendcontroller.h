#ifndef BKENDCONTROLLER_H
#define BKENDCONTROLLER_H

#include "getingcategory.h"
#include "getingqustions.h"
#include "repository.h"


class BkendController: public GetingCategory, GetingQustions
{
public:
    BkendController();
private:
    void categoryIsReady(QVector<Category*>& category);
    Repository* repository;
};

#endif // BKENDCONTROLLER_H
