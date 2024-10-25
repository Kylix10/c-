#include "additiem.h"

AddItiem::AddItiem() {}

//背包相关函数
void const AddItiem::addToBackpack(const QString &imagePath,const QString &imageContent) {
    pictures.append(BackpackItem(imagePath,imageContent));
}
AddItiem additems;
