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

Contador::Contador(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    setPlainText(QString("contador: ")+QString::number(contador));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comic Sans MS",20));
    timer = new QTimer();
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,&Contador::Decrementar);

}


void Contador::Decrementar()
{
    --contador;
    setPlainText(QString("contador: ")+QString::number(contador));
}

