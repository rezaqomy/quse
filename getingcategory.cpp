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
        Category* category = &jsonToCategory(categoriesJson[i]);
        categories.push_back(category);
    }
    emit categoryIsReady(categories);
}

Category &GetingCategory::jsonToCategory(QJsonValueRef jsonData)
{
    Category category;
    QJsonObject json = jsonData.toObject();
    int num = json["id"].toInt();
    category.setID(num);
    QString name = json["name"].toString();
    category.setTitle(name);




    return category;
}
