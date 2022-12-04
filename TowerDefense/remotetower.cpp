#include "remotetower.h"
#include <QGraphicsSceneEvent>


void RemoteTower::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton) {
        ps state = getPos();
        emit this->deleteRemoteSignal(state.row, state.col);
    }
}
