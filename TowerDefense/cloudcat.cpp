#include "cloudcat.h"


void CloudCat::setConfig()
{
    movie.stop();
    movie.setFileName(":/new/prefix1/assets/enemy/05.gif");
    movie.setScaledSize(QSize(this->sideLen, this->sideLen));
    movie.start();

    this->moveSpeed = sideLen / 20;
    this->atk = 10;
    this->atkRange = sideLen;
    this->maxHp = 100;
    this->atkCycle = 10;
}
