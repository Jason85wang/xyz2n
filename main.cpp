#include "xyz2dat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个的对象
    QApplication a(argc, argv);
    //应用程序对象
    xyz2dat w;
    //显示程序
    w.show();
    //进入消息循环
    return a.exec();
}
