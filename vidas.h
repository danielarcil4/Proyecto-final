#ifndef VIDAS_H
#define VIDAS_H


#include <QGraphicsItem>
#include <QTimer>

class Vidas: public QGraphicsTextItem
{
    int vidas;
public:
    Vidas(QGraphicsItem * parent=0);
    QTimer *timer;
    int getVidas() const;
    void setVidas(int value);
    void Decrementar();
};

#endif // VIDAS_H
