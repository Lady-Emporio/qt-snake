#ifndef SCENE_H
#define SCENE_H

#include "allinclude.h"
#include "cell.h"

class Scene :public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(int rowsColsCount);
    QVector<QVector<CellImage*> >cells;
    QVector<CellImage*> canBeFood;
    QVector<CellImage*> snake;
    void createFood();
    WAY_PATH way;
    void keyPressEvent(QKeyEvent * keyEvent);
    QTimer timer;
    void endGame(bool win);
public slots:
    void updateTime();
};

#endif // SCENE_H
