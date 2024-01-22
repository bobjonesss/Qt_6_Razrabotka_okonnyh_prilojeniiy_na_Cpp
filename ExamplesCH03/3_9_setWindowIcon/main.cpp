#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Смена значка в заголовке окна");
   window.resize(350, 70);
   QIcon ico(":/test.ico");
   window.setWindowIcon(ico); // Значок для окна
   app.setWindowIcon(ico);    // Значок для приложения

       QLabel *label = new QLabel("ТЗначок для окна ТОЛЬКО для WINdows под MAC не пашет!");
       QVBoxLayout *vbox = new QVBoxLayout;
       vbox->addWidget(label);
       window.setLayout(vbox);

   window.show();
   return app.exec();
}
