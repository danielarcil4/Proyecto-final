#include "new_game.h"
#include "ui_new_game.h"
#include "QDebug"

#include <fstream>

using namespace std;


New_Game::New_Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Game)
{
    ui->setupUi(this);
    dificultad=1;
}

New_Game::~New_Game()
{
    delete ui;
}

void New_Game::on_pushButton_clicked()
{
    ofstream Escritura;
    string alo;

    Escritura.open("../Proyecto_final/Usuarios.txt",std::ios::app);

    if (!Escritura.is_open())
       {
        qDebug()<<"Error abriendo el archivo";
        exit(1);
       }

    Escritura<< ui->plainTextEdit->toPlainText().toStdString() <<endl;
    Usuario= ui->plainTextEdit->toPlainText();
    Escritura<< "70,768,60,3,100,"+ui->comboBox->currentText().toStdString()+","<<endl;
    Escritura<< ui->plainTextEdit_2->toPlainText().toStdString() <<endl;
    Usuario2= ui->plainTextEdit_2->toPlainText();
    Escritura<< "70,768,60,3,100,"+ui->comboBox->currentText().toStdString()+","<<endl;
    Escritura.close();

    if(ui->comboBox->currentText().toStdString()=="Facil")
        dificultad=1;
    if(ui->comboBox->currentText().toStdString()=="Normal")
        dificultad=2;
    if(ui->comboBox->currentText().toStdString()=="Dificil")
        dificultad=3;
    this->close();
}

QString New_Game::getUsuario2() const
{
    return Usuario2;
}

void New_Game::setUsuario2(const QString &value)
{
    Usuario2 = value;
}

QString New_Game::getUsuario() const
{
    return Usuario;
}

void New_Game::setUsuario(const QString &value)
{
    Usuario = value;
}

int New_Game::getDificultad() const
{
    return dificultad;
}

