#ifndef MAPGRID_H
#define MAPGRID_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QPixmap>
#include "config.h"

//该类处理路径上的需要点击的格子
class MapGrid: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    int row;
    int col;
    float sideLen;
    QPixmap pix;
    bool isGrid;//判断是否为节点路径
    bool isVacant;//是否能够放置
public:
    enum {Type = UserType + 4};
    MapGrid(int row, int col, float sideLen, QString pixPath):row(row), col(col), sideLen(sideLen) {
        this->pix = QPixmap(pixPath);
        setFlag(QGraphicsItem::ItemIsSelectable);
        setFlag(QGraphicsItem::ItemIsFocusable);
        this->isGrid = false;
        this->isVacant = true;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPainterPath shape() const override;
    void setVacancy(bool isVacant);
    void setGrid(bool isGrid) {this->isGrid = isGrid;}
    int type() const override {return Type;}
signals:
    void createTowerSignal(int row, int col);
};
#endif // MAPGRID_H
