#ifndef ROMANIAN_MAP_H
#define ROMANIAN_MAP_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>
#include <QColor>
#include <QThread>
#include <windows.h>
#include "cityinfo.h"
namespace Ui {
class Romanian_Map;
}

class Romanian_Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Romanian_Map(QWidget *parent = nullptr);
    ~Romanian_Map();

    //用数组来接收一下选择的两个地点是什么
    int places[20];

    //城市信息
    Cityinfo cf;
    Graph RC;


    //定义绘图的标识，如果为0则为初始图像，否则为需要绘画的图像
    int drawindex = 0;

    //定义一个数组容器用于绘图
    std::vector<int> plotpath;

private slots:
    void on_btn_bfs_clicked();
    int onStateChanged();

    void on_btn_clear_clicked();

    void on_btn_dfs_clicked();

    void on_btn_Astar_clicked();

private:
    Ui::Romanian_Map *ui;
    void paintEvent(QPaintEvent *);
    void draw_initial_map(QPainter &painter);//绘制初始图像
    void draw_path_map(QPainter &painter);//绘制有路径的图像
    QButtonGroup *m_buttonGroup;
};

#endif // ROMANIAN_MAP_H
