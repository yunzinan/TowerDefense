#ifndef MAPGRID_H
#define MAPGRID_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QPixmap>

//该类处理路径上的需要点击的格子
class MapGrid: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int row;
    int col;
    float sideLen;
    QPixmap pix;

public:
    MapGrid(int row, int col, float sideLen, QString pixPath):row(row), col(col), sideLen(sideLen) {
        this->pix = QPixmap(pixPath);
        setFlag(QGraphicsItem::ItemIsSelectable);
        setFlag(QGraphicsItem::ItemIsFocusable);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPainterPath shape() const override;
};
#endif // MAPGRID_H
