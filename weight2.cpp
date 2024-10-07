#include "weight2.h"
#include "ui_weight2.h"
//#include "mainsence1.h"
weight2::weight2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::weight2)
{
    ui->setupUi(this);
    //工具栏（隐藏任务栏图标）窗体置顶 隐藏标题栏
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    //setWindowOpacity(0.5); //包括子控件都变透明
    setAttribute(Qt::WA_TranslucentBackground, true);//只是窗体变透明

    //样式表实现圆角窗口
    //    setStyleSheet("QWidget{background-color:gray;border-top-left-radius:25px;border-top-right-radius:25px;"
    //                  "border-bottom-left-radius:25px;border-bottom-right-radius:25px}");



}

weight2::~weight2()
{
    delete ui;
}

void weight2::on_pushButton_clicked()
{
    //mainsence1 *in = new mainsence1();
    this->close();

}

