#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "allinclude.h"
#include "mygraphicview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyGraphicView *view;
    QLineEdit *rowsCols;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_debugMap_clicked();
    void on_start_clicked();
};

#endif // MAINWINDOW_H
