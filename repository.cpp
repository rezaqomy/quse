#include "repository.h"

Repository::Repository()
{
    createDatabase();
}

Repository::~Repository()
{
    db.close();
}

void Repository::createDatabase()
{
    qDebug() << "il";
    const QString dbName = "quse.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open()){
        qDebug() << "database not found";
    }
    query = new QSqlQuery(db);

    createTable();

}

void Repository::createTable()
{
    query->exec("CREATE TABLE category (id INTEGER, title TEXT)");
}

void Repository::addCategory(QVector<Category*> &categorys)
{
    query->exec("DROP TABLE category");

    createTable();
    for (int i{}; i < categorys.size(); i++){
        QString queryInsert = "INSERT INTO category (id, title) VALUES (?, ?)";

        QString idString = QString::number(categorys[i]->getID());
        QString titleString = categorys[i]->getTitle();

        query->prepare(queryInsert);
        query->bindValue(0, idString); // Bind ID to first placeholder
        query->bindValue(1, titleString); // Bind title to second placeholder

        bool result = query->exec();

        if (result) {
          qDebug() << "Category inserted successfully!";
        } else {
          qDebug() << "Error inserting category: " << query->lastError().text();
        }

        qDebug() << categorys[i]->getID() << categorys[i]->getTitle(); // Print for debugging

    }
    qDebug() << "categorys added";
}
