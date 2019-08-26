#ifndef CELL_H
#define CELL_H

#include "allinclude.h"

class Cell : public QGraphicsRectItem
{
public:
    int row;
    int col;
    STATUS_SELL type;
    Cell(int row,int col,STATUS_SELL type);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // CELL_H
