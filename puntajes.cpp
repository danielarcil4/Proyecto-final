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
    QString copia;

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
    for (long long unsigned int i=0;i<copiar.size();i++ ) {
        copia+=copiar.at(i);
    }

    Lectura.close();
    ui->plainTextEdit->setPlainText(copia);
    ui->plainTextEdit->setReadOnly(true);
}

Puntajes::~Puntajes()
{
    delete ui;
}
