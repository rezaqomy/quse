#ifndef GETINGQUSTIONS_H
#define GETINGQUSTIONS_H

#include "apiclient.h"

static const QString QUESTION_URL = "https://opentdb.com/api.php?amount=%1&category=%2&difficulty=%3&type=multiple";

class GetingQustions: public ApiClient
{
public:
    GetingQustions();
    ~GetingQustions();

private:
    void handelRequst(QString& data);
};

#endif // GETINGQUSTIONS_H
