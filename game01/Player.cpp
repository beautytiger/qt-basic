#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "key pressed";
    if(event->key()==Qt::Key_Left) {
        if (pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right) {
        if (pos().x()+100 < 1920)
        setPos(x()+10,y());
    }
//    else if(event->key()==Qt::Key_Up) {
//        setPos(x(),y()-10);
//    }
//    else if(event->key()==Qt::Key_Down) {
//        setPos(x(),y()+10);
//    }
    else if(event->key()==Qt::Key_Space) {
        //create a bullet
        Bullet * bullet = new Bullet();
//        qDebug() << "bullet created";
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    // create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
