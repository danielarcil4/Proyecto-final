#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>

#include "muros.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * evento);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    Muros *muro1;
    Muros *muro2;
    QGraphicsRectItem *personaje = new QGraphicsRectItem;
};
#endif // DIALOG_H
