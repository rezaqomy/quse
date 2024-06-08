#include "score.h"

Score::Score()
{

}

Score::Score(int easyScore, int mediumScore, int hardScore, QString& name, QString& date)
{
    setEasy(easyScore);
    setMedium(mediumScore);
    setHard(hardScore);
    setScore(3*hard + 2*medium + easy);
    setName(name);
    setDate(date);
}

Score::Score(int easyScore, int mediumScore, int hardScore, QString& name, QDate& date)
{
    setEasy(easyScore);
    setMedium(mediumScore);
    setHard(hardScore);
    setScore(3*hard + 2*medium + easy);
    setName(name);
    setDate(date);
}

Score::Score(int easyScore, int mediumScore, int hardScore, QString name)
{
    setEasy(easyScore);
    setMedium(mediumScore);
    setHard(hardScore);
    setScore(3*hard + 2*medium + easy);
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

int Score::getEasy()
{
    return easy;
}

int Score::getMedium()
{
    return medium;
}

int Score::getHard()
{
    return hard;
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

void Score::setEasy(int num)
{
    easy = num;
}

void Score::setMedium(int num)
{
    medium = num;
}

void Score::setHard(int num)
{
    hard = num;
}
