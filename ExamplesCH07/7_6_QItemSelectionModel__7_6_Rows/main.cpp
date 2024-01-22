#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTableView");
   window.resize(500, 200);

   QTableView *view = new QTableView();
   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setRowCount(3);
   model->setColumnCount(4);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   view->setModel(model);
   QStringList list;
   list << "A" << "B" << "C" << "D";
   model->setHorizontalHeaderLabels(list);
   QStringList list2;
   list2 << "01" << "02" << "03";
   model->setVerticalHeaderLabels(list2);

   QItemSelectionModel *selModel = new QItemSelectionModel(model, &window);
   view->setSelectionModel(selModel);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->setFocus();
      QItemSelectionModel *sel = view->selectionModel();
      QModelIndex ind = view->model()->index(0, 0);
      sel->select(ind, QItemSelectionModel::Rows | QItemSelectionModel::Select);
   });

   window.show();
   return app.exec();
}



