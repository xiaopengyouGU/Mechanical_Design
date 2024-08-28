#include "mechanicaldesign.h"
#include <QApplication>
#include <QSplashScreen>
#include<QLabel>
#include<QHBoxLayout>
#include<QThread>
#include<QScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建欢迎界面
    QLabel* hello = new QLabel;
    QPixmap pic(":/images/images/hello.jpg");
    hello->resize(600,400);
    hello->setPixmap(pic);
    //将欢迎界面移动屏幕中间
    QScreen* screen = a.primaryScreen(); //主界面
    int W = screen->size().width(), H = screen->size().height();
    hello->move((W - hello->width()) / 2, (H - hello->height()) / 2);
    //显示欢迎界面，持续3.5秒
    hello->show();
    QThread::msleep(3500);  //
    hello->close();
    delete hello;
    //开始正常操作
    MechanicalDesign w;
    w.show();

    return a.exec();
}
