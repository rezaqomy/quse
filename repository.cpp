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
    query->exec("CREATE TABLE score (score INTEGER, name TEXT, date TEXT)");
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
        query->bindValue(0, idString);
        query->bindValue(1, titleString);

        bool result = query->exec();

        if (result) {
          ;
        } else {
          qDebug() << "Error inserting category: " << query->lastError().text();
        }

    }
    qDebug() << "categorys added";
}

void Repository::addScore(int score, QString name, QString date)
{
    QString queryAddScore = "INSERT INTO score (score, name, date) VALUES (?, ?, ?)";
    query->prepare(queryAddScore);
    query->bindValue(0, score);
    query->bindValue(1, name);
    query->bindValue(2, date);
    qDebug() << score << name << date;
    bool result = query->exec();

    if (result) {
      ;
    } else {
      qDebug() << "Error inserting score: " << query->lastError().text();
    }
}
