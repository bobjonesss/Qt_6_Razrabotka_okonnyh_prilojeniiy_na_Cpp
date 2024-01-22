#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   splitter = new QSplitter(Qt::Vertical);
   label1 = new QLabel("Содержимое компонента 1");
   label2 = new QLabel("Содержимое компонента 2");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   splitter->addWidget(label1);
   splitter->addWidget(label2);
   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(splitter);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(splitter, SIGNAL(splitterMoved(int,int)),
           this, SLOT(on_splitterMoved(int,int)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << splitter->count();
}

void Widget::on_splitterMoved(int a, int b)
{
   qDebug() << a << b;
}

Widget::~Widget() {}
