#ifndef WEIGHT2_H
#define WEIGHT2_H

#include <QMainWindow>
#include "mainsence1.h"
namespace Ui {
class weight2;
}

class weight2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit weight2(QWidget *parent = nullptr);
    ~weight2();

private slots:
    void on_pushButton_clicked();


private:
    Ui::weight2 *ui;
};

#endif // WEIGHT2_H
