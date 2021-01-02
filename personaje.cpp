#include "personaje.h"

int Personaje::getColumnas() const
{
    return columnas;
}

void Personaje::setColumnas(int value)
{
    columnas = value;
}

int Personaje::getAlto() const
{
    return alto;
}

int Personaje::getAncho() const
{
    return ancho;
}

float Personaje::getVx() const
{
    return Vx;
}

void Personaje::setVx(float value)
{
    Vx = value;
}

float Personaje::getVy() const
{
    return Vy;
}

void Personaje::setVy(float value)
{
    Vy = value;
}

float Personaje::getMasa() const
{
    return masa;
}

float Personaje::getNormal() const
{
    return Normal;
}

void Personaje::setNormal(float value)
{
    Normal = value;
}

Personaje::Personaje()
{
    filas = 0;
    columnas = 0;
    Vx=0;
    masa = 10;
    g=10;
    Vy=0;
    Normal=masa*g;

    Pixmap = new QPixmap(":/Resourse/Personaje 1.png");
    ancho = 96;
    alto = 96;

}

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*Pixmap,columnas,0,ancho,alto);
}

void Personaje::salto()
{
    if(y()<755)
        Vy = Vy+10;

    setPos( x() + Vx , y() + Vy - Normal+masa*g);
}

void Personaje::setVel(float Vx_, float Vy_)
{
    Vx = Vx_;
    Vy = Vy_;
}



