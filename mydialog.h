#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include<scene.h>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
namespace Ui {
class MyDialog;
}

class MyDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
    void initScene();

    void updateDisplayText();

private:
    Ui::MyDialog *ui;
    QLabel *label; //显示对话框的Qlabel
    QLabel *label2; //过渡黑窗
    QTimer *timer1;
    QTimer *timer2;
    Scene*scene;//指向第二个窗口的指针
    QStringList textParagraphs; // 存储文本段落的列表
    int currentParagraphIndex = 0; // 当前显示的文本段落索引
    int currentCharIndex=0;
private slots:
    void on_buttonNext_clicked();
    void switchLabels();
    void onTimer2Timeout();



};

#endif // MYDIALOG_H
