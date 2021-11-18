#include "BuildRedTowerIcon.h"
#include "Game.h"
#include "RedTower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pics/tower-red.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build) {
        game->build = new RedTower();
        game->setCursor(QString(":/pics/tower-red.png"));
    }
}
