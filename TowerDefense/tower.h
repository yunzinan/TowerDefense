#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QPixmap>
#include <QMovie>
#include "config.h"
#include "enemy.h"

class Enemy;

class Tower: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int row;
    int col;
    int hp;
    int maxHp;
    int atk;
    int atkCycle;
    int curCnt = 0;
    float atkRange;
    QMovie movie;//动画
    void destroy(); //当塔生命值等于0或者到达终点时, 摧毁该敌人
    float sideLen; //地图的大小, 也是物体的最大范围
protected:
    void setAtkRange(float scale) {
        this->atkRange *= scale;
    }
public:
    enum {Type = UserType + 2};
    Tower(int row, int col, float sideLen, QGraphicsItem *parent = nullptr): row(row), col(col), sideLen(sideLen) {
        this->maxHp = 100;
        this->hp = maxHp;
        this->atk = 10;
        this->atkCycle = 5;
        this->atkRange = sideLen;
        movie.setFileName(":/new/prefix1/assets/tower/1.gif");
        movie.setScaledSize(QSize(this->sideLen, this->sideLen));
        movie.start();
    }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    ps getPos() const {return ps(this->row, this->col);}
    void resetGif(QString path) {
        movie.stop();
        movie.setFileName(path);
        movie.setScaledSize(QSize(this->sideLen, this->sideLen));
        movie.start();
    }
    int getAtk() const {return this->atk;}
    int getHp() const {return this->hp;}
    int getMaxHP() const {return this->maxHp;}
    float getAtkRange() const {return this->atkRange;}
    float getAtkSpeed() const {return (float)20/(float)this->atkCycle;}
    qreal calcDis(QGraphicsItem *target);
    void attack(Enemy *target);
    void rangeAttack(vector<Enemy *> target);//范围攻击
    void beAttacked(Enemy *target);
    int& getCurCnt() {return this->curCnt;}
    int type() const override {
        return Type;
    }
    bool bleedAffix = false;//流血词缀
    bool rageAffix = false;//狂暴词缀
    void setRage(bool state) {
        if(state) {
            this->rageAffix = true;
            this->atk *= 2;
            this->atkCycle /= 2;
        }
        else {
            this->rageAffix = false;
            this->atk /= 2;
            this->atkCycle *= 2;
        }
    }
    bool freezeAffix = false;//冰冻词缀
    bool areaDamageAffix = false;//群伤词缀
    int affixCnt = 0;
signals:
    void deleteSignal(int row, int col);//删除该对象的信号
    void getFocus(QGraphicsItem *p);
};

#endif // TOWER_H
