#include "additiem.h"

AddItiem::AddItiem() {}

//背包相关函数
void const AddItiem::addToBackpack(const QString &imagePath,const QString &imageContent) {
    bool flag=true;
    QVector<BackpackItem> items=additems.getVector();//判断图片是否已经添加到了容器中，避免重复添加
    for (const auto &item : items) {
        if(imagePath==item.imagePath){
            flag=false;
        }
    }
    if(flag){
        pictures.append(BackpackItem(imagePath,imageContent));
    }

}
AddItiem additems;
