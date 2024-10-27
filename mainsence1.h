
#ifndef MAINSENCE1_H
#define MAINSENCE1_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <mydialog.h>
#include <weight2.h>
namespace Ui {
class mainsence1;
}

class mainsence1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainsence1(QWidget *parent = nullptr);
    ~mainsence1();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_cancelButton_clicked();
    void on_musicbutton_clicked();

private:
    Ui::mainsence1 *ui;
    MyDialog* mdl;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    bool flag; // 将flag作为成员变量
    //weight2* w2; // 添加weight2的指针作为成员变量以管理其生命周期
};

#endif // MAINSENCE1_H
