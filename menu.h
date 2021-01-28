#ifndef MENU_H
#define MENU_H

#include <QDialog>

#include "new_game.h"
#include "load_game.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    bool getLoader() const;
    void setLoader(bool value);

    bool getNewGames() const;

    bool getCerrar() const;
    void setCerrar(bool value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    New_Game *game;
    Load_Game *cargar;
    bool loader;
    bool NewGames;
    bool cerrar;
};

#endif // MENU_H
