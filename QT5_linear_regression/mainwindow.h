#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPaintEvent> //用于绘画事件
#include <QtGui> //引入用到的控件

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Paint();
    void PaintLine();

private:
    Ui::MainWindow *ui;
    QImage image;

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};

#endif // MAINWINDOW_H
