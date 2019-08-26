#include "cell.h"

Cell::Cell(int row, int col, STATUS_SELL type)
    :row(row),col(col),type(type)
{
    setRect(SIZE_SELL*row,SIZE_SELL*col,SIZE_SELL,SIZE_SELL);
    this->setBrush(Qt::darkGreen);
    this->setAcceptHoverEvents(true);
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setBrush(Qt::green);
}
void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    this->setBrush(Qt::darkGreen);
}
