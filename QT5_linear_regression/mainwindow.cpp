#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(600,300,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    Paint();
    PaintLine();
}

void MainWindow::Paint()
{
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点
    int pointx=35,pointy=280;//确定坐标轴起点坐标，这里定义(35,280)
    int width=580-pointx,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    //绘制坐标轴 坐标轴原点(35，280)
    painter.drawRect(5,15,600-10,280);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
    painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height

    QPen penPoint;
    penPoint.setColor(Qt::red);
    penPoint.setWidth(4);
   // painter.drawPoint(35,280);

    double Y[15] = {2.000,2.500,2.900,3.147,4.515,4.903,5.365,5.704,6.853,7.971,8.561,10.000,11.280,12.900,0};
    painter.setPen(penPoint);
    for(int i=0;i<14;i++)
    {
        painter.drawPoint(i*30+60,260-Y[i]*18);
    }

}

void MainWindow::PaintLine()
{
    QPainter painter(&image);
    double Y[15] = {2.000,2.500,2.900,3.147,4.515,4.903,5.365,5.704,6.853,7.971,8.561,10.000,11.280,12.900,0};
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(1);

    painter.setPen(pen);
    double alpha = 0.001;
    double theta[2] = {0,0};
    int ms=1000;
    double X[15];
    for (int i = 0; i < 15; ++i)
    {
        X[i] = i;
    }
    while(ms--)
    {
        double diff[2] = {0,0};

        for (int k = 0; k < 14; ++k)
        {
            diff[0] += (theta[0] + theta[1] * X[k])-Y[k];
            diff[1] += ((theta[0] + theta[1] * X[k])-Y[k])*X[k];
        }
        for(int k = 0;k < 2; ++k)
        {
                theta[k] = theta[k]-alpha*(diff[k]);
        }



    }
    double s0=theta[0]+theta[1]*(-1);
    double s1=theta[0]+theta[1]*(15);

    painter.drawLine(30,260-s0*18,510,260-s1*18);
}

MainWindow::~MainWindow()
{
    delete ui;
}
