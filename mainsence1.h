#ifndef MAINSENCE1_H
#define MAINSENCE1_H

#include <QMainWindow>
#include <weight2.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <mydialog.h>
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

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::mainsence1 *ui;
    MyDialog*mdl;


};

#endif // MAINSENCE1_H
