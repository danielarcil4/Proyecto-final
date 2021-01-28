#ifndef PUNTAJES_H
#define PUNTAJES_H

#include <QDialog>

namespace Ui {
class Puntajes;
}

class Puntajes : public QDialog
{
    Q_OBJECT

public:
    explicit Puntajes(QWidget *parent = nullptr);
    ~Puntajes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Puntajes *ui;
};

#endif // PUNTAJES_H
