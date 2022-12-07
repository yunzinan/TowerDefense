#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "gamescene.h"
#include "mapgrid.h"
#include "tower.h"
#include "remotetower.h"
#include <QCheckBox>
#include "wizard.h"
#include "vanguard.h"
#include "dragonmaster.h"
#include "cloudcat.h"
#include "supertower.h"
#include "superremotetower.h"
#include <QTime>

void GameWindow::loadMap()
{
    QString fp = QDir::currentPath() + "./info/level" + QString::number(this->curLevel) + ".txt";
    qDebug() << fp;
    QFile file(fp);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error! file not exists!";
        return ;
    }
    QTextStream fin(&file);
    QString buffer;
    buffer = file.readLine();
    QStringList list = buffer.split(" ");
    this->lineNum = list[1].toInt();
    this->colNum = list[0].toInt();
    buffer = file.readLine();
    int n = buffer.toInt();
    for(int i = 0; i < n; i++) {
        buffer = file.readLine();
        QStringList path = buffer.split(" ");
        int k = path[0].toInt();
        vector<struct ps> cur;
        for(int j = 1; j <= k; j++) {
            QString substr = path[j].mid(1, path[j].length()-2);
            QStringList psStr = substr.split(",");
            ps curps;
            curps.row = psStr[0].toInt();
            curps.col = psStr[1].toInt();
            cur.push_back(curps);
        }
        this->pathList.push_back(cur);
    }
    //下面读取敌人信息
    for(int i = 0; i < n; i++) {
        buffer = file.readLine();
        QStringList path = buffer.split(" ");
        int k = path[0].toInt();
        vector<struct enemyInfo> cur;
        for(int j = 1; j <= k; j++) {
            QString substr = path[j].mid(1, path[j].length()-2);
            QStringList psStr = substr.split(",");
            enemyInfo info;
            info.type = psStr[0].toInt();
            info.num = psStr[1].toInt();
            this->maxEnemyCnt += info.num;
            cur.push_back(info);
        }
        this->enemyInfoList.push_back(cur);
    }
    file.close();
    qDebug() << this->pathList.size() << " " << this->pathList[0].size();
    qDebug() << this->enemyInfoList.size() << " " << this->enemyInfoList[0].size();
}

void GameWindow::getGridStatus()
{
    for(int i = 0; i < this->pathList.size(); i++) {
        for(int k = 0; k < this->pathList[i].size()-1; k++) {
            struct ps curps = pathList[i][k];
            struct ps nxtps = pathList[i][k+1];
            if(curps.row == nxtps.row) {//行数一样, 说明要么是从右至左
                if(curps.col > nxtps.col) {
                    for(int j = curps.col; j >= nxtps.col; j--) {
                        isGrid[curps.row][j] = true;
                    }
                }
                else {
                    for(int j = curps.col; j <= nxtps.col; j++) {
                        isGrid[curps.row][j] = true;
                    }
                }
            }
            else {
               //否则就是从上到下, 或者从下到上
                if(curps.row < nxtps.row) {
                    for(int j = curps.row; j <= nxtps.row; j++) {
                        isGrid[j][curps.col] = true;
                    }
                }
                else {
                    for(int j = curps.row; j >= nxtps.row; j--) {
                        isGrid[j][curps.col] = true;
                    }
                }
            }
        }
    }
}

int GameWindow::getGridType(int row, int col)
{
    if(!this->isGrid[row][col]) {
        if(row-1 >= 0 && isGrid[row-1][col]) return 0;
        if(row+1 < this->lineNum && isGrid[row+1][col]) return 0;
        if(col-1 >= 0 && isGrid[row][col-1]) return 0;
        if(col+1 < this->colNum && isGrid[row][col+1]) return 0;
        return -1;
    }
    else {
        bool lGrid = false;//1表示左边有通路
        bool rGrid = false;
        bool bGrid = false;
        bool tGrid = false;
        if(col-1 >= 0 && isGrid[row][col-1]) lGrid = true;
        if(col+1 < this->colNum && isGrid[row][col+1]) rGrid = true;
        if(row-1 >= 0 && isGrid[row-1][col]) tGrid = true;
        if(row+1 < this->lineNum && isGrid[row+1][col]) bGrid = true;
        return lGrid * 8 + rGrid * 4 + tGrid * 2 + bGrid;//左右上下=8421
    }
}

void GameWindow::renderMap()
{
    int totWidth = 2400 * 0.9;
    int totHeight= 1800 * 0.9;
    vMargin = 0;
    hMargin = 0;
    if(totWidth / this->colNum > totHeight / this->lineNum) {
        sideLen = totHeight / this->lineNum;
        vMargin = (totWidth - this->colNum * sideLen) / 2;
    }
    else {
        sideLen = totWidth / this->colNum;
        hMargin = (totHeight - this->lineNum * sideLen) / 2;
    }
    QString pixPath;
    for(int i = 0; i < this->lineNum; i++) {
        for(int j = 0; j < this->colNum; j++) {
            int type = getGridType(i, j);
            qDebug() << type;
            switch (type) {//左右上下 二进制编码

            case -1://非路径且不可放置远程塔
                pixPath = ":/new/prefix1/assets/map/cp.png";
                break;
            case 0://可放置远程塔, 会在上面加一个插槽
                pixPath = ":/new/prefix1/assets/map/cp.png";
                break;
            case 1:
                pixPath = ":/new/prefix1/assets/map/qds.png";
                break;
            case 2:
                pixPath = ":/new/prefix1/assets/map/qdx.png";
                break;
            case 3:
                pixPath = ":/new/prefix1/assets/map/lsz.png";
                break;
            case 4:
                pixPath = ":/new/prefix1/assets/map/qdz.png";
                break;
            case 5:
                pixPath = ":/new/prefix1/assets/map/gdyx.png";
                break;
            case 6:
                pixPath = ":/new/prefix1/assets/map/gdys.png";
                break;
            case 7:
                pixPath = ":/new/prefix1/assets/map/scly.png";
                break;
            case 8:
                pixPath = ":/new/prefix1/assets/map/qdy.png";
                break;
            case 9:
                pixPath = ":/new/prefix1/assets/map/gdzx.png";
                break;
            case 10:
                pixPath = ":/new/prefix1/assets/map/gdzs.png";
                break;
            case 11:
                pixPath = ":/new/prefix1/assets/map/sclz.png";
                break;
            case 12:
                pixPath = ":/new/prefix1/assets/map/lsp.png";
                break;
            case 13:
                pixPath = ":/new/prefix1/assets/map/sclx.png";
                break;
            case 14:
                pixPath = ":/new/prefix1/assets/map/scls.png";
                break;
            case 15:
                pixPath = ":/new/prefix1/assets/map/scl.png";
                break;
            default:
                qDebug() << "error! no such type!";
                break;

            }
            QGraphicsItem *cur = new MapGrid(i, j, sideLen, pixPath);
            this->scene->addItem(cur);
            cur->setPos(j*sideLen, i*sideLen);
            if(type > 0 && type < 16) {
                //路径, 设定可被选中
                dynamic_cast<MapGrid *>(cur)->setGrid(true);
                connect(dynamic_cast<MapGrid *>(cur), &MapGrid::createTowerSignal, [=](int row, int col){
                    this->createTower(row, col, 0);
                });
            }
//            qDebug() << j << " " << i << " " << j *sideLen;

            if(type == 0) {//添加槽图像
                QGraphicsItem *cur = new MapGrid(i, j, sideLen, ":/new/prefix1/assets/map/slot.png");
                this->scene->addItem(cur);
                cur->setPos(j*sideLen, i*sideLen);
                dynamic_cast<MapGrid *>(cur)->setGrid(true);
                connect(dynamic_cast<MapGrid *>(cur), &MapGrid::createTowerSignal, [=](int row, int col){
                    this->createTower(row, col, 1);//创建远程塔
                });
                slotList[i][j] = dynamic_cast<MapGrid *>(cur);
            }
        }
    }
    ui->graphicsView->show();
}

void GameWindow::renderSpecialPoints()
{
    for(int i = 0; i < this->pathList.size(); i++) {
        ps startPoint = pathList[i][0];
        ps endPoint = pathList[i][pathList[i].size()-1];
        QPixmap sp = QPixmap(":/new/prefix1/assets/map/startPoint.png");
        QGraphicsPixmapItem *cur = scene->addPixmap(sp);
        cur->setPos(startPoint.col * sideLen, startPoint.row * sideLen);
        cur->setScale(sideLen / sp.height() * 0.7);
        QPixmap ep = QPixmap(":/new/prefix1/assets/map/endPoint.png");
        cur = scene->addPixmap(ep);
        cur->setPos(((float)endPoint.col)* sideLen, endPoint.row * sideLen);
        cur->setScale(sideLen / ep.height());
    }
}

void GameWindow::EnemyMove()
{
    //先判断能否移动
    for(int i = 0; i < this->enemyList.size(); i++) {
        enemyList[i]->setMovable(true);
        for(auto j = 0; j < enemyList[i]->collidingItems().size(); j++) {
            if(enemyList[i]->collidingItems().at(j)->type() == Tower::Type || enemyList[i]->collidingItems().at(j)->type() == SuperTower::Type) {
               enemyList[i]->setMovable(false);
               //如果类型是Wizard && isValid, 就发动闪现
               if((enemyList[i]->type() == Wizard::Type && dynamic_cast<Wizard *>(enemyList[i])->getValid()) || (enemyList[i]->type() == DragonMaster::Type && dynamic_cast<DragonMaster *>(enemyList[i])->getValid())) {
                   bool IsDead = false;
                   enemyList[i]->setMovable(true);
                   //闪现, 就是迅速移动多次
                   for(int k = 0; k < 40; k++) {
                       Enemy * curEnemy = enemyList[i];
                       //既然能够移动, 那么必然是在终点以以前, 因此必然有下一个关键节点
                       ps nxtPoint = this->pathList[curEnemy->getPathIdx()][curEnemy->getNodeIdx()+1];
                       ps curPoint = this->pathList[curEnemy->getPathIdx()][curEnemy->getNodeIdx()];
                       int dir = 0;
                       if(curPoint.row == nxtPoint.row) {
                           if(curPoint.col > nxtPoint.col) {
                               dir = 3;
                           }
                           else dir = 4;
                       }
                       else {
                           if(curPoint.row > nxtPoint.row) {
                               dir = 1;
                           }
                           else dir = 2;
                       }
                       QPointF ret = curEnemy->moveBy(dir);
//                       qDebug() << "enemy--->" << curEnemy->scenePos();
                       //判断是否超出终点
                       if(curEnemy->getNodeIdx() == pathList[curEnemy->getPathIdx()].size()-2) {
                           bool isDead = false;
                           ps endPoint = pathList[curEnemy->getPathIdx()][pathList[curEnemy->getPathIdx()].size()-1];
                           switch (dir) {
                           case 1:
                               if(ret.y() <= sideLen * endPoint.row) isDead = true;
                               break;
                           case 2:
                               if(ret.y() >= sideLen * endPoint.row) isDead = true;
                               break;
                           case 3:
                               if(ret.x() <= sideLen * endPoint.col) isDead = true;
                               break;
                           case 4:
                               if(ret.x() >= sideLen * endPoint.col) isDead = true;
                           default:
                               qDebug() << "error! wrong dir!";
                           }
                           if(isDead) {
                               qDebug() << "curEnemy out of map range! destroy!";
                               this->life--;
                               ui->l_hp->setText(QString::number(life));
                               delete enemyList[i];
                               this->enemyList.erase(enemyList.begin() + i);
                               IsDead = true;
                               break;
                           }
                       }
                       else {//当前不是倒数第二个点, 那么就要判断是否要换方向
                           switch (dir) {
                           case 1:
                               if(ret.y() <= nxtPoint.row * sideLen) {
                                   //纠正坐标
                                   curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                                   curEnemy->getNodeIdx()++;
                               }
                               break;
                           case 2:
                               if(ret.y() >= nxtPoint.row * sideLen) {
                                   //纠正坐标
                                   curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                                   curEnemy->getNodeIdx()++;
                               }
                               break;
                           case 3:
                               if(ret.x() <= nxtPoint.col * sideLen) {
                                   //纠正坐标
                                   curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                                   curEnemy->getNodeIdx()++;
                               }
                               break;
                           case 4:
                               if(ret.x() >= nxtPoint.col * sideLen) {
                                   //纠正坐标
                                   curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                                   curEnemy->getNodeIdx()++;
                               }
                               break;
                           default:
                               qDebug() << "error! wrong dir!";
                           }
                       }
                    }
                   if(!IsDead) {
                       dynamic_cast<Wizard *>(enemyList[i])->resetCD(5);
                    }
               }
            }
        }
    }
    for(int i = 0; i < this->enemyList.size(); i++) {
        Enemy * curEnemy = enemyList[i];
        //既然能够移动, 那么必然是在终点以以前, 因此必然有下一个关键节点
        ps nxtPoint = this->pathList[curEnemy->getPathIdx()][curEnemy->getNodeIdx()+1];
        ps curPoint = this->pathList[curEnemy->getPathIdx()][curEnemy->getNodeIdx()];
        int dir = 0;
        if(curPoint.row == nxtPoint.row) {
            if(curPoint.col > nxtPoint.col) {
                dir = 3;
            }
            else dir = 4;
        }
        else {
            if(curPoint.row > nxtPoint.row) {
                dir = 1;
            }
            else dir = 2;
        }
        QPointF ret = curEnemy->moveBy(dir);
//        qDebug() << "enemy--->" << curEnemy->scenePos();
        //判断是否超出终点
        if(curEnemy->getNodeIdx() == pathList[curEnemy->getPathIdx()].size()-2) {
            bool isDead = false;
            ps endPoint = pathList[curEnemy->getPathIdx()][pathList[curEnemy->getPathIdx()].size()-1];
            switch (dir) {
            case 1:
                if(ret.y() <= sideLen * endPoint.row) isDead = true;
                break;
            case 2:
                if(ret.y() >= sideLen * endPoint.row) isDead = true;
                break;
            case 3:
                if(ret.x() <= sideLen * endPoint.col) isDead = true;
                break;
            case 4:
                if(ret.x() >= sideLen * endPoint.col) isDead = true;
            default:
                qDebug() << "error! wrong dir!";
            }
            if(isDead) {
                qDebug() << "curEnemy out of map range! destroy!";
                this->life--;
                if(enemyList[i] == this->focusItem) {
                    focusItem = nullptr;
                    ui->tableWidget->removeColumn(0);
                    ui->tableWidget->setColumnCount(1);
                    ui->tableWidget->horizontalHeader()->setHidden(true);
                }
                ui->l_hp->setText(QString::number(life));
                delete enemyList[i];
                this->enemyList.erase(enemyList.begin() + i);
            }
        }
        else {//当前不是倒数第二个点, 那么就要判断是否要换方向
            switch (dir) {
            case 1:
                if(ret.y() <= nxtPoint.row * sideLen) {
                    //纠正坐标
                    curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                    curEnemy->getNodeIdx()++;
                }
                break;
            case 2:
                if(ret.y() >= nxtPoint.row * sideLen) {
                    //纠正坐标
                    curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                    curEnemy->getNodeIdx()++;
                }
                break;
            case 3:
                if(ret.x() <= nxtPoint.col * sideLen) {
                    //纠正坐标
                    curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                    curEnemy->getNodeIdx()++;
                }
                break;
            case 4:
                if(ret.x() >= nxtPoint.col * sideLen) {
                    //纠正坐标
                    curEnemy->setPos(QPointF(sideLen * nxtPoint.col, sideLen * nxtPoint.row));
                    curEnemy->getNodeIdx()++;
                }
                break;
            default:
                qDebug() << "error! wrong dir!";
            }
        }
    }
}

void GameWindow::getFocusItem(QGraphicsItem *p)
{
    this->focusItem = p;
}

void GameWindow::showFocusItem()
{
//    //控制checkBox能否被选中
//    //先设置均不可被选中
//    ui->checkBox->setEnabled(false);
//    ui->checkBox_2->setEnabled(false);
//    ui->checkBox_3->setEnabled(false);
//    ui->checkBox_4->setEnabled(false);
    QGraphicsItem *p = this->focusItem;
    if(p == nullptr) return ;
    qDebug() << "get Focus Item!";
    switch (p->type()) {
    case Enemy::Type:{
        QTableWidgetItem *name = new QTableWidgetItem("皇家企鹅");
        ui->tableWidget->setItem(0, 0, name);
        Enemy *target = dynamic_cast<Enemy *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString::number(target->getMoveSpeed()));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        QTableWidgetItem *effect1 = new QTableWidgetItem("");
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem("");
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case Wizard::Type:{
        QTableWidgetItem *name = new QTableWidgetItem("圣灵法师");
        ui->tableWidget->setItem(0, 0, name);
        Enemy *target = dynamic_cast<Enemy *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString::number(target->getMoveSpeed()));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        QTableWidgetItem *effect1 = new QTableWidgetItem("闪现");
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem("");
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case Vanguard::Type: {
        QTableWidgetItem *name = new QTableWidgetItem("急先锋");
        ui->tableWidget->setItem(0, 0, name);
        Enemy *target = dynamic_cast<Enemy *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString::number(target->getMoveSpeed()));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        QTableWidgetItem *effect1 = new QTableWidgetItem("");
        ui->tableWidget->setItem(7, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem("急速");
        ui->tableWidget->setItem(6, 0, effect2);
        break;
    }
    case DragonMaster::Type:{
        QTableWidgetItem *name = new QTableWidgetItem("驯龙法师");
        ui->tableWidget->setItem(0, 0, name);
        Enemy *target = dynamic_cast<Enemy *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString::number(target->getMoveSpeed()));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        QTableWidgetItem *effect1 = new QTableWidgetItem("闪现");
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem("急速");
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case CloudCat::Type: {
        QTableWidgetItem *name = new QTableWidgetItem("祥云喵喵");
        ui->tableWidget->setItem(0, 0, name);
        Enemy *target = dynamic_cast<Enemy *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString::number(target->getMoveSpeed()));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        QTableWidgetItem *effect1 = new QTableWidgetItem("");
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem("");
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case Tower::Type:{
//        //设置checkBox的状态
//        if(rageUnlocked) ui->checkBox->setEnabled(true);
//        if(freezeUnlocked) ui->checkBox_2->setEnabled(true);
//        if(bleedUnlocked) ui->checkBox_3->setEnabled(true);
//        if(areaDamageUnlocked) ui->checkBox_4->setEnabled(true);
        QTableWidgetItem *name = new QTableWidgetItem("近战塔");
        ui->tableWidget->setItem(0, 0, name);
        Tower *target = dynamic_cast<Tower *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        //获取词缀
        QString affix1;
        QString affix2;
        if(target->rageAffix) {
            if(!affix1.isEmpty()) affix2 = "狂暴";
            else affix1 = "狂暴";
            //设置checkBox
            ui->checkBox->setChecked(true);
        } else ui->checkBox->setChecked(false);
        if(target->freezeAffix) {
            if(!affix1.isEmpty()) affix2 = "冰冻";
            else affix1 = "冰冻";
            ui->checkBox_2->setChecked(true);
        } else ui->checkBox_2->setChecked(false);
        if(target->bleedAffix) {
            if(!affix1.isEmpty()) affix2 = "流血";
            else affix1 = "流血";
            ui->checkBox_3->setChecked(true);
        } else ui->checkBox_3->setChecked(false);
        if(target->areaDamageAffix) {
            if(!affix1.isEmpty()) affix2 = "群伤";
            else affix1 = "群伤";
            ui->checkBox_4->setChecked(true);
        } else ui->checkBox_4->setChecked(false);
        QTableWidgetItem *effect1 = new QTableWidgetItem(affix1);
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem(affix2);
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case SuperTower::Type: {
        QTableWidgetItem *name = new QTableWidgetItem("超级近战塔");
        ui->tableWidget->setItem(0, 0, name);
        Tower *target = dynamic_cast<Tower *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        //获取词缀
        QString affix1;
        QString affix2;
        if(target->rageAffix) {
            if(!affix1.isEmpty()) affix2 = "狂暴";
            else affix1 = "狂暴";
            //设置checkBox
            ui->checkBox->setChecked(true);
        } else ui->checkBox->setChecked(false);
        if(target->freezeAffix) {
            if(!affix1.isEmpty()) affix2 = "冰冻";
            else affix1 = "冰冻";
            ui->checkBox_2->setChecked(true);
        } else ui->checkBox_2->setChecked(false);
        if(target->bleedAffix) {
            if(!affix1.isEmpty()) affix2 = "流血";
            else affix1 = "流血";
            ui->checkBox_3->setChecked(true);
        } else ui->checkBox_3->setChecked(false);
        if(target->areaDamageAffix) {
            if(!affix1.isEmpty()) affix2 = "群伤";
            else affix1 = "群伤";
            ui->checkBox_4->setChecked(true);
        } else ui->checkBox_4->setChecked(false);
        QTableWidgetItem *effect1 = new QTableWidgetItem(affix1);
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem(affix2);
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case RemoteTower::Type:{
//        //设置checkBox的状态
//        if(rageUnlocked) ui->checkBox->setEnabled(true);
//        if(freezeUnlocked) ui->checkBox_2->setEnabled(true);
//        if(bleedUnlocked) ui->checkBox_3->setEnabled(true);
//        if(areaDamageUnlocked) ui->checkBox_4->setEnabled(true);
        QTableWidgetItem *name = new QTableWidgetItem("远程塔");
        ui->tableWidget->setItem(0, 0, name);
        Tower *target = dynamic_cast<Tower *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        //获取词缀
        QString affix1;
        QString affix2;
        if(target->rageAffix) {
            if(!affix1.isEmpty()) affix2 = "狂暴";
            else affix1 = "狂暴";
            //设置checkBox
            ui->checkBox->setChecked(true);
        } else ui->checkBox->setChecked(false);
        if(target->freezeAffix) {
            if(!affix1.isEmpty()) affix2 = "冰冻";
            else affix1 = "冰冻";
            ui->checkBox_2->setChecked(true);
        } else ui->checkBox_2->setChecked(false);
        if(target->bleedAffix) {
            if(!affix1.isEmpty()) affix2 = "流血";
            else affix1 = "流血";
            ui->checkBox_3->setChecked(true);
        } else ui->checkBox_3->setChecked(false);
        if(target->areaDamageAffix) {
            if(!affix1.isEmpty()) affix2 = "群伤";
            else affix1 = "群伤";
            ui->checkBox_4->setChecked(true);
        } else ui->checkBox_4->setChecked(false);
        QTableWidgetItem *effect1 = new QTableWidgetItem(affix1);
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem(affix2);
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    case SuperRemoteTower::Type: {
        QTableWidgetItem *name = new QTableWidgetItem("超级远程塔");
        ui->tableWidget->setItem(0, 0, name);
        Tower *target = dynamic_cast<Tower *>(p);
        QTableWidgetItem *hp = new QTableWidgetItem(QString::number(target->getHp()) + "/" + QString::number(target->getMaxHP()));
        ui->tableWidget->setItem(1, 0, hp);
        QTableWidgetItem *atk = new QTableWidgetItem(QString::number(target->getAtk()));
        ui->tableWidget->setItem(2, 0, atk);
        QTableWidgetItem *atkRange = new QTableWidgetItem(QString::number(target->getAtkRange()));
        ui->tableWidget->setItem(3, 0, atkRange);
        QTableWidgetItem *atkSpeed = new QTableWidgetItem(QString::number(target->getAtkSpeed()));
        ui->tableWidget->setItem(4, 0, atkSpeed);
        QTableWidgetItem *moveSpeed = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(5, 0, moveSpeed);
        //获取词缀
        QString affix1;
        QString affix2;
        if(target->rageAffix) {
            if(!affix1.isEmpty()) affix2 = "狂暴";
            else affix1 = "狂暴";
            //设置checkBox
            ui->checkBox->setChecked(true);
        } else ui->checkBox->setChecked(false);
        if(target->freezeAffix) {
            if(!affix1.isEmpty()) affix2 = "冰冻";
            else affix1 = "冰冻";
            ui->checkBox_2->setChecked(true);
        } else ui->checkBox_2->setChecked(false);
        if(target->bleedAffix) {
            if(!affix1.isEmpty()) affix2 = "流血";
            else affix1 = "流血";
            ui->checkBox_3->setChecked(true);
        } else ui->checkBox_3->setChecked(false);
        if(target->areaDamageAffix) {
            if(!affix1.isEmpty()) affix2 = "群伤";
            else affix1 = "群伤";
            ui->checkBox_4->setChecked(true);
        } else ui->checkBox_4->setChecked(false);
        QTableWidgetItem *effect1 = new QTableWidgetItem(affix1);
        ui->tableWidget->setItem(6, 0, effect1);
        QTableWidgetItem *effect2 = new QTableWidgetItem(affix2);
        ui->tableWidget->setItem(7, 0, effect2);
        break;
    }
    default: {
        return;
    }
    }
}

void GameWindow::UnlockAffix()
{
    //先判断是否已经全部解锁
    if(rageUnlocked && freezeUnlocked && bleedUnlocked && areaDamageUnlocked) return ;
    //获取1-4之间的一个随机数
    bool flag = false;
    while(!flag) {
        qsrand(QTime::currentTime().msec());	//设置种子，该种子作为qrand生成随机数的起始值，RAND_MAX为32767，即随机数在种子值到32767之间
        int idx = qrand()%4;
        switch (idx) {
        case 0:{//rage
            if(!rageUnlocked) {
                rageUnlocked = true;
                ui->checkBox->setStyleSheet("QCheckBox{color:red}");
                flag = true;
            }
            break;
        }
        case 1:{//冰冻
            if(!freezeUnlocked) {
                freezeUnlocked = true;
                ui->checkBox_2->setStyleSheet("QCheckBox{color:red}");
                flag = true;
            }
            break;
        }
        case 2:{//bleed
            if(!bleedUnlocked) {
                bleedUnlocked = true;
                ui->checkBox_3->setStyleSheet("QCheckBox{color:red}");
                flag = true;
            }
            break;
        case 3:{//areaDamage
                if(!areaDamageUnlocked) {
                    areaDamageUnlocked = true;
                    ui->checkBox_4->setStyleSheet("QCheckBox{color:red}");
                    flag = true;
                }
                break;
            }
            default: return ;
        }
        }
    }
}

GameWindow::GameWindow(int level, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //初始化信息
    this->curLevel = level;
    setWindowTitle("TowerDefense");
    setMinimumSize(QSize(2800, 1800));
    this->money = 1000;
    this->life = 30;
    this->stop = false;
    this->maxLife = 30;
    this->maxEnemyCnt = 0;
    this->timeCntForMakingEnemy = 0;
    this->enemyCnt = 0;
    ui->l_hp->setText(QString::number(this->life));
    ui->l_money->setText(QString::number(this->money));
    QString curLevel = "第" + QString::number(this->curLevel+1) + "关";
    ui->l_level->setText(curLevel);
    ui->l_progress->setText(QString::number(this->enemyCnt) + "/" + QString::number(this->maxEnemyCnt));
    this->scene = new GameScene;
    ui->graphicsView->setScene(scene);
    //加载和预览地图
    loadMap();
    qDebug() << "done!";
    this->isGrid.resize(this->lineNum);
    for(int i = 0; i < lineNum; i++) {
        isGrid[i].resize(this->colNum);
    }
    connect(&globalTimer, &QTimer::timeout, [=](){
//        qDebug() << "Timer Out!";
        globalTimer.start(50);
        makeEnemy();//创建怪物
        ui->l_progress->setText(QString::number(this->enemyCnt) + "/" + QString::number(this->maxEnemyCnt));
        //怪物移动
        EnemyMove();
        //怪物和塔的攻击
        atk();
        this->scene->update();
        //游戏的终局判断
        //显示关注信息
        showFocusItem();
        endGame();
//        this->scene->advance();
    });
    connect(ui->pb_stop, &QPushButton::clicked, [=](){
        if(isStopped) {
            this->isStopped = false;
            globalTimer.start(50);
            qDebug() << "restart!";
        }
        else {
            this->isStopped = true;
            globalTimer.stop();
            qDebug() << "stop";
        }
    });
    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        //先判断当前有没有获得防御塔类型的focus
        if(focusItem == nullptr) return ;
        if(focusItem->type() == Tower::Type || focusItem->type() == RemoteTower::Type || focusItem->type() == SuperTower::Type || focusItem->type() == SuperRemoteTower::Type) {
            Tower *target = dynamic_cast<Tower*>(focusItem);
            if(state == Qt::Unchecked) {//卸下词缀
                qDebug() << "卸下词缀";
                if(!target->rageAffix) return ;
                if(target->affixCnt > 0) {
                    target->setRage(false);
                    target->affixCnt--;
                    //返还金币
                    money += 50;
                    ui->l_money->setText(QString::number(money));
                }
            }
            else if(state == Qt::Checked) {//安装词缀
                qDebug() << "安装词缀";
                if(target->rageAffix) return ;
                if(target->affixCnt < 2 && rageUnlocked && money >= 100) {
                    target->setRage(true);
                    target->affixCnt++;
                    // 扣除金币
                    money -= 100;
                    ui->l_money->setText(QString::number(money));
                }
            }
        }
    });
    connect(ui->checkBox_2, &QCheckBox::stateChanged, [=](int state){
        //先判断当前有没有获得防御塔类型的focus
        if(focusItem == nullptr) return ;
        if(focusItem->type() == Tower::Type || focusItem->type() == RemoteTower::Type || focusItem->type() == SuperTower::Type || focusItem->type() == SuperRemoteTower::Type) {
            Tower *target = dynamic_cast<Tower*>(focusItem);
            if(state == Qt::Unchecked) {//卸下词缀
                qDebug() << "卸下词缀";
                if(!target->freezeAffix) return ;
                if(target->affixCnt > 0) {
                    target->freezeAffix = false;
                    target->affixCnt--;
                    money += 100;
                    ui->l_money->setText(QString::number(money));
                }
            }
            else if(state == Qt::Checked) {//安装词缀
                qDebug() << "安装词缀";
                if(target->freezeAffix) return ;
                if(target->affixCnt < 2 && freezeUnlocked && money >= 200) {
                    target->freezeAffix = true;
                    target->affixCnt++;
                    money -= 200;
                    ui->l_money->setText(QString::number(money));
                }
            }
        }
    });
    connect(ui->checkBox_3, &QCheckBox::stateChanged, [=](int state){
        //先判断当前有没有获得防御塔类型的focus
        if(focusItem == nullptr) return ;
        if(focusItem->type() == Tower::Type || focusItem->type() == RemoteTower::Type || focusItem->type() == SuperTower::Type || focusItem->type() == SuperRemoteTower::Type) {
            Tower *target = dynamic_cast<Tower*>(focusItem);
            if(state == Qt::Unchecked) {//卸下词缀
                qDebug() << "卸下词缀";
                if(!target->bleedAffix) return ;
                if(target->affixCnt > 0) {
                    target->bleedAffix = false;
                    target->affixCnt--;
                    money += 100;
                    ui->l_money->setText(QString::number(money));
                }
            }
            else if(state == Qt::Checked) {//安装词缀
                qDebug() << "安装词缀";
                if(target->bleedAffix) return ;
                if(target->affixCnt < 2 && bleedUnlocked && money >= 200) {
                    target->bleedAffix = true;
                    target->affixCnt++;
                    money -= 200;
                    ui->l_money->setText(QString::number(money));
                }
            }
        }
    });
    connect(ui->checkBox_4, &QCheckBox::stateChanged, [=](int state){
        //先判断当前有没有获得防御塔类型的focus
        if(focusItem == nullptr) return ;
        if(focusItem->type() == Tower::Type || focusItem->type() == RemoteTower::Type || focusItem->type() == SuperTower::Type || focusItem->type() == SuperRemoteTower::Type) {
            Tower *target = dynamic_cast<Tower*>(focusItem);
            if(state == Qt::Unchecked) {//卸下词缀
                qDebug() << "卸下词缀";
                if(!target->areaDamageAffix) return ;
                if(target->affixCnt > 0) {
                    target->areaDamageAffix = false;
                    target->affixCnt--;
                    money += 200;
                    ui->l_money->setText(QString::number(money));
                }
            }
            else if(state == Qt::Checked) {//安装词缀
                qDebug() << "安装词缀";
                if(target->areaDamageAffix) return ;
                if(target->affixCnt < 2 && areaDamageUnlocked && money >= 400) {
                    target->areaDamageAffix = true;
                    target->affixCnt++;
                    money -= 400;
                    ui->l_money->setText(QString::number(money));
                }
            }
        }
    });
    getGridStatus();
    slotList.resize(this->lineNum);
    for(int i = 0; i < this->lineNum; i++) {
        slotList[i].assign(this->colNum, nullptr);
    }
    renderMap();
    renderSpecialPoints();
    this->globalTimer.start(50);
    ui->graphicsView->show();
}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::closeEvent(QCloseEvent * e)
{
    if(QMessageBox::question(this,
                             tr("退出"),
                             tr("确定退出吗?"),
                              QMessageBox::Yes, QMessageBox::No )
                   == QMessageBox::Yes){
        emit returnSignal();
        e->accept();//不会将事件传递给组件的父组件
        qDebug()<<"ok";
    }
    else
        e->ignore();
}

void GameWindow::makeEnemy()
{
    if(this->enemyCnt >= this->maxEnemyCnt) return ;
    if(this->timeCntForMakingEnemy != 40) {
        timeCntForMakingEnemy++;
        return ;
    }
    else {
        timeCntForMakingEnemy = 1;
        //创建怪物
//        for(int i = 0; i < this->pathList.size() && enemyCnt < maxEnemyCnt; i++) {
//            DragonMaster* curEnemy = new DragonMaster(i, this->sideLen);
//            this->enemyCnt++;
//            this->scene->addItem(curEnemy);
//            curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
//            enemyList.push_back(curEnemy);
//        }
        for(int i = 0; i < pathList.size(); i++) {
            if(!this->enemyInfoList[i].empty()) {
                enemyInfo cur = enemyInfoList[i][0];
                if(--cur.num == 0) enemyInfoList[i].erase(enemyInfoList[i].begin());
                else enemyInfoList[i][0] = cur;
                this->enemyCnt++;
                switch (cur.type) {
                case 1: {
                    Enemy* curEnemy = new Enemy(i, this->sideLen);
                    connect(curEnemy, &Enemy::getFocus, [=](QGraphicsItem *p){
                        getFocusItem(p);
                    });
                    this->scene->addItem(curEnemy);
                    curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
                    enemyList.push_back(curEnemy);
                    break;
                }

                case 2:{
                    Wizard* curEnemy = new Wizard(i, this->sideLen);
                    connect(curEnemy, &Enemy::getFocus, [=](QGraphicsItem *p){
                        getFocusItem(p);
                    });
                    this->scene->addItem(curEnemy);
                    curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
                    enemyList.push_back(curEnemy);
                    break;
                }

                case 3:{
                    Vanguard* curEnemy = new Vanguard(i, this->sideLen);
                    connect(curEnemy, &Enemy::getFocus, [=](QGraphicsItem *p){
                        getFocusItem(p);
                    });
                    this->scene->addItem(curEnemy);
                    curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
                    enemyList.push_back(curEnemy);
                    break;
                }
                case 4:{
                    DragonMaster* curEnemy = new DragonMaster(i, this->sideLen);
                    connect(curEnemy, &Enemy::getFocus, [=](QGraphicsItem *p){
                        getFocusItem(p);
                    });
                    this->scene->addItem(curEnemy);
                    curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
                    enemyList.push_back(curEnemy);
                    break;
                }
                case 5:{
                    CloudCat *curEnemy = new CloudCat(i, this->sideLen);
                    connect(curEnemy, &Enemy::getFocus, [=](QGraphicsItem *p){
                        getFocusItem(p);
                    });
                    this->scene->addItem(curEnemy);
                    curEnemy->setPos(pathList[i][0].col * sideLen, pathList[i][0].row * sideLen);
                    enemyList.push_back(curEnemy);
                    break;
                }
                default:
                    qDebug() << "wrong";
                }
            }
        }
    }
}

void GameWindow::createTower(int row, int col, int type)
{
    qDebug() << "TowerCreated at row " << row << ", col " << col;
    //获取当前要建设的塔的类型
    if(type == 0) {
        if(ui->radioButton_1->isChecked()) {
            if(this->money >= 100) {
                this->money -= 100;
                ui->l_money->setText(QString::number(money));
                Tower *cur = new Tower(row, col, this->sideLen);
                connect(cur, &Tower::deleteSignal, [=](int row, int col){
                    deleteTower(row, col);
                });
                connect(cur, &Tower::getFocus, [=](QGraphicsItem *p){
                    getFocusItem(p);
                });
                cur->setPos(col * sideLen, row * sideLen);
                this->scene->addItem(cur);
                this->towerList.push_back(cur);
            }
            else {
                qDebug() << "not enough money!";
            }
        }
        else if(ui->radioButton_2->isChecked()) {//创建超级近战塔
            if(this->money >= 300) {
                this->money -= 300;
                ui->l_money->setText(QString::number(money));
                QGraphicsItem *cur = new SuperTower(row, col, this->sideLen);
                connect(dynamic_cast<Tower *>(cur), &Tower::deleteSignal, [=](int row, int col){
                    deleteTower(row, col);
                });
                connect(dynamic_cast<Tower *>(cur), &Tower::getFocus, [=](QGraphicsItem *p){
                    getFocusItem(p);
                });
                cur->setPos(col * sideLen, row * sideLen);
                this->scene->addItem(cur);
                this->towerList.push_back(dynamic_cast<Tower *>(cur));
            }
            else {
                qDebug() << "not enough money!";
            }
        }
    }
    else {
        if(ui->radioButton_3->isChecked()) {
            if(this->money >= 200) {
                this->money -= 200;
                ui->l_money->setText(QString::number(money));
                RemoteTower *cur = new RemoteTower(row, col, this->sideLen);
                connect(cur, &RemoteTower::deleteRemoteSignal, [=](int row, int col){
                    deleteTower(row, col, 1);
                });
                connect(cur, &Tower::getFocus, [=](QGraphicsItem *p){
                    getFocusItem(p);
                });
                cur->setPos(col * sideLen, row * sideLen);
                this->scene->addItem(cur);
                this->towerList.push_back(cur);
                //隐藏SLOT
                if(slotList[row][col] != nullptr) slotList[row][col]->hide();
            }
            else {
                qDebug() << "not enough money!";
            }
        }
        else if(ui->radioButton_4->isChecked()) {//创建超级远程塔
            if(this->money >= 400) {
                this->money -= 400;
                ui->l_money->setText(QString::number(money));
                RemoteTower *cur = new SuperRemoteTower(row, col, this->sideLen);
                connect(cur, &RemoteTower::deleteRemoteSignal, [=](int row, int col){
                    deleteTower(row, col, 1);
                });
                connect(cur, &Tower::getFocus, [=](QGraphicsItem *p){
                    getFocusItem(p);
                });
                cur->setPos(col * sideLen, row * sideLen);
                this->scene->addItem(cur);
                this->towerList.push_back(cur);
                //隐藏SLOT
                if(slotList[row][col] != nullptr) slotList[row][col]->hide();
            }
            else {
                qDebug() << "not enough money!";
            }
        }
    }
}

void GameWindow::deleteTower(int row, int col, int type)
{
    //合法性判断
    //先判断这个地方有没有塔
    auto it = towerList.begin();
    for(; it != towerList.end(); it++) {
        if((*it)->getPos().row == row && (*it)->getPos().col == col) break;
    }
    if(it != towerList.end()) {
        if(type == 0) {
            //说明存在, 需要被摧毁
            //首先从Scene删除对象
            this->scene->removeItem(dynamic_cast<QGraphicsItem *>(*it));
            //恢复金币
            this->money += 100;
            ui->l_money->setText(QString::number(this->money));
            //删除对象
            if(focusItem == *it) focusItem = nullptr;
            delete *it;
            towerList.erase(it);
            //然后在TowerList中删除
            qDebug() << "TowerDeleted!";
        }
        else {//远程塔
            //说明存在, 需要被摧毁
            //首先从Scene删除对象
            this->scene->removeItem(dynamic_cast<QGraphicsItem *>(*it));
            //恢复金币
            this->money += 200;
            ui->l_money->setText(QString::number(this->money));
            //删除对象
            if(focusItem == *it) focusItem = nullptr;
            delete *it;
            towerList.erase(it);
            //然后在TowerList中删除
            if(slotList[row][col] != nullptr) slotList[row][col]->show();
            qDebug() << "TowerDeleted!";
        }
    }

}

void GameWindow::endGame()
{
    if(this->life <= 0) {
        qDebug() << "YOU LOSE THE GAME!";
        globalTimer.stop();
        isStopped = true;
        if(QMessageBox::information(this, "游戏结束", "胜败乃兵家常事, 再来一局吧!", QMessageBox::Yes) == QMessageBox::Yes) {
            emit returnSignal();
        }
    }
    else {
        if(enemyCnt == maxEnemyCnt && this->enemyList.size() == 0) {
            qDebug() << "YOU WIN THE GAME!";
            globalTimer.stop();
            isStopped = true;
            if(QMessageBox::information(this, "游戏结束", "恭喜你, 游戏胜利!", QMessageBox::Yes) == QMessageBox::Yes) {
                emit winSinal(this->curLevel);
            }
        }
    }
}

void GameWindow::atk()
{
    for(int i = 0; i < this->towerList.size(); i++) {
        //如果是群伤塔, 直接将整个enemyList 传入, 不走下面的流程
        if(towerList[i]->areaDamageAffix) {
            towerList[i]->rangeAttack(this->enemyList);
        }
        else {
            if(towerList[i]->type() == SuperRemoteTower::Type) {//治疗塔攻击的同时进行治疗
                towerList[i]->heal(towerList);
            }
            //计算与所有在场怪物的最近的距离
            Enemy *target = nullptr;
            qreal minDis = 1000000000;
            for(int j = 0; j < this->enemyList.size(); j++) {
                qreal curDis = calcDis(towerList[i], enemyList[j]);
                if(curDis < minDis) {
                    minDis = curDis;
                    target = enemyList[j];
                }
            }
            towerList[i]->attack(target);
        }
    }
    for(int i = 0; i < this->enemyList.size(); i++) {
        //计算与所有在场怪物的最近的距离
        Tower *target = nullptr;
        qreal minDis = 1000000000;
        for(int j = 0; j < this->towerList.size(); j++) {
            qreal curDis = calcDis(enemyList[i], towerList[j]);
            if(curDis < minDis) {
                minDis = curDis;
                target = towerList[j];
            }
        }
        enemyList[i]->attack(target);
    }
    //清除尸体
    for(auto it = towerList.begin(); it != towerList.end(); it++) {
        if((*it)->getHp() <= 0) {
            qDebug() << "tower destroyed!";
            if((*it)->type() == SuperTower::Type) this->freezeAllEnemy();
            if(*it == this->focusItem) {
                focusItem = nullptr;
                ui->tableWidget->removeColumn(0);
                ui->tableWidget->setColumnCount(1);
                ui->tableWidget->horizontalHeader()->setHidden(true);
            }
            this->scene->removeItem(*it);
            ps state = (*it)->getPos();
            if(slotList[state.row][state.col] != nullptr) slotList[state.row][state.col]->show();
            delete *it;
            towerList.erase(it);
            it--;
        }
    }
    for(auto it = enemyList.begin(); it != enemyList.end(); it++) {
        if((*it)->getHp() <= 0) {
            qDebug() << "enemy destroyed!";
            //如果是BOSS, 解锁一个词缀
            if((*it)->type() == CloudCat::Type) this->UnlockAffix();
            if(*it == this->focusItem) {
                focusItem = nullptr;
                ui->tableWidget->removeColumn(0);
                ui->tableWidget->setColumnCount(1);
                ui->tableWidget->horizontalHeader()->setHidden(true);
            }
            this->scene->removeItem(*it);
            delete *it;
            enemyList.erase(it);
            it--;
            //击杀敌人增加金币
            this->money += 50;
            ui->l_money->setText(QString::number(money));
        }
    }
}

void GameWindow::freezeAllEnemy()
{
    for(auto enemy : this->enemyList) {
        enemy->beFreezed(3);
    }
}
