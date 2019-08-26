#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include "allinclude.h"
#include "scene.h"

class MyGraphicView : public QGraphicsView
{
public:
    Scene *scene;
    MyGraphicView(QWidget *parent = nullptr);
    void init(int rowsColsCount);

};

#endif // MYGRAPHICVIEW_H
