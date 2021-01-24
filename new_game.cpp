#include "new_game.h"
#include "ui_new_game.h"
#include "QDebug"

#include <fstream>
//#include <iostream>

using namespace std;


New_Game::New_Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Game)
{
    ui->setupUi(this);
}

New_Game::~New_Game()
{
    delete ui;
}

void New_Game::on_pushButton_clicked()
{
    ofstream escritura;

    escritura.open("../Proyecto_final/BD.txt");

    if (!escritura.is_open())
       {
        qDebug()<<"Error abriendo el archivo";
        exit(1);
       }
    qDebug()<<ui->plainTextEdit->toPlainText();
    //QString registro = ui->plainTextEdit->toPlainText();
    escritura<< "";
    escritura.close();

    this->close();
}
