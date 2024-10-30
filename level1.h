#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <additiem.h>

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
    // 背景切换相关
    void updateBackgroundFrame();

signals:
    void collisionOccurred();
    void levelCompleted();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    // 初始化函数
    void initScene();
    void loadCharacterSprites();
    void initializePlatforms();
    void initializeBackground();

    // 游戏逻辑函数
    void updatePhysics();
    void updateMovement();
    void updateCharacterSprite();
    void pick();
    void checkLevelCompletion(const QPoint &pos);

    // 碰撞检测函数
    bool checkCollision(const QPoint &pos);
    bool checkVerticalCollision(const QPoint &pos);
    bool checkHorizontalCollision(const QPoint &pos);
    bool isOnPlatform(const QPoint &pos);
    QPoint adjustPositionToPlatform(const QPoint &pos);
    bool isWithinBounds(const QPoint &pos);

private:
    Ui::level1 *ui;
    QVector<BackpackItem> l1_pictures;

    // 开头黑窗相关
    QLabel *label;
    QTimer *timer1;

    // 背景动画相关
    QTimer *backgroundAnimTimer;        // 背景动画定时器
    QVector<QString> backgroundPaths;   // 背景图片路径
    int currentFrameIndex;             // 当前帧索引
    QPixmap currentBackground;         // 当前背景

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
    //  const int GAME_WIDTH = 900;           // 新的游戏宽度
    //  const int GAME_HEIGHT = 506;          // 新的游戏高度
    const int GAME_BOUND_LEFT = 57;       // 80 * (900/1260)
    const int GAME_BOUND_RIGHT = 843;     // 1180 * (900/1260)
    const int GAME_BOUND_TOP = 57;        // 80 * (506/720)
    const int GAME_BOUND_BOTTOM = 450;    // 640 * (506/720)
    const int GROUND_Y = 450;             // 640 * (506/720)

    // 物理常量
    const float GRAVITY = 0.5f;                     // 重力加速度
    const float JUMP_FORCE = -9.0f;                // 跳跃力度，从-12.0f改小使跳跃高度降低
    const float MOVE_SPEED = 3.0f;                  // 移动速度
    const float DASH_SPEED = 4.0f;                 // 冲刺速度
    const float MOVEMENT_DAMPING = 1.0f;            // 移动阻尼
    const int DOUBLE_CLICK_INTERVAL = 250;          // 双击检测间隔(ms)
    const int DASH_DURATION = 200;                  // 冲刺持续时间(ms)
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

    // 背景动画常量
    const int BACKGROUND_FRAME_COUNT = 2;           // 背景帧数
    const int BACKGROUND_UPDATE_INTERVAL = 648;     // 背景更新间隔(ms)

private:
    // 禁用拷贝构造和赋值操作符
    level1(const level1 &) = delete;
    level1 &operator=(const level1 &) = delete;
};

#endif // LEVEL1_H
