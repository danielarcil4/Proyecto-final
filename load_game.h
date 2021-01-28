#ifndef LOAD_GAME_H
#define LOAD_GAME_H

#include <QDialog>

namespace Ui {
class Load_Game;
}

class Load_Game : public QDialog
{
    Q_OBJECT

public:
    explicit Load_Game(QWidget *parent = nullptr);
    ~Load_Game();

    bool getLoad() const;
    void setLoad(bool value);

    QString getUsuario() const;
    void setUsuario(const QString &value);

    bool getLoadlvl() const;
    void setLoadlvl(bool value);

    QString getUsuario2() const;
    void setUsuario2(const QString &value);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Load_Game *ui;
    bool load;
    QString Usuario,Usuario2;
    bool loadlvl;
    //QString loadId;
};

#endif // LOAD_GAME_H
