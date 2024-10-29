
#include "level4.h"
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
double vx4;
double vy4;
double ax4;
double ay4;
double dx4;
double dy4;
// 背景图片索引和定时器ID用于图片切换
int backgroundIndex4 = 0;
QTimer *backgroundTimer4 = nullptr;
QVector<QPixmap> backgroundImages4;

level4::level4(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::level4)
    , label(new QLabel(this))
    , timer1(new QTimer(this))

{
    ui->setupUi(this);

    //配置关卡信息
    initScene();
    // //配置图标
    // this->setWindowIcon(QPixmap(":/new/prefix1/res/man.png"));

    // 初始化背景图片
    backgroundImages4.append(QPixmap(":/new/prefix1/res/level4(1).png"));
    backgroundImages4.append(QPixmap(":/new/prefix1/res/level4(1).png"));
    // ... 添加更多背景图片到 backgroundImages4 中

    mScene.setSceneRect(QRect(0, 0, 900, 506));
    mGameView.setSceneRect(QRect(0, 0, 900, 506));
    mBackGround.setPixmap(backgroundImages4[backgroundIndex4]);
    Fire.setPixmap(QPixmap(":/new/prefix1/res/man.png"));
    Fire.setPos(60, 398);

    mScene.addItem(&mBackGround);
    mScene.addItem(&Fire);
    mGameView.setScene(&mScene);
    mGameView.setParent(this);
    mGameView.resize(this->width(), this->height());
    mGameView.show();

    id1=startTimer(10);

    // 初始化背景切换定时器
    backgroundTimer4 = new QTimer(this);
    connect(backgroundTimer4, &QTimer::timeout, this, &level4::changeImg);
    backgroundTimer4->start(500); // 每500毫秒切换一次背景

    //音乐
    this->mMediaBG.setSource(QUrl("qrc:/LevelMusic.wav"));
    this->mMediaBG.setLoopCount(QSoundEffect::Infinite);
    this->mMediaBG.play();

    //物品拾取部分
    //

    label->setStyleSheet("QLabel { "
                         "background-color: black;"
                         "color: white; " // 设置文字颜色，以便在深色背景上清晰可见
                         "padding: 10px; " // 增加内边距，避免文字直接贴边
                         "font-size: 25px; " // 设置文字大小
                         "font-family:隶书;"
                         "}");
    label->setText("西崖之半，层楼高悬，曲榭斜倚，望之如蜃，吐重台者，悬空寺也。\r\n入则楼阁高下，槛路屈曲。崖既矗削，为天下巨观，而寺之点缀，兼能尽胜。\r\n                  ——《游恒山日记》");
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
    connect(timer1, &QTimer::timeout, this, &level4::switchLabels);
    // 启动 QTimer，设置延迟时间（例如 3 秒）
    timer1->start(3000); // 3000 毫秒 = 3 秒

}

void level4::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;

}
void level4::changeImg() {
    // 切换背景图片
    backgroundIndex4 = (backgroundIndex4 + 1) % backgroundImages4.size();
    mBackGround.setPixmap(backgroundImages4[backgroundIndex4]);
}



void level4::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle("悬空寺");

}
//黑窗
void level4::switchLabels()
{
    // 停止计时器
    qDebug() << "Switching labels";
    timer1->stop();

    // 切换标签的可见性
    label->setVisible(false);
    // label->hide();

}
//判断冰面
int level4::judgeicefloor3(double X,double Y){
    if(X>=400&&X<=435&&Y>=398&&Y<=410) return 1;
    return 0;
}
//判断毒面
int level4::judgepoisonousfloor3(double X,double Y)
{
    if(X>=540&&X<=550&&Y>=306&&Y<=340)return 1;
    return 0;
}
//判断地面
int level4::judgefloor(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if ((X >= 93 && X <= 130 && Y >= 95 && Y <= 105) ||
        (X >= 18 && X <= box1.x() + 36 && Y >= 237 && Y <= 240) ||
        (X >= 720 && X <=800 && Y >= 175 && Y <= 185) ||//第三层箱子地面
        (X >= 18 && X <= 900 && Y >= 398 && Y <= 410) ||//最底部地面
        (X >= 720 && X <= 800 && Y >= 354 && Y <= 370) ||//最底部最右
        (X >= 240 && X <= 710 && Y >= 306 && Y <= 315) ||//第二层较低侧
        (X >= 10 && X <= 340 && Y >= 277 && Y <= 306) ||//第二次较高侧
        (X >= 70 && X <= 360 && Y >= 195 && Y <= 210) ||//第三层较高侧
        (X >= 360 && X <= 790 && Y >= 215 && Y <= 230) ||//第三次较低侧
        (X >= 20 && X <= 710 && Y >= 140 && Y <= 160) ||//第四层地面
        (X >= 10 && X <= 110 && Y >= 80 && Y <= 100) ||
        (X >= 160 && X <= 790 && Y >= 65 && Y <= 75))//第五层
    {
        return 1;
    }
    return 0;
}
//判断是否撞左墙
int level4::judgeleftwall3(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if ((X <= 120 && Y >= 105 && Y <= 146) ||
        (X <= 95 && Y >= 100 && Y <= 145) ||
        X <= 20 ||//最左墙
        (X >= 55 && X <= 60 && Y >= 237 && Y <= 281) ||
        (X >= 255 && X <= 350 && Y >= 280 && Y <= 310) ||//第二层中间斜坡
        (X >= 20 && X <= 295 && Y >= 213 && Y <= 218))
        return 1;
    return 0;
}
//判断是否撞右墙
int level4::judgerightwall3(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if (X >= 790 || (X >= 720 && Y <= 410 && Y >= 397) || (X >= 720 && Y >= 185 && Y <= 220))
        //最右边的墙      //最底层最右的墙                       //第三层最右的墙
        return 1;
    return 0;
}
//判断头是否会撞墙
int level4::judgehead3(double X, double Y) {//目测这函数不用改

    if ((X >= 15 && X <= 190 && Y >= 365 && Y <= 385) ||
        (X >= 250 && X <= 500 && Y >= 335 && Y <= 355) ||
        (X >= 20 && X <= 500 && Y >= 170 && Y <= 190) ||
        (X >= 160 && X <= 560 && Y >= 110 && Y <= 120))
        return 1;
    return 0;
}
//判断是否胜利
int level4::judgewin3(double X,double Y)
{
    if(X>=700&&X<=720&&Y>=55&&Y<=75)return 1;
    return 0;
}

//拾取物品
int level4::pick(int x,int y,int wide,int height){
    QRectF targetRect(x,y,wide,height); // 设定目标矩形区域
    // 检查人是否在目标矩形内
    QPointF scenePos = Fire.mapToScene(Fire.boundingRect().center()); // 或者使用 fire->pos() + 偏移量，取决于您如何定义火娃的中心
    if (targetRect.contains(scenePos)) {
        qDebug() << "The character is inside the target rectangle!";
        return 1;
    }
    else
        return 0;
    qDebug() << "OUT";
}


void level4::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==id1)
    {
        if(judgepoisonousfloor3(Fire.x(),Fire.y())==1||judgeicefloor3(Fire.x(),Fire.y())==1)
        {
            Fire.setPos(20,398);

            int ret1=QMessageBox::question(this,"游戏结束","是否重开？",QMessageBox::Yes,QMessageBox::No);
            if(ret1==QMessageBox::Yes)
            {
                Fire.setPos(20,398);
                this->show();
            }
            if(ret1==QMessageBox::No){
                this->close();
            }
        }
        if(judgewin3(Fire.x(),Fire.y())==1)
        {
            Fire.setPos(1000,1000);
            ret2=QMessageBox::information(this,"闯关成功","恭喜你闯关成功！",QMessageBox::Ok);
            if(ret2==QMessageBox::Ok)
            {
                QTimer::singleShot(4000, this, &QWidget::close);
                this->close();
                Map m ;
                m.show();
            }
        }
        int modex= 0;
        int modey= 0;
        int t=1;

        if(GetAsyncKeyState('W')&0x8000)modey++;
        if(GetAsyncKeyState('A')&0x8000) {
            modex--;
            Fire.setPixmap(QPixmap(":/new/prefix1/res/manleft.png"));// 面向左
        }
        if(GetAsyncKeyState('D')&0x8000) {
            modex++;
            Fire.setPixmap(QPixmap(":/new/prefix1/res/man.png"));// 面向右的图片路径 // 面向右
        }
        if(modex==0)
            vx4=0;
        if(modex==1)
        {
            if(judgerightwall3(Fire.x(),Fire.y())==1)vx4=0;
            else vx4=2.2;
        }
        if(modex==-1)
        {
            if(judgeleftwall3(Fire.x(),Fire.y())==1)vx4=0;
            else
            {
                vx4=-2.2;
            }
        }
        if(judgefloor(Fire.x(),Fire.y())==1)
        {
            if(modey==1)vy4=6;
            else
            {
                vy4=0;
                ay4=0;
            }
            t=1;
        }
        if(judgefloor(Fire.x(),Fire.y())==0)
        {
            if(judgehead3(Fire.x(),Fire.y())==1)
                vy4=-vy4;
            if(vy4<=6&&vy4>=-6)
            {
                ay4=0.5;
                vy4-=ay4;
            }
            if(vy4>6)
                vy4=6;
            if(vy4<-6)
                vy4=-6;

        }

        // if((pick(60,270, 50, 50))&&flag==1){
        //     ui->item2->hide();

        //     additems.addToBackpack(":/new/prefix1/bag_picture/it2.png"," 映荫溪色，香风来处，玉兰芳草，处处不绝。");

        //     ui->dia2->show();
        //     flag=2;
        //     QEventLoop loop;
        //     QTimer::singleShot(2000, &loop, &QEventLoop::quit); // 2秒后退出loop
        //     loop.exec(); // 进入事件循环，等待退出

        //     ui->dia2->hide();
        //     ui->dia2_2->show();
        //     QTimer::singleShot(1500, &loop, &QEventLoop::quit); // 2秒后退出loop
        //     loop.exec(); // 进入事件循环，等待退出
        //     ui->dia2_2->hide();
        //     QMessageBox::information(this, "拾取物品", "山路上捡到一枚银杏叶!");
        //     flag=0;
        // }


        double x=Fire.x();
        double y=Fire.y();
        dx4+=vx4;
        dy4+=vy4*t+ay4*t*t/2;
        t++;
        x+=dx4;
        y-=dy4;

        Fire.setPos(x,y);
        dx4=0,dy4=0;
        modex=0;modey=0;
    }
}