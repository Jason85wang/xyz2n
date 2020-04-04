#ifndef XYZ2DAT_H
#define XYZ2DAT_H

#include <QMainWindow>

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

private:
    Ui::xyz2dat *ui;
};
#endif // XYZ2DAT_H
