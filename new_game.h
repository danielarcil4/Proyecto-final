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

    int getDificultad() const;

    QString getUsuario() const;
    void setUsuario(const QString &value);

    QString getUsuario2() const;
    void setUsuario2(const QString &value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::New_Game *ui;
    int dificultad;
    QString Usuario,Usuario2;
};

#endif // NEW_GAME_H
