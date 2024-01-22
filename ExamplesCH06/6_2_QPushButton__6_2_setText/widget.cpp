#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Получить значение");
   btn1->setText("&Выполнить операцию &&1");
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << "Кнопка нажата";
   qDebug() << btn1->text();
}

Widget::~Widget() {}
