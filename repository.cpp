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
}

void Repository::addScore(Score& score)
{
    QString queryAddScore = "INSERT INTO score (score, name, date) VALUES (?, ?, ?)";
    query->prepare(queryAddScore);
    query->bindValue(0, score.getScore());
    query->bindValue(1, score.getName());
    query->bindValue(2, score.getStringDate());
    bool result = query->exec();

    if (result) {
      ;
    } else {
      qDebug() << "Error inserting score: " << query->lastError().text();
    }
}

QVector<Score *> Repository::getScore()
{
    query->exec("SELECT * FROM score ORDER BY score DESC");


    QVector<Score *> scores;
    while (query->next()) {
        int score = query->value(0).toInt();
        QString name = query->value(1).toString();
        QString date = query->value(2).toString();
        Score* scoreInfo = new Score(score, name, date);
        scores.push_back(scoreInfo);

    }
    if (!query->exec()){
        qDebug() << "error in geting score : " << query->lastError();
    }
    return scores;
}
