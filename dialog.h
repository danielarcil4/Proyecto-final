#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>

#include "muros.h"
#include "personaje.h"
#include "obstaculos.h"

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
    Personaje *jugador;
    QList <QGraphicsItem*> Muro;
    QTimer *timer;

signals:
public slots:
    void saltar();
};
#endif // DIALOG_H
