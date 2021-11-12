#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QBitmap>
#include<QImage>
#include<QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(2000, 1000);
#if 0
    //定义一个绘图设备
    QBitmap bit(200,200);
    //定义一个画家
    QPainter painter(&bit);
    //画图，注意，不是在当前窗口显示
    painter.drawEllipse(QPoint(100,100), 100,100);
    //保存图片
    bit.save("C:\\workspace\\qt-project\\16_draw\\pic01.jpg");
#endif
#if 0
    QImage img;
    img.load(":/image/6.jpg");
    int value = qRgb(255, 100, 100);
    for (int i=50;i<100;i++)
    {
        for (int j=50;j<100;j++)
        {
            img.setPixel(i,j, value);
        }
    }
    QPainter painter(&img);
    painter.drawEllipse(QPoint(100,100), 100,100);
    img.save("C:\\workspace\\qt-project\\16_draw\\pic02.jpg");
#endif
#if 0
    QPicture pic;
    QPainter painter;
    //记录绘图指令
    painter.begin(&pic);

    painter.drawEllipse(100,100,200,200);
    //结束记录绘图指令
    painter.end();
    //保存绘图过程
    pic.save("C:\\workspace\\qt-project\\16_draw\\pic.zl");
#endif


}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->drawLine(0,0,100,50);
    painter->drawLine(0,0,100,100);
    painter->drawLine(0,0,100,200);
    painter->drawLine(0,0,100,300);
    painter->drawLine(0,0,100,400);

    //设置画笔颜色
    painter->setPen(Qt::red);

    painter->drawLine(0,0,100,500);
    painter->drawLine(0,0,100,600);

    //画笔样式，颜色被重置了
    painter->setPen(Qt::DashDotDotLine);
    //画方形
    painter->drawRect(200,200, 400, 400);

    painter->drawRect(600,600, 400, 400);
    painter->drawRect(600,600, 600, 200);
    //画圆
    painter->drawEllipse(600,600, 400, 400);
    painter->drawEllipse(600,600, 600, 200);

#if 1
    //重现绘图指令
    QPicture pic;
    QPainter paint(this);
    //绘图设备加载绘图指令
    pic.load("C:\\workspace\\qt-project\\16_draw\\pic.zl");
    //画家根据绘图指令绘画
    paint.drawPicture(100,100, pic);
#endif

}

