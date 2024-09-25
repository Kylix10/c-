#ifndef LEVEL2_H
#define LEVEL2_H

#include <QWidget>

namespace Ui {
class level2;
}

class level2 : public QWidget
{
    Q_OBJECT

public:
    explicit level2(QWidget *parent = nullptr);
    ~level2();

private:
    Ui::level2 *ui;
};

#endif // LEVEL2_H
