#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

void GameWindow::loadMap()
{
    QString fp = QDir::currentPath() + "./info/map" + QString::number(this->curLevel) + ".txt";
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
            struct ps curps;
            curps.row = psStr[0].toInt();
            curps.col = psStr[1].toInt();
            cur.push_back(curps);
        }
        this->pathList.push_back(cur);
    }
    file.close();
    qDebug() << this->pathList.size() << " " << this->pathList[0].size();
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
        if(col < this->colNum && isGrid[row][col+1]) return 0;
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

            case -1://非路径
                pixPath = ":/new/prefix1/assets/map/cp.png";
                break;
            case 0:
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
            QGraphicsPixmapItem *cur = this->scene->addPixmap(QPixmap(pixPath));
            cur->setPos(j*sideLen, i*sideLen);
            cur->setScale(sideLen / 32);
            if(type == 0) {//添加槽图像
                QPixmap pix = QPixmap(":/new/prefix1/assets/map/slot.png");
                cur = this->scene->addPixmap(pix);
                cur->setPos(j*sideLen, i*sideLen);
                cur->setScale(sideLen / pix.width());
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
        cur->setPos(((float)endPoint.col + 0.3)* sideLen, endPoint.row * sideLen);
        cur->setScale(sideLen / ep.height() * 0.7);
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
    ui->l_hp->setText(QString::number(this->life));
    ui->l_money->setText(QString::number(this->money));
    QString curLevel = "第" + QString::number(this->curLevel+1) + "关";
    ui->l_level->setText(curLevel);
    ui->l_progress->setText(QString("第1波"));
    this->scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    //加载和预览地图
    loadMap();
    qDebug() << "done!";
    this->isGrid.resize(this->lineNum);
    for(int i = 0; i < lineNum; i++) {
        isGrid[i].resize(this->colNum);
    }
    getGridStatus();
    renderMap();
    renderSpecialPoints();
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
