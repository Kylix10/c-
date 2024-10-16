#ifndef PICKSHOW_H
#define PICKSHOW_H

#include <QWidget>

namespace Ui {
class pickshow;
}

class pickshow : public QWidget
{
    Q_OBJECT

public:
    explicit pickshow(QWidget *parent = nullptr);
    ~pickshow();

private:
    Ui::pickshow *ui;
};

#endif // PICKSHOW_H
