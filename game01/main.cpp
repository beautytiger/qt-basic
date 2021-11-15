#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(1920,1080);
    scene->setSceneRect(0, 0, 1920,1080);

    player->setPos((view->width()-player->rect().width())/2, view->height()-player->rect().height());

    return a.exec();
}
