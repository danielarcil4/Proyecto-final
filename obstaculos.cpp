#include "obstaculos.h"

void Obstaculos::setAlto(int value)
{
    alto = value;
}

Obstaculos::Obstaculos()
{
    Pixmap = new QPixmap(":/Resourse/Muros proyecto final 2.png");
    ancho = 40;
    alto = 150;
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Obstaculos::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*Pixmap,0,0,ancho,alto);
}
