#include "BuildGreenTowerIcon.h"
#include "Game.h"
#include "GreenTower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pics/tower-green.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build) {
        game->build = new GreenTower();
        game->setCursor(QString(":/pics/tower-green.png"));
    }
}
