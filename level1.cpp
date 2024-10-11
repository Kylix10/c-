#include "level1.h"
#include "ui_level1.h"

#include"config.h"

#include <QPixmap>

level1::level1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level1)
{
    ui->setupUi(this);

    initScene();


    //下面这三行是设置了人物图片，如果有别的需要可以删除用自己的办法写

    QPixmap pixmap(":/new/prefix1/res/man.png");
    // 确保 QLabel 的 objectName 在 Qt Designer 中已设置为 labelPicture
    ui->Man->setPixmap(pixmap);
    // 如果需要调整 QLabel 的大小以适合图片
    ui->Man->setScaledContents(true);

    ui->Man->move(422, 141);

    QPixmap backgroundPixmap(":/new/prefix1/res/level1.jpg"); // 注意替换为你的图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);
}

level1::~level1()
{
    delete ui;
}

void level1::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}

void level1::pick(){
    QRect labelRect = ui->Man->geometry(); // 获取QLabel的矩形区域
    QRect targetRect(422, 160, 28, 28); // 设定目标矩形区域

    // 检测两个矩形区域是否有重叠
    if (labelRect.intersects(targetRect)) {
        // QLabel的边界触及或落入了目标坐标范围
    }
}





