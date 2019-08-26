#include "scene.h"

Scene::Scene(int rowsColsCount)
{
    int maxValue=rowsColsCount+2;
    QVector<QVector<Cell*> >cells;

    for(int row=0;row!=maxValue;++row){
        QVector<Cell*> colVec;
        cells.append(colVec);
        for(int col=0;col!=maxValue;++col){
            Cell *cell=new Cell(row,col,EMPTY);
            if (0==row || 0==col || maxValue-1==row || maxValue-1==col){
                cell->type=WALL;
            }
            colVec.append(cell);
            this->addItem(cell);
        }
    }
    this->setBackgroundBrush(Qt::blue);
}

