#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>

#include "personaje.h"
#include "obstaculos.h"
#include "contador.h"
#include "enemigo_1.h"
#include "bala.h"
#include "vidas.h"
#include "ventana.h"
#include "menu.h"
#include "pausa.h"

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

    //Qlists
    QList <Obstaculos*> Obstaculo;
    QList <Obstaculos*> Pantano;
    QList <Bala*> balas; 

    //Enemigos
    Enemigo_1 *Disparador1;
    Enemigo_1 *Scorpion;
    Enemigo_1 *Ave;

    //ventanas
    Ventana *ventana;
    Menu *menu;
    Pausa *pausa;
    Load_Game *load;

    //timers
    QTimer *timer;
    QTimer *disparo;

    //items
    Contador *tiempo;
    Vidas *vidas;
    Personaje *jugador;
    Obstaculos *Meta;

signals:
public slots:
    void saltar();
    void Disparo();
};
#endif // DIALOG_H
