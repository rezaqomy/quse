#ifndef SCORE_H
#define SCORE_H
#include <QString>
#include <QDate>

static const QString DATE_FORMAT = "yyyy/MM/dd";

class Score
{
public:
    Score();
    Score(int, QString&, QString&);
    Score(int, QString&, QDate&);
    Score(int, QString);
    int getScore();
    QString getName();
    QString getStringDate();
    QDate getDate();

    void setScore(int score);
    void setName(QString& name);
    void setDate(QString date);
    void setDate(QDate date);


private:
    int score{};
    QString name{};
    QDate date{};
};

#endif // SCORE_H
