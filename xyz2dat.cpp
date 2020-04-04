#include "xyz2dat.h"
#include "ui_xyz2dat.h"
#include <qpushbutton.h>
#include <qdebug.h>

//命名规范
//类名　首字母大写,单词和单词之间首字母大写
//函数名称　变量名称　首字母小写,单词和单词之间首字母大写
//快捷键 ctrl+/
//编译　ctrl+b
//运行　ctrl+r
//自动对齐　ctrl+i


xyz2dat::xyz2dat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::xyz2dat)
{
    ui->setupUi(this);
    //设置窗口标题
    setWindowTitle("xyz2dat 1.0 wangwangming535@163.com modify:2020.4.1 ");
    //设置窗口固定大小
    //    setFixedSize(800,600);
    //增加xyz2dat按钮功能
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->move(100,10);
    btn->resize(100,50);
    btn->setText("Exit");
    //xyz2dat按钮功能定义
    connect(btn,&QPushButton::clicked,this,[=](){
        this->close();
    });

    //第二个按钮功能
    QPushButton *btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->move(300,300);
    btn2->resize(20,20);
    btn2->setText("about");
    //xyz2dat按钮功能定义
    connect(btn2,&QPushButton::clicked,this,[=](){
        //使用自定函数处理
        fileReadxyz();
    });

}

xyz2dat::~xyz2dat()
{
    delete ui;
    //测试输出结果
    qDebug() << "主程序退出! send to github";
}

void xyz2dat::fileReadxyz()
{
    qDebug() <<" this is file read function add to github";
}
