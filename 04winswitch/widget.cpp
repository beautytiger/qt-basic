#include "widget.h"
#include<QPushButton>
#include "swidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,600);
    this->setWindowTitle("登录");

    SWidget *s = new SWidget();
    QPushButton *btn = new QPushButton("下一页", this);
    connect(btn, &QPushButton::clicked, [=](){
        this->hide();
        s->show();
    });
    connect(s, &SWidget::back,[=](){
        s->hide();
        this->show();
    });
}

Widget::~Widget()
{
}

