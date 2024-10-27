#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 900             //宽度
#define GAME_HEIGHT 506            //高度
#define GAME_TITLE "万里遐征 v1.0" //标题

// 物理参数常量，将这些移到这里以便统一管理
const float GRAVITY = 0.6f;
const float JUMP_FORCE = -12.0f;
const float MOVE_SPEED = 3.0f;
const float DASH_SPEED = 6.0f;
const float MOVEMENT_DAMPING = 0.8f;

// 游戏设定常量
const int DASH_DURATION = 600;
const int DOUBLE_CLICK_INTERVAL = 400;
const int CHARACTER_WIDTH = 64;
const int CHARACTER_HEIGHT = 72;

#endif // CONFIG_H
