#ifndef SCORE_H
#define SCORE_H
#include <QString>
#include <QDate>

static const QString DATE_FORMAT = "yyyy/MM/dd";

class Score
{
public:
    Score();

    Score(int, int , int, QString&, QString&);
    Score(int, int , int, QString&, QDate&);
    Score(int, int, int, QString);
    int getScore();
    QString getName();
    QString getStringDate();
    QDate getDate();
    int getEasy();
    int getMedium();
    int getHard();

    void setScore(int score);
    void setName(QString& name);
    void setDate(QString date);
    void setDate(QDate date);
    void setEasy(int num);
    void setMedium(int num);
    void setHard(int num);

private:
    int score{};
    int hard{};
    int easy{};
    int medium{};
    QString name{};
    QDate date{};
};

#endif // SCORE_H
