#include "map.h"
#include "ui_map.h"
#include <QMessageBox>
#include"config.h"
#include"backpack.h"


Map::Map(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Map),
    lv1(nullptr),
    lv2(nullptr)
{
    ui->setupUi(this);

    initScene();



    // Example: Add item to backpack after completing a level (simulated here)


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
    ui->btn1->setText("黄<br>山");

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

    lv1->show(); // 显示第二个窗口
    additems.addToBackpack(":/new/prefix1/bag_picture/huangshan.png","    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓“五岳归来不看山，黄山归来不看岳”。");
    additems.addToBackpack(":/new/prefix1/bag_picture/tiantaishan.png","    天台山位于浙江省台州市，明万历四十一年徐霞客曾在此停顿近一个月。或许是沉迷于天台山“峰萦水映，木秀石奇；青松紫蕊；攒峦夹翠”的秋景，亦或是和国清寺大师有“如遇故知”的欢喜，终让“游天台山记”成为徐霞客传奇旅途的开篇之作。");
}


void Map::on_btn2_clicked()
{
    if (!lv2) { // 如果map还没创建，则创建它

        lv2= new level2(nullptr);
    }
    this->hide(); // 隐藏当前窗口
    lv2->show(); // 显示第二个窗口
   // addToBackpack(":/images/image2.png");
    //QMessageBox::information(this, "哟呵", "你教徐霞客拍摄了一张照片!");
    additems.addToBackpack(":/new/prefix1/bag_picture/tiantaishan.png","    天台山位于浙江省台州市，明万历四十一年徐霞客曾在此停顿近一个月。或许是沉迷于天台山“峰萦水映，木秀石奇；青松紫蕊；攒峦夹翠”的秋景，亦或是和国清寺大师有“如遇故知”的欢喜，终让“游天台山记”成为徐霞客传奇旅途的开篇之作。");
}

void Map::on_btn3_clicked()
{

    additems.addToBackpack(":/new/prefix1/bag_picture/fenglin.png","    天台山位于浙江省台州市，明万历四十一年徐霞客曾在此停顿近一个月。或许是沉迷于天台山“峰萦水映，木秀石奇；青松紫蕊；攒峦夹翠”的秋景，亦或是和国清寺大师有“如遇故知”的欢喜，终让“游天台山记”成为徐霞客传奇旅途的开篇之作。");
}


void Map::on_btn4_clicked()
{
     additems.addToBackpack(":/new/prefix1/bag_picture/xuankongsi.png","    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓“五岳归来不看山，黄山归来不看岳”。");

}


void Map::on_btn5_clicked()
{
     additems.addToBackpack(":/new/prefix1/bag_picture/shaolinsi.png","    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓“五岳归来不看山，黄山归来不看岳”。");
}

//该模块作者自行添加图片，做好界面布局



//打开背包

void Map::on_backpackButton_clicked()
{

     //QMessageBox::information(this, "哟呵", "你拍摄了一张照片!");
     backpack *backpackWindow = new backpack(this);
     backpackWindow->show();

}

