#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>
#include<QPixmap>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,600);
    this->setWindowTitle("菜单栏");

    //创建一个菜单栏
    QMenuBar *menuBar = new QMenuBar(this);
    //将菜单栏添加到主窗口中
    this->setMenuBar(menuBar);

    QMenu *mfile = new QMenu("文件", this);
    QMenu *medit = new QMenu("编辑", this);
    QMenu *mtool = new QMenu("工具", this);

    menuBar->addMenu(mfile);
    menuBar->addMenu(medit);
    menuBar->addMenu(mtool);

    QAction *mnew = new QAction("新建", this);
    QAction *msave = new QAction("保存", this);

    mfile->addAction(mnew);
    mfile->addSeparator(); // 插入分割线
    mfile->addAction(msave);

    //菜单项设置快捷键
    mnew->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    msave->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    //菜单项动起来
    connect(mnew,&QAction::triggered,[=](){
        qDebug() << "新建文件" << endl;
    });

    connect(msave,&QAction::triggered,[=](){
        qDebug() << "保存文件" << endl;
    });

    //工具栏
    QToolBar *tool = new QToolBar(this);
    this->addToolBar(tool);

    tool->addAction(mnew);
    tool->addSeparator();
    tool->addAction(msave);

    //工具栏默认允许浮动， 可以禁用浮动
    tool->setFloatable(false);
    //工具栏停靠位置
    tool->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);

    //状态栏
    QStatusBar *mstatus = new QStatusBar(this);
    this->setStatusBar(mstatus);

    //
    QLabel *label1 = new QLabel("左侧提示信息", this);
    QLabel *label2 = new QLabel("右侧提示信息", this);

    mstatus->addWidget(label1);
    mstatus->addPermanentWidget(label2);

    //铆接部件
    QDockWidget *mdocke1 = new QDockWidget("顶部铆接部件",this);
    this->addDockWidget(Qt::TopDockWidgetArea, mdocke1);
    mdocke1->setAllowedAreas(Qt::TopDockWidgetArea);
    QDockWidget *mdocke2 = new QDockWidget("底部铆接部件",this);
    this->addDockWidget(Qt::BottomDockWidgetArea, mdocke2);
    mdocke2->setAllowedAreas(Qt::BottomDockWidgetArea);
    QDockWidget *mdocke3 = new QDockWidget("左侧铆接部件",this);
    this->addDockWidget(Qt::LeftDockWidgetArea, mdocke3);
    mdocke3->setAllowedAreas(Qt::LeftDockWidgetArea);

    //中心部件
    QTextEdit *mtext = new QTextEdit(this);
    mtext->setText("请输入内容...\n谢谢\n");
    this->setCentralWidget(mtext);

    //菜单项添加图标
    QPixmap pix;
    pix.load(":/image/myicon.jpg");
    mnew->setIcon(QIcon(pix));
}

MainWindow::~MainWindow()
{
}

