#ifndef XYZ2DAT_H
#define XYZ2DAT_H

#include <QMainWindow>
#include <QString>

//网络连接用
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class xyz2dat; }
QT_END_NAMESPACE

class xyz2dat : public QMainWindow
{
    Q_OBJECT

public:
    xyz2dat(QWidget *parent = nullptr);
    ~xyz2dat();
    QString fname; //打开文件的路径与文件名
    QString fnamesave; //保存文件的路径与文件名
    QString tempfilemsg;//文件读写总量信息
    //network para
    QNetworkAccessManager *m_accessManager;
signals:

public slots:
    //早期需要写入此处,高级版本可以在public或全局下
    long fileReadxyz(); //返回处理的行数
    long fileSavedat(); //返回处理的行数
    void showmodifyinfo(QString info1);  //显示程序版本文字说明
    void fileOpenx(int type);
    void fileSavex(int type);
    //my network function
    void requestFinished(QNetworkReply* reply);
private slots:
    void on_Btn_xyz2dat_clicked();

    void on_pushButton_clicked();

    void on_pushB_getinfo_login_clicked();

    void on_pushButton_2_clicked();

    void on_pushB_getinfo_clicked();

    void on_actionview1_readfile_triggered();

    void on_actionview2_readnet_triggered();

    void on_pushB_getinfo_2_clicked();

    void on_pushB_getinfo_3_clicked();

private:
    Ui::xyz2dat *ui;
    QString token;
};
#endif // XYZ2DAT_H
