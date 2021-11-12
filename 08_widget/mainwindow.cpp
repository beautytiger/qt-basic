#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRadioButton>
#include<QDebug>
#include<QListWidgetItem>
#include<QListWidget>
#include<QTreeWidget>
#include<QTableWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置单选框默认被选中
    ui->male->setChecked(true);
    ui->unmarried->setChecked(true);
    //设置触发事件
    connect(ui->female, &QRadioButton::clicked,[=](){
        qDebug() << "选中女" << endl;
    });
    connect(ui->unmarried, &QRadioButton::clicked,[=](){
        qDebug() << "选中未婚" << endl;
    });

    //列表控件
    //单个添加
    QListWidgetItem *item = new QListWidgetItem("静夜思");
    ui->listWidget->addItem(item);

    //添加列表
    QStringList list;
    list << "窗前明月光" << "疑是地上霜" << "举头望明月" << "低头思故乡";
    ui->listWidget->addItems(list);

    //添加单击响应事件
    connect(ui->listWidget, &QListWidget::itemClicked, [=](QListWidgetItem *item){
        qDebug() << item->text() << endl;
    });

    //树控件
    //设置头信息
    QStringList hlist;
    hlist << "英雄" << "介绍" ;
    ui->treeWidget->setHeaderLabels(hlist);
    //设置顶层控件
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"斧王");
    ui->treeWidget->addTopLevelItem(item1);
    item1->addChild(new QTreeWidgetItem(QStringList()<<"力量"<<"坦克"));

    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"小黑");
    ui->treeWidget->addTopLevelItem(item2);
    item2->addChild(new QTreeWidgetItem(QStringList()<<"敏捷"<<"输出"));

    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"风行");
    ui->treeWidget->addTopLevelItem(item3);
    item3->addChild(new QTreeWidgetItem(QStringList()<<"智力"<<"控制"));

    //树控件交互
    connect(ui->treeWidget, &QTreeWidget::itemClicked, [](QTreeWidgetItem *it, int col){
        qDebug() << it->text(col).toUtf8().data() << endl;
    });

    //表格控件
    //设置行数，列数
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(5);
    //设置表头信息
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"英雄"<<"属性"<<"角色"); // 参数为匿名对象
    //表格添加内容
    QStringList name;
    name << "斧王" << "小黑" << "风行" << "沙王" << "末日" ;
    QStringList prop;
    prop << "力量" << "敏捷" << "智力" << "力量" << "力量" ;
    for(int i=0; i<5; i++) {
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(prop[i]));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(i+20)));
    }
    //交互
    connect(ui->tableWidget, &QTableWidget::itemClicked, [=](QTableWidgetItem *item){
        qDebug() << item->text() << endl;
    });

    connect(ui->tableWidget, &QTableWidget::cellClicked, [=](int row, int col){
        qDebug() << "row, col" << row << col << endl;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

