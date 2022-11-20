#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

