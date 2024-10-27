#include "level2.h"
#include <QKeyEvent>
#include <QDebug>
#include<QTimer>
#include<QMessageBox>
#include"windows.h"
#pragma comment  (lib, "User32.lib")
#include"config.h"
#include <QVector>

double vx1;
double vy1;
double ax1;
double ay1;
double dx1;
double dy1;
// 背景图片索引和定时器ID用于图片切换
int backgroundIndex = 0;
QTimer *backgroundTimer = nullptr;
QVector<QPixmap> backgroundImages;

level2::level2(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::level2),boxItem(nullptr) {
    ui->setupUi(this);

    //配置关卡信息
    initScene();
    // //配置图标
    // this->setWindowIcon(QPixmap(":/new/prefix1/res/man.png"));

    // 初始化背景图片
    backgroundImages.append(QPixmap(":/new/prefix1/res/level2(1).png"));
    backgroundImages.append(QPixmap(":/new/prefix1/res/level2(2).png"));
    // ... 添加更多背景图片到 backgroundImages 中

    mScene.setSceneRect(QRect(0, 0, 900, 506));
    mGameView.setSceneRect(QRect(0, 0, 900, 506));
    mBackGround.setPixmap(backgroundImages[backgroundIndex]);
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
    backgroundTimer = new QTimer(this);
    connect(backgroundTimer, &QTimer::timeout, this, &level2::changeImg);
    backgroundTimer->start(500); // 每500毫秒切换一次背景



    mScene.addItem(&mBackGround);
    mScene.addItem(&Fire);
    mGameView.setScene(&mScene);

    mScene.addItem(boxItem);

    mGameView.setParent(this);
    mGameView.resize(this->width(), this->height());
    mGameView.show();
    id1=startTimer(10);
    //音乐
    this->mMediaBG.setSource(QUrl("qrc:/LevelMusic.wav"));
    this->mMediaBG.setLoopCount(QSoundEffect::Infinite);
    this->mMediaBG.play();

    //物品拾取部分
    QPixmap pixmap_item(":/new/prefix1/res/item2_.png");
    // 确保 QLabel 的 objectName 在 Qt Designer 中已设置为 labelPicture
    ui->item2->setPixmap(pixmap_item);
    // 如果需要调整 QLabel 的大小以适合图片
    ui->item2->setScaledContents(true);
    ui->item2->raise();//置于顶层
    ui->item2->move(60,270);

    //物品拾取对话
    QPixmap pixmap_dialogue(":/new/prefix1/dialogue.png");
    // 确保 QLabel 的 objectName 在 Qt Designer 中已设置为 labelPicture
    ui->dia2->setPixmap(pixmap_dialogue);
    // 如果需要调整 QLabel 的大小以适合图片
    ui->dia2->setScaledContents(true);
    ui->dia2->raise();//置于顶层
    ui->dia2->move(250,260);
     ui->dia2->hide();



}
void level2::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;

}
void level2::changeImg() {
    // 切换背景图片
    backgroundIndex = (backgroundIndex + 1) % backgroundImages.size();
    mBackGround.setPixmap(backgroundImages[backgroundIndex]);
}



void level2::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}

//判断冰面
int judgeicefloor1(double X,double Y){
    if(X>=400&&X<=435&&Y>=398&&Y<=410) return 1;
    return 0;
}
//判断毒面
int judgepoisonousfloor1(double X,double Y)
{
    if(X>=540&&X<=550&&Y>=306&&Y<=340)return 1;
    return 0;
}
//判断地面
int level2::judgefloor(double X, double Y) {
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
int judgeleftwall1(double X, double Y) {
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
int judgerightwall1(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if (X >= 790 || (X >= 720 && Y <= 410 && Y >= 397) || (X >= 720 && Y >= 185 && Y <= 220))
        //最右边的墙      //最底层最右的墙                       //第三层最右的墙
        return 1;
    return 0;
}
//判断头是否会撞墙
int judgehead1(double X, double Y) {//目测这函数不用改

    if ((X >= 15 && X <= 190 && Y >= 365 && Y <= 385) ||
        (X >= 250 && X <= 500 && Y >= 335 && Y <= 355) ||
        (X >= 20 && X <= 500 && Y >= 170 && Y <= 190) ||
        (X >= 160 && X <= 560 && Y >= 110 && Y <= 120))
        return 1;
    return 0;
}
//判断是否胜利
int judgewin1(double X,double Y)
{
    if(X>=700&&X<=720&&Y>=55&&Y<=75)return 1;
    return 0;
}

//拾取物品
int level2::pick(){
    QRectF targetRect(60,298, 100, 100); // 设定目标矩形区域
    // 检查火娃是否在目标矩形内
    QPointF scenePos = Fire.mapToScene(Fire.boundingRect().center()); // 或者使用 fire->pos() + 偏移量，取决于您如何定义火娃的中心
    if (targetRect.contains(scenePos)) {
        qDebug() << "Fire is inside the target rectangle!";
        return 1;
    }
    else
        return 0;
}


void level2::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==id1)
    {
        if(judgepoisonousfloor1(Fire.x(),Fire.y())==1||judgeicefloor1(Fire.x(),Fire.y())==1)
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
        if(judgewin1(Fire.x(),Fire.y())==1)
        {
            Fire.setPos(20,398);
            ret2=QMessageBox::information(this,"闯关成功","恭喜你闯关成功！",QMessageBox::Ok);
            if(ret2==QMessageBox::Ok)
            {
                QTimer::singleShot(4000, this, &QWidget::close);
                this->hide();
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
            vx1=0;
        if(modex==1)
        {
            if(judgerightwall1(Fire.x(),Fire.y())==1)vx1=0;
            else vx1=2.2;
        }
        if(modex==-1)
        {
            if(judgeleftwall1(Fire.x(),Fire.y())==1)vx1=0;
            else
            {
                vx1=-2.2;
            }
        }
        if(judgefloor(Fire.x(),Fire.y())==1)
        {
            if(modey==1)vy1=6;
            else
            {
                vy1=0;
                ay1=0;
            }
            t=1;
        }
        if(judgefloor(Fire.x(),Fire.y())==0)
        {
            if(judgehead1(Fire.x(),Fire.y())==1)
                vy1=-vy1;
            if(vy1<=6&&vy1>=-6)
            {
                ay1=0.5;
                vy1-=ay1;
            }
            if(vy1>6)
                vy1=6;
            if(vy1<-6)
                vy1=-6;

        }

        if((pick())&&flag){
            ui->item2->hide();
            additems.addToBackpack(":/new/prefix1/bag_picture/it2.png"," 映荫溪色，香风来处，玉兰芳草，处处不绝。");
            QMessageBox::information(this, "拾取物品", "山路上捡到一枚银杏叶!");
             ui->dia2->show();
             flag=false;
        }

        double x=Fire.x();
        double y=Fire.y();
        dx1+=vx1;
        dy1+=vy1*t+ay1*t*t/2;
        t++;
        x+=dx1;
        y-=dy1;

        Fire.setPos(x,y);
        dx1=0,dy1=0;
        modex=0;modey=0;
    }
}
