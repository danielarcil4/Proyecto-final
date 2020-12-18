#include "muros.h"

Muros::Muros(QObject *parent): QObject(parent)
{
    Pixmap = new QPixmap(":/Resourse/Muros proyecto final.png");
    ancho = 750;
    alto = 50;
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Muros::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*Pixmap,columnas,0,ancho,alto);
}
