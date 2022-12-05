#ifndef CLOUDCAT_H
#define CLOUDCAT_H

#include "enemy.h"

class CloudCat: public Enemy
{
public:
    enum{Type = UserType + 8};
    int type() const override {
        return Type;
    }
    void setConfig() override;
    CloudCat(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Enemy(pathIdx, sideLen, parent) {
        setConfig();
    }
};

#endif // CLOUDCAT_H
