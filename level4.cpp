#include "level4.h"
#include "ui_level4.h"
#include <QKeyEvent>
#include <QDebug>
#include<QTimer>
#include<QMessageBox>
#include"windows.h"
#pragma comment  (lib, "User32.lib")
#include"config.h"
#include <QVector>
#include "map.h"
#include <QVBoxLayout>
level4::level4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level4)
{
    ui->setupUi(this);
    initScene();
}

level4::~level4()
{
    delete ui;
}
void level4::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle("天台山");

}
