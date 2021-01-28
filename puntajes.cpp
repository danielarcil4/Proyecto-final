#include "puntajes.h"
#include "ui_puntajes.h"
#include "QDebug"

#include <fstream>

using namespace std;

Puntajes::Puntajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Puntajes)
{
    ui->setupUi(this);
    ifstream Lectura;
    string puntaje,copiar;

    Lectura.open("../Proyecto_final/Puntajes.txt");

    if (!Lectura.is_open())
       {
        qDebug()<<"Error abriendo el archivo";
        exit(1);
       }
    Lectura>>puntaje;
    while(!Lectura.eof()){
        copiar += puntaje+"\n";
        Lectura>>puntaje;
    }

    Lectura.close();
    ui->plainTextEdit->setPlainText(copiar.data());
    ui->plainTextEdit->setReadOnly(true);
}

Puntajes::~Puntajes()
{
    delete ui;
}
