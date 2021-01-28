#ifndef ELIMINAR_PARTIDA_H
#define ELIMINAR_PARTIDA_H

#include <QDialog>

namespace Ui {
class Eliminar_partida;
}

class Eliminar_partida : public QDialog
{
    Q_OBJECT

public:
    explicit Eliminar_partida(QWidget *parent = nullptr);
    ~Eliminar_partida();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Eliminar_partida *ui;
};

#endif // ELIMINAR_PARTIDA_H
