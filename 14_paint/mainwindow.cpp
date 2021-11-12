#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //定义一个画家
    QPainter *painter = new QPainter(this);
    //定义图片控件
    QPixmap pix;
    pix.load(":/image/08c64505c9f3075335e7ff79c3a174a6.jpeg");
    //修改图片大小
    pix.scaled(this->width(),this->height());

    //画家在主窗口绘画
    painter->drawPixmap(0,0, this->width(), this->height(), pix);
}

