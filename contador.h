#ifndef CONTADOR_H
#define CONTADOR_H

#include <QGraphicsItem>
#include <QTimer>

class Contador: public QGraphicsTextItem
{
    int contador;
    bool contadorEn0;
public:
    Contador(QGraphicsItem * parent=0);
    QTimer *timer;
    int getcontador() const;
    void setcontador(int value);

    bool getContadorEn0() const;
    void setContadorEn0(bool value);

signals:
public slots:
    void Decrementar();
};

#endif // CONTADOR_H
