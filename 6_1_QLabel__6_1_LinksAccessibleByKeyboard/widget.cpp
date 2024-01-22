#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label = new QLabel();
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setText(
        "<a href=\"https://google.ru/\">Это гиперссылка 1</a><br>"
        "<a href=\"https://bhv.ru/\">Это гиперссылка 2</a>");
   label->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard);

   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(label, SIGNAL(linkActivated(QString)),
           this, SLOT(on_link_activated(QString)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << label->textInteractionFlags();
}

void Widget::on_link_activated(const QString &s)
{
   qDebug() << s;
}


Widget::~Widget() {}
