#include "MyRect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "key pressed";
    if(event->key()==Qt::Key_Left) {
        setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right) {
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
