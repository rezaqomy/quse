#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlDatabase>
#include <QString>
#include <QMap>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <iostream>
#include <QVector>
#include <QDebug>
#include "category.h"




class Repository
{
public:
    Repository();
    ~Repository();
    void addCategory(QVector<Category*>& categorys);
    void addScore(int score, QString difficaly, QString name);
    QVector<QPair<int, QString>> getScore(QString difficaly);



protected:
    QSqlDatabase db;
    QSqlQuery* query;
    void createTable();
    void createDatabase();
};

#endif // REPOSITORY_H
