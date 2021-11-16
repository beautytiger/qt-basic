#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1920,1080);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);

    player = new Player();
//    player->setRect(0,0,100,100);
    player->setPos((scene->width())/2, scene->height()-100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, player, &Player::spawn);
    timer->start(2000);

    QMediaPlayer * media = new QMediaPlayer();
    media->setMedia(QUrl("qrc:/sounds/resource/lu guo ren jian.mp3"));
    media->play();

    show();
}
