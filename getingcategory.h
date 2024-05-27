#ifndef GETINGCATEGORY_H
#define GETINGCATEGORY_H

#include "apiclient.h"
#include "category.h"
#include <QString>
#include <QVector>

static const QString CATEGORY_URL = "https://opentdb.com/api_category.php";

class GetingCategory: public ApiClient
{
public:
    GetingCategory();

protected:
    void getCategorys();
    void virtual categoryIsReady(QVector<Category*>& category)=0;

private:
    void handelRequst(QString& data);
    Category* jsonToCategory(QJsonValueRef json);
};

#endif // GETINGCATEGORY_H
