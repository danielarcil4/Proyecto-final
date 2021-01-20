#ifndef CONTADOR_H
#define CONTADOR_H

#include <QGraphicsItem>
#include <QTimer>

class Contador: public QGraphicsTextItem
{
    int contador;
public:
    Contador(QGraphicsItem * parent=0);
    QTimer *timer;
    int getcontador() const;
    void setcontador(int value);
    //void ganarLvl();

signals:
public slots:
    void Decrementar();
};

#endif // CONTADOR_H
