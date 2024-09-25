#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include<level1.h>
#include<level2.h>

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

private:
    Ui::Map *ui;

    level1*lv1;
    level2*lv2;

};

#endif // MAP_H
