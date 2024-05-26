#include "repository.h"

Repository::Repository(QString& dbName)
{
    createDatabase(dbName);
}

void Repository::createDatabase(QString &dbName)
{
    QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        /* TODO */
    }


}

void Repository::createTable()
{
    query.exec("CREATE TABLE category (id_customer INTEGER, title STRING");
}
