
#ifndef LEVEL2_H
#define LEVEL2_H

#include "ui_level2.h"
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
class level2 : public QWidget
{
    Q_OBJECT
public:
    explicit level2(QWidget *parent = nullptr);

    void initScene();
    int pick();

protected:
    void paintEvent(QPaintEvent *event);

signals:

private:
    QVector<BackpackItem> l1_pictures; // 存储图片路径的背包
    int ret2;
    QTimer*PersonMoveTimer;
    Ui::level2 *ui;
    QPoint position;
    QPixmap image;
    QGraphicsView mGameView;//游戏视图
    QGraphicsScene mScene;//场景
    QGraphicsPixmapItem mBackGround;//背景元素
    QGraphicsPixmapItem Fire;//火娃
    QGraphicsPixmapItem box;//箱子
    QGraphicsPixmapItem box1;//箱子
    QGraphicsPixmapItem box2;//箱子

    QGraphicsPixmapItem *boxItem;//拾取的物品
    int judgefloor(double X,double Y);
    void timerEvent(QTimerEvent*e);
    int id1;

    bool flag=true;

    QSoundEffect mMediaBG;
};

#endif // GAME_H
