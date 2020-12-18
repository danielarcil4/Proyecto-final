#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Muros: public QObject,public QGraphicsItem
{
    Q_OBJECT
    int ancho,alto;
    int filas,columnas;
public:
    Muros(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *Pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
};

#endif // MUROS_H