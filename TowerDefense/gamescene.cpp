#include "gamescene.h"
#include <QGraphicsSceneEvent>
#include <QGraphicsItem>
GameScene::GameScene()
{

}

void GameScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
 qDebug() << "SceneDoubleClick!";
 QGraphicsScene::mouseDoubleClickEvent(event);
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Scene Press";
    qDebug() << itemAt(event->scenePos(), QTransform());
    QGraphicsScene::mousePressEvent(event);
}
