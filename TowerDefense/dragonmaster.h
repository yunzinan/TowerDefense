#ifndef DRAGONMASTER_H
#define DRAGONMASTER_H

#include "enemy.h"

class DragonMaster: public Enemy
{
public:
    void setConfig() override;
    DragonMaster(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Enemy(pathIdx, sideLen, parent) {
        setConfig();
    }
};

#endif // DRAGONMASTER_H
