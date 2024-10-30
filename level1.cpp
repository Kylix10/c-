#include "level1.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "config.h"
#include "ui_level1.h"

level1::level1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level1)
    , label(new QLabel(this))
    , timer1(new QTimer(this))
    , currentFrameIndex(0)
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
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);

    // 加载角色精灵
    loadCharacterSprites();

    // 设置角色初始位置和大小
    ui->Man->setFixedSize(CHARACTER_WIDTH * GAME_WIDTH/1260, CHARACTER_HEIGHT * GAME_HEIGHT/720);
    ui->Man->setScaledContents(true);
    ui->Man->move(79, 405);
    updateCharacterSprite();

    // 初始化背景
    initializeBackground();

    // 初始化并启动背景动画定时器
    backgroundAnimTimer = new QTimer(this);
    connect(backgroundAnimTimer, &QTimer::timeout, this, &level1::updateBackgroundFrame);
    backgroundAnimTimer->start(BACKGROUND_UPDATE_INTERVAL);

    // 初始化平台
    initializePlatforms();

    // 初始化物理定时器
    physicsTimer = new QTimer(this);
    connect(physicsTimer, &QTimer::timeout, this, &level1::updatePhysics);
    physicsTimer->start(16); // 约60FPS

    setFocusPolicy(Qt::StrongFocus);

    // 设置开场文字样式和内容
    label->setStyleSheet("QLabel { "
                         "background-color: black;"
                         "color: white; "
                         "padding: 10px; "
                         "font-size: 25px; "
                         "font-family:隶书;"
                         "}");
    label->setText(
        "北望黄山诸峰，片片可掇拾取。\r\n群峰或上或下，或巨或纤，或直或欹，与身穿绕而过。"
        "\r\n俯窥辗顾，步步生奇，但壑深雪厚，一步一悚。\r\n             ——《游黄山日记》");
    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(true);
    label->raise();
    label->setVisible(true);

    // 创建布局并将label添加到其中
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 连接并启动黑窗计时器
    connect(timer1, &QTimer::timeout, this, &level1::switchLabels);
    timer1->start(3000);
}

level1::~level1()
{
    delete ui;
}

void level1::initializeBackground()
{
    // 初始化背景图片路径
    backgroundPaths = {
        ":/new/prefix1/res/level1.jpg.png",
        ":/new/prefix1/res/level1(2).png",
    };

    // 加载初始背景
    if (!backgroundPaths.isEmpty()) {
        currentBackground.load(backgroundPaths[0]);
        currentBackground = currentBackground.scaled(GAME_WIDTH, GAME_HEIGHT,
                                                     Qt::IgnoreAspectRatio);
        // 设置初始背景
        QPalette palette;
        palette.setBrush(QPalette::Window, currentBackground);
        this->setPalette(palette);
    }
}

void level1::updateBackgroundFrame()
{
    // 更新帧索引
    currentFrameIndex = (currentFrameIndex + 1) % BACKGROUND_FRAME_COUNT;

    // 加载新的背景帧
    if (currentFrameIndex < backgroundPaths.size()) {
        QPixmap newBackground(backgroundPaths[currentFrameIndex]);
        if (!newBackground.isNull()) {
            currentBackground = newBackground.scaled(GAME_WIDTH, GAME_HEIGHT,
                                                     Qt::IgnoreAspectRatio,
                                                     Qt::SmoothTransformation);
            // 更新背景
            QPalette palette;
            palette.setBrush(QPalette::Window, currentBackground);
            this->setPalette(palette);
        }
    }
}
void level1::loadCharacterSprites()
{
    characterRight.load(":/new/prefix1/res/1_reverse_man.png");
    characterLeft = characterRight.transformed(QTransform().scale(-1, 1));

    int newWidth = CHARACTER_WIDTH * GAME_WIDTH/1260;
    int newHeight = CHARACTER_HEIGHT * GAME_HEIGHT/720;

    characterRight = characterRight.scaled(newWidth,
                                           newHeight,
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
    characterLeft = characterLeft.scaled(newWidth,
                                         newHeight,
                                         Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation);
}

void level1::initializePlatforms()
{
    // 清空现有平台
    platforms.clear();

    // 按新尺寸添加基本平台
    platforms.append({QRect(0, 449, 900, 29), true});      // 地面
    platforms.append({QRect(57, 365, 711, 28), false});    // 第一层
    platforms.append({QRect(629, 281, 229, 28), false});   // 第二层右
    platforms.append({QRect(57, 281, 457, 28), false});    // 第二层左
    platforms.append({QRect(314, 197, 371, 28), false});   // 第三层
    platforms.append({QRect(714, 112, 143, 28), false});   // 终点层

    // 添加边界
    platforms.append({QRect(0, 0, 900, 57), true});        // 顶部边界
    platforms.append({QRect(0, 0, 57, 506), true});        // 左边界
    platforms.append({QRect(857, 0, 57, 506), true});      // 右边界
}

void level1::switchLabels()
{
    timer1->stop();
    label->setVisible(false);
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

void level1::checkLevelCompletion(const QPoint &pos)
{
    if (pos.y() >= 57 && pos.y() <= 140 && pos.x() > 757) {
        // 停止所有计时器
        physicsTimer->stop();
        backgroundAnimTimer->stop();

        QMessageBox::information(this, "恭喜", "恭喜你通过了第一关！");

        emit levelCompleted();

        QTimer::singleShot(100, this, [this]() {
            this->close();
        });
    }
}
void level1::updatePhysics()
{
    updateMovement();

    QPoint newPos = ui->Man->pos();
    QPoint originalPos = newPos;

    // 水平移动检测
    float proposedX = newPos.x() + horizontalVelocity;
    newPos.setX(
        qBound(GAME_BOUND_LEFT, static_cast<int>(proposedX), GAME_BOUND_RIGHT - ui->Man->width()));

    if (checkHorizontalCollision(newPos)) {
        newPos.setX(originalPos.x());
        horizontalVelocity = 0;
    }

    // 垂直移动检测
    if (!isGrounded) {
        verticalVelocity += GRAVITY;  // 使用新的重力常量
        float proposedY = newPos.y() + verticalVelocity;
        newPos.setY(qBound(GAME_BOUND_TOP,
                           static_cast<int>(proposedY),
                           GAME_BOUND_BOTTOM - ui->Man->height()));

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
        checkPos.setY(checkPos.y() + 2); // 检查点稍微向下偏移
        if (!isOnPlatform(checkPos)) {
            isGrounded = false;
        }
    }

    // 移动角色
    if (isWithinBounds(newPos)) {
        ui->Man->move(newPos);
    }

    pick();
    checkLevelCompletion(newPos);
}

void level1::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        keyLeft = true;
        if (lastKeyPressed == Qt::Key_Left
            && lastKeyPressTime.msecsTo(QTime::currentTime()) < DOUBLE_CLICK_INTERVAL) {
            isDashing = true;
            QTimer::singleShot(DASH_DURATION, this, [this]() { isDashing = false; });
        }
        lastKeyPressed = Qt::Key_Left;
        lastKeyPressTime = QTime::currentTime();
        break;

    case Qt::Key_D:
    case Qt::Key_Right:
        keyRight = true;
        if (lastKeyPressed == Qt::Key_Right
            && lastKeyPressTime.msecsTo(QTime::currentTime()) < DOUBLE_CLICK_INTERVAL) {
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
            verticalVelocity = JUMP_FORCE;  // 使用新的跳跃力度常量
        }
        break;
    }
}
void level1::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

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
        if (std::abs(horizontalVelocity) < 0.1f)
            horizontalVelocity = 0;
    }

    updateCharacterSprite();
}
bool level1::checkCollision(const QPoint &pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform &platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            return true;
        }
    }
    return false;
}

bool level1::checkVerticalCollision(const QPoint &pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform &platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 计算重叠区域
            int overlapTop = playerRect.bottom() - platform.rect.top();
            int overlapBottom = platform.rect.bottom() - playerRect.top();

            // 调整碰撞检测的容差范围
            if (verticalVelocity > 0 && overlapTop < 15) { // 下落碰撞
                return true;
            }
            if (verticalVelocity < 0 && overlapBottom < 15) { // 向上碰撞
                return true;
            }
        }
    }
    return false;
}

bool level1::checkHorizontalCollision(const QPoint &pos)
{
    QRect playerRect(pos, ui->Man->size());
    for (const Platform &platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 忽略从上方接触的碰撞
            if (playerRect.bottom() > platform.rect.top() + 10) {
                return true;
            }
        }
    }
    return false;
}

bool level1::isOnPlatform(const QPoint &pos)
{
    QRect playerRect(pos, ui->Man->size());
    // 扩大脚部碰撞检测区域
    QRect feetRect(playerRect.x() + 5, playerRect.bottom() - 4, playerRect.width() - 10, 6);

    for (const Platform &platform : platforms) {
        if (feetRect.intersects(platform.rect)) {
            // 放宽判定条件
            return (feetRect.bottom() - platform.rect.top() < 10);
        }
    }
    return false;
}

QPoint level1::adjustPositionToPlatform(const QPoint &pos)
{
    QPoint adjustedPos = pos;
    QRect playerRect(pos, ui->Man->size());

    for (const Platform &platform : platforms) {
        if (playerRect.intersects(platform.rect)) {
            // 精确调整到平台顶部，留出1像素的容差
            adjustedPos.setY(platform.rect.top() - ui->Man->height() + 1);
            break;
        }
    }

    return adjustedPos;
}

bool level1::isWithinBounds(const QPoint &pos)
{
    return pos.x() >= GAME_BOUND_LEFT && pos.x() + ui->Man->width() <= GAME_BOUND_RIGHT
           && pos.y() >= GAME_BOUND_TOP && pos.y() + ui->Man->height() <= GAME_BOUND_BOTTOM;
}

void level1::pick()
{
    QRect labelRect = ui->Man->geometry();
    QRect targetRect(301, 112, 20, 20); // 按新尺寸调整道具位置

    if (labelRect.intersects(targetRect)) {
        emit collisionOccurred();
    }
}
