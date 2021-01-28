#include "pausa.h"
#include "ui_pausa.h"
#include "QDebug"
#include <fstream>

using namespace std;

Pausa::Pausa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pausa)
{
    ui->setupUi(this);
    reset=false;
    save=false;
    cerrar=false;
    Lineas=4;
    veces=1;
    misiones = new Misiones;
    if(veces==1){
        ifstream Lectura;
        string Data;

        Lectura.open("../Proyecto_final/Usuarios.txt");

        if (!Lectura.is_open())
           {
            qDebug()<<"Error abriendo el archivo";
            exit(1);
           }
        Lectura>>Data;

        while(!Lectura.eof()){
            Lineas++;
            Lectura>>Data;
        }
        Lectura.close();
        veces++;
    }

}

Pausa::~Pausa()
{
    delete ui;  
}

void Pausa::on_pushButton_clicked()
{
    reset = true;
}

bool Pausa::getSave() const
{
    return save;
}

void Pausa::setSave(bool value)
{
    save = value;
}

int Pausa::getReset() const
{
    return reset;
}

void Pausa::setReset(int value)
{
    reset = value;
}

void Pausa::on_pushButton_2_clicked()
{
    save = true;
}

void Pausa::setLineas(int value)
{
    Lineas = value;
}

int Pausa::getLineas() const
{
    return Lineas;
}

void Pausa::on_pushButton_4_clicked()
{
    misiones->setModal(true);
    misiones->exec();
}

void Pausa::on_pushButton_3_clicked()
{
    cerrar = true;
    this->close();
}

bool Pausa::getCerrar() const
{
    return cerrar;
}

void Pausa::setCerrar(bool value)
{
    cerrar = value;
}
