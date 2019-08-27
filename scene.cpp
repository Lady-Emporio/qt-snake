#include "scene.h"

Scene::Scene(int rowsColsCount)
{ 
    int maxValue=rowsColsCount+2;

    for(int row=0;row!=maxValue;++row){
        QVector<CellImage*> colVec;

        for(int col=0;col!=maxValue;++col){
            CellImage *cell=new CellImage(row,col,EMPTY);
            canBeFood.append(cell);
            if (0==row || 0==col || maxValue-1==row || maxValue-1==col){
                cell->updateType(WALL);
                canBeFood.removeLast();
            }
            colVec.append(cell);
            this->addItem(cell);
        }
        cells.append(colVec);
    }
    this->setBackgroundBrush(Qt::blue);
    way=DOWN;

    createFood();

    int row=qrand() % canBeFood.size();
    auto beSnake=canBeFood[row];
    beSnake->updateType(SNAKE);
    snake.append(beSnake);
    canBeFood.removeAt(row);

    this->timer.setInterval(1000 );//1 sec 1000 ms
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));

}

void Scene::createFood()
{
    int row=qrand() % canBeFood.size();
    canBeFood[row]->updateType(FOOD);
    canBeFood.removeAt(row);

}

void Scene::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key()){
        case Qt::Key_Down: way=DOWN;qDebug()<<"DOWN";break;
        case Qt::Key_Right: way=RIGHT;qDebug()<<"RIGHT";break;
        case Qt::Key_Up: way=TOP;qDebug()<<"TOP";break;
        case Qt::Key_Left: way=LEFT;qDebug()<<"LEFT";break;
        case Qt::Key_Escape:
            if (timer.isActive()){
                timer.stop();
            }else{
                this->timer.start();
            }
          break;
    }
}

void Scene::endGame(bool win)
{
    this->timer.stop();
    if(false==win){
        this->setBackgroundBrush(Qt::red);
    }else{
        this->setBackgroundBrush(Qt::black);
    }
}

void Scene::updateTime()
{
    if (0==canBeFood.size()){
        endGame(true);
        return;
    }
    CellImage *nextCell;
    CellImage * last=snake.last();

    if(DOWN==way){
        nextCell=cells[last->row][last->col+1];
    }else if(RIGHT==way){
        nextCell=cells[last->row+1][last->col];
    }else if(TOP==way){
        nextCell=cells[last->row][last->col-1];
    }else if(LEFT==way){
        nextCell=cells[last->row-1][last->col];
    }

    if (WALL==nextCell->type || SNAKE==nextCell->type){
        endGame(false);
    }else if (FOOD==nextCell->type){
        nextCell->updateType(SNAKE);
        canBeFood.removeOne(nextCell);
        snake.append(nextCell);
        this->createFood();
    }else if (EMPTY==nextCell->type){
        auto first=snake.first();
        first->updateType(EMPTY);
        first->startAnimation();
        canBeFood.append(first);
        snake.pop_front();

        nextCell->updateType(SNAKE);
        snake.append(nextCell);
        nextCell->startAnimation();
        canBeFood.removeOne(nextCell);
    }
}


