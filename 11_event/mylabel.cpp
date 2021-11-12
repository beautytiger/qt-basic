#include "mylabel.h"
#include<QDebug>
#include<QEvent>
#include<QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);

    //加载事件过滤器
    this->installEventFilter(this);
}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入了" << endl;
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开了" << endl;
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << "mousePressEvent左键按下" << endl;
    }
    else if (event->button() == Qt::RightButton){
        qDebug() << "mousePressEvent右键按下" << endl;
    }
    else {
        qDebug() << "mousePressEvent其他键按下了" << endl;
    }

}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    //默认情况鼠标必须按下才能移动
    qDebug() << "鼠标移动了" << endl;
    qDebug() << "全局坐标" << event->globalX() << event->globalY();
    qDebug() << "局部坐标" << event->x() << event->y();
}

//事件分发器
bool MyLabel::event(QEvent *e)
{
    //只处理鼠标按下事件
    if(e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "在事件分发器中鼠标单击了" << endl;
        //QEvent中没有坐标信息
        //需要进行类型转换
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        qDebug() << ev->x() << ev->y() << endl;
        return true; //当前事件已经处理，不需要继续下发
        //但是这里好像有bug啊，双击还是会传进去
    }
    //请调用父类的事件分发器处理其他事件
    return QLabel::event(e);
}

bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==this)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "事件过滤器中鼠标被单击了" << endl;
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);
            qDebug() << ev->x() << ev->y() << endl;
            return true;
        }
    }
    return QLabel::eventFilter(watched, event);
}
