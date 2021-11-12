#include "widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("信号测试");
    this->resize(800, 600);

    QPushButton *btn1=new QPushButton("关闭",this);
    //单击btn1关闭主窗口
    connect(btn1,&QPushButton::clicked, this, &QWidget::close);

    //lambda表达式
    QPushButton *btn2=new QPushButton("点我", this);
    btn2->move(400, 300);
    connect(btn2, &QPushButton::clicked, this, [=](){
        // 获取按钮上的文本
        QString text = btn2->text();
        qDebug() << text << endl;
        //设置按钮文本
        btn2->setText("已经点了");
    });
}

Widget::~Widget()
{
}

