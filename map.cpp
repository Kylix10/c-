#include "map.h"
#include "ui_map.h"
#include <QMessageBox>
#include"config.h"
#include"backpack.h"
#include<QToolTip>
#include<QFont>
Map::Map(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Map),
    lv1(nullptr),
    lv2(nullptr),
    lv3(nullptr),
    lv4(nullptr),
    lv5(nullptr)
{
    ui->setupUi(this);

    initScene();

    // 安装事件过滤器到所有需要的按钮上，例如 ui->btn1
    ui->btn1->installEventFilter(this);
    ui->btn2->installEventFilter(this);
    ui->btn3->installEventFilter(this);
    ui->btn4->installEventFilter(this);
    ui->btn5->installEventFilter(this);

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

    // 检查lv1指针是否为nullptr，并仅在非空时删除它
    if (lv3 != nullptr) {
        delete lv3;
        lv3 = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

    // 检查lv1指针是否为nullptr，并仅在非空时删除它
    if (lv4 != nullptr) {
        delete lv4;
        lv4 = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

    // 检查lv1指针是否为nullptr，并仅在非空时删除它
    if (lv5 != nullptr) {
        delete lv5;
        lv5 = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
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

void Map::handleLevel1Completion()
{
    // 启用第二关按钮
    ui->btn2->setEnabled(true);

    // 添加相关物品到背包
    additems.addToBackpack(
        ":/new/prefix1/bag_picture/huangshan.png",
        "    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山"
        "四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓\"五岳归来不看山，黄山归来不看岳\"。");

    // 确保地图界面显示
    this->show();

    // 清理关卡实例
    if (lv1) {
        lv1->deleteLater();  // 使用deleteLater而不是直接delete
        lv1 = nullptr;
    }
}
//以下处理各关卡按钮点击跳转对应关卡界面的操作，一个按钮的点击声明一个对象
void Map::on_btn1_clicked()
{
    if (!lv1) { // 如果map还没创建，则创建它

        lv1= new level1(nullptr);
    }

    lv1->show(); // 显示第二个窗口
    additems.addToBackpack(":/new/prefix1/bag_picture/huangshan.png","    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓“五岳归来不看山，黄山归来不看岳”。");

}


void Map::on_btn2_clicked()
{
    if (!lv2) { // 如果map还没创建，则创建它

        lv2= new level2(nullptr);
    }
   // 隐藏当前窗口
    lv2->show(); // 显示第二个窗口

    //QMessageBox::information(this, "哟呵", "你教徐霞客拍摄了一张照片!");
    additems.addToBackpack(":/new/prefix1/bag_picture/tiantaishan.png","    天台山位于浙江省台州市，明万历四十一年徐霞客曾在此停顿近一个月。或许是沉迷于天台山“峰萦水映，木秀石奇；青松紫蕊；攒峦夹翠”的秋景，亦或是和国清寺大师有“如遇故知”的欢喜，终让“游天台山记”成为徐霞客传奇旅途的开篇之作。");
}

void Map::on_btn3_clicked()
{
    if (!lv3) { // 如果map还没创建，则创建它

        lv3= new level3(nullptr);
    }

    lv3->show(); // 显示第二个窗口

    additems.addToBackpack(":/new/prefix1/bag_picture/fenglin.png","    “天下山峰何其多，惟有此处峰成林！”徐霞客初游万峰林便有此诗传世。而在崇祯十年第二次踏上这片土地更是惊叹其“磅礴数千里，为西南奇胜”，壮丽浩然无需多言");
}


void Map::on_btn4_clicked()
{
    if (!lv4) { // 如果map还没创建，则创建它

        lv4= new level4(nullptr);
    }

    lv4->show(); // 显示第二个窗口

     additems.addToBackpack(":/new/prefix1/bag_picture/xuankongsi.png","    明崇祯六年夏，徐霞客登恒山而见悬空寺。在西崖之半，“层楼高悬，曲榭斜倚”，遂“仰之神飞，鼓勇独登”，记其“天下巨观”。");

}


void Map::on_btn5_clicked()
{
    if (!lv5) { // 如果map还没创建，则创建它

        lv5= new level5(nullptr);
    }

    lv5->show(); // 显示第二个窗口

     additems.addToBackpack(":/new/prefix1/bag_picture/shaolinsi.png","    明天启三年春，徐霞客登嵩山游少林。正值身强力壮之年，却也显得修身养性，连五日留居名寺，参佛礼征辟山迹。或许这便是少林文化的感染吧。");
}

//该模块作者自行添加图片，做好界面布局

//打开背包

void Map::on_backpackButton_clicked()
{

     backpack *backpackWindow = new backpack(this);
     backpackWindow->show();

}

bool Map::eventFilter(QObject *obj, QEvent *event)
{


    if (obj == ui->btn1) {

        if (event->type() == QEvent::Enter) {
            QString toolTipText = "“五岳归来不看山，黄山归来不看岳”";
            QPoint pos = mapToGlobal(ui->btn1->rect().center());
            // 向右下方偏移10个像素，可根据实际情况调整偏移量
            pos += QPoint(100, 50);
            QToolTip::showText(pos, toolTipText, ui->btn1); // 应用字体
        } else if (event->type() == QEvent::Leave) {
            QToolTip::hideText();
        }
    }
    else if (obj == ui->btn2) {
        if (event->type() == QEvent::Enter) {
            QString toolTipText = "“峰萦水映，木秀石奇；青松紫蕊；攒峦夹翠”";
            QPoint pos2 = mapToGlobal(ui->btn1->rect().center());
            // 向右下方偏移10个像素，可根据实际情况调整偏移量
            pos2 += QPoint(330, 80);
           QPoint pos = mapToGlobal(ui->btn2->rect().bottomRight());
           QToolTip::showText(pos2, toolTipText, ui->btn2);

        } else if (event->type() == QEvent::Leave) {
            QToolTip::hideText();
        }
    }
    else if (obj == ui->btn3) {
        if (event->type() == QEvent::Enter) {
            QString toolTipText = "“天下山峰何其多，惟有此处峰成林！”";
            QPoint pos3 = mapToGlobal(ui->btn1->rect().center());
            // 向右下方偏移10个像素，可根据实际情况调整偏移量
            pos3 += QPoint(80, 290);
            QToolTip::showText(pos3, toolTipText, ui->btn3);
        } else if (event->type() == QEvent::Leave) {
            QToolTip::hideText();
        }
    }
    else if (obj == ui->btn4) {
        if (event->type() == QEvent::Enter) {
            QString toolTipText = "“天下巨观！”";
            QPoint pos4 = mapToGlobal(ui->btn1->rect().center());
            // 向右下方偏移10个像素，可根据实际情况调整偏移量
            pos4 += QPoint(360, 270);
            QToolTip::showText(pos4, toolTipText, ui->btn4);
        } else if (event->type() == QEvent::Leave) {
            QToolTip::hideText();
        }
    }
    else if (obj == ui->btn5) {
        if (event->type() == QEvent::Enter) {
            QString toolTipText = "“嵩山天下奥，少室险奇特。不到三皇寨，不算少林客”";
            QPoint pos5 = mapToGlobal(ui->btn1->rect().center());
            // 向右下方偏移10个像素，可根据实际情况调整偏移量
            pos5 += QPoint(370, 370);
            QToolTip::showText(pos5, toolTipText, ui->btn5);
        } else if (event->type() == QEvent::Leave) {
            QToolTip::hideText();
        }
    }

    // 对于未处理的事件，调用基类的 eventFilter 方法
    return QObject::eventFilter(obj, event);
}
