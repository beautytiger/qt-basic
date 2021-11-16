#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/resource/qiang sheng.wav"));

    setPixmap(QPixmap(":/images/player.png"));
//    setRotation(-90);
    setScale(0.3);

}

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

        if(bulletsound->state()==QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        }
//        else if (bulletsound->state()==QMediaPlayer::StoppedState) {
//            bulletsound->play();
//        }
        bulletsound->play();
    }
}

void Player::spawn()
{
    // create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
