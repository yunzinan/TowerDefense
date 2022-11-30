#include "enemy.h"
#include <QPainter>
#include "config.h"
#include <QGraphicsSceneMouseEvent>

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
    this->atk = 10;
    this->atkRange = sideLen;
    this->maxHp = 100;
    this->hp = maxHp;
    this->isMovable = true;
    this->atkCycle = 10;
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
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
    //绘制血条
    float rate = (float)this->hp / (float)this->maxHp;
    QBrush green_brush(QColor("#12FF08"));
    QBrush red_brush(QColor("#E70000"));
    painter->setBrush(green_brush);
    painter->drawRect(0, 0, (float)sideLen * rate, 20);
    painter->setBrush(red_brush);
    painter->drawRect(sideLen * rate, 0, (1-rate) * sideLen, 20);
}

QPointF Enemy::moveBy(int direction)
{
    if(this->isMovable) {
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
    }
    qDebug() << "posx: " << this->pos().x();
    return pos();
}

void Enemy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "enemy: press!";
    QGraphicsItem::mouseReleaseEvent(event);
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Enemy::attack(Tower *target)
{
    if(target == nullptr) return ;
    if(this->hp <= 0) return ;
    if(this->curCnt < this->atkCycle) {
        curCnt++;
        return ;
    }
    //判定是否在一个的距离内
    qreal dis = calcDis(target);
    if(dis <= this->atkRange * this->atkRange) {
        qDebug() << "atk success!";
        target->beAttacked(this);
    }
        curCnt = 0;
}

void Enemy::beAttacked(Tower *target)
{
    this->hp -= target->getAtk();
    if(hp < 0) hp = 0;
}
qreal Enemy::calcDis(QGraphicsItem *target)
{
    return (this->pos().x() - target->pos().x()) * (this->pos().x() - target->pos().x()) + (this->pos().y() - target->pos().y()) * (this->pos().y() - target->pos().y());
}


