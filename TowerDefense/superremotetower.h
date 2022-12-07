#ifndef SUPERREMOTETOWER_H
#define SUPERREMOTETOWER_H

#include "remotetower.h"

class SuperRemoteTower: public RemoteTower
{
    Q_OBJECT
    QString gifPath;
public:
    enum {Type = UserType + 10};
    SuperRemoteTower(int row, int col, float sideLen, QGraphicsItem *parent = nullptr): RemoteTower(row, col, sideLen, parent)
    {
        this->gifPath = ":/new/prefix1/assets/tower/4.gif";
        Tower::resetGif(this->gifPath);
    }
    int type() const override{
        return Type;
    }
};

#endif // SUPERREMOTETOWER_H
