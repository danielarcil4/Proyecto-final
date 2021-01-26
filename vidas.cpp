#include "vidas.h"
#include <QFont>

int Vidas::getVidas() const
{
    return vidas;
}

void Vidas::setVidas(int value)
{
    vidas = value;
}

Vidas::Vidas(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    vidas=3;
    setPlainText(QString("Vidas: ")+QString::number(vidas));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comic Sans MS",20));
}


void Vidas::Decrementar()
{
    --vidas;
    setPlainText(QString("Vidas: ")+QString::number(vidas));
}
