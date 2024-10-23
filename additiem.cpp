#include "additiem.h"

AddItiem::AddItiem() {}

//背包相关函数
void const AddItiem::addToBackpack(const QString &imagePath,const QString &imageContent) {
    pictures.append(BackpackItem(imagePath,imageContent));
    // // You can add a QMessageBox or log to confirm the addition for debugging

}
AddItiem additems;
