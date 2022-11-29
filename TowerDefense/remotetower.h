#ifndef REMOTETOWER_H
#define REMOTETOWER_H

#include "tower.h"

class RemoteTower : public Tower
{
    Q_OBJECT
    QString gifPath;
    float atkRange;
public:
    RemoteTower(int row, int col, float sideLen, QGraphicsItem *parent = nullptr): Tower(row, col, sideLen, parent) {
        this->gifPath = ":/new/prefix1/assets/tower/3.gif";
        Tower::resetGif(gifPath);
    }
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void deleteRemoteSignal(int row, int col);
};

#endif // REMOTETOWER_H
