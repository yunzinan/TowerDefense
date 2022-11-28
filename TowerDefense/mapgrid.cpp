#include "mapgrid.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneEvent>

void MapGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, sideLen, sideLen, pix);
}

QRectF MapGrid::boundingRect() const
{
    return QRectF(0, 0, sideLen, sideLen);
}

void MapGrid::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Item mouseDoubleClickEvent!";
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void MapGrid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Item : press";
    QGraphicsItem::mouseReleaseEvent(event);
}

QPainterPath MapGrid::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
