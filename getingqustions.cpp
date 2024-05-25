#include "getingqustions.h"

GetingQustions::GetingQustions()
{
    sendRecuset(QUESTION_URL.arg(5).arg(14).arg("easy"));
}

GetingQustions::~GetingQustions()
{

}

void GetingQustions::handelRequst(QString &data)
{
    qDebug() << data;
}

