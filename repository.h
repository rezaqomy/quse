#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <iostream>
#include <QVector>
#include <QDebug>
#include "category.h"
#include "score.h"



class Repository
{
public:
    Repository();
    ~Repository();
    void addCategory(QVector<Category*>& categorys);
    void addScore(Score& score);
    QVector<Score*> getScore();



protected:
    QSqlDatabase db;
    QSqlQuery* query;
    void createTable();
    void createDatabase();
};

#endif // REPOSITORY_H
