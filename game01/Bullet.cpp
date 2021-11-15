#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
Bullet::Bullet()
{
    //draw the rect
    setRect(0, 0, 10, 50);

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(20);
}

void Bullet::move()
{
    setPos(x(), y()-10);
    if (pos().y()+rect().height()<0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
