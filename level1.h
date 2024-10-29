
#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDebug>
#include <QKeyEvent>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <additiem.h>
#include<QGraphicsPixmapItem>
namespace Ui {
class level1;
}

class level1 : public QWidget
{
    Q_OBJECT

public:
    explicit level1(QWidget *parent = nullptr);
    ~level1();

private slots:
    // 黑窗切换
    void switchLabels();
signals:
    void collisionOccurred();
    void levelCompleted();  // 新增通关信号

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    // 初始化函数
    void initScene();
    void loadCharacterSprites();
    void initializePlatforms();

    // 游戏逻辑函数
    void updatePhysics();
    void updateMovement();
    void updateCharacterSprite();
    void pick();
    void checkLevelCompletion(const QPoint &pos);  // 新增通关检测函数

    // 碰撞检测函数
    bool checkCollision(const QPoint &pos);
    bool checkVerticalCollision(const QPoint &pos);
    bool checkHorizontalCollision(const QPoint &pos);
    bool isOnPlatform(const QPoint &pos);
    QPoint adjustPositionToPlatform(const QPoint &pos);
    bool isWithinBounds(const QPoint &pos);

private:
    Ui::level1 *ui;
    QVector<BackpackItem> l1_pictures; // 存储图片路径的背包
    //开头黑窗相关
    QLabel *label;
    QTimer *timer1;
    //切换背景图片相关
    QGraphicsPixmapItem mBackGround;//背景元素
    // 精灵相关
    QPixmap characterRight;
    QPixmap characterLeft;
    bool isFacingRight;

    // 物理系统相关变量
    QTimer *physicsTimer;
    float verticalVelocity;
    float horizontalVelocity;
    bool isJumping;
    bool isGrounded;

    // 游戏边界常量
    const int GAME_BOUND_LEFT = 80;
    const int GAME_BOUND_RIGHT = 1180;
    const int GAME_BOUND_TOP = 80;
    const int GAME_BOUND_BOTTOM = 640;
    const int GROUND_Y = 640;

    // 双击检测相关
    QTime lastKeyPressTime;
    Qt::Key lastKeyPressed;
    bool isDashing;

    // 按键状态
    bool keyLeft;
    bool keyRight;

    // 平台数据
    struct Platform
    {
        QRect rect;
        bool isGround;
    };
    QVector<Platform> platforms;

private:
    // 禁用拷贝构造和赋值操作符
    level1(const level1 &) = delete;
    level1 &operator=(const level1 &) = delete;

};

#endif // LEVEL1_H
