#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "config.h"
#include <enemy.h>
#include "tower.h"
#include "mapgrid.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    int curLevel;//当前关卡数
    int life; //还有几条命, 是游戏失败的充要条件
    int maxLife;
    int money;
    int enemyCnt;//记录已经创造出多少个怪物
    int maxEnemyCnt = 0;//最多有多少个怪物, 同样是游戏判断胜利的条件之一
    bool stop; //记录当前游戏是否暂停
    QTimer globalTimer;//全局时钟
    bool isStopped = false;
    QGraphicsScene *scene = nullptr; //游戏场景
    vector<Tower *> towerList; //当前在场的塔
    vector<Enemy *> enemyList; //当前在场的敌人
    //地图信息
    int lineNum;
    int colNum;
    float sideLen;//格子的边长
    float vMargin;//竖直页边距, 位于左右两侧
    float hMargin;//水平页边距, 位于上下两侧
    vector<vector<bool>> isGrid;
    vector<vector<ps>> pathList;
    vector<vector<enemyInfo>> enemyInfoList;//记录本场所有的怪物, 按照线路记录, 对应pathList;
    void loadMap(); //从文件读取地图
    void getGridStatus();//获取这个格子是否为路径节点
    int getGridType(int row, int col); //左右上下编码, 0表示可以放置远程塔, -1表示没用的点
    void renderMap(); //将地图信息加载到场景里, 加上起点终点标志, 加上槽
    void renderSpecialPoints();//绘制起点和终点
    vector<vector<MapGrid *>> slotList;//用于存放所有的槽的指针
    int timeCntForMakingEnemy;
    void EnemyMove();//为在场的怪物确定移动方向, 并传递给怪物对应的移动接口
    QGraphicsItem *focusItem = nullptr;
    void getFocusItem(QGraphicsItem *p);
    void showFocusItem();//在属性栏详细展示信息, 如果是防御塔的话, 还会在下方显示词缀信息
    bool rageUnlocked = false;//狂暴词缀是否解锁
    bool freezeUnlocked = false;//冰冻词缀是否解锁
    bool bleedUnlocked = false;//流血词缀是否解锁
    bool areaDamageUnlocked = false;//群伤词缀是否解锁
    void UnlockAffix();//随机解锁一种我方防御塔词缀
public:
    explicit GameWindow(int level, QWidget *parent = nullptr);
    ~GameWindow();
    void closeEvent(QCloseEvent *ev);
    void makeEnemy(); //出怪
    void createTower(int row, int col, int type = 0);//在(row, col)考虑建造一座塔(还需要判定能否建造), type=0为近战塔, 1为远程塔
    void deleteTower(int row, int col, int type = 0);
    void endGame(); //判断游戏状态: 胜利/失败/进行中, 给出相应反馈.
    void atk();//攻击判定
    void freezeAllEnemy();
    qreal calcDis(QGraphicsItem *a, QGraphicsItem *b) {return (a->pos().x() - b->pos().x()) * (a->pos().x() - b->pos().x()) + (a->pos().y() - b->pos().y()) * (a->pos().y() - b->pos().y());}
private:
    Ui::GameWindow *ui;
signals:
    void returnSignal();
    void winSinal(int idx);//胜利返回
};

#endif // GAMEWINDOW_H
