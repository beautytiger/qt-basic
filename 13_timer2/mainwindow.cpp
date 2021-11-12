#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //开启两个定时器
    this->id1 = this->startTimer(1000);
    this->id2 = this->startTimer(2000);

    //创建一个定时器对象
    QTimer *time = new QTimer(this);
    connect(time, &QTimer::timeout,[=](){
        static int num = 0;
        ui->label_3->setText(QString::number(num++));
    });
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        time->start(1000);
    });
    connect(ui->pushButton_2, &QPushButton::clicked,[=](){
        time->stop();
    });

    //通过singleshot完成延时
    QTimer::singleShot(5000,[=](){
        ui->label_4->setText("我喜欢你");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//定时器事件唯一
void MainWindow::timerEvent(QTimerEvent *e)
{
    static int num1 = 0;
    static int num2 = 0;
    //需要通过timerid判断是哪个id触发的
    if(e->timerId() == this->id1)
    {
        ui->label->setText(QString::number(num1++));
    }
    else if (e->timerId() == this->id2)
    {
        ui->label_2->setText(QString::number(num2++));
    }
}
