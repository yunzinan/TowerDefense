#include "document.h"
#include "ui_document.h"

document::document(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::document)
{
    ui->setupUi(this);
    setFixedSize(2500, 1000);
    ui->label_penguine->setPixmap(QPixmap(":/new/prefix1/assets/enemy/01.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_wizard->setPixmap(QPixmap(":/new/prefix1/assets/enemy/02.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_vanguard->setPixmap(QPixmap(":/new/prefix1/assets/enemy/03.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_dragonMaster->setPixmap(QPixmap(":/new/prefix1/assets/enemy/04.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_cloudCat->setPixmap(QPixmap(":/new/prefix1/assets/enemy/05.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_tower->setPixmap(QPixmap(":/new/prefix1/assets/tower/1.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_remoteTower_2->setPixmap(QPixmap(":/new/prefix1/assets/tower/3.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_superTower->setPixmap(QPixmap(":/new/prefix1/assets/tower/2.gif").scaledToWidth(ui->label_penguine->width()));
    ui->label_superRemoteTower->setPixmap(QPixmap(":/new/prefix1/assets/tower/4.gif").scaledToWidth(ui->label_penguine->width()));
}

document::~document()
{
    delete ui;
}
