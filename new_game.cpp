#include "new_game.h"
#include "ui_new_game.h"

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
