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

MakeMap::MakeMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MakeMap)
{
    ui->setupUi(this);
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
        //文件写
        file.close();
        QMessageBox::information(this, "提示", "保存成功!");
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
        }
        QString dirPath = QFileDialog::getExistingDirectory(this,"请选择文件保存路径","./");
        if(dirPath.isEmpty()) return ;
        QString fp = dirPath + "/map.txt";
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
}

MakeMap::~MakeMap()
{
    delete ui;
}
