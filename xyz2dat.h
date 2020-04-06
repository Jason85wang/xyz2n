#ifndef XYZ2DAT_H
#define XYZ2DAT_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class xyz2dat; }
QT_END_NAMESPACE

class xyz2dat : public QMainWindow
{
    Q_OBJECT

public:
    xyz2dat(QWidget *parent = nullptr);
    ~xyz2dat();

signals:

public slots:
    //早期需要写入此处,高级版本可以在public或全局下
    void fileReadxyz();
    void showmodifyinfo(QString info1);  //显示程序版本文字说明
private:
    Ui::xyz2dat *ui;
};
#endif // XYZ2DAT_H
