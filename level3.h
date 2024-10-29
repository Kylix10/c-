#ifndef LEVEL3_H
#define LEVEL3_H

#include "ui_level3.h"
#include <QMainWindow>
#include<QPainter>
#include <QKeyEvent>
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsView>//视图
#include<QGraphicsScene>//场景
#include<QList>//链表
#include<QMediaPlayer>
#include<QSoundEffect>
#include <QWidget>
#include <QTimer>
#include <QPoint>
#include <QPixmap>
#include<QLabel>
#include <additiem.h>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QPointF>
#include <QRectF>



QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
class level3 : public QWidget
{
    Q_OBJECT
public:
    explicit level3(QWidget *parent = nullptr);

    void initScene();
    int pick(int x,int y,int wide,int height);

protected:
    void paintEvent(QPaintEvent *event);

signals:
private slots:

    void switchLabels();
private:
    QVector<BackpackItem> l1_pictures; // 存储图片路径的背包
    int ret2;
    QTimer*PersonMoveTimer;
    Ui::level3 *ui;
    QPoint position;
    QPixmap image;
    QGraphicsView mGameView;//游戏视图
    QGraphicsScene mScene;//场景
    QGraphicsPixmapItem mBackGround;//背景元素
    QGraphicsPixmapItem Fire;//火娃
    QGraphicsPixmapItem box;//箱子
    QGraphicsPixmapItem box1;//箱子
    QGraphicsPixmapItem box2;//箱子
    QLabel *label;
    QTimer *timer1;


    int judgeicefloor3(double X,double Y);
    int judgepoisonousfloor3(double X,double Y);
    int judgeleftwall3(double X, double Y);
    //判断是否撞右墙
    int judgerightwall3(double X, double Y);
    //判断头是否会撞墙
    int judgehead3(double X, double Y);
    //判断是否胜利
    int judgewin3(double X,double Y);
    int judgefloor(double X,double Y);

    void timerEvent(QTimerEvent*e);
    void changeImg();
    int id1;

    int flag=3;

    QSoundEffect mMediaBG;
};


#endif // LEVEL3_H
