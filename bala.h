#ifndef BALA_H
#define BALA_H

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QTimer>
#include <math.h>

class Bala: public QObject,public QGraphicsItem
{
    int r;
    float V,angulo,Ax,Ay,Vx,Vy,t;
public:
    Bala();
    QTimer *timer;
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void setR(int value);

signals:
public slots:
    void Move();
};

#endif // BALA_H
