#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QComboBox>
#include<QDebug>
#include<QMovie>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //下拉列表添加选项
    QStringList list;
    list << "宝马" << "奔驰" << "奥迪" << "沃尔沃";
    ui->comboBox->addItems(list);
    //调整大小
    ui->comboBox->resize(200,40);
    //设置默认选项
    ui->comboBox->setCurrentIndex(2);

    //一旦信号发生重载，需要用函数指针匹配
    void (QComboBox::*p)(int) = &QComboBox::currentIndexChanged;

    connect(ui->comboBox, p,[=](int index){
        qDebug() << index << endl;
        qDebug() << ui->comboBox->currentText() << endl;
    });

    ui->label->setText("haha");
    qDebug() << ui->label->text() << endl;

    //设置图片
    QPixmap pix;
    pix.load(":/summer/retina/summer-01@2x.png");
    ui->label_2->setPixmap(pix);

    //播放动画
    QMovie *movie = new QMovie(":/gif/7.gif");
//    movie->setScaledSize(QSize(400,300));
    ui->label_3->setMovie(movie);
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        movie->start();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        movie->stop();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

