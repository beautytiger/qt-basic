#include "RedTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RedTower::aquire_target);
    timer->start(1000);
}

void RedTower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/pics/axe_red.png"));

//    bullet->setPos(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2);
    bullet->setPos(x()+40, y()+40);

//    QLineF ln(QPointF(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2), attack_dest);
    QLineF ln(QPointF(x()+40, y()+40), attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void RedTower::aquire_target()
{
    Tower::aquire_target();
}
