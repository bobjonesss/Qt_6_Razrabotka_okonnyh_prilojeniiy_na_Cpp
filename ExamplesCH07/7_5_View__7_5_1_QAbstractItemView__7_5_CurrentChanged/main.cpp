#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QListView");
   window.resize(500, 200);

   QListView *view = new QListView();
   view->setEditTriggers(QAbstractItemView::CurrentChanged);
   QStringList list;
   for (int i = 1; i < 101; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);

   view->setModel(model);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QItemSelectionModel *m = view->selectionModel();
      QModelIndexList list = m->selectedIndexes();
      for (int i = 0, c = list.size(); i < c; ++i) {
         QModelIndex ind = list[i];
         if (ind.isValid()) {
            qDebug() << "Данные:" << ind.data().toString();
            qDebug() << "row:" << ind.row();
         }
      }
      if (list.size() == 0) {
         qDebug() << "Нет выделенных элементов";
      }
   });

   window.show();
   return app.exec();
}









