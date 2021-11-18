#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
protected:
    QPointF attack_dest;
public slots:
    void aquire_target();
private:
    QGraphicsPolygonItem * attack_area;

    bool has_target;
};
#endif // TOWER_H
