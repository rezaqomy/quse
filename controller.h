#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDate>
#include <QDateTimeEdit>
#include <QObject>
#include "getingcategory.h"
#include "getingqustions.h"
#include "repository.h"
#include "mainwindow.h"
#include "score.h"


class Controller: public QObject
{
    Q_OBJECT
public:
    Controller(MainWindow* w);
    QVector<Score*> getAllScore();
    void addScore(Score score);
public slots:
    void sendQuestionRequest(int category);

private:
    void categoryIsReady(QVector<Category*>& category);
    void questionIsReady(QVector<Question*>& questions);
    Repository* repository;
    GetingCategory* getCategory;
    GetingQustions* getQuestion;
    MainWindow* window;
};

#endif // CONTROLLER_H
