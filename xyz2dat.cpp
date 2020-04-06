#include "xyz2dat.h"
#include "ui_xyz2dat.h"
#include <qpushbutton.h>
#include <qdebug.h>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

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
    //设置图片直接在ui编辑器中处理就好

    //设置窗口标题
    setWindowTitle("xyz2dat 1.0 wangwangming535@163.com modify:2020.4.1 ");
    //设置窗口固定大小
//    setFixedSize(600,400);
    //增加xyz2dat按钮功能
    /**
    第一个自定义按钮功能(测试用)
    关闭程序
    **/
//    QPushButton *btn = new QPushButton;
//    btn->setParent(this);
//    btn->move(300,300);
//    btn->resize(100,50);
//    btn->setText("Exit");
//    //xyz2dat按钮功能定义
//    connect(btn,&QPushButton::clicked,this,[=](){
//        this->close();
//    });

    /**
    第二个按钮功能
    程序版本功能更新说明
    **/
    QPushButton *btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->move(10,300);
    btn2->resize(20,20);
    btn2->setText("about");
    //xyz2dat按钮功能定义
    connect(btn2,&QPushButton::clicked,this,[=](){
        //说明文件编辑状态
        QString proinfo;
        proinfo = "wangwangming535@163.com tel:13476457809\n";
        proinfo.insert(1,"1-2020.4.1开始修改\n");
        proinfo.insert(1,"2- 2020.4.4将程序同步至github\n");
        proinfo.insert(1,"3- 2020.4.6增加对话框说明\n");
        proinfo.insert(1,"2020.4.6增加对话框说明\n");
        proinfo.insert(1,"2020.4.6增加对话框说明\n");
        proinfo.insert(1,"2020.4.6增加对话框说明\n");
        proinfo.insert(1,"2020.4.6增加对话框说明\n");

        showmodifyinfo(proinfo);
    });
   //XYZ2DAT工具栏的功能定义
    connect(ui->Act_axyz2dat,&QAction::triggered,this,[=](){
        //使用自定函数处理
        fileOpenx(1);
    });
}

xyz2dat::~xyz2dat()
{
    delete ui;
    //测试输出结果
    qDebug() << "主程序退出! send to github";
}

/**对取得的文件进行相应的数据处理
 *
 *
 * */
void xyz2dat::fileReadxyz()
{
    QByteArray array1;
    double line_number = 0;  //读取的行数
    QString linedata;
    //读取文件并放入控件中
    QFile filein(fname);
    filein.open(QIODevice::ReadOnly);
    for (int var = 0; var < 100; ++var) {
        array1 = filein.readLine();
        ui->textEdit_org->insertPlainText(array1);
        //识别与处理数字
        linedata=array1;

        QStringList str_list = linedata.split(QRegExp("\\W+"));
        for (int i=0; i<str_list.length(); ++i) {
             ui->textBro_out->append(str_list[i]);
            ui->textBro_out->append(str_list[i]);

        }
        ++line_number;
//        ui->textEdit_org->insert(array1);
    }

    filein.close();
    qDebug() <<" 打开文件名为:"<<fname;
}

/**　处理的第一步,选择文件,并取得文件路径与文件名
*参数一,文件类型过滤,默认为所有文件
**/
void xyz2dat::fileOpenx(int type=0)
{
    QString filefilt;
    //文件对话框
    switch (type) {
        case 1:
            //xyz与dat格式互转
            filefilt = tr("xyz data Files (*.xyz *.dat *.txt)");
        break;
    default:
        filefilt = tr("all Files (*.*)");
    }
    fname = QFileDialog::getOpenFileName(this,"打开文件","\\",filefilt );
    //将文件名显示在状态栏中
    ui->statusbar->showMessage(fname);
    //输出调试信息
    qDebug() <<" 打开文件名为:"<<fname;
}
void xyz2dat::showmodifyinfo(QString info1)
{
    //模态对话框
//        QDialog dlg(this);
//        dlg.resize(300,100);
//        dlg.exec();
//        qDebug() << "模态对话框　mo tai dialog.";
    //非模态对话框
//    QDialog *dlg2 = new QDialog(this);
//    dlg2->resize(300,200);
//    dlg2->setAttribute(Qt::WA_DeleteOnClose); //55号属性,关闭后释放内存
//    dlg2->show();

//    qDebug() <<" this is file read function add to github";

    //消息对话框
    //错误
//     QMessageBox::critical(this,"错误窗口","说明");
    //信息
//    QMessageBox::information(this,"info title","info for this ");
    //警告
//    QMessageBox::warning(this,"警告","下面输出程序修改说明!");

    //提问
    if(QMessageBox::Ok == QMessageBox::question(this,"程序修改过程说明",info1,QMessageBox::Cancel|QMessageBox::Ok,QMessageBox::Cancel))
    {
        qDebug() << "选择的是ok";
    }
    else
    {
        qDebug() << "选择的是cancel";
    }
}

//xyz与dat文件格式转化的主要程序
void xyz2dat::on_Btn_xyz2dat_clicked()
{
    fileOpenx(1);
    //对数据进行处理
    fileReadxyz();
}
