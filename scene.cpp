#include "scene.h"
#include "ui_scene.h"


#include"config.h"

Scene::Scene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Scene),
    map(nullptr)//初始时第二个窗口的指针为空
{

    ui->setupUi(this);

    initScene();

    connect(ui->Yesbtn, &QPushButton::clicked, this, &Scene::on_Yesbtn_clicked); // 连接信号与槽


}

Scene::~Scene()
{
    delete ui;

    // 检查map指针是否为nullptr，并仅在非空时删除它
    if (map != nullptr) {
        delete map;
        map = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

}

void Scene::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}


void Scene::on_Yesbtn_clicked()
{

    if (!map) { // 如果map还没创建，则创建它

        map= new Map(nullptr);
    }
    this->hide(); // 隐藏当前窗口
    map->show(); // 显示第二个窗口
}


