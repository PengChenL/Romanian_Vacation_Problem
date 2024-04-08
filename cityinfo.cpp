#include "cityinfo.h"

Cityinfo::Cityinfo()
{
    //录入各城市信息

    CityNumber[0].setinfo("Arad",96,285,0);
    CityNumber[1].setinfo("Bucharest",771, 588, 1);
    CityNumber[2].setinfo("Craiova", 476, 767, 2);
    CityNumber[3].setinfo("Drobeta", 276, 772, 3);
    CityNumber[4].setinfo("Eforie", 1070, 678, 4);
    CityNumber[5].setinfo("Fagaras", 575, 311, 5);
    CityNumber[6].setinfo("Giurgiu", 739, 736, 6);
    CityNumber[7].setinfo("Hirsova", 1014, 522, 7);
    CityNumber[8].setinfo("Iasi", 917, 123, 8);
    CityNumber[9].setinfo("Lugoj", 246, 561, 9);
    CityNumber[10].setinfo("Mehadia", 256, 664, 10);
    CityNumber[11].setinfo("Neamt", 826, 33, 11);
    CityNumber[12].setinfo("Oradea", 178, 51, 12);
    CityNumber[13].setinfo("Pitesti", 580, 534, 13);
    CityNumber[14].setinfo("Rimnicu", 412, 473, 14);
    CityNumber[15].setinfo("Sibiu", 383, 297, 15);
    CityNumber[16].setinfo("Timisoara", 139, 446, 16);
    CityNumber[17].setinfo("Urziceni", 883, 493, 17);
    CityNumber[18].setinfo("Vaslui", 980, 246, 18);
    CityNumber[19].setinfo("Zerind", 136, 168, 19);


    //创建图，设置边
//    Graph RC;
//    RC.setEgde(0,19,75);
//    RC.setEgde(0,15,140);
//    RC.setEgde(0,16,118);
//    RC.setEgde(19,12,71);
//    RC.setEgde(12,15,151);
//    RC.setEgde(16,9,111);
//    RC.setEgde(9,10,70);
//    RC.setEgde(10,3,75);
//    RC.setEgde(3,2,120);
//    RC.setEgde(14,2,146);
//    RC.setEgde(14,15,80);
//    RC.setEgde(2,13,138);
//    RC.setEgde(13,14,97);
//    RC.setEgde(15,5,99);
//    RC.setEgde(5,1,211);
//    RC.setEgde(1,6,90);
//    RC.setEgde(1,13,101);
//    RC.setEgde(1,17,85);
//    RC.setEgde(17,18,142);
//    RC.setEgde(18,8,92);
//    RC.setEgde(11,8,37);
//    RC.setEgde(7,17,98);
//    RC.setEgde(7,4,86);

//    RC.Print();
    //RC.BFS(0,1);

}

City::City(QString name, int x, int y, int num)
{
    x_pos = x;
    y_pos = y;
    this->name = name;
    this->number = num;
}

City::City()
{

}

void City::setinfo(QString name, int x, int y, int num)
{
    this->x_pos = x;
    this->y_pos = y;
    this->name = name;
    this->number = num;
}


Graph::Graph()
{
    //城市需要按顺序录入
    for(int i = 0; i < 20; i++)
    {
        cities[i] = i;
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            matrix[i][j] = 0;
        }
    }
    CityNumber[0].setinfo("Arad",96,285,0);
    CityNumber[1].setinfo("Bucharest",771, 588, 1);
    CityNumber[2].setinfo("Craiova", 476, 767, 2);
    CityNumber[3].setinfo("Drobeta", 276, 772, 3);
    CityNumber[4].setinfo("Eforie", 1070, 678, 4);
    CityNumber[5].setinfo("Fagaras", 575, 311, 5);
    CityNumber[6].setinfo("Giurgiu", 739, 736, 6);
    CityNumber[7].setinfo("Hirsova", 1014, 522, 7);
    CityNumber[8].setinfo("Iasi", 917, 123, 8);
    CityNumber[9].setinfo("Lugoj", 246, 561, 9);
    CityNumber[10].setinfo("Mehadia", 256, 664, 10);
    CityNumber[11].setinfo("Neamt", 826, 33, 11);
    CityNumber[12].setinfo("Oradea", 178, 51, 12);
    CityNumber[13].setinfo("Pitesti", 580, 534, 13);
    CityNumber[14].setinfo("Rimnicu", 412, 473, 14);
    CityNumber[15].setinfo("Sibiu", 383, 297, 15);
    CityNumber[16].setinfo("Timisoara", 139, 446, 16);
    CityNumber[17].setinfo("Urziceni", 883, 493, 17);
    CityNumber[18].setinfo("Vaslui", 980, 246, 18);
    CityNumber[19].setinfo("Zerind", 136, 168, 19);


}

void Graph::setEgde(int c1, int c2, int weight)
{
    matrix[c1][c2] = matrix[c2][c1] =  weight;

}

void Graph::Print()//测试用
{
    //qDebug() << "\t";
     for (int i = 0; i < 20; i++)
     {
         qDebug() << CityNumber[i].name;
     }
     qDebug() << endl;

     for (int i = 0; i < 20; i++)
     {
//         qDebug() << "\t" << cities[i];
         for (int j = 0; j < 20; j++)
         {
             qDebug() << "\t" << matrix[i][j];
         }
         qDebug() << endl;
     }

}


std::vector<int> Graph::DFS(int c1, int c2)
{
    int x;
    //将每个顶点标记未访问
    for (int i = 0; i < 20; i++)
        visited[i] = false;
    qDebug() << "Depth First Search  (begins at " << c1 << ") : ";
    qDebug() << c1;

     int costindex = 0;//代价下标
    //初始化一下代价数组
    int DFScost[20];//用一个数组来记录路径代价,记录的是路径的权值
    for(int i = 0; i < 20; i++)
    {
        DFScost[i] = 0;
    }

    int parent[20]; // 记录DFS路径上的前驱节点

    //定义结束标志
    bool finish = 0;

    //开始DFS
    QStack<int> S;
    S.push(c1);
    visited[c1] = true;//入栈就要标记
    // int temp = c1;
    while(!S.empty() && !finish)
    {
        x = S.top();
        int flag = 0;
        for(int i = 0; i < 20; i ++)
        {
            if (visited[i] == 0 && matrix[x][i] != 0)//搜索x的临界点并且没有被访问过的，满足条件就入栈
            {
                qDebug() << cities[i];
                parent[i] = x;

                //到目标点停下-----------------------------------------
                if(cities[i] == c2)
                {
                    finish = 1;
                }
                //---------------------------------------------------
                S.push(i);
                visited[i] = 1;
                flag = 1;

                //同时记录把这条路加进数组中
                DFScost[costindex] = matrix[x][i];
                costindex++;


                 break;
            }
        }
        if(flag == 0)
        {
            S.pop();
        }

    }

    //打印一下路径代价看看
    qDebug() << "这是走过的路径代价：";
    for(int i = 0; i < costindex; i++)
    {
        qDebug() << DFScost[i] << " ";
    }


    //寻找路径

    std::vector<int> path; // 存储路径
    for (int u = c2; u != c1; u = parent[u]) {
        path.push_back(u);
    }
    path.push_back(c1);
    reverse(path.begin(), path.end()); // 翻转路径
    qDebug() << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        qDebug() << path[i] << " ";
    }
    return path;



}




std::vector<int> Graph::BFS(int c1, int c2)
{
    // 先将所有结点设置为未访问
    for (int i = 0; i < 20; i++)
        visited[i] = false;
    qDebug() << "Breadth First Search  (begins at " << c1 << ") : ";

    int costindex = 0;//代价下标
   //初始化一下代价数组
   int BFScost[20];//用一个数组来记录路径代价,记录的是路径的权值
   for(int i = 0; i < 20; i++)
   {
       BFScost[i] = 0;
   }

   //定义结束标志
   bool finish = 0;

   //定义搜索过的路径结点
   int b_searched[20] = {0};
   //定义搜索过的路径下标
   int b_searchedindex = 0;
   b_searched[b_searchedindex] = c1;
   b_searchedindex++;

   int parent[20]; // 记录BFS路径上的前驱节点

    //开始BFS
    int u;
    QQueue<int> Q;
    qDebug() << c1;
    // 寻找v结点所对应的下标，将其状态改为true
    int index = -1;
    for (int i = 0; i < 20; i++)
    {
        if (cities[i] == c1)
        {
            visited[i] = true;
            index = i;
        }
    }
    Q.enqueue(c1);



    while (!Q.isEmpty())
    {

        u = Q.head();

        //找到u所对应的下标x;
        int x = -1;
        for (int j = 0; j < 20; j++)
        {
            if (cities[j] == u)
            {
                x = j;
            }
        }

        Q.dequeue();

        for (int i = 0; i < 20; i++)
        {

            if (matrix[x][i] != 0 && (!visited[i]))
            {
                // qDebug()<<"测试点";
                qDebug() << cities[i];

                //把这个结点加入搜索过的路径数组
                b_searched[b_searchedindex] = cities[i];
                b_searchedindex++;

                //同时记录把这条路加进数组中
                BFScost[costindex] = matrix[x][i];
                costindex++;
                visited[i] = true;

                parent[i] = u; // 记录前驱节点
                Q.enqueue(cities[i]);

//---------------------------------------------------------------------------
                //到达目标点后停下
                if(cities[i] == c2)
                {
                    finish = 1;
                }
//---------------------------------------------------------------------------

            }
            if(finish)
            {
                break;
            }
        }
    }

//    qDebug() << endl;
    //打印一下路径代价看看
    qDebug() << "这是走过的路径代价：";
    for(int i = 0; i < costindex; i++)
    {
        qDebug() << BFScost[i] << " ";
    }


    //现在我们来找路径
    //先定义一个路径数组
    int path[20] = {0};
    //路径下标
    int pathindex = 0;

    //先把终点加到这个里面
    path[pathindex] = c2;
    pathindex++;

    //打印一下搜索数组//没问题
//    qDebug() << "-------------------------------------";
//    for(int k = 0; k < b_searchedindex; k++)
//    {
//        qDebug() << b_searched[k];
//    }
//    qDebug() << "-------------------------------------";


//    //从走过的数组中去选择
//    //从c2这一列中去寻找，也即是终点，从终点开始
//    int p = c2;

//    int times = 0;
//    while(p != c1 && times < 5)
//    {

//        for(int i = 0 ; i < 20; i++)
//        {
//            //qDebug() << matrix[p][i];
//            if(matrix[p][i] != 0)
//            {

//                qDebug() << "找到了不为0的：" << matrix[p][i] << " " << cities[i];
//                for(int j = b_searchedindex - 1 ; j >= 0; j--)
//                {
//                    while()
//                    qDebug() << j << b_searched[j] << cities[i];
//                    if(cities[i] == b_searched[j] && b_searched[i] != p)
//                    {
//                        //加入数组
//                        qDebug() << "找到了相等的：" << b_searched[j] << cities[i];
//                        p = cities[i];
//                        path[pathindex] = cities[i];
//                        pathindex++;
//                        break;
//                    }
//                }


//            }
//        }
//        p = path[pathindex - 1];

//    }



    //    //从走过的数组中去选择
    //    //从c2这一列中去寻找，也即是终点，从终点开始
//    int p = c2;
//    int k = b_searchedindex;
//    while (k != 0)
//    {
//        for(int i = 0; i < 20; i++)
//        {
//            if(matrix[p][i] != 0)
//            {
//                qDebug() << p << "与" << cities[i] << "之间有通路";
//                k = b_searchedindex;
//                while(1)
//                {
//                    if(cities[i] == b_searched[k])
//                    {
//                        qDebug() << cities[i] << "属于最终数组";
//                        break;
//                    }
//                    k--;
//                }
//            }
//        }

//    }

    std::vector<int> vpath; // 存储路径
    for (int u = c2; u != c1; u = parent[u]) {
        vpath.push_back(u);
    }
    vpath.push_back(c1);
    std::reverse(vpath.begin(), vpath.end()); // 翻转路径
    qDebug() << "Path: ";
    for (size_t i = 0; i < vpath.size(); ++i) {
        qDebug() << vpath[i] << " ";
    }
    // cout << endl;








    //打印一下
    qDebug() << "这是路径";
    for(int i = 0 ; i < 0; i++)
    {
        qDebug() << path[i];
    }
    //times++;
    return vpath;







}







/*多路图是指在一个图中有多个起点和多个终点。A星算法是一种启发式搜索算法，
 * 其基本思想是通过估价函数来评估节点到目标点的距离，从而决定搜索路径，从而可以有效地搜索出起点到终点的最短路径。

基于邻接表实现A星算法，主要分为以下步骤：

1. 将邻接表中每个节点标记为未访问状态。
2. 将起点加入到开放列表（Open List）中，同时将其f值设为0，g值设为0，h值通过估价函数计算得出。
3. 重复以下步骤，直到找到终点或者开放列表为空：
    a. 从开放列表中选出f值最小的节点作为当前节点，并将其从开放列表中删除，加入到关闭列表（Close List）中。
    b. 对当前节点的相邻节点进行遍历，如果相邻节点不可通行或者已经在关闭列表中，则忽略该节点。
        否则，如果相邻节点不在开放列表中，则将其加入到开放列表中，并且更新该节点的父节点为当前节点，
        计算其f、g、h值；如果相邻节点已经在开放列表中，则比较以当前节点作为父节点时的g值与原先的g值哪个更小，
        然后更新其父节点、g值、f值。
    c. 如果终点在关闭列表中，则表示找到了一条最短路径。
以上步骤就是基于邻接表实现A星算法的具体流程。其中，估价函数需要结合实际场景来设计，常用的有曼哈顿估价和欧几里得估价等。
 */



//准备一个结构体，用来存储每个节点的编号、f、h、g
class node
{
public:
    int g;
    int h;
    int f;
    int name;
    int parent;

    node(int name, int g, int h)
    {
        this->name = name;
        this->g = g;
        this->h = h;
        this->f = g + h;
    }
    node(){

    }

    bool operator <(const node &a)const //操作符重载，便于排序
    {
        return f < a.f;
    }
};


//先写几个函数

//计算欧几里得距离
double Graph::calcEucliDis(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

node Graph::getMinF(std::vector<node> &openlist)
{
    size_t index = 0;//第一个点
    for (size_t i = 1; i < openlist.size(); ++i) { //i表示当前遍历到的节点在openList容器中的下标
        if (openlist[i].f < openlist[index].f) {
            index = i;
        } //获得f值最小的节点
    }
    node res = openlist[index]; //将openList[index]节点的指针赋值给res指针
    openlist.erase(openlist.begin() + index); //使用erase函数将openList容器中下标为index的节点删除
    return res;
}

//bool Graph::isInCloseList(std::vector<node> v, node n)
//{
//    auto it = std::find(v.begin(), v.end(), n);
//    if (it != v.end()) {//找到了
//        return true;
//    } else {//没找到
//        return false;
//    }
//}

//启发函数，欧几里得距离，当前结点和目标结点
double Graph::heuristicfunction(node n1, node n2)
{
    return calcEucliDis(this->CityNumber[n1.name].x_pos,this->CityNumber[n1.name].y_pos,
            this->CityNumber[n2.name].x_pos,this->CityNumber[n2.name].y_pos);
}


std::vector<int> Graph::AStar(int c1, int c2)
{
    // H = G + H
    // 总代价 = 起点到当前点的代价 + 预估代价

    //创建c1和c2对应的结点
    node n1(c1, 0, calcEucliDis(this->CityNumber[c1].x_pos,this->CityNumber[c1].y_pos,
                        this->CityNumber[c2].x_pos,this->CityNumber[c2].y_pos));
    // node n2(c2, 0, 0);
    qDebug() << "起始节点的h值 " << n1.h;

    //计算所有结点的启发函数值
    int heuri[20];
    for(int i = 0; i < 20; i++)
    {
        heuri[i] = calcEucliDis(this->CityNumber[i].x_pos,this->CityNumber[i].y_pos,
                                this->CityNumber[c2].x_pos,this->CityNumber[c2].y_pos);
    }
    qDebug() << "启发函数值";
    for(int i = 0; i < 20; i++)
    {
        qDebug() << heuri[i];
    }

    //初始化所有结点
//    node nodes[20];
//    for(int i = 0; i < 20; i++)
//    {
//        nodes[i].name = i;
//        nodes[i].h = heuri[i];
//        //nodes[i].g = 9999;//先将代价置为无限大
//        //nodes[i].f = nodes[i].h + nodes[i].g;
//        qDebug() << nodes[i].name <<" " << nodes[i].h << " " <<  nodes[i].g;
//    }


//    // 将所有结点设置为未访问
//    for (int i = 0; i < 20; i++)
//        visited[i] = false;

    std::vector<node> openList;//oepn表
    std::vector<node> closeList;//close表
//    bool bopenlist[20];//记录节点是否在openList中
//    bool bcloseList[20];//结点是否在closeList中
    int parent[20];//用来记录每个节点对应的父节点

    //首先将始点放进openList
    openList.push_back(n1);
    //sort(openList.begin(), openList.end());

    while(!openList.empty())//当open表非空
    {

        //不断从openlist中取出f最小的结点，直到open表为空
        node current = getMinF(openList);



        //检查这个元素是否已经在close表中，如果已经存在，则不再添加
        // auto it = std::find(closeList.begin(), closeList.end(), current);
        bool isincloselist = false;
        foreach(auto node, closeList)
        {
            if(current.name == node.name)//找到了
            {
                qDebug() << current.name << "已经在close表中";
                isincloselist = true;

            }

        }
        //没找到才加入close表中
        if(!isincloselist)
        {
            closeList.push_back(current);
        }
        else {
            continue;
        }


//        //并且将取出的结点加入close表中
//        closeList.push_back(current);



        qDebug() << "当前的open表为：";
        foreach(auto node , openList)
        {
            qDebug() << node.name;
        }

        qDebug() << "当前的close表为：";
        foreach(auto node, closeList)
        {
            qDebug() << node.name;
        }


        //g走过的距离

        //如果已经到达终点，则输出路径代价
        if(current.name == c2)
        {
            std::vector<int> path; // 存储路径
            int cost = 0;         

            qDebug() << "遍历完成！";
            qDebug() << "打印父节点";
            foreach(auto node, closeList)
            {
                qDebug() << node.name << node.parent;
            }

            node temp;
            //先遍历vector容器，找到终点结点并拿出来
            foreach(auto node, closeList)
            {
                parent[node.name] = node.parent;
            }

            qDebug() << "下面是路径";
//            while(temp.name != c1)
//            {

//            }

            for (int u = c2; u != c1; u = parent[u]) {
                path.push_back(u);
            }
            path.push_back(c1);
            reverse(path.begin(), path.end()); // 翻转路径
            qDebug() << "Path: ";
            for (size_t i = 0; i < path.size(); ++i) {
                qDebug() << path[i] << " ";
            }
            return path;


        }

        //遍历邻居城市，加入open表
        for(int i = 0; i < 20; i++)
        {
            if(matrix[current.name][i] != 0)//则说明为邻居城市
            {
                node next(cities[i], current.g + matrix[current.name][i], heuri[i]);
                // parent[i] = current.name;
                next.parent = current.name;

                //判断这个next结点是否在close表中
                bool found = false;
                foreach(auto closed, closeList)
                {
                    if(closed.name == next.name)
                        found = true;
                    break;
                }

                //如果找到了
                if(found)//跳过这次循环
                {
                    continue;
                }

                //在判断其是否在open表中
                found = false;
                foreach(auto node, openList)
                {
                    if(node.name == next.name)
                    {
                        found = true;
                        if(next < node)
                        {
                            node.f = next.f;
                            node.g = next.g;
                            node.parent = next.parent;
                            //parent
                        }
                        break;
                    }
                }
                if (!found)
                {
                    openList.push_back(next);
                }
            }
        }

    }





/*
    //现在遍历open表
    while(!openList.empty())
    {
        node current = openList[0];//取出第一个节点，第一个节点的f值是最小的
        if (current.name == c2)//如果是目标节点，那么结束循环
            break;

        openList.erase(openList.begin());//将节点从openList表中拿出
        //并且放在close表中
        //closeList.push_back(current);
        bopenlist[current.name] = false;
        sort(openList.begin(), openList.end());//对openList重新排序//从小到大
        bcloseList[current.name] = true;

        qDebug() << current.name << " " << current.g << " " << current.h;




        //以下开始遍历和当前节点相邻的点
        for(int i = 0; i < 20; i++)
        {
            if (matrix[current.name][i] != 0 )//如果值不等于0，则代表相邻
            {
                if(bcloseList[i])//如果已经在close表中，执行下次循环
                {
                    continue;
                }

                else if (bopenlist[i])//如果在openList表中
                {
                    //以下进行的操作是，从openList中找到这个节点
                    size_t num = 0;
                    for (std::vector<node>::iterator it = openList.begin(); it != openList.end(); it++)
                    {
                        if (it->name == i)
                            break;
                        num++;
                    }

                    if (current.g + matrix[current.name][i] < openList[num].g)
                    {
                        openList[num].g = current.g + matrix[current.name][i];
                        openList[num].f = openList[num].g + openList[num].h;
                        parent[i] = current.name;
                        bopenlist[i] = true;
                    }
                }
                else
                {
                    //如果这个点既不在openList也不在closeList则创建一个新点，将这个点加入openList
                    node newNode(i, matrix[current.name][i], heuri[i]);
                    parent[i] = current.name;
                    openList.push_back(newNode);
                    sort(openList.begin(), openList.end());
                }
            }
        }

    }
    qDebug () << "good!";

*/


//    std::stack<int> road;//用来保存最终结果并输出
//    //目的是输出结果，将所有的节点的编号放入栈中，这样就能倒转了，
//    //然后计算从始点到目标点的cost
//    int p = openList[0].name;
//    int lastNodeNum;
//    road.push(p);
//    while (parent[p] != 0)
//    {
//        road.push(parent[p]);
//        p = parent[p];
//    }


//    qDebug () << "nice!";

//    lastNodeNum = road.top();
//    int cost = 0;
//    qDebug() << "solution: ";
//    while (!road.empty())
//    {
//        qDebug() << road.top() << "-> ";
//        if (road.top() != lastNodeNum)
//        {
//            cost += matrix[lastNodeNum][road.top()];
//            lastNodeNum = road.top();
//        }
//        road.pop();
//    }
//    qDebug() << "end" << endl;
//    qDebug() << "cost:" << cost;

}

