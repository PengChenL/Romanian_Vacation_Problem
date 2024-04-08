#include "romanian_map.h"
#include "ui_romanian_map.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QPainter>
#include <QButtonGroup>

Romanian_Map::Romanian_Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Romanian_Map)
{
    ui->setupUi(this);

//    QCheckBox* checkBox1 = new QCheckBox("CheckBox1", this);
//    checkBox1->setGeometry(QRect(130, 160, 111, 22));

//    QCheckBox* checkBox2 = new QCheckBox("CheckBox2", this);
//    checkBox2->setGeometry(QRect(130, 190, 111, 22));

//    m_btnGroup = new QButtonGroup(this);
//    m_btnGroup->addButton(ui->checkBox, 0);
//    m_btnGroup->addButton(checkBox1, 1);
//    m_btnGroup->addButton(checkBox2, 2);


    //-------------
    // QbuttonGroup
    ui->cb0->setGeometry(96,285,200,50);
    ui->cb1->setGeometry(771,588,200,50);   // Bucharest
    ui->cb2->setGeometry(476,767,200,50);   // Craiova
    ui->cb3->setGeometry(276,772,200,50);   // Drobeta
    ui->cb4->setGeometry(1070,678,200,50);  // Eforie
    ui->cb5->setGeometry(575,311,200,50);   // Fagaras
    ui->cb6->setGeometry(739,736,200,50);   // Giurgiu
    ui->cb7->setGeometry(1014,522,200,50);  // Hirsova
    ui->cb8->setGeometry(917,123,200,50);   // Iasi
    ui->cb9->setGeometry(246,561,200,50);   // Lugoj
    ui->cb10->setGeometry(256,664,200,50);  // Mehadia
    ui->cb11->setGeometry(826,33,200,50);   // Neamt
    ui->cb12->setGeometry(178,51,200,50);   // Oradea
    ui->cb13->setGeometry(580,534,200,50);  // Pitesti
    ui->cb14->setGeometry(412,473,200,50);  // Rimnicu
    ui->cb15->setGeometry(383,297,200,50);  // Sibiu
    ui->cb16->setGeometry(139,446,200,50);  // Timisoara
    ui->cb17->setGeometry(883,493,200,50);  // Urziceni
    ui->cb18->setGeometry(980,246,200,50);  // Vaslui
    ui->cb19->setGeometry(136,168,200,50);  // Zerind

    //调整一下字体
    ui->cb0->setFont(QFont("SimSun", 12));
    ui->cb1->setFont(QFont("SimSun", 12));
    ui->cb2->setFont(QFont("SimSun", 12));
    ui->cb3->setFont(QFont("SimSun", 12));
    ui->cb4->setFont(QFont("SimSun", 12));
    ui->cb5->setFont(QFont("SimSun", 12));
    ui->cb6->setFont(QFont("SimSun", 12));
    ui->cb7->setFont(QFont("SimSun", 12));
    ui->cb8->setFont(QFont("SimSun", 12));
    ui->cb9->setFont(QFont("SimSun", 12));
    ui->cb10->setFont(QFont("SimSun", 12));
    ui->cb11->setFont(QFont("SimSun", 12));
    ui->cb12->setFont(QFont("SimSun", 12));
    ui->cb13->setFont(QFont("SimSun", 12));
    ui->cb14->setFont(QFont("SimSun", 12));
    ui->cb15->setFont(QFont("SimSun", 12));
    ui->cb16->setFont(QFont("SimSun", 12));
    ui->cb17->setFont(QFont("SimSun", 12));
    ui->cb18->setFont(QFont("SimSun", 12));
    ui->cb19->setFont(QFont("SimSun", 12));


    //设置复选框
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->setExclusive(false);
    //把所有checkbox加入group中
    m_buttonGroup->addButton(ui->cb0, 0);
    m_buttonGroup->addButton(ui->cb1, 1);
    m_buttonGroup->addButton(ui->cb2, 2);
    m_buttonGroup->addButton(ui->cb3, 3);
    m_buttonGroup->addButton(ui->cb4, 4);
    m_buttonGroup->addButton(ui->cb5, 5);
    m_buttonGroup->addButton(ui->cb6, 6);
    m_buttonGroup->addButton(ui->cb7, 7);
    m_buttonGroup->addButton(ui->cb8, 8);
    m_buttonGroup->addButton(ui->cb9, 9);
    m_buttonGroup->addButton(ui->cb10, 10);
    m_buttonGroup->addButton(ui->cb11, 11);
    m_buttonGroup->addButton(ui->cb12, 12);
    m_buttonGroup->addButton(ui->cb13, 13);
    m_buttonGroup->addButton(ui->cb14, 14);
    m_buttonGroup->addButton(ui->cb15, 15);
    m_buttonGroup->addButton(ui->cb16, 16);
    m_buttonGroup->addButton(ui->cb17, 17);
    m_buttonGroup->addButton(ui->cb18, 18);
    m_buttonGroup->addButton(ui->cb19, 19);


    //添加信号
    connect(ui->cb0, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb1, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb2, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb3, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb4, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb5, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb6, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb7, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb8, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb9, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb10, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb11, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb12, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb13, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb14, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb15, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb16, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb17, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb18, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);
    connect(ui->cb19, &QCheckBox::stateChanged, this, &Romanian_Map::onStateChanged);


    //创建图//设置图信息
    RC.setEgde(0,19,75);
    RC.setEgde(0,15,140);
    RC.setEgde(0,16,118);
    RC.setEgde(19,12,71);
    RC.setEgde(12,15,151);
    RC.setEgde(16,9,111);
    RC.setEgde(9,10,70);
    RC.setEgde(10,3,75);
    RC.setEgde(3,2,120);
    RC.setEgde(14,2,146);
    RC.setEgde(14,15,80);
    RC.setEgde(2,13,138);
    RC.setEgde(13,14,97);
    RC.setEgde(15,5,99);
    RC.setEgde(5,1,211);
    RC.setEgde(1,6,90);
    RC.setEgde(1,13,101);
    RC.setEgde(1,17,85);
    RC.setEgde(17,18,142);
    RC.setEgde(18,8,92);
    RC.setEgde(11,8,37);
    RC.setEgde(7,17,98);
    RC.setEgde(7,4,86);


    //设置按钮位置
    int de = 105;
    ui->btn_bfs->setGeometry(250+de,865,100,60);
    ui->btn_dfs->setGeometry(400+de,865,100,60);
    ui->btn_Astar->setGeometry(550+de,865,100,60);
    ui->btn_clear->setGeometry(700+de,865,100,60);


}

Romanian_Map::~Romanian_Map()
{
    delete ui;
}

void Romanian_Map::paintEvent(QPaintEvent *)
{
    //把路线画出来
    QPainter painter(this);
    if(this->drawindex == 0)
    {
        draw_initial_map(painter);
    }
    else {
        draw_path_map(painter);
    }



}

void Romanian_Map::draw_initial_map(QPainter &painter)//绘制初始图像
{

    int devx = 10;
    int devy = 29;
    painter.drawLine(96+devx,285+devy,136+devx,168+devy);
    painter.drawLine(96+devx, 285+devy, 383+devx, 297+devy);
    painter.drawLine(139+devx, 446+devy, 246+devx, 561+devy);

    painter.drawLine(178+devx, 51+devy, 383+devx, 297+devy);

    painter.drawLine(276+devx, 772+devy, 476+devx, 767+devy);
    painter.drawLine(476+devx, 767+devy, 580+devx, 534+devy);

    painter.drawLine(412+devx, 473+devy, 383+devx, 297+devy);
    painter.drawLine(580+devx, 534+devy, 771+devx, 588+devy);
    painter.drawLine(771+devx, 588+devy, 739+devx, 736+devy);
    painter.drawLine(771+devx, 588+devy, 883+devx, 493+devy);
    painter.drawLine(880+devx, 491+devy, 980+devx, 246+devy);
    painter.drawLine(980+devx, 246+devy, 917+devx, 123+devy);
    painter.drawLine(256+devx, 664+devy, 276+devx, 772+devy);
    painter.drawLine(1014+devx, 522+devy, 883+devx, 493+devy);

    //自己修正
    painter.drawLine(917+devx, 123+devy, 826+devx, 33+devy);
    painter.drawLine(178+devx, 51+devy, 136+devx, 168+devy);//12,19
    painter.drawLine(96+devx, 285+devy, 139+devx, 446+devy);//0,16
    painter.drawLine(246+devx, 561+devy, 256+devx, 664+devy);//9,10
    painter.drawLine(412+devx, 473+devy, 476+devx, 767+devy);//14,2
    painter.drawLine(412+devx, 473+devy, 580+devx, 534+devy);//14,13
    painter.drawLine(383+devx, 297+devy, 575+devx, 311+devy);//15,5
    painter.drawLine(771+devx, 588+devy, 575+devx, 311+devy);//1,5
    painter.drawLine(1014+devx, 522+devy, 1070+devx, 678+devy);//7,4

}

void Romanian_Map::draw_path_map(QPainter &painter)
{
    int devx = 10;
    int devy = 29;
    this->draw_initial_map(painter);
    // painter.drawLine(100,100,500,500);

    // 现在，根据路径数组来绘图吧
//    plotpath[0] = 0;
//    plotpath[1] = 15;
//    plotpath[2] = 5;
//    plotpath[3] = 1;

//    //找到0和15的横纵坐标
//    QPen pen(Qt::red);
//    pen.setWidth(3);
//    painter.setPen(pen);
//    for(int i = 0; i < 4 - 1; i++)
//    {
//        painter.drawLine(this->cf.CityNumber[plotpath[i]].x_pos+devx, this->cf.CityNumber[plotpath[i]].y_pos + devy,
//                this->cf.CityNumber[plotpath[i+1]].x_pos + devx, this->cf.CityNumber[plotpath[i+1]].y_pos + devy);
//        // QThread::msleep(500);
//         Sleep(400);
//    }

    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    for(size_t i = 0; i < plotpath.size() - 1; i++)
    {
        painter.drawLine(this->cf.CityNumber[plotpath[i]].x_pos+devx, this->cf.CityNumber[plotpath[i]].y_pos + devy,
                this->cf.CityNumber[plotpath[i+1]].x_pos + devx, this->cf.CityNumber[plotpath[i+1]].y_pos + devy);
        // QThread::msleep(500);
        // Sleep(400);
    }




}

void Romanian_Map::on_btn_bfs_clicked()
{
    // qDebug() << "选择了： " << m_buttonGroup->checkedId();


    if(Romanian_Map::onStateChanged() == 2)//只能选择两个地点
    {
        qDebug() << "满足函数执行条件 " ;
        qDebug() << "选择的编号是" << this->places[0] << " " << this->places[1];

        qDebug() << "这两个城市是" << cf.CityNumber[this->places[0]].name << " "
                                 << cf.CityNumber[this->places[1]].name;

        //执行BFS
        //选择一下起点和终点
        QMessageBox choice;
        choice.setWindowTitle("起点选择");
        choice.setText("请选择起点");
        QPushButton* yes = choice.addButton(cf.CityNumber[this->places[0]].name,QMessageBox::ActionRole);
        QPushButton* no = choice.addButton(cf.CityNumber[this->places[1]].name,QMessageBox::ActionRole);
        choice.exec();
        if(choice.clickedButton() == yes)
        {
            plotpath = RC.BFS(places[0],places[1]);
        }
        else if(choice.clickedButton() == no)
        {
            plotpath = RC.BFS(places[1],places[0]);
        }

        this->drawindex = 1;
        update();
//        int cost = 0;
//        for(auto x: plotpath)
//        {
//            cost +=
//        }

    }
    else
    {
        qDebug() << "请选择两个地点！";
    }
}


int Romanian_Map::onStateChanged()
{
    int checkednum = 0;
    for(int i = 0; i < 20; i++)
    {
        if(m_buttonGroup->button(i)->isChecked())
        {
            qDebug()<< "你选择了城市：" << cf.CityNumber[i].name ;
            checkednum++;
            this->places[checkednum - 1] = i;
        }
    }
    qDebug() << "现在选中了" << checkednum << "个";
    return checkednum;
}



void Romanian_Map::on_btn_clear_clicked()
{
    for(int i = 0; i < 20; i++)
    {
        m_buttonGroup->button(i)->setChecked(false);
    }
    //还需要重绘一下图像
    this->drawindex = 0;
    update();
    qDebug() << "清除成功！";
}


void Romanian_Map::on_btn_dfs_clicked()
{
    if(Romanian_Map::onStateChanged() == 2)//只能选择两个地点
    {
        qDebug() << "满足函数执行条件 " ;
        qDebug() << "选择的编号是" << this->places[0] << " " << this->places[1];

        qDebug() << "这两个城市是" << cf.CityNumber[this->places[0]].name << " "
                                 << cf.CityNumber[this->places[1]].name;

        //执行DFS
        QMessageBox choice;
        choice.setWindowTitle("起点选择");
        choice.setText("请选择起点");
        QPushButton* yes = choice.addButton(cf.CityNumber[this->places[0]].name,QMessageBox::ActionRole);
        QPushButton* no = choice.addButton(cf.CityNumber[this->places[1]].name,QMessageBox::ActionRole);
        choice.exec();
        if(choice.clickedButton() == yes)
        {
            plotpath = RC.DFS(places[0],places[1]);
        }
        else if(choice.clickedButton() == no)
        {
            plotpath = RC.DFS(places[1],places[0]);
        }

        this->drawindex = 1;
        update();



    }
    else
    {
        qDebug() << "请选择两个地点！";
    }
}

void Romanian_Map::on_btn_Astar_clicked()
{
    if(Romanian_Map::onStateChanged() == 2)//只能选择两个地点
    {
        qDebug() << "满足函数执行条件 " ;
        qDebug() << "选择的编号是" << this->places[0] << " " << this->places[1];

        qDebug() << "这两个城市是" << cf.CityNumber[this->places[0]].name << " "
                                 << cf.CityNumber[this->places[1]].name;

        //执行A星算法
        QMessageBox choice;
        choice.setWindowTitle("起点选择");
        choice.setText("请选择起点");
        QPushButton* yes = choice.addButton(cf.CityNumber[this->places[0]].name,QMessageBox::ActionRole);
        QPushButton* no = choice.addButton(cf.CityNumber[this->places[1]].name,QMessageBox::ActionRole);
        choice.exec();
        if(choice.clickedButton() == yes)
        {
            plotpath = RC.AStar(places[0],places[1]);
        }
        else if(choice.clickedButton() == no)
        {
            plotpath = RC.AStar(places[1],places[0]);
        }

        this->drawindex = 1;
        update();


    }
    else
    {
        qDebug() << "请选择两个地点！";
    }
}
