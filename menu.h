#ifndef MENU_H
#define MENU_H

#include <QDialog>

#include "new_game.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    New_Game *game;
};

#endif // MENU_H
