#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //启动定时器事件
    this->startTimer(1000); //单位是毫秒
}

MainWindow::~MainWindow()
{
    delete ui;
}

//重写定时器事件
//在构造函数中启动定时器
void MainWindow::timerEvent(QTimerEvent *e)
{
    static int time = 0;
    ui->label->setText(QString::number(time++));
}

