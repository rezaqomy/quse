#include "categoryview.h"



CategoryView::CategoryView(Category* category): category(category)
{
    QHBoxLayout* layout = new QHBoxLayout();

    button = new QPushButton;
    label = new QLabel;

    button->setText(category->getTitle());
    button->connect(button, &QPushButton::clicked, this, &CategoryView::on_button_clicked);

    layout->addWidget(button);


    setLayout(layout);


}

void CategoryView::on_button_clicked()
{
    qDebug() << category->getID() << category->getTitle();
    emit categorySelected(category->getID());
}



