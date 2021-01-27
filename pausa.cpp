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
    Lineas=1;
    veces=1;
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

int Pausa::getLineas() const
{
    return Lineas;
}
