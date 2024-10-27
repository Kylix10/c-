#include "level1.h"
#include "ui_level1.h"
#include "config.h"

level1::level1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level1)
    , isFacingRight(true)
    , physicsTimer(nullptr)
    , verticalVelocity(0.0f)
    , horizontalVelocity(0.0f)
    , isJumping(false)
    , isGrounded(true)
    , isDashing(false)
    , keyLeft(false)
    , keyRight(false)
    , lastKeyPressed(Qt::Key_unknown)
{
    ui->setupUi(this);
    setFixedSize(1260, 720);
    setWindowTitle(GAME_TITLE);

    // 加载角色精灵
    loadCharacterSprites();

    // 设置角色初始位置和大小
    ui->Man->setFixedSize(CHARACTER_WIDTH, CHARACTER_HEIGHT);
    ui->Man->setScaledContents(true);
    ui->Man->move(422, 141);
    updateCharacterSprite();

    // 设置背景
    QPixmap backgroundPixmap(":/new/prefix1/res/level1.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window,
                     backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);

    // 初始化平台
    initializePlatforms();

    // 初始化物理定时器
    physicsTimer = new QTimer(this);
    connect(physicsTimer, &QTimer::timeout, this, &level1::updatePhysics);
    physicsTimer->start(16);  // 约60FPS

    setFocusPolicy(Qt::StrongFocus);
}

level1::~level1()
{
    delete ui;
}

void level1::loadCharacterSprites()
{
    characterRight.load(":/new/prefix1/res/1_reverse_man.png");
    characterLeft = characterRight.transformed(QTransform().scale(-1, 1));

    characterRight = characterRight.scaled(CHARACTER_WIDTH, CHARACTER_HEIGHT,
                                           Qt::KeepAspectRatio, Qt::SmoothTransformation);
    characterLeft = characterLeft.scaled(CHARACTER_WIDTH, CHARACTER_HEIGHT,
                                         Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void level1::initializePlatforms()
{
    // 清空现有平台
    platforms.clear();

    // 添加基本平台
    platforms.append({QRect(0, 639, 1260, 41), true});  // 地面
    platforms.append({QRect(80, 520, 999, 40), false});     // 第一层
    platforms.append({QRect(880, 400, 320, 40), false});     // 第二层右
    platforms.append({QRect(80, 400, 640, 40), false});      // 第二层左
    platforms.append({QRect(440, 280, 520, 40), false});     // 第三层
    platforms.append({QRect(1000, 160, 200, 40), false});    // 终点层

    // 添加边界
    platforms.append({QRect(0, 0, 1260, 80), true});         // 顶部边界
    platforms.append({QRect(0, 0, 80, 720), true});          // 左边界
    platforms.append({QRect(1200, 0, 80, 720), true});       // 右边界
}

void level1::updateCharacterSprite()
{
    if (horizontalVelocity > 0) {
        isFacingRight = true;
        ui->Man->setPixmap(characterLeft);
    } else if (horizontalVelocity < 0) {
        isFacingRight = false;
        ui->Man->setPixmap(characterRight);
    }
}

void level1::keyPressEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat()) return;

    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        keyLeft = true;
        if (lastKeyPressed == Qt::Key_Left &&
            lastKeyPressTime.msecsTo(QTime::currentTime()) < DOUBLE_CLICK_INTERVAL) {
            isDashing = true;
            QTimer::singleShot(DASH_DURATION, this, [this]() { isDashing = false; });
        }
        lastKeyPressed = Qt::Key_Left;
        lastKeyPressTime = QTime::currentTime();
        break;

    case Qt::Key_D:
    case Qt::Key_Right:
        keyRight = true;
        if (lastKeyPressed == Qt::Key_Right &&
            lastKeyPressTime.msecsTo(QTime::currentTime()) < DOUBLE_CLICK_INTERVAL) {
            isDashing = true;
            QTimer::singleShot(DASH_DURATION, this, [this]() { isDashing = false; });
        }
        lastKeyPressed = Qt::Key_Right;
        lastKeyPressTime = QTime::currentTime();
        break;

    case Qt::Key_Space:
    case Qt::Key_W:
    case Qt::Key_Up:
        if (isGrounded) {
            isJumping = true;
            isGrounded = false;
            verticalVelocity = JUMP_FORCE;
        }
        break;
    }
}

void level1::keyReleaseEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat()) return;

    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        keyLeft = false;
        break;

    case Qt::Key_D:
    case Qt::Key_Right:
        keyRight = false;
        break;
    }
}

void level1::updateMovement()
{
    float currentSpeed = isDashing ? DASH_SPEED : MOVE_SPEED;

    if (keyLeft && !keyRight) {
        horizontalVelocity = -currentSpeed * MOVEMENT_DAMPING;
    } else if (keyRight && !keyLeft) {
        horizontalVelocity = currentSpeed * MOVEMENT_DAMPING;
    } else {
        horizontalVelocity *= 0.8f;
        if (std::abs(horizontalVelocity) < 0.1f) horizontalVelocity = 0;
    }

    updateCharacterSprite();
}

void level1::updatePhysics()
{
    updateMovement();

    QPoint newPos = ui->Man->pos();
    QPoint originalPos = newPos;

    // 水平移动检测
    float proposedX = newPos.x() + horizontalVelocity;
    newPos.setX(qBound(GAME_BOUND_LEFT, static_cast<int>(proposedX), GAME_BOUND_RIGHT - ui->Man->width()));

    if (checkHorizontalCollision(newPos)) {
        newPos.setX(originalPos.x());
        horizontalVelocity = 0;
    }

    // 垂直移动检测
    if (!isGrounded) {
        verticalVelocity += GRAVITY;
        float proposedY = newPos.y() + verticalVelocity;
        newPos.setY(qBound(GAME_BOUND_TOP, static_cast<int>(proposedY), GAME_BOUND_BOTTOM - ui->Man->height()));

        if (checkVerticalCollision(newPos)) {
            if (verticalVelocity > 0) { // 落地
                newPos = adjustPositionToPlatform(newPos);
                verticalVelocity = 0;
                isGrounded = true;
                isJumping = false;
            } else { // 碰到天花板
                newPos.setY(originalPos.y());
                verticalVelocity = 0;
            }
        }
    }

    // 检查是否仍在平台上
    if (isGrounded) {
        QPoint checkPos = newPos;
        checkPos.setY(checkPos.y() + 2);  // 检查点稍微向下偏移
        if (!isOnPlatform(checkPos)) {
            isGrounded = false;
        }
    }

    // 移动角色
    if (isWithinBounds(newPos)) {
        ui->Man->move(newPos);
    }

    pick();
}

bool level1::checkCollision(const QPoint& pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform& platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            return true;
        }
    }
    return false;
}

bool level1::checkVerticalCollision(const QPoint& pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform& platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 计算重叠区域
            int overlapTop = playerRect.bottom() - platform.rect.top();
            int overlapBottom = platform.rect.bottom() - playerRect.top();

            // 调整碰撞检测的容差范围
            if (verticalVelocity > 0 && overlapTop < 15) {  // 下落碰撞
                return true;
            }
            if (verticalVelocity < 0 && overlapBottom < 15) {  // 向上碰撞
                return true;
            }
        }
    }
    return false;
}

bool level1::checkHorizontalCollision(const QPoint& pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform& platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 忽略从上方接触的碰撞
            if (playerRect.bottom() > platform.rect.top() + 10) {
                return true;
            }
        }
    }
    return false;
}

bool level1::isOnPlatform(const QPoint& pos)
{
    QRect playerRect(pos, ui->Man->size());
    // 扩大脚部碰撞检测区域
    QRect feetRect(playerRect.x() + 5, playerRect.bottom() - 4,
                   playerRect.width() - 10, 6);

    for (const Platform& platform : platforms) {
        if (feetRect.intersects(platform.rect)) {
            // 放宽判定条件
            return (feetRect.bottom() - platform.rect.top() < 10);
        }
    }
    return false;
}

QPoint level1::adjustPositionToPlatform(const QPoint& pos)
{
    QPoint adjustedPos = pos;
    QRect playerRect(pos, ui->Man->size());

    for (const Platform& platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 精确调整到平台顶部，留出1像素的容差
            adjustedPos.setY(platform.rect.top() - ui->Man->height() + 1);
            break;
        }
    }

    return adjustedPos;
}

bool level1::isWithinBounds(const QPoint& pos)
{
    return pos.x() >= GAME_BOUND_LEFT &&
           pos.x() + ui->Man->width() <= GAME_BOUND_RIGHT &&
           pos.y() >= GAME_BOUND_TOP &&
           pos.y() + ui->Man->height() <= GAME_BOUND_BOTTOM;
}

void level1::initScene()
{
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
}

void level1::pick()
{
    QRect labelRect = ui->Man->geometry();
    QRect targetRect(422, 160, 28, 28);

    if (labelRect.intersects(targetRect)) {
        qDebug() << "Collision detected!";            // QLabel的边界触及或落入了目标坐标范围
        // additems.addToBackpack(":/new/prefix1/bag_picture/huangshan.png","    徐霞客一生曾于明万历四十四年和万历四十六年两游黄山，并留《游黄山日记》予后世。其中所载黄山四绝：奇松、怪石、云海、温泉惊奇绝艳，正所谓“五岳归来不看山，黄山归来不看岳”。");
        // ui->item1->hide();
        emit collisionOccurred();
    }

}
