#ifndef WIZARD_H
#define WIZARD_H

#include "enemy.h"
#include <QTimer>

class Wizard: public Enemy
{
    bool isValid;//表示当前情况下能否发动技能, cd为3s
    QTimer timer;
public:
    enum {Type = UserType + 5};
    void setConfig() override;
    Wizard(int pathIdx, float sideLen, QGraphicsItem *parent = nullptr) : Enemy(pathIdx, sideLen, parent) {
        setConfig();
        this->isValid = true;
        connect(&timer, &QTimer::timeout, [=](){
            this->isValid = true;
        });
    }
    int type() const override {
        return Type;
    }
    bool getValid() const {return this->isValid;}
    void resetCD(int t) {
        this->isValid = false;
        timer.start(t * 1000);
    }
};

#endif // WIZARD_H
