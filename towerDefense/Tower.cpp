#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include "Bullet.h"
#include "Game.h"
#include <QTimer>
#include "Enemy.h"

extern Game * game;

Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
//    setPixmap(QPixmap(":/pics/tower.png"));

    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0)
           << QPoint(3,1) << QPoint(3,2)
           << QPoint(2,3) << QPoint(1,3)
           << QPoint(0,2) << QPoint(0,1);
    int SCALE_FACTOR = 65;
    for (size_t i=0, n=points.size(); i<n; i++) {
        points[i] *= SCALE_FACTOR;
    }
    QPolygonF polygon(points);
    attack_area = new QGraphicsPolygonItem(polygon, this);
    attack_area->setPen(QPen(Qt::DotLine));

    QPointF ploy_center(1.5,1.5);
    ploy_center *= SCALE_FACTOR;
    ploy_center = mapToScene(ploy_center);
    QPointF tower_center(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2);
    QLineF ln(ploy_center, tower_center);
    attack_area->setPos(x()+ln.dx(), y()+ln.dy());

//    QTimer * timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &Tower::aquire_target);
//    timer->start(1000);

    attack_dest = QPointF(800, 0);
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void Tower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2);

    QLineF ln(QPointF(x()+this->pixmap().width()/2, y()+this->pixmap().height()/2), attack_dest);
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() == 1) {
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPoint(0, 0);
    for (size_t i=0, n=colliding_items.size(); i<n;i++){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy) {
            double this_dist = distanceTo(enemy);
            if (this_dist < closest_dist) {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    if (closest_dist>=300) {
        has_target = false;
        return;
    }
    if (has_target) {
        attack_dest = closest_pt;
        fire();
    }
}
