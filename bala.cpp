#include "bala.h"

void Bala::setR(int value)
{
    r = value;
}

Bala::Bala()
{
    Vx=50;
    Vy=50;
    t = 0;
    r = 5;
    timer = new QTimer();
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&Bala::Move);
}

QRectF Bala::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

void Bala::Move()
{
    if(r==5)
        setPos(x(),y()-5);
    else{
        t+=0.1;
        V= sqrt((Vx*Vx)+(Vy*Vy));
        angulo= atan2(Vy,Vx);
        Ax= Vx*cos(angulo);
        Ay= Vy*sin(angulo);
        if(y()<755)
            Vy = V*sin(angulo) - 10*t;

        setPos(x() + -1*(Vx*t + (Ax/2)*t*t), y() + -1*((Vy*t)+(Ay/2)*t*t));
    }
}
