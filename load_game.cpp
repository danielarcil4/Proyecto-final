#include "load_game.h"
#include "ui_load_game.h"
#include "QDebug"

#include <fstream>

using namespace std;

Load_Game::Load_Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load_Game)
{
    ui->setupUi(this);

    load = false;
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
    }

    Lectura.close();

}

Load_Game::~Load_Game()
{
    delete ui;
}

bool Load_Game::getLoad() const
{
    return load;
}

void Load_Game::setLoad(bool value)
{
    load = value;
}

void Load_Game::on_pushButton_clicked()
{
    load = true;
    Usuario = ui->comboBox->currentText();
    this->close();
}

bool Load_Game::getLoadlvl() const
{
    return loadlvl;
}

void Load_Game::setLoadlvl(bool value)
{
    loadlvl = value;
}

QString Load_Game::getUsuario() const
{
    return Usuario;
}

void Load_Game::setUsuario(const QString &value)
{
    Usuario = value;
}


void Load_Game::on_pushButton_2_clicked()
{

}

void Load_Game::on_pushButton_3_clicked()
{

}
