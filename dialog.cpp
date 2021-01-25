#include "dialog.h"
#include "ui_dialog.h"

#include <fstream>

using namespace std;

short int i=-5;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    menu = new Menu;
    menu->setModal(true);
    menu->exec();
    pausa = new Pausa;
    load = new Load_Game;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,4500,1000);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QBrush(QImage(":/Resourse/mapa.png")));
    this->resize(1500,1000);
    scene->addRect(scene->sceneRect());


    for (short int i=0, I=882,y=740;i<8;i++,I+=350) {
        y=740;
        Obstaculo.push_back(new Obstaculos);
        if(i==0 or i==3 or i==4 or i==7){
            Obstaculo.back()->setAlto(60);
            y=785;
        }
        if(i==4){
            I=2500;
        }
        Obstaculo.back()->setPos(I,y);
        scene->addItem(Obstaculo.back());
    }

    for (short int i=0, I=1050,y=815;i<3;i++,I+=350) {
        Pantano.push_back(new Obstaculos);
        Pantano.back()->setAncho(200);
        Pantano.back()->setAlto(20);
        Pantano.back()->Pixmap = new QPixmap(":/Resourse/Pantano.png");
        Pantano.back()->setPos(I,y);
        scene->addItem(Pantano.back());
    }

    for (short int i=0, I=2650,y=790;i<3;i++,I+=350) {
        Disparador1 = new Enemigo_1();
        Disparador1->setPos(I,y);
        scene->addItem(Disparador1);
    }

    Disparador1 = new Enemigo_1();
    Disparador1->setPos(720,790);
    scene->addItem(Disparador1);

    Ave = new Enemigo_1();
    Ave->setPos(1550,670);
    Ave->setAlto(70);
    Ave->setAncho(70);
    Ave->Pixmap = new QPixmap(":/Resourse/Vulture_attack.png");
    scene->addItem(Ave);

    Scorpion = new Enemigo_1();
    Scorpion->setPos(2050,780);
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

    Meta = new Obstaculos();
    Meta->setPos(4000,765);
    Meta->setAlto(270);
    Meta->setAncho(200);
    Meta->Pixmap = new QPixmap(":/Resourse/Meta.png");
    scene->addItem(Meta);

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
    case Qt::Key_Escape:
        pausa->setModal(true);
        pausa->exec();
        break;
    case Qt::Key_W:
        for (int I=0;I<Obstaculo.size();I++){
            if(jugador->y()>765 or jugador->collidesWithItem(Obstaculo.at(I))){
                jugador->setVel(jugador->getVx(),-60);
            }
        }

        break;
    case Qt::Key_A:
        jugador->setVel(-20,jugador->getVy());
        for (int I=0;I<Pantano.size();I++) {
            if(jugador->x()>Pantano.at(I)->x()-130 and jugador->x()<Pantano.at(I)->x()+130 and jugador->y()>755)
                jugador->setVel(-5,jugador->getVy());

        }

        tiempo->setPos(jugador->x()+150,tiempo->y());
        vidas->setPos(jugador->x(),vidas->y());
        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1.png");

        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        for (int i=0;i<Obstaculo.size();i++ ) {
            if((jugador->x()<Obstaculo.at(i)->x()+20 and jugador->x()>Obstaculo.at(i)->x()) and jugador->y()>Obstaculo.at(i)->y()-120)
                jugador->setVel(jugador->getVx()+20,jugador->getVy());
        }
        break;
    case Qt::Key_D:
        jugador->setVel(20,jugador->getVy());
        for (int I=0;I<Pantano.size();I++) {
            if(jugador->x()>Pantano.at(I)->x()-130 and jugador->x()<Pantano.at(I)->x()+130 and jugador->y()>755)
                jugador->setVel(5,jugador->getVy());           
        }
        tiempo->setPos(jugador->x()+150,tiempo->y());
        vidas->setPos(jugador->x(),vidas->y());
        jugador->Pixmap = new QPixmap(":/Resourse/Personaje 1 reverso.png");
        jugador->setColumnas(jugador->getColumnas()+96);
        if(jugador->getColumnas()>=576){
            jugador->setColumnas(0);
        }
        this->update(-jugador->getAncho()/2,-jugador->getAlto()/2,jugador->getAncho(),jugador->getAlto());

        for (int i=0;i<Obstaculo.size();i++ ) {
            if((jugador->x()>Obstaculo.at(i)->x()-20 and jugador->x()<Obstaculo.at(i)->x()) and jugador->y()>Obstaculo.at(i)->y()-120)
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
    jugador->setPos( jugador->x() + jugador->getVx() , jugador->y() + jugador->getVy() );
    if(jugador->getVy()==0){
        if (jugador->getVx()!=0)
            jugador->setVx(jugador->getVx() - jugador->getVx()/3);
    }

    if(jugador->y()>765)
        jugador->setVel(jugador->getVx(),0);
    else{
        jugador->setVy(jugador->getVy()+10);

}
    for (int i=0;i<Obstaculo.size();i++ ) {
        if(jugador->collidesWithItem(Obstaculo.at(i)) and jugador->y()>Obstaculo.at(i)->y()-123)
            jugador->setVel(jugador->getVx(),0);
            }
    QList<QGraphicsItem *> colision = jugador->collidingItems();
    for (int i=0;i<colision.size();i++ ) {
        for (int I=0;I<balas.size();I++ ) {
            if(colision.at(i)== balas.at(I) or colision.at(i)==Ave){
                scene->removeItem(colision.at(i));
                balas.removeAt(i);
                if(colision.at(i)==Ave){
                    Ave = new Enemigo_1();
                    Ave->setPos(1550,670);
                    Ave->setAlto(70);
                    Ave->setAncho(70);
                    Ave->Pixmap = new QPixmap(":/Resourse/Vulture_attack_reverse.png");
                    scene->addItem(Ave);
                }
                jugador->setVel(0,jugador->getVy());         
                ui->progressBar->setValue(ui->progressBar->value()-100);

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

    Ave->setPos(Ave->x()+i,Ave->y());
    if(Ave->x()<=1545){
      i = 10;
      Ave->Pixmap = new QPixmap(":/Resourse/Vulture_attack_reverse.png");
    }
    else if(Ave->x()>=2500){
      i = -10;
      Ave->Pixmap = new QPixmap(":/Resourse/Vulture_attack.png");
    }
    if(jugador->x()>4000){
        qDebug()<<"aaa";
    }
    if(tiempo->getcontador()<=0){
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

    if(pausa->getReset()){
        jugador->setPos(70,768);
        jugador->setVel(0,0);
        ui->progressBar->setValue(100);
        tiempo->setcontador(100);
        vidas->setVidas(4);
        vidas->Decrementar();
        pausa->setReset(false);
    }
    else if(pausa->getSave()){
        ofstream Escritura;
        string alo;

        Escritura.open("../Proyecto_final/Usuarios.txt",std::ios::app);

        if (!Escritura.is_open())
           {
            qDebug()<<"Error abriendo el archivo";
            exit(1);
           }

        Escritura<< jugador->x()<<","<<jugador->y()<<","<<tiempo->getcontador()<<","<<vidas->getVidas()<<","<<ui->progressBar->value()<<endl;
        Escritura.close();
        pausa->setSave(false);
    }
    qDebug()<<"Error";
    if(load->getLoad()==true){
        Load_Game().setLoad(false);
        ifstream Lectura;
        string ID,cargar;

        Lectura.open("../Proyecto_final/Usuarios.txt");

        if (!Lectura.is_open())
           {
            qDebug()<<"Error abriendo el archivo";
            exit(1);
           }
        Lectura>>ID;
        Lectura>>ID;

        while(!Lectura.eof()){
            for (int i=0,I=0,cont=0; i<ID.length();i++) {
                if(ID.at(i)==','){
                    cargar = ID.substr(I,i);
                    I=i;
                    cont++;
                }

            }
            Lectura>>ID;
            Lectura>>ID;
        }

        Lectura.close();

    }

}

void Dialog::Disparo()
{
    balas.push_back(new Bala);
    balas.back()->setPos(720,755);
    scene->addItem(balas.back());

    for (short int i=0, I=2650,y=755;i<3;i++,I+=350) {
        balas.push_back(new Bala);
        balas.back()->setPos(I,y);
        scene->addItem(balas.back());
    }

    balas.push_back(new Bala);
    balas.back()->setPos(2050,755);
    balas.back()->setR(6);
    scene->addItem(balas.back());

}





