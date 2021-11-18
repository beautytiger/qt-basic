#include "BuildYellowTowerIcon.h"
#include "Game.h"
#include "YellowTower.h"

extern Game * game;

BuildYellowTowerIcon::BuildYellowTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pics/tower-yellow.png"));
}

void BuildYellowTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build) {
        game->build = new YellowTower();
        game->setCursor(QString(":/pics/tower-yellow.png"));
    }
}
