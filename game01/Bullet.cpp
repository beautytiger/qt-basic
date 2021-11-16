#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

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
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            //increase score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-10);
    if (pos().y()+rect().height()<0) {
        scene()->removeItem(this);
        delete this;
//        qDebug() << "bullet deleted";
    }
}
