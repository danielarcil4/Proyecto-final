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
