#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    //draw the rect
    setRect(0, 0, 100, 100);

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(20);
}

void Enemy::move()
{
    setPos(x(), y()+5);
    if (pos().y()>1080) {
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
//        qDebug() << "enemy deleted";
    }
}
