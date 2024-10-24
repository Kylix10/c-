#ifndef BACKPACKITEM_H
#define BACKPACKITEM_H
#include <QString>

class BackpackItem {
public:
    QString imagePath;   //图片路径
    QString description; // 文案字段
    BackpackItem(const QString &path,const QString &content) : imagePath(path),description(content) {}
};
#endif // BACKPACKITEM_H
