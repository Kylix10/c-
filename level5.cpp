#include "level5.h"
#include "ui_level5.h"
#include <QVector>
#include "map.h"
#include <QVBoxLayout>
#include"config.h"
#include <QVector>
level5::level5(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level5)
    , label(new QLabel(this))
    , timer1(new QTimer(this))
{
    ui->setupUi(this);


    //设置背景图片
    // 创建背景 QLabel
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setFixedSize(this->size()); // 设置与窗口大小相同
    backgroundLabel->setStyleSheet("QLabel { border: none; margin: 0; padding: 0; background-image: url(:/new/prefix1/res/level5.png); background-repeat: no-repeat; background-position: center; }");
    backgroundLabel->setAlignment(Qt::AlignCenter); // 确保图片居中（虽然对于背景通常不需要）

    //初始化窗口
    initScene();
    //黑窗文本
    label->setStyleSheet("QLabel { "
                         "background-color: black;"
                         "color: white; " // 设置文字颜色，以便在深色背景上清晰可见
                         "padding: 10px; " // 增加内边距，避免文字直接贴边
                         "font-size: 25px; " // 设置文字大小
                         "font-family:隶书;"
                         "}");
    label->setText("俯环其后者为九乳峰，蜿蜒东接太室，其阴则少林寺在焉。\r\n寺甚整丽，庭中新旧碑森列成行，俱完善。\r\n夹墀二松，高伟而整，如有尺度。\r\n                  ——《游嵩山日记》");
    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(true);
    label->raise();//置于顶层
    label->setVisible(true); // 初始显示
    // 创建布局并将label添加到其中
    QVBoxLayout *layout = new QVBoxLayout(this); // 假设this指向的是父窗口或包含label的widget
    layout->addWidget(label);
    layout->setContentsMargins(0, 0, 0, 0); // 设置布局的边距为0（如果需要的话）
    layout->setSpacing(0); // 设置布局中控件之间的间距为0（如果需要的话）
    // 连接 QTimer 的 timeout 信号到 slot 函数
    connect(timer1, &QTimer::timeout, this, &level5::switchLabels);
    // 启动 QTimer，设置延迟时间（例如 3 秒）
    timer1->start(3000); // 3000 毫秒 = 3 秒
}
void level5::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle("少林寺");

}
//黑窗
void level5::switchLabels()
{
    // 停止计时器
    qDebug() << "Switching labels";
    timer1->stop();

    // 切换标签的可见性
    label->setVisible(false);
    // label->hide();

}
level5::~level5()
{
    delete ui;
}
