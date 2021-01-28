#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <sstream>
#include <QMediaPlayer>

#include "personaje.h"
#include "obstaculos.h"
#include "contador.h"
#include "enemigo_1.h"
#include "bala.h"
#include "vidas.h"
#include "ventana.h"
#include "menu.h"
#include "pausa.h"
#include "puntajes.h"
#include "eliminar_partida.h"


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
    int dificultad;

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
    New_Game *nuevo;
    Puntajes *puntajes;
    Eliminar_partida *eliminar;

    //timers
    QTimer *timer;
    QTimer *disparo;

    //items
    Contador *tiempo;
    Contador *tiempo2;
    Vidas *vidas;
    Vidas *vidas2;
    Personaje *jugador;
    Personaje *jugador2;
    Obstaculos *Meta;
    QMediaPlayer *musica;
    QMediaPlayer *lastimarse;



signals:
public slots:
    void saltar();
    void Disparo();
};
#endif // DIALOG_H
