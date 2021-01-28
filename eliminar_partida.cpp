#include "eliminar_partida.h"
#include "ui_eliminar_partida.h"
#include "QDebug"

#include <sstream>
#include <fstream>

using namespace std;

Eliminar_partida::Eliminar_partida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Eliminar_partida)
{
    ui->setupUi(this);

    ifstream Lectura;
    string ID;

    Lectura.open("../Proyecto_final/Usuarios.txt");

    if (!Lectura.is_open())
       {
        qDebug()<<"Error abriendo el archivo";
        exit(1);
       }
    Lectura>>ID;

    while(!Lectura.eof()){
        ui->comboBox->addItem(QString(ID.data()));
        Lectura>>ID;
        Lectura>>ID;
        Lectura>>ID;
        Lectura>>ID;
    }

    Lectura.close();
}

Eliminar_partida::~Eliminar_partida()
{
    delete ui;
}

void Eliminar_partida::on_pushButton_clicked()
{
    ofstream Escritura;
    ifstream Lectura;
    string Datos,Guardar;

    Lectura.open("../Proyecto_final/Usuarios.txt");
    Lectura>>Datos;

    while(!Lectura.eof()){
        if(Datos==ui->comboBox->currentText().toStdString()){
            Lectura>>Datos;
            Lectura>>Datos;
            Lectura>>Datos;
            Lectura>>Datos;
        }
        if(Lectura.eof())break;
        Guardar+=Datos+"\n";
        Lectura>>Datos;
    }
    Lectura.close();

    Escritura.open("../Proyecto_final/Usuarios.txt");

    if (!Escritura.is_open())
       {
        qDebug()<<"Error abriendo el archivo";
        exit(1);
       }
    Escritura<< Guardar<<endl;
    Escritura.close();
    this->close();
}

