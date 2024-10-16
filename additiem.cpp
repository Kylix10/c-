#include "additiem.h"

AddItiem::AddItiem() {}

//背包相关函数
void const AddItiem::addToBackpack(const QString &imagePath) {
    pictures.append(BackpackItem(imagePath));
    // // You can add a QMessageBox or log to confirm the addition for debugging

}
AddItiem additems;
