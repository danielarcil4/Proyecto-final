#include "menu.h"
#include "ui_menu.h"
#include "QDebug"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    loader = false;
    NewGames = false;
    cerrar=false;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    NewGames=true;
    this->close();
}

void Menu::on_pushButton_4_clicked()
{
    loader = true;
    this->close();
}

bool Menu::getNewGames() const
{
    return NewGames;
}

bool Menu::getLoader() const
{
    return loader;
}

void Menu::setLoader(bool value)
{
    loader = value;
}

void Menu::on_pushButton_2_clicked()
{
    cerrar=true;
    this->close();
}

bool Menu::getCerrar() const
{
    return cerrar;
}

void Menu::setCerrar(bool value)
{
    cerrar = value;
}

void Menu::on_pushButton_3_clicked()
{
    eliminar = new Eliminar_partida;
    eliminar->setModal(true);
    eliminar->exec();
}
