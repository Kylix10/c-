#include "level1.h"
#include "ui_level1.h"

#include"config.h"

level1::level1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level1)
{
    ui->setupUi(this);

    initScene();


    //下面这三行是设置了人物图片，如果有别的需要可以删除用自己的办法写

    QPixmap pixmap(":/new/prefix1/character1.png");
    // 确保 QLabel 的 objectName 在 Qt Designer 中已设置为 labelPicture
    ui->Man->setPixmap(pixmap);
    // 如果需要调整 QLabel 的大小以适合图片
    ui->Man->setScaledContents(true);
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
