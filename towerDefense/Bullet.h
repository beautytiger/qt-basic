#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsPixmapItem {
public:
    Bullet(QGraphicsItem * parent=0);
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
public slots:
    void move();
private:
    double maxRange;
    double distanceTravelled;
};

#endif // BULLET_H
