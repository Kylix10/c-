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
};

#endif // BACKPACK_H
