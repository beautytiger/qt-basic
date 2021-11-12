#include "widget.h"
#include "teacher.h"
#include "student.h"
#include<QPushButton>

#define N 1
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800, 600);
    //实例化老师
    Teacher *tea = new Teacher(this);
    //实例化学生
    Student *stu = new Student(this);

#if N
    //建立关系
    void (Teacher::*p1)() = &Teacher::hungry;
    void (Student::*p2)() = &Student::treat;
    connect(tea, p1, stu, p2);
#else
    //通过函数指针，明确哪个信号
    void (Teacher::*p1)(QString foodName) = &Teacher::hungry;
    void (Student::*p2)(QString foodName) = &Student::treat;
    connect(tea, p1, stu, p2);
#endif
    //下课了老师就饿
    QPushButton *btn = new QPushButton("下课", this);
    //信号触发信号
    connect(btn, &QPushButton::clicked,tea, p1);
/*
    // emit信号
    connect(btn, &QPushButton::clicked, [=](){
        //下课函数，发出饿的信号
#if N
        emit tea->hungry();
#else
        emit tea->hungry("干锅牛蛙");
#endif
    });
*/
}

Widget::~Widget()
{
}

