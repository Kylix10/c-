#ifndef ADDITIEM_H
#define ADDITIEM_H
#include <QWidget>
#include "backpackitem.h"
class AddItiem
{
public:
    AddItiem();
    //接口函数，向BackpackItem容器中添加图片路径以及对应文案
    void const addToBackpack(const QString &imagePath,const QString &imageContent);
    const QVector<BackpackItem>&getVector()const{
        return pictures;
    }
private:
    // 存储图片路径和对应文案的容器
    QVector<BackpackItem> pictures;
};
//声明为全局变量
extern AddItiem additems;
#endif // ADDITIEM_H
