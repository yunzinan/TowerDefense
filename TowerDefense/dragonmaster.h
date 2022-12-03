#ifndef DRAGONMASTER_H
#define DRAGONMASTER_H

#include "wizard.h"

class DragonMaster: public Wizard
{
public:
    void setConfig() override;
    enum {Type = UserType + 7};
    DragonMaster(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Wizard(pathIdx, sideLen, parent) {
        setConfig();
    }
    int type() const override {
        return Type;
    }
};

#endif // DRAGONMASTER_H
