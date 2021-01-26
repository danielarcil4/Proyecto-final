#include "pausa.h"
#include "ui_pausa.h"

Pausa::Pausa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pausa)
{
    ui->setupUi(this);
    reset=false;
    save=false;
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
