#include "makemap.h"
#include "ui_makemap.h"
#include <QFileDialog>


void MakeMap::createGrids()
{
    if(this->pbList.size() != 0 || this->pathList.size() != 0) {
        //说明之前已经加载了一张地图文件, 需要清空所有之前的信息.
        for(int i = 0; i < pbList.size(); i++) {
            for(int j = 0; j < pbList[i].size(); j++) {
                delete this->pbList[i][j];
            }
        }
        this->pbList.clear();
    }
    int totWidth = ui->w_display->width();
    int totHeight = ui->w_display->height();
    float colCnt = (this->colNum - 1) * 0.1 + this->colNum;
    float rowCnt = (this->lineNum - 1) * 0.1 + this->lineNum;
    float sideLen;
    float rowMargin = 0;
    float colMargin = 0;
    if(totWidth / colCnt > totHeight / rowCnt) {
        sideLen = totHeight / rowCnt;
        colMargin = (totWidth - colCnt * sideLen) / 2;
    }
    else {
        sideLen = totWidth / colCnt;
        rowMargin = (totHeight - rowCnt * sideLen) / 2;
    }
    this->pbList.resize(this->lineNum);
    for(int i = 0; i < this->lineNum; i++) {
        pbList[i].resize(this->colNum);
    }
    for(int i = 0; i < lineNum; i++) {
        for(int j = 0; j < colNum; j++) {
            pbList[i][j] = new QPushButton(ui->w_display);
            pbList[i][j]->setGeometry(colMargin + j*1.1*sideLen, rowMargin + i*1.1*sideLen, sideLen, sideLen);
            pbList[i][j]->setCheckable(true);
            pbList[i][j]->show();
        }
    }
    qDebug() << "createGrids: " << this->lineNum << " " << this->colNum;
}

void MakeMap::getGridStatus()
{
    //首先清空isGrid数组.
    this->isGrid.clear();
    isGrid.resize(this->lineNum);
    for(int i = 0; i < this->lineNum; i++) {
        this->isGrid[i].resize(this->colNum);
    }
    for(int i = 0; i < this->pathList.size(); i++) {
        showPath(i);
        for(int row = 0; row < this->lineNum; row++) {
            for(int col = 0; col < this->colNum; col++) {
                if(this->pbList[row][col]->isChecked()) this->isGrid[row][col] = true;
            }
        }
    }
    ui->comboBox->setCurrentIndex(this->pathList.size()-1);
}

void MakeMap::showPath(int idx)//显示第idx条路径
{
    qDebug() << "show: " << idx;
    if(idx < 0) return ;
    //先清空所有的按下状态
    for(int i = 0; i < this->lineNum; i++) {
        for(int j = 0; j < this->colNum; j++) {
            pbList[i][j]->setChecked(false);
        }
    }
    //下面显示当前路径, 注意: 如果还没有设置好, 那么会跳过
    if(pathList[idx].size() == 0 || pathList[idx].size() == 1) return ;
    for(int i = 0; i < this->pathList[idx].size()-1; i++) {
        struct ps curps = pathList[idx][i];
        struct ps nxtps = pathList[idx][i+1];
        if(curps.row == nxtps.row) {//行数一样, 说明要么是从右至左
            if(curps.col > nxtps.col) {
                for(int j = curps.col; j >= nxtps.col; j--) {
                    this->pbList[curps.row][j]->setChecked(true);
                }
            }
            else {
                for(int j = curps.col; j <= nxtps.col; j++) {
                    this->pbList[curps.row][j]->setChecked(true);
                }
            }
        }
        else {
           //否则就是从上到下, 或者从下到上
            if(curps.row < nxtps.row) {
                for(int j = curps.row; j <= nxtps.row; j++) {
                    this->pbList[j][curps.col]->setChecked(true);
                }
            }
            else {
                for(int j = curps.row; j >= nxtps.row; j--) {
                    this->pbList[j][curps.col]->setChecked(true);
                }
            }
        }
    }
}

int MakeMap::cntNeighbours(int row, int col)
{
    int ret = 0;
    if(row + 1 < lineNum && pbList[row+1][col]->isChecked())  ++ret;
    if(row - 1 >= 0 && pbList[row-1][col]->isChecked()) ++ret;
    if(col + 1 < colNum && pbList[row][col+1]->isChecked()) ++ret;
    if(col - 1 >= 0 && pbList[row][col-1]->isChecked()) ++ret;
    return ret;
}

ps MakeMap::getNext(int curCol, int curRow, int prevCol, int prevRow)
{
    int nxtCol = -1, nxtRow = -1;
    if(curRow + 1 < lineNum && pbList[curRow+1][curCol]->isChecked() && (curRow+1 != prevRow || curCol != prevCol)) {nxtCol = curCol; nxtRow = curRow+1;}
    else if(curRow - 1 >= 0 && pbList[curRow-1][curCol]->isChecked() && (curRow-1 != prevRow || curCol != prevCol)) {nxtCol = curCol; nxtRow = curRow-1;}
    else if(curCol + 1 < colNum && pbList[curRow][curCol+1]->isChecked() && (curRow != prevRow || curCol+1 != prevCol))  {nxtCol = curCol+1; nxtRow = curRow;}
    else if(curCol - 1 >= 0 && pbList[curRow][curCol-1]->isChecked() && (curRow != prevRow || curCol-1 != prevCol)) {nxtCol = curCol-1; nxtRow = curRow;}
    ps ret;
    ret.col = nxtCol;
    ret.row = nxtRow;
    return ret;
}

void MakeMap::drawPreview() //将地图信息转化为QGraphicsScene中的Item
{
    if(this->lineNum == 0 || this->colNum == 0) return ; //尚未加载地图
    if(this->mapScene != nullptr) delete mapScene;
    this->mapScene = new QGraphicsScene;
    //获得当前所有各自的状态数组
    getGridStatus();
    int totWidth = ui->tab->width();
    int totHeight=  ui->tab->height();
    float sideLen;
    float vMargin = 0;
    float hMargin = 0;
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
            QGraphicsPixmapItem *cur = this->mapScene->addPixmap(QPixmap(pixPath));
            cur->setPos(j*sideLen, i*sideLen);
            cur->setScale(sideLen / 32);
            qDebug() << "size: " << mapScene->items().size();
        }
    }
    ui->graphicsView->setScene(this->mapScene);
    ui->graphicsView->show();
}

int MakeMap::getGridType(int row, int col)
{
    if(!this->isGrid[row][col]) return -1;//非路径
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


QGraphicsScene *MakeMap::getMapScene() const
{
    return mapScene;
}

void MakeMap::setMapScene(QGraphicsScene *value)
{
    mapScene = value;
}

void MakeMap::showEnemyInfo()
{
    ui->comboBox_2->clear();
    for(int i = 0; i < enemyInfoList.size(); i++) {
        ui->comboBox_2->addItem(QString::number(i+1));
    }
    ui->treeWidget->clear();
    for(int i = 0; i< this->pathList.size(); i++) {
        QTreeWidgetItem *cur = new QTreeWidgetItem(ui->treeWidget);
        cur->setText(0, QString("线路"+ QString::number(i+1)));
        for(int j = 0; j < this->enemyInfoList[i].size(); j++) {
            QTreeWidgetItem *subItem = new QTreeWidgetItem(cur);
            subItem->setText(0, QString::number(enemyInfoList[i][j].type));
            subItem->setText(1, QString::number(enemyInfoList[i][j].num));
        }
        ui->treeWidget->addTopLevelItem(cur);
    }
}

MakeMap::MakeMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MakeMap)
{
    ui->setupUi(this);
    this->setWindowTitle("地图制作模块");
    setMinimumSize(QSize(2000, 1500));
    connect(ui->pb_exit1, &QPushButton::clicked, [=](){
        emit returnSignal();
    });
    connect(ui->pb_import, &QPushButton::clicked, [=](){//打开文件的方式
        if(this->pbList.size() != 0 || this->pathList.size() != 0) {
            //说明之前已经加载了一张地图文件, 需要清空所有之前的信息.
            for(int i = 0; i < pbList.size(); i++) {
                for(int j = 0; j < pbList[i].size(); j++) {
                    delete this->pbList[i][j];
                }
            }
            this->lineNum = 0;
            this->colNum = 0;
            this->pbList.clear();
            this->pathList.clear();
            ui->comboBox->clear();
            ui->treeWidget->clear();
            this->enemyInfoList.clear();
        }
        QString filePath = QFileDialog::getOpenFileName(this,QStringLiteral("打开文件"),"C:",QStringLiteral("文本文件(*txt)"));
        ui->l_fp->setText(filePath);
        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << "error! file not exists!";
            return ;
        }
        //文件读取
        QString buffer;
        buffer = file.readLine();
        if(buffer.isEmpty()) {
            QMessageBox::warning(this, "失败", "空白文件!已删除!");
            file.remove();
            return ;
        }
        QStringList list = buffer.split(" ");
        this->lineNum = list[1].toInt();
        this->colNum = list[0].toInt();
        ui->spinBox->setValue(this->lineNum);
        ui->spinBox_2->setValue(this->colNum);
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
        //接下来读怪物信息
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
                cur.push_back(info);
            }
            this->enemyInfoList.push_back(cur);
        }
        file.close();
        //调用createGrids, 创建网格
        createGrids();
        //给comboBox添加Item
        for(int i = 0; i < this->pathList.size(); i++) {
            ui->comboBox->addItem(QString::number(i+1));
        }
        //调用showPath, 显示第一条路径
        if(this->pathList.size() > 0) {
            showPath(0);
        }
        //显示当前的怪物信息
        showEnemyInfo();
        //怪物信息按钮的初始化
        for(int i = 0; i < this->enemyInfoList.size(); i++) {
            ui->comboBox_2->addItem(QString::number(i+1));
        }
        ui->spinBox_num->setMinimum(1);
        ui->spinBox_type->setRange(1,5);
    });
    connect(ui->comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int idx){
         this->showPath(idx);
    });
    connect(ui->pb_savePath, &QPushButton::clicked, [=](){//保存对当前路径的修改
        int idx = this->ui->comboBox->currentIndex();
        this->pathList[idx].clear();
        vector<struct ps> newPath;
        //下面重新记录该路径的所有信息
        //从右上至左下, 依次扫描所有的格子
        //分为三种格子: 非路径, 一般路径节点, 关键路径节点(起点, 拐点, 终点)
        //首先寻找起点, 起点满足3个条件: isChecked; 只与一个点相邻; col = colNum-1
        for(int i = 0; i < this->lineNum; i++) {
            if(pbList[i][this->colNum-1]->isChecked() && cntNeighbours(i, colNum-1) == 1) {
                struct ps point;
                point.row = i;
                point.col = this->colNum-1;
                newPath.push_back(point);
            }
        }
        //下面找与起点邻接的一个点
        ps curPoint = getNext(newPath[0].col, newPath[0].row, -1, -1);
        ps prevPoint = newPath[0];
        ps nextPoint;
        ps end = {-1, -1};
        nextPoint = getNext(curPoint.col, curPoint.row, prevPoint.col, prevPoint.row);
        while(nextPoint != end) {
            //判断是否为拐点
            if(nextPoint.row != prevPoint.row && nextPoint.col != prevPoint.col) {
                newPath.push_back(curPoint);
            }
            prevPoint = curPoint;
            curPoint = nextPoint;
            nextPoint = getNext(curPoint.col, curPoint.row, prevPoint.col, prevPoint.row);
        }
        //存放终点
        newPath.push_back(curPoint);
        this->pathList[idx] = newPath;
        QMessageBox::information(this, "提示", "保存当前路径成功!");
        //一旦添加Path, EnemyInfoList也要跟着改
        this->enemyInfoList.resize(pathList.size());
        this->showEnemyInfo();
    });
    connect(ui->pb_addPath, &QPushButton::clicked, [=](){//添加新的路径
        vector<ps> newPath;
        this->pathList.push_back(newPath);
        //comboBox添加item
        ui->comboBox->addItem(QString::number(this->pathList.size()));
        ui->comboBox->setCurrentIndex(this->pathList.size()-1);
    });
    connect(ui->pb_export, &QPushButton::clicked, [=](){//写入当前地图至文件
        //覆盖之前文件
        QString fp = ui->l_fp->text();
        QFile file(fp);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "error!file not exists!";
            return ;
        }
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << this->colNum << " " << this->lineNum << endl;
        out << this->pathList.size() << endl;
        for(int i = 0; i < this->pathList.size(); i++) {
            out << this->pathList[i].size() << " ";
            for(int j = 0; j < pathList[i].size(); j++) {
                out << "(" << pathList[i][j].row << "," <<pathList[i][j].col << ") ";
            }
            out << endl;
        }
        for(int i = 0; i < this->enemyInfoList.size(); i++) {
            out << this->enemyInfoList[i].size() << " ";
            for(int j = 0; j < enemyInfoList[i].size(); j++) {
                out << "(" << enemyInfoList[i][j].type << "," <<enemyInfoList[i][j].num << ") ";
            }
            out << endl;
        }
        //文件写
        file.close();
        QMessageBox::information(this, "提示", "保存成功!");
        emit mapUpdated();
    });
    connect(ui->pb_new, &QPushButton::clicked, [=](){
        if(this->pbList.size() != 0 || this->pathList.size() != 0) {
            //说明之前已经加载了一张地图文件, 需要清空所有之前的信息.
            for(int i = 0; i < pbList.size(); i++) {
                for(int j = 0; j < pbList[i].size(); j++) {
                    delete this->pbList[i][j];
                }
            }
            this->lineNum = 0;
            this->colNum = 0;
            this->pbList.clear();
            this->pathList.clear();
            ui->comboBox->clear();
            this->enemyInfoList.clear();
            showEnemyInfo();
        }
        ui->spinBox_num->setMinimum(1);
        ui->spinBox_type->setRange(1,5);
        QString fp = getNewFilePath();
        QFile file(fp);
        if(file.exists()) {
            QMessageBox::warning(this, "失败", "该文件已经存在, 请选择打开!");
            return ;
        }
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
        //创建空文件, 关闭
        //初始化地图参数
        ui->l_fp->setText(fp);
        this->colNum = MAPMINWIDTH;
        this->lineNum = MAPMINHEIGHT;
        createGrids();
    });
    connect(ui->spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int val){
        //一旦修改行数, 就相当于开了一个新的文件, 之前的所有信息全部删除!
        if(this->pbList.size() != 0 || this->pathList.size() != 0) {
            for(int i = 0; i < pbList.size(); i++) {
                for(int j = 0; j < pbList[i].size(); j++) {
                    delete this->pbList[i][j];
                    qDebug() << "deleted: " <<i<<" " <<j;
                }
            }
            this->pbList.clear();
            this->pathList.clear();
            ui->comboBox->clear();
        }
        this->lineNum = val;
        createGrids();
    });
    connect(ui->spinBox_2, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int val){
        //一旦修改列数, 就相当于开了一个新的文件, 之前的所有信息全部删除!
        if(this->pbList.size() != 0 || this->pathList.size() != 0) {
            for(int i = 0; i < pbList.size(); i++) {
                for(int j = 0; j < pbList[i].size(); j++) {
                    delete this->pbList[i][j];
                }
            }
            this->pbList.clear();
            this->pathList.clear();
            ui->comboBox->clear();
        }
        this->colNum = val;
        createGrids();
    });
    connect(ui->tabWidget, &QTabWidget::tabBarClicked, [=](int idx){
        if(idx == 2) {
            this->drawPreview();
        }
        if(idx == 1) {
            this->showEnemyInfo();
        }
    });
    connect(ui->pb_addItem, &QPushButton::clicked, [=](){
        int pathIdx = ui->comboBox_2->currentIndex();
        int type = ui->spinBox_type->value();
        int num = ui->spinBox_num->value();
        QTreeWidgetItem *cur = new QTreeWidgetItem(ui->treeWidget->topLevelItem(pathIdx));
        cur->setText(0, QString::number(type));
        cur->setText(1, QString::number(num));
        ui->treeWidget->insertTopLevelItem(pathIdx, cur);
        enemyInfo info;
        info.num = num;
        info.type = type;
        this->enemyInfoList[pathIdx].push_back(info);
    });
    connect(ui->pb_clear, &QPushButton::clicked, [=](){
        if(QMessageBox::warning(this, "确认", "您确定要删除所有的敌人信息吗?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            for(int i = 0; i < enemyInfoList.size(); i++) {
                enemyInfoList[i].clear();
            }
            ui->treeWidget->clear();
            //但是要恢复Top
            showEnemyInfo();
        }
    });
}

MakeMap::~MakeMap()
{
    delete ui;
}

QString MakeMap::getNewFilePath()
{
    QString curPath = QDir::currentPath();
    QString fp_config = curPath + "/info/config.txt";
    QFile config(fp_config);
    config.open(QIODevice::ReadOnly);
    int curLevel, totLevel;
    QString buffer;
    QTextStream fin(&config);
    fin >> buffer;
    totLevel = buffer.toInt();
    fin >> buffer;
    curLevel = buffer.toInt();
    //那么创建的文件就是totLevel;
    QString ret = curPath + "/info/level" + QString::number(totLevel) + ".txt";
    qDebug() << ret;
    return ret;
}
