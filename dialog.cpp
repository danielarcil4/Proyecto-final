#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    menu = new Menu;
    menu->setModal(true);
    menu->exec();
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,10000,1000);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QBrush(QImage(":/Resourse/mapa.png")));
    this->resize(1500,1000);
    scene->addRect(scene->sceneRect());
    for (short int i=0, I=380;i<8;i++,I+=745) {
        Muro.push_back(new Muros);
        Muro.back()->setPos(I,840);
        scene->addItem(Muro.back());
    }

    /*for (short int i=0, I=882;i<1;i++,I+=200) {
        Obstaculo.push_back(new Obstaculos);
        Obstaculo.back()->setPos(I,740);
        scene->addItem(Obstaculo.back());
    }*/
    Obstaculo.push_back(new Obstaculos);
    Obstaculo.back()->setAlto(90);
    Obstaculo.back()->setPos(1082,770);
    scene->addItem(Obstaculo.back());

    Disparador1 = new Enemigo_1();
    Disparador1->setPos(720,790);
    scene->addItem(Disparador1);

    Scorpion = new Enemigo_1();
    Scorpion->setPos(1720,780);
    Scorpion->setAlto(70);
    Scorpion->setAncho(70);
    Scorpion->Pixmap = new QPixmap(":/Resourse/Scorpio_attack.png");
    scene->addItem(Scorpion);

    tiempo = new Contador();
    scene->addItem(tiempo);
    tiempo->setPos(220,10);
    tiempo->setcontador(100);

    vidas = new Vidas();
    scene->addItem(vidas);
    vidas->setPos(70,10);

    jugador = new Personaje();
    jugador->setPos(70,768);

    scene->addItem(jugador);

    timer = new QTimer();
    timer->start(100);
    disparo = new QTimer();
    disparo->start(5000);
    connect(timer,SIGNAL(timeout()),this,SLOT(saltar()));
    connect(disparo,SIGNAL(timeout()),this,SLOT(Disparo()));

}

void Dialog::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_W:
        for(int i=0;i<Muro.size();i++){
            for (int I=0;I<Obstaculo.size();I++){
                if(jugador->collidesWithItem(Muro.at(i)) or jugador->collidesWithItem(Obstaculo.at(I))){
                    jugador->setVel(jugador->getVx(),-60);
                }
            }
        }

        break;
    case Qt::Key_A:
        jugador->setVel(-20,jugador->getVy());
        tiempo->setPos(jugador->x()+150,tiempo->y());
        vidas->setPos(jugador->x(),vidas->y());
        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1.png");

        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        for (int i=0;i<Obstaculo.size();i++ ) {
            if(jugador->collidesWithItem(Obstaculo.at(i)) and jugador->x()<Obstaculo.at(i)->x()+20 and jugador->x()>Obstaculo.at(i)->x() and jugador->y()>Obstaculo.at(i)->y()-120)
                jugador->setVel(jugador->getVx()+20,jugador->getVy());
        }
        break;
    case Qt::Key_D:
        jugador->setVel(20,jugador->getVy());
        tiempo->setPos(jugador->x()+150,tiempo->y());
        vidas->setPos(jugador->x(),vidas->y());
        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1 reverso.png");
        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        for (int i=0;i<Obstaculo.size();i++ ) {
            if(jugador->collidesWithItem(Obstaculo.at(i)) and jugador->x()>Obstaculo.at(i)->x()-20 and jugador->x()<Obstaculo.at(i)->x() and /*posicion y del obstaculo*/jugador->y()>Obstaculo.at(i)->y()-120)
                jugador->setVel(jugador->getVx()-20,jugador->getVy());
                }

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
    if(jugador->getVy()==0){
        if (jugador->getVx()!=0)
            jugador->setVx(jugador->getVx() - jugador->getVx()/3);
    }
    if(jugador->y()>765)
        jugador->setVel(jugador->getVx(),0);

    //qDebug()<<Obstaculo.at(i)->y()-119;

    for (int i=0;i<Obstaculo.size();i++ ) {
        if(jugador->y()<768 and !jugador->collidesWithItem(Obstaculo.at(i)))
            jugador->setVy(jugador->getVy()+10);

        if(jugador->collidesWithItem(Obstaculo.at(i)) and jugador->y()>Obstaculo.at(i)->y()-123)
            jugador->setVel(jugador->getVx(),0);
            }
    QList<QGraphicsItem *> colision = jugador->collidingItems();
    for (int i=0;i<colision.size();i++ ) {
        for (int I=0;I<balas.size();I++ ) {
            if(jugador->collidesWithItem(colision.at(i)) and colision.at(i)== balas.at(I)){
                scene->removeItem(colision.at(i));
                balas.removeAt(i);
                jugador->setVel(0,jugador->getVy());         
                ui->progressBar->setValue(ui->progressBar->value()-25);

                if(ui->progressBar->value()==0){
                    jugador->setPos(70,768);
                    jugador->setVel(0,0);
                    ui->progressBar->setValue(100);
                    vidas->Decrementar();
                    if(vidas->getVidas()==0){
                        ventana = new Ventana;
                        ventana->setModal(true);
                        ventana->exec();
                        tiempo->setcontador(100);
                        vidas->setVidas(4);
                        vidas->Decrementar();
                        }
                    }
                }
        }
     }
    for (int i=0;i<balas.size();i++ ) {
        if(balas.at(i)->y()<=0 or balas.at(i)->y()>755){
            scene->removeItem(balas.at(i));
            balas.removeAt(i);
        }
    }

}

void Dialog::Disparo()
{
    balas.push_back(new Bala);
    balas.back()->setPos(720,755);
    scene->addItem(balas.back());

    balas.push_back(new Bala);
    balas.back()->setPos(1720,755);
    balas.back()->setR(6);
    scene->addItem(balas.back());

}
void Ventana::on_pushButton_clicked()
{
  this->close();
}


