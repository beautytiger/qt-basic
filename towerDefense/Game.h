#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    void setCursor(QString filename);

//    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

    void createEnemies(int numberOfEnemies);
    void createRoad();

    QGraphicsScene * scene;

    QGraphicsPixmapItem * cursor;
    Tower * build;

    QTimer * spawnTimer;
    int enemySpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;

public slots:
    void spawnEnemies();
};

#endif // GAME_H
