#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLineEdit");
   window.resize(350, 70);

   QLineEdit *lineEdit = new QLineEdit();
   lineEdit->setPlaceholderText("Введите логин");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(lineEdit);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
