#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::on_pushButton_clicked()
{
    this->close();
}

void Ventana::on_pushButton_2_clicked()
{
    this->close();
}


