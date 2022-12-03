#ifndef VANGUARD_H
#define VANGUARD_H

#include "enemy.h"

class Vanguard: public Enemy
{
public:
    void setConfig() override;
    Vanguard(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Enemy(pathIdx, sideLen, parent) {
       setConfig();
    }
};

#endif // VANGUARD_H
