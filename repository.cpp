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
    query->exec("CREATE TABLE easy_score (score INTEGER, name TEXT)");
    query->exec("CREATE TABLE medium_score (score INTEGER, name TEXT)");
    query->exec("CREATE TABLE hard_score (score INTEGER, name TEXT)");
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
}

void Repository::addScore(int score, QString difficaly, QString name)
{
    QString queryAddScore = "INSERT INTO %1_score (score, name) VALUES (?, ?)";
    query->prepare(queryAddScore.arg(difficaly));
    query->bindValue(0, score);
    query->bindValue(1, name);

    bool result = query->exec();

    if (result) {
      ;
    } else {
      qDebug() << "Error inserting score: " << query->lastError().text();
    }
}

QVector<QPair<int, QString>> Repository::getScore(QString difficaly)
{
    query->exec(QString("SELECT * FROM %1_score ORDER BY score DESC Limit 20").arg(difficaly));


    QVector<QPair<int, QString>> scores;
    while (query->next()) {
        int score = query->value(0).toInt();
        QString name = query->value(1).toString();
        QPair<int, QString> pair(score, name);
        scores.push_back(pair);

    }
    if (!query->exec()){
        qDebug() << "error in geting score : " << query->lastError();
    }
    return scores;
}
