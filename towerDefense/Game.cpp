#include "Game.h"
#include <QGraphicsScene>
#include "RedTower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildRedTowerIcon.h"
#include "BuildGreenTowerIcon.h"
#include "BuildYellowTowerIcon.h"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);

//    Tower * t = new Tower();
//    t->setPos(300, 200);
//    scene->addItem(t);

    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

//    setCursor(":/pics/tower.png");
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildYellowTowerIcon * yt = new BuildYellowTowerIcon();
    gt->setPos(x(), y()+100);
    yt->setPos(x(), y()+200);

    scene->addItem(rt);
    scene->addItem(gt);
    scene->addItem(yt);
}

void Game::setCursor(QString filename)
{
    if (cursor) {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor) {
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (build) {

        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i=0, n=items.size();i<n;i++) {
            if (dynamic_cast<Tower*>(items[i]))
                return;
        }
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

//void Game::mousePressEvent(QMouseEvent *event)
//{
//    Bullet * bullet = new Bullet();
//    bullet->setPos(event->pos());
//    bullet->setRotation(40);
//    scene->addItem(bullet);
//}
