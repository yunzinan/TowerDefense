#ifndef SUPERTOWER_H
#define SUPERTOWER_H
#include <QGraphicsSceneMouseEvent>
#include "tower.h"
/* 超级近战塔: 死亡时释放全场冰冻
 *
 *
 *
 *
*/
class SuperTower: public Tower
{
    Q_OBJECT
    QString gifPath;
public:
    enum{Type = UserType + 9};
    SuperTower(int row, int col, float sideLen, QGraphicsItem *parent = nullptr): Tower(row, col, sideLen, parent) {
        this->gifPath = ":/new/prefix1/assets/tower/2.gif";
        Tower::resetGif(gifPath);
    }
    int type() const override {
        return Type;
    }
};

#endif // SUPERTOWER_H
