#include "score.h"

Score::Score()
{

}

Score::Score(int score, QString& name, QString& date)
{
    setScore(score);
    setName(name);
    setDate(date);
}

Score::Score(int score, QString& nane, QDate& date)
{
    setScore(score);
    setName(name);
    setDate(date);
}

Score::Score(int score, QString name)
{
    setScore(score);
    setName(name);
    setDate(QDate::currentDate());
}

int Score::getScore()
{
    return score;
}

QString Score::getName()
{
    return name;
}

QString Score::getStringDate()
{
    return date.toString(DATE_FORMAT);
}

QDate Score::getDate()
{
    return date;
}

void Score::setScore(int score)
{
    this->score = score;
}

void Score::setName(QString &name)
{
    this->name = name;
}

void Score::setDate(QString date)
{
    this->date = QDate::fromString(date, DATE_FORMAT);
}

void Score::setDate(QDate date)
{
    this->date = date;
}
