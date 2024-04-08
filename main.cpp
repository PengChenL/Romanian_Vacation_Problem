#include "romanian_map.h"
#include "cityinfo.h"
#include <QApplication>
#include <QButtonGroup>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Romanian_Map w;

    //设置窗口大小
    w.resize(1300,1000);

    //设置窗口居中
    QDesktopWidget *desktop = QApplication::desktop();
    w.move((desktop->width() - w.width())/ 2, (desktop->height() - w.height()) /2);

    //设置窗口不可更改大小
    w.setFixedSize(w.geometry().size());
    w.show();





    //测试一下
    //Cityinfo c;


    return a.exec();
}
