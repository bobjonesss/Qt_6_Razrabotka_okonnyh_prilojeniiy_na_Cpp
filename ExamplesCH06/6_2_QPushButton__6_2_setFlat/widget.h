#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
private:
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
