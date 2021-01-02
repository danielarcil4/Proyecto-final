#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,10000,1000);
    ui->graphicsView->setScene(scene);
    //scene->setBackgroundBrush(QBrush(QImage(":/Resourse/mapa.png")));
    this->resize(1500,1000);
    scene->addRect(scene->sceneRect());
    for (short int i=0, I=380;i<3;i++,I+=755) {
        Muro.push_back(new Muros);
        Muro.back()->setPos(I,840);
        scene->addItem(Muro.back());
    }
    Muro.push_back(new Obstaculos);
    Muro.back()->setPos(880,720);
    scene->addItem(Muro.back());


    jugador = new Personaje();
    jugador->setPos(70,768);

    scene->addItem(jugador);

    timer = new QTimer();
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(saltar()));

}

void Dialog::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_W:
        for (int i=0;i<Muro.size();i++ ) {
            if(jugador->collidesWithItem(Muro.at(i)))
                jugador->setVel(jugador->getVx(),jugador->getVy()-40);
        }
        break;
    case Qt::Key_A:
        jugador->setVel(-20,jugador->getVy());
        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1.png");

        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        if(jugador->x()<-50)
            jugador->setPos(jugador->x()+5,jugador->y());
        break;
    case Qt::Key_D:
        jugador->setVel(20,jugador->getVy());

        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1 reverso.png");
        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        break;
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::saltar()
{
    jugador->salto();
    if(jugador->y()>760){
        jugador->setVy(0);
        if (jugador->getVx()!=0)
            jugador->setVx(jugador->getVx() - jugador->getVx()/4);
    }

}

