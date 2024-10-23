#include "level2.h"
#include <QKeyEvent>
#include <QDebug>
#include<QTimer>
#include<QMessageBox>
#include"windows.h"


double vx1;
double vy1;
double ax1;
double ay1;

double dx1;
double dy1;

level2::level2(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::level2) {
    ui->setupUi(this);


    //配置关卡信息
    this->setFixedSize(900,506);
    // //配置图标
    // this->setWindowIcon(QPixmap(":/new/prefix1/res/man.png"));
    //设置标题
    this->setWindowTitle("万里遐征");

    mScene.setSceneRect(QRect(0,0,900,506));
    mGameView.setSceneRect(QRect(0,0,900,506));


    // //箱子
    // box.setPixmap(QPixmap(":/box"));
    // mBackGround.setPixmap(QPixmap(":/scene0"));
    // box.setPos(540,215);

    // box1.setPixmap(QPixmap(":/box"));
    // mBackGround.setPixmap(QPixmap(":/scene0"));
    // box1.setPos(25,275);

    // box2.setPixmap(QPixmap(":/box"));
    // mBackGround.setPixmap(QPixmap(":/scene0"));
    // box2.setPos(100,140);




    mBackGround.setPixmap(QPixmap(":/new/prefix1/res/level2.png")); // 注意替换为你的图片路径
    Fire.setPixmap(QPixmap(":/new/prefix1/res/man.png"));


    Fire.setPos(60,398);



    mScene.addItem(&mBackGround);
    mScene.addItem(&Fire);
    mGameView.setScene(&mScene);
    mGameView.setParent(this);
    mGameView.resize(this->width(), this->height());
    mGameView.show();
    id1=startTimer(10);
    //音乐
    this->mMediaBG.setSource(QUrl("qrc:/LevelMusic.wav"));
    this->mMediaBG.setLoopCount(QSoundEffect::Infinite);
    this->mMediaBG.play();


}
void level2::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    QPixmap suc;
    suc.load(":/succeed.jpg");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    if(ret2==QMessageBox::Ok)
        painter.drawPixmap(0,0,this->width(),this->height(),suc);
}

//判断冰面
int judgeicefloor1(double X,double Y){
    if(X>=395&&X<=445&&Y>=398&&Y<=410) return 1;
    return 0;
}
//判断毒面
int judgepoisonousfloor1(double X,double Y)
{
    if(X>=378&&X<=423&&Y>=306&&Y<=340)return 1;
    return 0;
}

//判断地面
int level2::judgefloor(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if ((X >= 93 && X <= 130 && Y >= 95 && Y <= 105) ||
        (X >= 18 && X <= box1.x() + 36 && Y >= 237 && Y <= 240) ||
        (X >= 518 && X <= 565 && Y >= 175 && Y <= 185) ||
        (X >= 18 && X <= 562 && Y >= 398 && Y <= 410) ||
        (X >= 515 && X <= 565 && Y >= 354 && Y <= 370) ||
        (X >= 240 && X <= 510 && Y >= 306 && Y <= 315) ||
        (X >= 20 && X <= 240 && Y >= 277 && Y <= 285) ||
        (X >= 70 && X <= 285 && Y >= 195 && Y <= 210) ||
        (X >= 285 && X <= 565 && Y >= 215 && Y <= 230) ||
        (X >= 20 && X <= 500 && Y >= 140 && Y <= 160) ||
        (X >= 15 && X <= 95 && Y >= 80 && Y <= 100) ||
        (X >= 160 && X <= 560 && Y >= 65 && Y <= 75))
    {
        return 1;
    }
    return 0;
}
//判断是否撞左墙
int judgeleftwall1(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if ((X <= 134 && Y >= 105 && Y <= 146) ||
        (X <= 95 && Y >= 100 && Y <= 145) ||
        X <= 20 ||
        (X >= 55 && X <= 60 && Y >= 237 && Y <= 281) ||
        (X >= 255 && X <= 260 && Y >= 280 && Y <= 310) ||
        (X >= 280 && X <= 295 && Y >= 213 && Y <= 218))
        return 1;
    return 0;
}
//判断是否撞右墙
int judgerightwall1(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
    if (X >= 560 || (X >= 515 && Y <= 410 && Y >= 397) || (X >= 516 && Y >= 185 && Y <= 220))
        return 1;
    return 0;
}
//判断头是否会撞墙
int judgehead1(double X, double Y) {
    // 根据新的背景尺寸调整坐标范围
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
    if(X>=470&&X<=495&&Y>=55&&Y<=75)return 1;
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
                mGameView.hide();
                QTimer::singleShot(4000, this, &QWidget::close);
            }
        }
        int modex= 0;
        int modey= 0;
        int t=1;
        if(GetAsyncKeyState('A')&0x8000)modex--;
        if(GetAsyncKeyState('W')&0x8000)modey++;
        if(GetAsyncKeyState('D')&0x8000)modex++;
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
