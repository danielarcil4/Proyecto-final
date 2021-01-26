#include "menu.h"
#include "ui_menu.h"
#include "QDebug"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    game = new New_Game();
    game->setModal(true);
    game->exec();
    this->close();
}

void Menu::on_pushButton_4_clicked()
{
    this->close();
}
