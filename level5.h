#ifndef LEVEL5_H
#define LEVEL5_H

#include <QWidget>

namespace Ui {
class level5;
}

class level5 : public QWidget
{
    Q_OBJECT

public:
    explicit level5(QWidget *parent = nullptr);
    ~level5();

private:
    Ui::level5 *ui;
};

#endif // LEVEL5_H
