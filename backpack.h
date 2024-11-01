#ifndef BACKPACK_H
#define BACKPACK_H

#include <QWidget>
#include <QDialog>
#include <QVector>
#include <QString>
#include <QLabel>
#include "backpackitem.h"
#include "additiem.h"

namespace Ui {
class backpack;
}

class backpack : public QWidget
{
    Q_OBJECT

public:
    explicit backpack(QWidget *parent = nullptr);
    ~backpack();
private:
    Ui::backpack *ui;
    // 在backpack类的定义中添加如下函数声明
    void resizeEvent(QResizeEvent *event)
    {
        QWidget::resizeEvent(event);

        QPixmap backgroundPixmap(":/new/prefix1/bag_picture/bag_backgroud.png");
        QPalette palette;
        palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        this->setPalette(palette);
    }
};

#endif // BACKPACK_H
