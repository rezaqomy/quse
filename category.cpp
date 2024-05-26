#include "category.h"

Category::Category(int &id, QString &title)
{
   setID(id);
   setTitle(title);
}

Category::Category()
{

}

void Category::setID(int &id)
{
    this->id = id;
}

void Category::setTitle(QString &title)
{
    this->title = title;
}

int &Category::getID()
{
    return id;
}

QString &Category::getTitle()
{
    return title;
}
