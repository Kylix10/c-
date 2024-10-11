#ifndef BACKPACKITEM_H
#define BACKPACKITEM_H
#include <QString>

class BackpackItem {
public:
    QString imagePath;

    BackpackItem(const QString &path) : imagePath(path) {}
};
#endif // BACKPACKITEM_H
