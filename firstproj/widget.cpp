#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置主窗口的标题
    this->setWindowTitle("我的窗口标题");

    //固定窗口
    this->setFixedSize(1920,1080);

    //在窗口上创建一个按钮
    //默认控件会显示在窗口的左上角
    QPushButton *button = new QPushButton("我的按钮",this);

    QPushButton *button1 = new QPushButton("你的按钮",this);
    //位置以左上角为基准
    button1->move(900,500);
}

Widget::~Widget()
{
}

