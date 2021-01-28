#include "contador.h"
#include <QFont>

int Contador::getcontador() const
{
    return contador;
}

void Contador::setcontador(int value)
{
    contador = value;
}

bool Contador::getContadorEn0() const
{
    return contadorEn0;
}

void Contador::setContadorEn0(bool value)
{
    contadorEn0 = value;
}

Contador::Contador(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    contadorEn0=false;
    setPlainText(QString("contador: ")+QString::number(contador));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comic Sans MS",20));
    timer = new QTimer();
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,&Contador::Decrementar);

}


void Contador::Decrementar()
{
    if(contadorEn0)disconnect(timer,&QTimer::timeout,this,&Contador::Decrementar);
    --contador;
    setPlainText(QString("contador: ")+QString::number(contador));
}

