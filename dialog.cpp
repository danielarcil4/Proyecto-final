#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    setFixedSize(1000,1000);

    muro1 = new Muros;
    //muro2 = new Muros;
    personaje->setRect(0,0,50,50);
    personaje->setBrush(Qt::black);

    //personaje->setFocus();
    //personaje->setFlag(QGraphicsItem::ItemIsFocusable);

    muro1->setPos(-490,480);
    //muro2->setPos(266,430);

    scene->addItem(muro1);
    scene->addItem(personaje);
    //scene->addItem(muro2);

}

void Dialog::keyPressEvent(QKeyEvent *evento)
{
    switch (evento->key()) {
    case Qt::Key_W:
        personaje->setPos(personaje->x(),personaje->y()-5);
        break;
    case Qt::Key_A:
        personaje->setPos(personaje->x()-5,personaje->y());
        break;
    case Qt::Key_S:
        personaje->setPos(personaje->x(),personaje->y()+5);
        break;
    case Qt::Key_D:
        personaje->setPos(personaje->x()+5,personaje->y());
        break;
    }

}

Dialog::~Dialog()
{
    delete ui;
}

