#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDate>
#include <QDateTimeEdit>
#include <QObject>
#include "getingcategory.h"
#include "getingqustions.h"
#include "repository.h"
#include "mainwindow.h"



class Controller: public QObject
{
    Q_OBJECT
public:
    Controller(MainWindow* w);
    QVector<QPair<int, QString>> getAllScore(QString difficaly);
    void addScore(int score, QString difficaly, QString name);
public slots:
    void sendQuestionRequest(int category, QString difficaly);

private:
    void categoryIsReady(QVector<Category*>& category);
    void questionIsReady(QVector<Question*>& questions);
    void setScore();
    Repository* repository;
    GetingCategory* getCategory;
    GetingQustions* getQuestion;
    MainWindow* window;
};

#endif // CONTROLLER_H
