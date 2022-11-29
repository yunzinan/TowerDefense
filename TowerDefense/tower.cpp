#include "tower.h"
#include "config.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneEvent>

QRectF Tower::boundingRect() const
{
    return QRectF(0, 0, this->sideLen, this->sideLen);
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(this->boundingRect(), movie.currentImage());
}

QPainterPath Tower::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "tower pressed!";
}

void Tower::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton) {
        emit deleteSignal(row, col);
    }
    return QGraphicsItem::mouseDoubleClickEvent(event);
}
