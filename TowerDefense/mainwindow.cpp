#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

void MainWindow::loadInfo()
{
    QString curPath = QDir::currentPath();
    QString fp_config = curPath + "/info/config.txt";
    qDebug() << fp_config;
    QFile file(fp_config);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error! file not exists!";
        //如果不存在config文件, 那就创建文件
        file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << 0 << " " << 0;//关卡数; 当前游戏解锁到第几关.
        file.close();
        return ;
    }
    QString buffer;
    QTextStream fin(&file);
    fin >> buffer;
    this->totLevel = buffer.toInt();
    fin >> buffer;
    this->curLevel = buffer.toInt();
//    qDebug() << totLevel << " " << this->curLevel;
    QVariant v(0);
    for(int i = 0; i < this->totLevel; i++) {
        ui->comboBox->addItem(QString::number(i+1));
        if(i > curLevel) ui->comboBox->setItemData(i, v, Qt::UserRole-1);
    }
    file.close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("菜单");
    setMinimumSize(QSize(500, 800));
    connect(ui->pb_makemap, &QPushButton::clicked, [=](){
        qDebug() << "make_map";
        MakeMap *m = new MakeMap();
        connect(m, &MakeMap::returnSignal, [=](){
            qDebug() << "return signal released!";
            this->show();
            m->hide();
            delete m;
        });
        connect(m, &MakeMap::mapUpdated, [=](){
           //尝试更新当前的comboBox;
           //先获取文件数量
            qDebug() << "mapUpdated!";
            QDir *dir=new QDir(QDir::currentPath() + "/info");
               QStringList filter;
               filter<<"*.txt";
               dir->setNameFilters(filter);
               QFileInfoList fileInfoList=dir->entryInfoList(filter);
            if(fileInfoList.size()-2 > this->totLevel) {//说明产生了新的地图
                this->totLevel = fileInfoList.size() - 2;//更新totLevel
                QVariant v(0);
                ui->comboBox->clear();
                for(int i = 0; i < this->totLevel; i++) {
                    ui->comboBox->addItem(QString::number(i+1));
                    if(i > curLevel) ui->comboBox->setItemData(i, v, Qt::UserRole-1);
                }
                //重新写入config文件
                QString curPath = QDir::currentPath();
                QString fp_config = curPath + "/info/config.txt";
                qDebug() << fp_config;
                QFile file(fp_config);
                if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    qDebug() << "error!file not exists!";
                    return ;
                }
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out << this->totLevel << " " << this->curLevel;
                file.close();
            }
        });
        m->show();
        qDebug() << "m: show!";
        this->hide();
    });
    connect(ui->pb_start, &QPushButton::clicked, [=](){
        this->game = new GameWindow(ui->comboBox->currentIndex());
        connect(game, &GameWindow::returnSignal, [=](){
            this->show();
            delete game;
        });
        connect(game, &GameWindow::winSinal, [=](int level){
            this->show();
            delete game;
            //解锁level+1关, 如果存在并且没有解锁的话
            if(level+1 < totLevel && level+1 > curLevel) {
                curLevel = level + 1;
                QVariant v(0);
                ui->comboBox->clear();
                for(int i = 0; i < this->totLevel; i++) {
                    ui->comboBox->addItem(QString::number(i+1));
                    if(i > curLevel) ui->comboBox->setItemData(i, v, Qt::UserRole-1);
                }
                //保存进度
                QString curPath = QDir::currentPath();
                QString fp_config = curPath + "/info/config.txt";
                qDebug() << fp_config;
                QFile file(fp_config);
                if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    qDebug() << "error!file not exists!";
                    return ;
                }
                QTextStream out(&file);
                out.setCodec("UTF-8");
                out << this->totLevel << " " << this->curLevel;
                qDebug() << this->curLevel << "curLevel";
                file.close();
            }
        });
        this->hide();
        game->show();
    });
    //若info子文件夹不存在, 则创建
    QString folder_name("info");
    QDir dir(QDir::currentPath());    //初始化dir为当前目录
    if(!dir.exists(folder_name))    //如果info文件夹不存在
    {
        dir.mkdir(folder_name);    //创建文件夹（名为Images）

        qDebug()<<QString("文件夹%1创建成功！").arg(folder_name);
    }
//    qDebug() << QDir::currentPath();
    connect(ui->pb_shop, &QPushButton::clicked, [=](){
        this->store = new Store();
        connect(store, &Store::returnSignal, [=](){
            this->show();
            delete store;
            store = nullptr;
        });
        store->show();
        this->hide();
    });
    loadInfo();

}

MainWindow::~MainWindow()
{
    delete ui;
    //保存进度
    QString curPath = QDir::currentPath();
    QString fp_config = curPath + "/info/config.txt";
    qDebug() << fp_config;
    QFile file(fp_config);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "error!file not exists!";
        return ;
    }
    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << this->totLevel << " " << this->curLevel;
    qDebug() << this->curLevel << "curLevel";
    file.close();
}

