#ifndef MYLABEL2_H
#define MYLABEL2_H

#include <QLabel>
#include <QString>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPixmap>

class MyLabel2 : public QLabel
{
   Q_OBJECT
protected:
   void dragEnterEvent(QDragEnterEvent *e) override;
   void dropEvent(QDropEvent *e) override;
   void dragMoveEvent(QDragMoveEvent *e) override;
public:
   MyLabel2(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL2_H
