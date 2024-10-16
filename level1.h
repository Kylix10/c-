#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include<QLabel>
#include<QPixmap>//插入图片用
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

    void initScene();
    void pick();



private:
    Ui::level1 *ui;

    QVector<BackpackItem> l1_pictures; // 存储图片路径的背包
};

#endif // LEVEL1_H
