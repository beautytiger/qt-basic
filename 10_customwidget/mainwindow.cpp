#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //单击button设置值
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        ui->widget->mySetValue(50);
    });
    //单击button获得进度条的值
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->myGetValue();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

