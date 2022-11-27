#include "enemy.h"
#include <QPainter>
#include "config.h"

Enemy::Enemy(int pathIdx, float sideLen, float posX, float posY, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    movie.setFileName(":/new/prefix1/assets/enemy/01.gif");
    this->sideLen = sideLen;
    movie.setScaledSize(QSize(this->sideLen * 0.8, this->sideLen * 0.8)); //稍微小一点
    this->pathIdx = pathIdx;
    this->setFlags(QGraphicsItem::ItemIsMovable);
    movie.start();
    this->curNodeIdx = 0;
    this->moveSpeed = sideLen / 10;
}

QRectF Enemy::boundingRect() const
{
    //注意: 为了美观, 调整了x轴上的偏移量
    return QRectF(0.2*sideLen, 0, this->sideLen * 0.8, this->sideLen * 0.8);//血的教训, stackOverflow YYDS
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(movie.state() == QMovie::Running) {
        painter->drawImage(this->boundingRect(), movie.currentImage());
    }
}

QPointF Enemy::moveBy(int direction)
{
    switch (direction) {
    case 1://上
        this->setPos(pos() - QPointF(0, this->moveSpeed));
        break;
    case 2:
        this->setPos(pos() + QPointF(0, this->moveSpeed));
        break;
    case 3:
        this->setPos(pos() - QPointF(this->moveSpeed, 0));
        break;
    case 4:
        this->setPos(pos() + QPointF(this->moveSpeed, 0));
        break;
    default:
        qDebug() << "wrong direction!";
    }
    qDebug() << "posx: " << this->pos().x();
    return pos();
}

