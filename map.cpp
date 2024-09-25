#include "map.h"
#include "ui_map.h"

#include"config.h"

Map::Map(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Map),
    lv1(nullptr),
    lv2(nullptr)
{
    ui->setupUi(this);

    initScene();

    connect(ui->btn1, &QPushButton::clicked, this, &Map::on_btn1_clicked); // 连接信号与槽
    connect(ui->btn2, &QPushButton::clicked, this, &Map::on_btn2_clicked); // 连接信号与槽


}

Map::~Map()
{
    delete ui;

    // 检查lv1指针是否为nullptr，并仅在非空时删除它
    if (lv1 != nullptr) {
        delete lv1;
        lv1 = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

    // 检查lv1指针是否为nullptr，并仅在非空时删除它
    if (lv2 != nullptr) {
        delete lv2;
        lv2 = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

}

void Map::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}


//以下处理各关卡按钮点击跳转对应关卡界面的操作，一个按钮的点击声明一个对象

void Map::on_btn1_clicked()
{
    if (!lv1) { // 如果map还没创建，则创建它

        lv1= new level1(nullptr);
    }
    this->hide(); // 隐藏当前窗口
    lv1->show(); // 显示第二个窗口


}


void Map::on_btn2_clicked()
{
    if (!lv2) { // 如果map还没创建，则创建它

        lv2= new level2(nullptr);
    }
    this->hide(); // 隐藏当前窗口
    lv2->show(); // 显示第二个窗口

}


void Map::on_btn3_clicked()
{

}


void Map::on_btn4_clicked()
{

}


void Map::on_btn5_clicked()
{

}


//该模块作者自行添加图片，做好界面布局
