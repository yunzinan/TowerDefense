#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QPixmap>
#include <QMovie>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int hp;
    int maxHp;
    int atk;
    int atkRange;
    float atkSpeed;
    float moveSpeed;
    int pathIdx;//记录属于哪一条路径
    bool isMovable; //置1表示能移动, 0表示不能移动
    int curNodeIdx;//当前已经经过了第几个路径关键节点, 范围[0, pathList[pathIdx].size()-2], 否则就已经到达终点了
    QMovie movie;//敌人运动的动画
    void destroy(); //当怪物生命值等于0或者到达终点时, 摧毁该敌人
//    void attack(Tower *t); //对t**尝试**攻击
    void move(int d); //尝试朝着d(1234表示上下左右)移动
    QPixmap pix; //当前的图像
    float sideLen; //地图的大小, 也是物体的最大范围\]
    
public:
    Enemy(int pathIdx, float sideLen, float posX, float posY, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
//    void advance(int phase) override; //好像没必要写了
    int getPathIdx() {return this->pathIdx;}
    int& getNodeIdx() {return this->curNodeIdx;}

    QPointF moveBy(int direction); //上下左右=1234, 其余不移动
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPainterPath shape() const override;
};

#endif // ENEMY_H
