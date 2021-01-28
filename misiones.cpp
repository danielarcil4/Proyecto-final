#include "misiones.h"
#include "ui_misiones.h"

Misiones::Misiones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Misiones)
{
    ui->setupUi(this);
}

Misiones::~Misiones()
{
    delete ui;
}
