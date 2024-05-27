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



class Repository
{
public:
    Repository();
    ~Repository();
    void addCategory(QVector<Category*>& categorys);


protected:
    QSqlDatabase db;
    QSqlQuery* query;
    void createTable();
    void createDatabase();

};

#endif // REPOSITORY_H
