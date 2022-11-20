#ifndef MAKEMAP_H
#define MAKEMAP_H

#include <QWidget>
#include "config.h"
#include <QFile>
#include <QComboBox>
#include <QTextStream>
#include <QMessageBox>
#include <QSpinBox>

namespace Ui {
class MakeMap;
}



class MakeMap : public QWidget
{
    Q_OBJECT
    int lineNum;// 4 <= line <= 10
    int colNum; // 10 <= col <= 20
    vector<vector<QPushButton *>> pbList;
    vector<vector<struct ps>> pathList;
    void createGrids(); //用于在widge中创建网格
    void showPath(int idx);//在网格中显示第idx条路径
    int cntNeighbours(int row, int col);//统计某个节点的邻接节点数量
    ps getNext(int curCol, int curRow, int prevCol, int prevRow);//寻找路径的下一个点, 找不到返回-1,-1
public:
    explicit MakeMap(QWidget *parent = nullptr);
    ~MakeMap();

private:
    Ui::MakeMap *ui;
signals:
    void returnSignal();
};

#endif // MAKEMAP_H
