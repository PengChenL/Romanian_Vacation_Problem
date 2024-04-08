#ifndef CITYINFO_H
#define CITYINFO_H
#include <qdebug.h>
#include <QString>
#include <QQueue>
#include <QStack>
#include <QVector>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>

class City
{
public:
    // 定义城市信息
    int number;//给每个城市一个编号
    QString name; //城市名称
    int x_pos;
    int y_pos;//位置信息
    City(QString name, int x, int y, int num);
    City();

    //设置城市信息
    void setinfo(QString name, int x, int y, int num);


};


class Cityinfo
{
public:
    Cityinfo();

    City CityNumber[20];

};


class node;

class Graph
{
    //用邻接矩阵来存放图的信息
public:
    int cities[20];//存放城市编号
    int matrix[20][20];//矩阵
    bool visited[20];//结点访问状态

    Graph();//构造图
    void setEgde(int c1, int c2, int weight);
    void Print();
    std::vector<int> BFS(int c1, int c2);//从c1到c2宽度优先


    std::vector<int> DFS(int c1, int c2); //从c1到c2深度优先
//    int DFScost[20];//用一个数组来记录路径代价,记录的是路径的权值

    std::vector<int> AStar(int c1, int c2); //从c1到c2的A*算法

    //启发函数

    double heuristicfunction(node n1, node n2);
    //欧氏距离
    double calcEucliDis(int x1, int y1, int x2, int y2);

    //判断是否在close表中
    bool isInCloseList(std::vector<node> v,node n);

    //取出open表中f最小结点
    node getMinF(std::vector<node>& openlist);

    //城市信息
    City CityNumber[20];


};

#endif // CITYINFO_H
