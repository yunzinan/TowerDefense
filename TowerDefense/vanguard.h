#ifndef VANGUARD_H
#define VANGUARD_H

#include "enemy.h"

class Vanguard: public Enemy
{
public:
    enum {Type = UserType + 6};
    void setConfig() override;
    Vanguard(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Enemy(pathIdx, sideLen, parent) {
       setConfig();
    }
    int type() const override {
        return Type;
    }
};

#endif // VANGUARD_H
