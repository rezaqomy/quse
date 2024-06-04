#ifndef CATEGORYVIEW_H
#define CATEGORYVIEW_H

#include <QWidget>
#include <QDebug>
#include <category.h>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class CategoryView: public QWidget
{
    Q_OBJECT
public:
    CategoryView(Category* category);

    void on_button_clicked();
Q_SIGNALS:
    void categorySelected(int id);


private:
    QLabel* label;
    QPushButton* button;
    Category* category;
    void emitSignal();

};

#endif // CATEGORYVIEW_H
