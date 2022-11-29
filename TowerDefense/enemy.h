#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QPixmap>
#include <QMovie>
#include "tower.h"

class Tower;

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int hp;
    int maxHp;
    int atk;
    float atkRange;
    int atkCycle;//多少个单位时间攻击一次
    int curCnt = 0;
    float moveSpeed;
    int pathIdx;//记录属于哪一条路径
    bool isMovable; //置1表示能移动, 0表示不能移动
    int curNodeIdx;//当前已经经过了第几个路径关键节点, 范围[0, pathList[pathIdx].size()-2], 否则就已经到达终点了
    QMovie movie;//敌人运动的动画
    void destroy(); //当怪物生命值等于0或者到达终点时, 摧毁该敌人
//    void attack(Tower *t); //对t**尝试**攻击
    QPixmap pix; //当前的图像
    float sideLen; //地图的大小, 也是物体的最大范围\]
    
public:
    Enemy(int pathIdx, float sideLen, float posX, float posY, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
//    void advance(int phase) override; //好像没必要写了
    int getPathIdx() {return this->pathIdx;}
    int& getNodeIdx() {return this->curNodeIdx;}
    void setMovable(bool isMovable) {this->isMovable = isMovable;}
    QPointF moveBy(int direction); //上下左右=1234, 其余不移动
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPainterPath shape() const override;
    void attack(Tower *target); //尝试对某个塔进行攻击
    void beAttacked(Tower *target);//被某个塔攻击
    int getAtk() const {return this->atk;}
    int getHp() const {return this->hp;}
    qreal calcDis(QGraphicsItem *target);
    int& getCurCnt() {return this->curCnt;} //用于攻击频率设置
};

#endif // ENEMY_H
