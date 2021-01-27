#ifndef LVL_2_H
#define LVL_2_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <sstream>

#include "personaje.h"
#include "obstaculos.h"
#include "contador.h"
#include "enemigo_1.h"
#include "bala.h"
#include "vidas.h"
#include "pausa.h"
#include "ventana.h"

namespace Ui {
class Lvl_2;
}

class Lvl_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Lvl_2(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * evento);
    ~Lvl_2();

    bool getLoadlvl() const;
    void setLoadlvl(bool value);

private:
    Ui::Lvl_2 *ui;
    QGraphicsScene *scene;
    int nivel;
    int dificultad;

    //Qlists
    QList <Obstaculos*> Obstaculo;
    QList <Obstaculos*> Pantano;
    QList <Bala*> balas;

    //Enemigos
    Enemigo_1 *Disparador1;
    Enemigo_1 *Scorpion;
    Enemigo_1 *Ave;
    Enemigo_1 *Scorpion2;
    Enemigo_1 *Ave2;

    //ventanas
    Pausa *pausa;
    Ventana *ventana;

    //timers
    QTimer *timer;
    QTimer *disparo;

    //items
    Contador *tiempo;
    Vidas *vidas;
    Personaje *jugador;
    Obstaculos *Meta;

    bool loadlvl;

signals:
public slots:
    void saltar();
    void Disparo();
};

#endif // LVL_2_H
