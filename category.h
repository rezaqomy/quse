#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

class Category
{
public:
    Category(int& id, QString& title);
    Category();

    void setID(int& id);
    void setTitle(QString& title);

    int& getID();
    QString& getTitle();

private:
    int id{};
    QString title{};
};

#endif // CATEGORY_H
