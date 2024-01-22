#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QTextDocumentFragment>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextEdit");
   window.resize(350, 250);

   QTextEdit *textEdit = new QTextEdit();
   textEdit->setPlainText("Блок 1\nБлок 2\nБлок 3\nБлок 4\nБлок 5 jjkh hkjhkjh khk hkh khk jhkh hkh khk hk hkh hkj hk hkhk k kjh kh jh kh khk hkh khk hkjh kh kh kjh kjhkj h kh kh kjh khk hk kh kh k");

   QPushButton *btn1 = new QPushButton("Вставить текст");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      QTextCursor cur = textEdit->textCursor();
      cur.beginEditBlock();             // Начало блока
      cur.insertText("Новый блок 1\n");
      cur.insertText("Новый блок 2\n");
      cur.endEditBlock();               // Конец блока
      cur.joinPreviousEditBlock();      // Продолжение предыдущего блока
      cur.insertText("Новый блок 3\n");
      cur.endEditBlock();               // Конец блока
      textEdit->setTextCursor(cur);
   });

   window.show();
   return app.exec();
}

