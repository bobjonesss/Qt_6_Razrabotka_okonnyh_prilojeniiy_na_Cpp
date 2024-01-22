    #include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   img = QImage(":/photo.jpg");
   img.invertPixels();
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawImage(0, 0, img);
}
