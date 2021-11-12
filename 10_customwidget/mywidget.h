#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    //提供设置slider value的接口
    void mySetValue(int value);
    //提供获取value的接口
    int myGetValue();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
