#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>


class Personaje : public QGraphicsItem ,public QObject
{
    int g;
    int filas,columnas;
    int ancho,alto;
    float Vx,Vy,masa,Normal;
public:
    Personaje();

    QPixmap *Pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);

    void setVel(float Vx,float Vy);

    int getColumnas() const;

    void setColumnas(int value);

    int getAlto() const;

    int getAncho() const;

    float getVx() const;
    void setVx(float value);

    float getVy() const;
    void setVy(float value);

    float getMasa() const;

    float getNormal() const;
    void setNormal(float value);
};

#endif // PERSONAJE_H
