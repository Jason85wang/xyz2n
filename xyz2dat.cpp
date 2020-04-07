#include "xyz2dat.h"
#include "ui_xyz2dat.h"
#include <qpushbutton.h>
#include <qdebug.h>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>

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
 *此处为数据预处理
 *
 * */
long xyz2dat::fileReadxyz()
{
    QByteArray array1;
    double line_number = 0;  //读取的行数
    QString linedata,tempout;       //每行的内容
    //读取文件并放入控件中
    QFile filein(fname);
    filein.open(QIODevice::ReadOnly);
    for (int var = 0; var < 100; ++var) {
        array1 = filein.readLine();
        ui->textEdit_org->insertPlainText(array1);
        //识别与处理数字
        linedata=array1;

        QStringList str_list = linedata.split(QRegExp("\\s{1,}"));
//        for (int i=0; i<str_list.length(); ++i) {
////            ui->textEdit_pre->insertPlainText("line: ");
////            ui->textEdit_pre->insertPlainText(QString::number(var,10));
////            ui->textEdit_pre->insertPlainText(" row:");
////            ui->textEdit_pre->insertPlainText(QString::number(i,10));
////            ui->textEdit_pre->insertPlainText(" ");
////            ui->textEdit_pre->insertPlainText(str_list[i]);
////            ui->textEdit_pre->append(" ");
////            tempout +=QString::number(i,10)+","+ str_list[i]+",";
//        }
        if(var == 0) {
            //第一行标记与其它不同
            tempout= QString::number(var+1,10)+",M,"+str_list[0] + "," + str_list[1]+"," + str_list[2];
        }
        else{
            tempout= QString::number(var+1,10)+",1,"+str_list[0] + "," + str_list[1]+"," + str_list[2];
        }

        ui->textEdit_pre->append(tempout);
        tempout="";

        ++line_number;
//        ui->textEdit_org->insert(array1);
    }

    filein.close();
    qDebug() <<" fileReadxyz打开文件名为:"<<fname;
    return line_number;
}

/**对取得的文件进行相应的数据处理
 *此处为数据预处理
 *
 * */
long xyz2dat::fileSavedat()
{
    QByteArray array1;
    double line_number = 0;  //读取的行数
    QString linedata,tempout;       //每行的内容

    //中文编码问题
//    QTextCodec * codec = QTextCodec::codecForName( "gbk");

    //读取文件并放入控件中
    QFile filein(fname);
    filein.open(QIODevice::ReadOnly);

    //写文件相关
    QFile fileout(fnamesave);
    fileout.open(QIODevice::WriteOnly);

    while( !filein.atEnd() ){
        array1 = filein.readLine();
        ui->textEdit_org->insertPlainText(array1);
        //识别与处理数字
        linedata=array1;

        QStringList str_list = linedata.split(QRegExp("\\s{1,}"));
        if(line_number == 0) {
            //第一行标记与其它不同
            tempout += QString::number(int(line_number)+1,10)+",M,"+str_list[0] + "," + str_list[1]+"," + str_list[2]+"\n";
        }
        else{
            tempout += QString::number(int(line_number)+1,10)+",1,"+str_list[0] + "," + str_list[1]+"," + str_list[2]+"\n";
        }

        if( int(line_number)%10000 == 0){
            //ui->textEdit_pre->append(tempout);
            fileout.write(tempout.toUtf8().data());
            tempout="";
            tempfilemsg = "已经读写:" +QString::number(line_number) + "个数据";
            //将文件名显示在状态栏中
            ui->statusbar->showMessage(tempfilemsg);
            qDebug() << tempfilemsg;
        }
        ++line_number;
    }
    //写入剩下的部分
    fileout.write(tempout.toUtf8().data());
    tempout="";

//    for (int var = 0; var < 100; ++var) {

////        for (int i=0; i<str_list.length(); ++i) {
//////            ui->textEdit_pre->insertPlainText("line: ");
//////            ui->textEdit_pre->insertPlainText(QString::number(var,10));
//////            ui->textEdit_pre->insertPlainText(" row:");
//////            ui->textEdit_pre->insertPlainText(QString::number(i,10));
//////            ui->textEdit_pre->insertPlainText(" ");
//////            ui->textEdit_pre->insertPlainText(str_list[i]);
//////            ui->textEdit_pre->append(" ");
//////            tempout +=QString::number(i,10)+","+ str_list[i]+",";
////        }

////        ui->textEdit_org->insert(array1);
//    }

    filein.close();
    fileout.close();
    qDebug() <<" fileSavedat打开文件名为:"<<fname;
    tempfilemsg = "已经读写:" +QString::number(line_number) + "个数据";
    QMessageBox::information(this,"读写文件信息",tempfilemsg);
    return line_number;
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
    fname = QFileDialog::getOpenFileName(this,"打开文件","D:/QtProjects/xyz2dat/xyz2dat1d2/xyz2dat/testdata/",filefilt );
    //将文件名显示在状态栏中
    ui->statusbar->showMessage(fname);
    //输出调试信息
    qDebug() <<" 打开文件名为:"<<fname;
}

/**　处理的第3步,选择保存的文件名,并取得文件路径与文件名
*参数一,文件类型过滤,默认为所有文件
**/
void xyz2dat::fileSavex(int type=0)
{
    QString filefilt;
    //文件对话框
    switch (type) {
        case 1:
            //dat格式互转
            filefilt = tr("south data Files ( *.dat )");
        break;
    case 2:
        //xyz格式互转
        filefilt = tr("xyz data Files ( *.xyz *.txt)");
    break;
    default:
        filefilt = tr("all Files (*.*)");
    }
    fnamesave = QFileDialog::getSaveFileName(this,"打开文件","D:/QtProjects/xyz2dat/xyz2dat1d2/xyz2dat/testdata/",filefilt );
    //将文件名显示在状态栏中
    ui->statusbar->showMessage(fnamesave);
    //输出调试信息
    qDebug() <<" 保存文件名为:"<<fnamesave;
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

void xyz2dat::on_pushButton_clicked()
{
    fileOpenx(1);
    //保存文件名
    fileSavex(1);
    //保存数据
    fileSavedat();
}
