#ifndef GETINGQUSTIONS_H
#define GETINGQUSTIONS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>
#include <QJsonArray>
#include "question.h"
#include "apiclient.h"

static const QString QUESTION_URL = "https://opentdb.com/api.php?amount=%1&category=%2&difficulty=%3&type=multiple&encode=base64";
static const QString RANDOM_QUESTION_URL = "https://opentdb.com/api.php?amount=1&type=multiple&encode=base64";

class GetingQustions: public ApiClient
{
    Q_OBJECT
public:
    GetingQustions();
    void getQuestion(int number, int category, QString difficaly);
    void getRandomQuestion();
    ~GetingQustions();

Q_SIGNALS:
    void questionIsReady(QVector<Question*>& questions);

private:
    void handelRequst(QString& data);
    Question* jsonToQuestion(QJsonValueRef json);

};

#endif // GETINGQUSTIONS_H
