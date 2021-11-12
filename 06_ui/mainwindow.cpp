#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QAction>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QFontDialog>
#include<QColorDialog>
#include<QFileDialog>
#define N 0
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    connect(ui->actionnew,&QAction::triggered,[=](){
        //
        qDebug() << "新建文件" << endl;
    });

#if N
    //模态对话框，带阻塞
    QDialog *dial = new QDialog(this);
    dial->resize(200,100);
    dial->exec(); // 这里
    qDebug() << "显示模态对话框" << endl;

    //非模态对话框，不带阻塞
    //模态对话框，带阻塞
    QDialog *dial = new QDialog(this);
    dial->resize(200,100);
    dial->show(); // 这里
    qDebug() << "显示模态对话框" << endl;

    QMessageBox::critical(this,"错误","致命错误");
    QMessageBox::information(this,"信息","信息提示");
    //QMessageBox::question(this,"询问","你还继续吗");
    //QMessageBox::StandardButton ret;
    int ret;
    ret = QMessageBox::question(this,"询问","你还继续吗",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
    if(ret == QMessageBox::Save) {
        qDebug() << "用户选择了保存" << endl;
    }
    else {
        qDebug() << "用户选择了取消" << endl;
    }

    bool isSuccess;
    QFont font;
    font = QFontDialog::getFont(&isSuccess,QFont("微软雅黑 Light"),this);
    qDebug() << isSuccess << endl;
    if (isSuccess) {
        qDebug() << "加粗" << font.bold() << "字体大小" << font.pointSize() << endl;
    }

    QColor color;
    color = QColorDialog::getColor();
    qDebug() << "r, g, b" << color.red() << color.green() << color.blue() << endl;
#else
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),"C:\\Users\\ethan\\Pictures\\web",tr("Images (*.png *.xpm *.jpg)")); // 有bug，只能看到最后一个扩展名的图片
    qDebug() << fileName << endl;
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

