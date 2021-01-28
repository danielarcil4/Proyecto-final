#ifndef MISIONES_H
#define MISIONES_H

#include <QDialog>

namespace Ui {
class Misiones;
}

class Misiones : public QDialog
{
    Q_OBJECT

public:
    explicit Misiones(QWidget *parent = nullptr);
    ~Misiones();

private:
    Ui::Misiones *ui;
};

#endif // MISIONES_H
