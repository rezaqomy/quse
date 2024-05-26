#ifndef GETINGQUSTIONS_H
#define GETINGQUSTIONS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>
#include <QJsonArray>
#include "apiclient.h"

static const QString QUESTION_URL = "https://opentdb.com/api.php?amount=%1&category=%2&difficulty=%3&type=multiple";

class GetingQustions: public ApiClient
{
public:
    GetingQustions();
    ~GetingQustions();
    void getQuestion(int number, int category, QString difficaly);
Q_SIGNALS:
    void questionIsReady(QVector<Question*>& questions){}

private:
    void handelRequst(QString& data);
    Question& jsonToQuestion(QJsonValueRef json);
};

#endif // GETINGQUSTIONS_H