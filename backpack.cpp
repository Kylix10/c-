#include "backpack.h"
#include "ui_backpack.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "LargeImageWidget.h"
#include <QDebug>

backpack::backpack(QWidget *parent)
    : QWidget(parent), ui(new Ui::backpack)
{
    ui->setupUi(this);
    this->setWindowTitle("背包");
    this->setWindowFlags(this->windowFlags() | Qt::Window);

    //设置窗口的背景图片
    QPixmap backgroundPixmap(":/new/prefix1/bag_picture/bag_backgroud.png"); // 注意替换为你的图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);


    // 创建一个网格布局来管理所有控件
    QGridLayout *gridLayout = new QGridLayout;
    int rowCount = 0;
    int colIndex = 0;
    const int columnsPerRow = 3;

    // 遍历容器中所有图片，并为其创建QLabel对象进行显示
    QVector<BackpackItem> items = additems.getVector(); // 确保additems已经被正确初始化
    for (const auto &item : items) {
        QLabel *label = new QLabel;
        QPixmap pixmap(item.imagePath);
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image:" << item.imagePath;
            continue;
        }
        pixmap = pixmap.scaled(130, 130, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(pixmap);
        label->setAlignment(Qt::AlignCenter);

        QPushButton *button = new QPushButton("查看详情");
        button->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none; font-family:隶书");
        connect(button, &QPushButton::clicked, this, [this, item]() {
            LargeImageWidget *viewer = new LargeImageWidget(this, item.imagePath, item.description);
            viewer->setAttribute(Qt::WA_DeleteOnClose);
            this->hide();
            viewer->show();
            connect(viewer, &LargeImageWidget::windowClosed, this, &backpack::show);
        });

        gridLayout->addWidget(label, rowCount, colIndex);
        gridLayout->addWidget(button, rowCount + 1, colIndex, 1, 1, Qt::AlignTop);

        colIndex++;
        if (colIndex >= columnsPerRow) {
            colIndex = 0;
            rowCount += 2;
        }
    }

    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(gridLayout);
    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setWidgetResizable(true);
}

backpack::~backpack()
{
    delete ui;
}
