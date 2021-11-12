#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QString>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击登录，获取用户名密码
    connect(ui->loginBtn,&QPushButton::clicked,[=](){
        //获取用户名
        QString userName = ui->user->text();
        QString password = ui->password->text();

        qDebug() << "用户名" << userName << endl;
        qDebug() << "密码" << password << endl;
    });

    connect(ui->cancelBtn, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

