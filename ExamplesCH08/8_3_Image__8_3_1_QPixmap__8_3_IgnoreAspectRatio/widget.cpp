#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   pix = QPixmap(":/photo.jpg");
   pix = pix.scaled(250, 300,
             Qt::IgnoreAspectRatio,
             Qt::FastTransformation);

}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0, 0, pix);
}
