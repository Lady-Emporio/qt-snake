#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *mainWidget=new QWidget(this);
    QHBoxLayout * mainLayout=new QHBoxLayout();
    QVBoxLayout * leftLayout=new QVBoxLayout();
    QVBoxLayout * rightLayout=new QVBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    view = new MyGraphicView(mainWidget);
    leftLayout->addWidget(this->view);

    QPushButton *debugMap=new QPushButton("d Map",mainWidget);
    connect(debugMap, SIGNAL(clicked()), this, SLOT(on_debugMap_clicked()));
    QPushButton *start=new QPushButton("Start",mainWidget);
    connect(start, SIGNAL(clicked()), this, SLOT(on_start_clicked()));
    rowsCols=new QLineEdit("10",mainWidget);
    rowsCols->setInputMask("D0");


    rightLayout->addWidget(start);
    rightLayout->addWidget(rowsCols);
    rightLayout->addWidget(debugMap);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_debugMap_clicked()
{

}

void MainWindow::on_start_clicked()
{
    int rowsColsCount=rowsCols->displayText().toInt();
    this->view->init(rowsColsCount);
}
