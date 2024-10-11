#ifndef BACKPACK_H
#define BACKPACK_H

#include <QWidget>
#include <QDialog>
#include <QVector>
#include <QString>
#include <QLabel>
#include "backpackitem.h"

namespace Ui {
class backpack;
}

class backpack : public QWidget
{
    Q_OBJECT

public:
    explicit backpack(QWidget *parent = nullptr, const QVector<BackpackItem> &items = QVector<BackpackItem>());
    ~backpack();
// private slots:
//     void showImageInViewer(const QString &imagePath);
private:
    Ui::backpack *ui;

     QVector<BackpackItem> items; // 用于显示图片的标签
};

#endif // BACKPACK_H
