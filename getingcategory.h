#ifndef GETINGCATEGORY_H
#define GETINGCATEGORY_H

#include "apiclient.h"
#include "category.h"
#include <QString>
#include <QVector>

static const QString CATEGORY_URL = "https://opentdb.com/api_category.php";

class GetingCategory: public ApiClient
{
    Q_OBJECT
public:
    GetingCategory();
    void getCategorys();

Q_SIGNALS:
    void categoryIsReady(QVector<Category*>& category);


private:
    void handelRequst(QString& data);
    Category* jsonToCategory(QJsonValueRef json);
};

#endif // GETINGCATEGORY_H
