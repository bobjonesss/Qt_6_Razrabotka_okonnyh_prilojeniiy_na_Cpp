#include "widget.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QStyle>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   radio1 = new QRadioButton("&Да");
   radio2 = new QRadioButton("&Нет");
   QIcon icon1 = style()->standardIcon(QStyle::SP_DialogOkButton);
   radio1->setIcon(icon1);
   QIcon icon2 = style()->standardIcon(QStyle::SP_MessageBoxCritical);
   radio2->setIcon(icon2);

   QGroupBox *box = new QGroupBox("&Вы знаете язык C++?");
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(radio1);
   hbox->addWidget(radio2);
   box->setLayout(hbox);

   vbox = new QVBoxLayout();
   vbox->addWidget(box);
   setLayout(vbox);

   radio1->setChecked(true);

   connect(radio1, SIGNAL(toggled(bool)),
           this, SLOT(on_radio1_toggled(bool)));
   connect(radio2, SIGNAL(toggled(bool)),
           this, SLOT(on_radio2_toggled(bool)));
}

Widget::~Widget() {}

void Widget::on_radio1_toggled(bool status)
{
   qDebug() << "radio1" << status;
}

void Widget::on_radio2_toggled(bool status)
{
   qDebug() << "radio2" << status;
}
