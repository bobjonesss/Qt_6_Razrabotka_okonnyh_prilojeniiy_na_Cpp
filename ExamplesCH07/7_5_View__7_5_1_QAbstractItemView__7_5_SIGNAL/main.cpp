#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QListView");
   window.resize(350, 400);
   window.show();
   return app.exec();
}
