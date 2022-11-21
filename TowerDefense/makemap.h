#ifndef MAKEMAP_H
#define MAKEMAP_H

#include <QWidget>
#include "config.h"
#include <QFile>
#include <QComboBox>
#include <QTextStream>
#include <QMessageBox>
#include <QSpinBox>
#include <QTabWidget>
#include <QGraphicsObject>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsObject>

namespace Ui {
class MakeMap;
}

class MakeMap : public QWidget
{
    Q_OBJECT
    int lineNum = 0;// 4 <= line <= 10
    int colNum = 0; // 10 <= col <= 20
    vector<vector<QPushButton *>> pbList;
    vector<vector<struct ps>> pathList;
    vector<vector<bool>> isGrid;//存储地图中所有点的状态.
    void createGrids(); //用于在widge中创建网格
    void getGridStatus(); //获得所有格子的状态
    void showPath(int idx);//在网格中显示第idx条路径
    int cntNeighbours(int row, int col);//统计某个节点的邻接节点数量
    ps getNext(int curCol, int curRow, int prevCol, int prevRow);//寻找路径的下一个点, 找不到返回-1,-1
    void drawPreview(); //在预览界面绘制地图
    int getGridType(int row, int col);//判断地图的类型
    QGraphicsScene *mapScene = nullptr;//用于布置地图
public:
    explicit MakeMap(QWidget *parent = nullptr);
    ~MakeMap();

    QGraphicsScene *getMapScene() const;
    void setMapScene(QGraphicsScene *value);

private:
    Ui::MakeMap *ui;
signals:
    void returnSignal();
};

#endif // MAKEMAP_H
