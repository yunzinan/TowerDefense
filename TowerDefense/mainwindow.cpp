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
            }
        });
        this->hide();
        game->show();
    });
//    qDebug() << QDir::currentPath();
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
    file.close();
}

