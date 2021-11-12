#include "swidget.h"
#include<QPushButton>
SWidget::SWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(300, 300);
    this->setWindowTitle("查询窗口");
    QPushButton *btn = new QPushButton("回退", this);
    connect(btn, &QPushButton::clicked, [=](){
        emit this->back();
    });

}
