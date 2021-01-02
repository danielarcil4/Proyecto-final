#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Obstaculos: public QObject,public QGraphicsItem
{
    Q_OBJECT
    int ancho,alto;
    int filas,columnas;
public:
    Obstaculos();

    QTimer *timer;
    QPixmap *Pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
};

#endif // MUROS_H
