#include "enemy.h"
#include <QPainter>
#include "config.h"
#include <QGraphicsSceneMouseEvent>

void Enemy::setConfig()
{
    movie.stop();
    movie.setFileName(":/new/prefix1/assets/enemy/01.gif");
    movie.setScaledSize(QSize(this->sideLen, this->sideLen));
    movie.start();

    this->moveSpeed = sideLen / 20;
    this->atk = 10;
    this->atkRange = sideLen;
    this->maxHp = 100;
    this->atkCycle = 10;
}

Enemy::Enemy(int pathIdx, float sideLen, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    this->sideLen = sideLen;
    this->curNodeIdx = 0;
    setConfig();
    this->hp = maxHp;
    this->isMovable = true;
    this->pathIdx = pathIdx;
//    this->setFlags(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF Enemy::boundingRect() const
{
    //注意: 为了美观, 调整了x轴上的偏移量
    return QRectF(0, 0, this->sideLen * 0.8, this->sideLen * 0.8);//血的教训, stackOverflow YYDS
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
//    qDebug() << "enemy: press!";
//    QGraphicsItem::mouseReleaseEvent(event);
    //左键单击显示详细信息
    if(event->button() == Qt::LeftButton) {
        emit getFocus(this);
    }
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


