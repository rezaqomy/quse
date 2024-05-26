#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <iostream>

class Repository
{
public:
    Repository(QString& dbName);


protected:
    void createDatabase(QString& dbName);
    QSqlDatabase db;
    QSqlQuery query;
    void createTable();

};

#endif // REPOSITORY_H
