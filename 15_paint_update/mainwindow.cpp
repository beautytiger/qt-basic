#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(1920,1080);

    //将button移动到下方中间位置
    ui->pushButton->resize(100,50);
    ui->pushButton->move(
        this->width()/2-ui->pushButton->width()/2,
        this->height()-ui->pushButton->height()
    );

    connect(ui->pushButton, &QPushButton::clicked,[=](){
        //重新加载绘图事件
        this->update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    static int x = 0;
    //定义一个画家
    QPainter *painter = new QPainter(this);
    //定义图片控件
    QPixmap pix;
    pix.load(":/image/3.jpg");
    //修改图片大小，有问题啊，没有改到目标大小
    pix.scaled(this->width()*0.5,this->height()*0.5);

    //画家在主窗口绘画
    painter->drawPixmap(x,0, pix.width(), pix.height(), pix);
    x += 10;
    if (x >= this->width()) {
        x = 0;
    }
}

