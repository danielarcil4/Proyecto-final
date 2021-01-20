#ifndef Enemigo_1_1_H
#define Enemigo_1_1_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class Enemigo_1: public QObject,public QGraphicsItem
{
    Q_OBJECT
    int ancho,alto;
    int filas,columnas;
public:
    Enemigo_1();

    QTimer *timer;
    QPixmap *Pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);

    void setAncho(int value);

    void setAlto(int value);

    void setFilas(int value);

    void setColumnas(int value);

signals:
public slots:
    void Atacar();
};

#endif // Enemigo_1_1_H
