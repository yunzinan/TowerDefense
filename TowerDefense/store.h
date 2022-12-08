#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "config.h"


namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT
    void loadInfo();//读取配置文件, 如果没有就创建
    float atkRate = 1.0;
    float hpRate = 1.0;
    int bombNum = 0;
    int freezeBombNum = 0;
    int pts = 0;
public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::Store *ui;
signals:
    void returnSignal();
};

#endif // STORE_H
