#include "enemigo_1.h"

void Enemigo_1::setAncho(int value)
{
    ancho = value;
}

void Enemigo_1::setAlto(int value)
{
    alto = value;
}

void Enemigo_1::setFilas(int value)
{
    filas = value;
}

void Enemigo_1::setColumnas(int value)
{
    columnas = value;
}

Enemigo_1::Enemigo_1()
{
    timer = new QTimer();
    Pixmap = new QPixmap(":/Resourse/Enemigo_1.png");

    ancho = 44;
    alto = 50;
    filas = 0;
    columnas = 0;
    timer->start(400);
    connect(timer,&QTimer::timeout,this,&Enemigo_1::Atacar);

}

QRectF Enemigo_1::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo_1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*Pixmap,columnas,0,ancho,alto);
}

void Enemigo_1::Atacar()
{
    if(ancho==70){
        columnas+=70;
        if(columnas>=280){
            columnas = 0;
        }
        this->update(-ancho/2,-alto/2,ancho,alto);
    }
    else{
        columnas+=44;
        if(columnas>=88){
            columnas = 0;
        }
        this->update(-ancho/2,-alto/2,ancho,alto);
    }


}
