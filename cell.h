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


class CellImage :  public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int row;
    int col;
    STATUS_SELL type;
    CellImage(int row,int col,STATUS_SELL type);
    QTimer timer;
    int activeIndex;
    QVector<QPixmap>pixmaps;
    void startAnimation();
    void updateType(STATUS_SELL type);
public slots:
    void updateTime();

};
#endif // CELL_H
