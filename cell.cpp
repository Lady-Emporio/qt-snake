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


CellImage::CellImage(int row, int col, STATUS_SELL type)
    :QObject(),row(row),col(col),type(type)
{
    activeIndex=0;

    switch (type){
    case WALL:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/wall.png") );
        break;
    case EMPTY:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/0.png") );
        break;
    case FOOD:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/food.png") );
        break;
    case SNAKE:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/5.png") );
        break;
    };

    //this->setX( (SIZE_SELL+5)*row);
    this->setX( (SIZE_SELL)*row);
    //this->setY( (SIZE_SELL+5)*col);
    this->setY( (SIZE_SELL)*col);

    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/0.png"));
    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/1.png"));
    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/2.png"));
    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/3.png"));
    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/4.png"));
    pixmaps.append(QPixmap("C:/Users/al/Pictures/sprite my/5.png"));

    this->timer.setInterval(100 );//1 sec 1000 ms
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

void CellImage::startAnimation()
{
    this->timer.start();
}

void CellImage::updateType(STATUS_SELL type)
{
    switch (type){
    case WALL:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/wall.png") );
        break;
    case EMPTY:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/0.png") );
        activeIndex=5;
        break;
    case FOOD:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/food.png") );
        break;
    case SNAKE:
        this->setPixmap( QPixmap("C:/Users/al/Pictures/sprite my/5.png") );
        activeIndex=0;
        break;
    };
    this->type=type;
}

void CellImage::updateTime()
{
    //begin set type then animation
    if (EMPTY==type){
        --activeIndex;
        if (0>=activeIndex){
            activeIndex=0;
            timer.stop();
        }

        this->setPixmap( pixmaps[activeIndex]);
    }else if (SNAKE==type){
        ++activeIndex;
        if (5<=activeIndex){
            activeIndex=5;
            timer.stop();
        }
        this->setPixmap( pixmaps[activeIndex]);
    }

}
