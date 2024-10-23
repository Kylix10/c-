#ifndef ADDITIEM_H
#define ADDITIEM_H
#include <QWidget>
#include "backpackitem.h"
class AddItiem
{
public:
    AddItiem();
    void const addToBackpack(const QString &imagePath,const QString &imageContent);
    const QVector<BackpackItem>&getVector()const{
        return pictures;
    }
private:
    QVector<BackpackItem> pictures; // 存储图片路径的背包
};
extern AddItiem additems;
#endif // ADDITIEM_H
