#ifndef GETINGCATEGORY_H
#define GETINGCATEGORY_H

#include "apiclient.h"
#include "category.h"
#include <QString>

static const QString CATEGORY_URL = "https://opentdb.com/api_category.php";

class GetingCategory: public ApiClient
{
public:
    GetingCategory();
Q_SIGNALS:
    void categoryIsReady(QVector<Category*>& categorys){}

private:
    void handelRequst(QString& data);
    Category& jsonToCategory(QJsonValueRef json);
};

#endif // GETINGCATEGORY_H
