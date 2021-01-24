#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <QDialog>


namespace Ui {
class New_Game;
}

class New_Game : public QDialog
{
    Q_OBJECT

public:
    explicit New_Game(QWidget *parent = nullptr);
    ~New_Game();

private slots:
    void on_pushButton_clicked();

private:
    Ui::New_Game *ui;
};

#endif // NEW_GAME_H
