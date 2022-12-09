#include "store.h"
#include "ui_store.h"
#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QTextStream>

void Store::loadInfo()
{
    QString fp = QDir::currentPath() + "/info/buff.txt";
    qDebug() << fp;
    QFile file(fp);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "buff.txt not exists!";
        file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << 0 << " " << 1.0 << " " << 1.0 << " " << 0 << " " << 0;
        file.close();
        return ;
    }
    QString buffer;
    QTextStream fin(&file);
    fin >> buffer;
    this->pts = buffer.toInt();
    fin >> buffer;
    this->atkRate = buffer.toFloat();
    fin >> buffer;
    this->hpRate = buffer.toFloat();
    fin >> buffer;
    this->freezeBombNum = buffer.toInt();
    fin >> buffer;
    this->bombNum = buffer.toInt();
    file.close();
}

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        if(this->pts >= 5) {
            pts -= 5;
            ui->label_pts->setText("当前积分:" + QString::number(this->pts));
            this->atkRate += 0.05;
ui->label_atk->setText(QString::number(this->atkRate) + "倍");
        }
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        if(this->pts >= 5) {
            pts -= 5;
            ui->label_pts->setText("当前积分:" + QString::number(this->pts));
            this->hpRate += 0.05;
            ui->label_hp->setText(QString::number(this->hpRate) + "倍");
        }
    });
    connect(ui->pushButton_3, &QPushButton::clicked, [=](){
        if(this->pts >= 1) {
            pts -= 1;
            ui->label_pts->setText("当前积分:" + QString::number(this->pts));
            this->freezeBombNum++;
            ui->label_fb->setText(QString::number(this->freezeBombNum) + "个");
        }
    });
    connect(ui->pushButton_4, &QPushButton::clicked, [=](){
        if(this->pts >= 1) {
            pts -= 1;
            ui->label_pts->setText("当前积分:" + QString::number(this->pts));
            this->bombNum++;
            ui->label_b->setText(QString::number(this->bombNum) + "个");
        }
    });
    connect(ui->pushButton_5, &QPushButton::clicked, [=](){
        //理论上是要弹窗扫码的.
        pts += 10;
        ui->label_pts->setText("当前积分:" + QString::number(this->pts));
    });
    loadInfo();
    ui->label_hp->setText(QString::number(this->hpRate) + "倍");
    ui->label_atk->setText(QString::number(this->atkRate) + "倍");
    ui->label_fb->setText(QString::number(this->freezeBombNum) + "个");
    ui->label_b->setText(QString::number(this->bombNum) + "个");
    ui->label_pts->setText("当前积分:" + QString::number(this->pts));
}

Store::~Store()
{
    delete ui;
    //写入数据
    QString fp = QDir::currentPath() + "/info/buff.txt";
    QFile file(fp);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "error! buff.txt not exists!";
        return ;
    }
    QTextStream out(&file);
    out.setCodec("UTF-8");
    out.setRealNumberPrecision(2);
    out << this->pts << " ";
    out << (qreal)this->atkRate << " " << (qreal)this->hpRate << " ";
    out << this->freezeBombNum << " " << this->bombNum;
    file.close();
}

void Store::closeEvent(QCloseEvent *event)
{
    emit returnSignal();
    event->accept();
}
