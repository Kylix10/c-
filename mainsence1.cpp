#include "mainsence1.h"
#include "ui_mainsence1.h"
#include "weight2.h"

//#include ""
mainsence1::mainsence1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainsence1)
    , mdl(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("万里遐征");
}

mainsence1::~mainsence1()
{
    delete ui;

    // 检查指针是否为nullptr，并仅在非空时删除它
    if ( mdl!= nullptr) {
        delete mdl;
        mdl = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }

}

void mainsence1::on_pushButton_2_clicked()
{

    weight2 *in = new weight2();
    in->show();

}//进入操作指南界面


void mainsence1::on_pushButton_clicked()
{
    if (!mdl) { // 如果还没创建，则创建它

        mdl= new MyDialog(nullptr);
    }
    this->hide(); // 隐藏当前窗口
    mdl->show(); // 显示第二个窗口
}//进入对话框界面

