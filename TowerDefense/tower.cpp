#include "tower.h"
#include "config.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneEvent>

QRectF Tower::boundingRect() const
{
    return QRectF(0, 0, this->sideLen, this->sideLen);
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(this->boundingRect(), movie.currentImage());
}

QPainterPath Tower::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        emit getFocus(this);
    }
}

void Tower::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton) {
        emit deleteSignal(row, col);
    }
}

qreal Tower::calcDis(QGraphicsItem *target)
{
    return (this->pos().x() - target->pos().x()) * (this->pos().x() - target->pos().x()) + (this->pos().y() - target->pos().y()) * (this->pos().y() - target->pos().y());
}

void Tower::attack(Enemy *target)
{
    if(target == nullptr) return ;
    if(this->hp <= 0) return ;
    if(this->curCnt < this->atkCycle) {
        curCnt++;
        return ;
    }
    qreal dis = calcDis(target);
    if(dis <= this->atkRange * this->atkRange) {
        qDebug() << "tower atk success!";
        if(this->freezeAffix) target->beFreezed(1);
        if(this->bleedAffix) target->bleeding(2);
        else qDebug() << this->freezeAffix;
        target->beAttacked(this);
    }
    curCnt = 0;
}

void Tower::rangeAttack(vector<Enemy *> targetList)
{
    if(this->hp <= 0) return ;
    if(this->curCnt < this->atkCycle) {
        curCnt++;
        return ;
    }
    for(auto target : targetList) {
        if(target == nullptr) return ;
        qreal dis = calcDis(target);
        if(dis <= this->atkRange * this->atkRange) {
            qDebug() << "tower atk success!";
            if(this->freezeAffix) target->beFreezed(1);
            if(this->bleedAffix) target->bleeding(2);
            else qDebug() << this->freezeAffix;
            target->beAttacked(this);
        }
        curCnt = 0;
    }
}

void Tower::beAttacked(Enemy *target)
{
    this->hp -= target->getAtk();
    if(hp < 0) hp = 0;
}
