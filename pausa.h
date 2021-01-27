#ifndef PAUSA_H
#define PAUSA_H

#include <QDialog>
//#include "dialog.h"

namespace Ui {
class Pausa;
}

class Pausa : public QDialog
{
    Q_OBJECT

public:
    explicit Pausa(QWidget *parent = nullptr);
    ~Pausa();

    int getReset() const;
    void setReset(int value);

    bool getSave() const;
    void setSave(bool value);

    int getLineas() const;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pausa *ui;
    bool reset;
    bool save;
    int Lineas;
    short int veces;
};

#endif // PAUSA_H
