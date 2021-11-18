#include "YellowTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

YellowTower::YellowTower(QGraphicsItem *parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &YellowTower::aquire_target);
    timer->start(1000);
}

void YellowTower::fire()
{
    Bullet * bullet = new Bullet();

    bullet->setPos(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2);

    QLineF ln(QPointF(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2), attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void YellowTower::aquire_target()
{
    Tower::aquire_target();
}
