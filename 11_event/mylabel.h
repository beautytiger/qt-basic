#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    //重写鼠标进入事件
    virtual void enterEvent(QEvent *event);
    //离开事件
    virtual void leaveEvent(QEvent *event);

    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *event);
    //鼠标移动
    virtual void mouseMoveEvent(QMouseEvent *event);

    //重写事件分发器
    virtual bool event(QEvent *e);

    //声明事件过滤器函数
    //watched：事件发生的控件
    //event：控件产生的具体事件
    virtual bool eventFilter(QObject *watched, QEvent *event);


signals:

};

#endif // MYLABEL_H
