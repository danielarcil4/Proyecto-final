#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Obstaculos: public QObject,public QGraphicsItem
{
    Q_OBJECT
    int ancho,alto;
public:
    Obstaculos();
    QPixmap *Pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void setAlto(int value);
};

#endif // MUROS_H
