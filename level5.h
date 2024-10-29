#ifndef LEVEL5_H
#define LEVEL5_H

#include <QWidget>
#include<QLabel>
namespace Ui {
class level5;
}

class level5 : public QWidget
{
    Q_OBJECT

public:
    explicit level5(QWidget *parent = nullptr);
     void initScene();
    ~level5();
private slots:
    void switchLabels();
private:
    Ui::level5 *ui;
    QLabel *label;
    QTimer *timer1;
};

#endif // LEVEL5_H
