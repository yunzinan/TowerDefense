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

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    int curLevel;
    int life; //还有几条命
    int maxLife;
    int money;
    int curProgress;
    bool stop; //记录当前游戏是否暂停
    QTimer globalTimer;//全局时钟
    QGraphicsScene *scene = nullptr; //游戏场景
    //vector<Tower *> towerList; //当前在场的塔
    //vecotr<Enemy *> enemyList; //当前在场的敌人
    //地图信息
    int lineNum;
    int colNum;
    float sideLen;//格子的边长
    float vMargin;//竖直页边距, 位于左右两侧
    float hMargin;//水平页边距, 位于上下两侧
    vector<vector<bool>> isGrid;
    vector<vector<ps>> pathList;
    void loadMap(); //从文件读取地图
    void getGridStatus();//获取这个格子是否为路径节点
    int getGridType(int row, int col); //左右上下编码, 0表示可以放置远程塔, -1表示没用的点
    void renderMap(); //将地图信息加载到场景里, 加上起点终点标志, 加上槽
    void renderSpecialPoints();//绘制起点和终点
public:
    explicit GameWindow(int level, QWidget *parent = nullptr);
    ~GameWindow();
    void closeEvent(QCloseEvent *ev);
private:
    Ui::GameWindow *ui;
signals:
    void returnSignal();
};

#endif // GAMEWINDOW_H
