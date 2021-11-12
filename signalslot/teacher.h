#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals: //自定义信号函数
    // 定义信号的规则：
    // 在signals下方
    // 返回值类型为void，只需声明，不需实现，可以有参数，可以被重载
    void hungry();
    //信号发出的参数会被槽函数接收
    void hungry(QString foodName);

};

#endif // TEACHER_H
