#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   pix = QPixmap(":/photo.jpg");
   QBitmap mask(pix.size());
   mask.clear();
   QPainter painter;
   painter.begin(&mask);
   painter.setPen(Qt::color1);
   painter.setBrush(Qt::color1);
   painter.setFont(QFont("Tahoma", 26, QFont::Bold));
   painter.setRenderHint(QPainter::TextAntialiasing);
   painter.setRenderHint(QPainter::Antialiasing);
   painter.drawText(0, 0, 500, 50,
                    Qt::AlignCenter, "Камеронова галерея");
   painter.drawEllipse(50, 50, 400, 250);
   painter.end();
   pix.setMask(mask);

}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0, 0, pix);
}
