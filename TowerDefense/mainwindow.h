#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "config.h"
#include "makemap.h"
#include "gamewindow.h"
#include "store.h"
#include "document.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int totLevel = 0; //总关卡数
    int curLevel = 0; //当前关卡数
    void loadInfo(); //获取地图信息和当前进度
    GameWindow *game = nullptr;//游戏界面
    Store* store = nullptr;//商店界面
    document *doc = nullptr;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
