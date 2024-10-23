#ifndef BACKPACKITEM_H
#define BACKPACKITEM_H
#include <QString>

class BackpackItem {
public:
    QString imagePath;
    QString description; // 新增文案字段
    BackpackItem(const QString &path,const QString &content) : imagePath(path),description(content) {}
};
#endif // BACKPACKITEM_H
