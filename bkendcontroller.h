#ifndef BKENDCONTROLLER_H
#define BKENDCONTROLLER_H

#include <QDate>
#include <QDateTimeEdit>
#include "getingcategory.h"
#include "getingqustions.h"
#include "repository.h"
#include "mainwindow.h"
#include "score.h"


class BkendController: public GetingCategory, GetingQustions
{
public:
    BkendController(MainWindow* w);
    void sendQuestionRequest(int num, int category, QString difficalty);
    void addScore(Score score);
    QVector<Score*> getAllScore();
private:
    void categoryIsReady(QVector<Category*>& category);
    void questionIsReady(QVector<Question*>& questions);
    Repository* repository;
    MainWindow* window;
};

#endif // BKENDCONTROLLER_H
