#include "widget.h"

#include <QFileDialog>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Отобразить диалоговое окно...");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   QFileDialog dialog(this, "Это заголовок окна");
   dialog.setAcceptMode(QFileDialog::AcceptOpen);
   dialog.setDirectory("C:\\cpp\\projectsQt\\Test");
   dialog.setNameFilter("All (*);;Images (*.png *.jpg)");
   int result = dialog.exec();
   if (result == QDialog::Accepted) {
       qDebug() << dialog.selectedFiles();
   }
   else {
      qDebug() << "Нажата кнопка Cancel";
   }
}

