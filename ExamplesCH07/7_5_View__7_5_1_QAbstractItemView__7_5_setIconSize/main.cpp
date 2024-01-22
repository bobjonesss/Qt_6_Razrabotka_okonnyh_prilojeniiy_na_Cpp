#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QListView");
   window.resize(500, 200);

   QListView *view = new QListView();
   view->setIconSize(QSize(32, 32));
   QStandardItemModel *model = new QStandardItemModel(3, 1, &window);

   QIcon icon1 = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   QStandardItem *item1 = new QStandardItem(icon1, "Пункт 1");
   model->setItem(1, 0, item1);

   QIcon icon2 = window.style()->standardIcon(QStyle::SP_MessageBoxInformation);
   QStandardItem *item2 = new QStandardItem(icon2, "Пункт 2");
   model->setItem(2, 0, item2);

   QIcon icon3 = window.style()->standardIcon(QStyle::SP_MessageBoxWarning);
   QStandardItem *item3 = new QStandardItem(icon3, "Пункт 3");
   model->setItem(3, 0, item3);

   view->setModel(model);
   view->setModelColumn(0);

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









