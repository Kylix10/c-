#include "LargeImageWidget.h"
#include "ui_LargeImageWidget.h"

LargeImageWidget::LargeImageWidget(QWidget *parent, const QString &imagePath,const QString &imageContent)
    : QWidget(parent)
    , ui(new Ui::LargeImageWidget)
    , imagePath(imagePath)
    ,imageContent(imageContent)
{
    ui->setupUi(this);
    this->setWindowTitle("背包");
    this->setWindowFlags(this->windowFlags() | Qt::Window);
    //设置窗口的背景图片
    QPixmap backgroundPixmap(":/new/prefix1/bag_picture/detail.png"); // 注意替换为你的图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);

    ui->label->setPixmap(QPixmap(imagePath).scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->label_2->setText(imageContent);
    //ui->label_2->setWordWrapMode(Qt::WordWrap);
}

void LargeImageWidget::closeEvent(QCloseEvent *event) {
    emit windowClosed();
    QWidget::closeEvent(event); // 确保调用基类的 closeEvent
}
LargeImageWidget::~LargeImageWidget()
{
    delete ui;
}
