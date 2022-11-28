#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include "config.h"

class GameScene: public QGraphicsScene
{
public:
    GameScene();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GAMESCENE_H
