#include "getingcategory.h"

GetingCategory::GetingCategory()
{
    sendRequest(CATEGORY_URL);
}


void GetingCategory::handelRequst(QString &data)
{
    QJsonDocument triviaCategories = QJsonDocument::fromJson(data.toUtf8());
    QJsonArray categoriesJson = triviaCategories["trivia_categories"].toArray();
    QVector<Category*> categories;
    for (int i{}; i < categoriesJson.size(); i++){
        Category* category = jsonToCategory(categoriesJson[i]);
        categories.push_back(category);
    }
    categoryIsReady(categories);
}

Category* GetingCategory::jsonToCategory(QJsonValueRef jsonData)
{
    QJsonObject json = jsonData.toObject();
    int num = json["id"].toInt();
    QString name = json["name"].toString();
    Category* category = new Category(num, name);
    return category;
}
