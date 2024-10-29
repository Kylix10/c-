#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <level1.h>
#include <level2.h>
#include <level3.h>
#include <level4.h>
#include <level5.h>
#include <additiem.h>
namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

    //初始化场景
    void initScene();


private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();
//背包相关函数

    void on_backpackButton_clicked();
    // 新增：处理关卡通关的槽函数
    void handleLevel1Completion();
    //void handleLevel2Completion();

private:
    Ui::Map *ui;

    level1*lv1;
    level2*lv2;
    level3*lv3;
    level4*lv4;
    level5*lv5;

};

#endif // MAP_H
