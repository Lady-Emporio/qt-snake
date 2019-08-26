#include "mygraphicview.h"

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{

}

void MyGraphicView::init(int rowsColsCount)
{
    scene=new Scene(rowsColsCount);
    this->setScene(scene);
}


