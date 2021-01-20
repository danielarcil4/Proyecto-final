#ifndef VENTANA_H
#define VENTANA_H


#include <QDialog>

namespace Ui {
class Ventana;
}

class Ventana : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
