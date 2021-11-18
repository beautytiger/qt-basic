#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Bullet::Bullet(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/pics/axe.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer, &QTimer::timeout, this, &Bullet::move);
    move_timer->start(50);

    maxRange = 100;
    distanceTravelled = 0;
}

double Bullet::getMaxRange()
{
    return maxRange;
}

double Bullet::getDistanceTravelled()
{
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng)
{
    maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist)
{
    distanceTravelled = dist;
}

void Bullet::move()
{
    int STEP_SIZE = 30;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
