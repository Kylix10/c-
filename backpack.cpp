#include "backpack.h"
#include "qpushbutton.h"
#include "ui_backpack.h"
#include <QGridLayout>
#include <QLabel>
#include "LargeImageWidget.h"

backpack::backpack(QWidget *parent)
    : QWidget(parent), ui(new Ui::backpack)
{

    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::Window);
    //设置窗口的背景图片
    QPixmap backgroundPixmap(":/new/prefix1/bag_picture/bag_backgroud.png"); // 注意替换为你的图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);

    //网格布局
    QGridLayout *gridLayout = new QGridLayout(ui->scrollAreaWidgetContents);
    int rowCount = 0; // 用于跟踪当前行号
    int colIndex = 0; // 计算当前应该放在哪一列
    const int columnsPerRow = 3; // 每行显示的列数
    QVector<BackpackItem> items=additems.getVector();
    for (const auto &item : items) {
        QLabel *label = new QLabel;
        QPixmap pixmap(item.imagePath);
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image:" << item.imagePath;
            continue; // 跳过无法加载的图片
        }
        pixmap = pixmap.scaled(130, 130, Qt::KeepAspectRatio);
        label->setPixmap(pixmap);
        label->setAlignment(Qt::AlignCenter);

        QPushButton *button = new QPushButton("查看详情");
        button->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none;"); // 透明背景和无边框
        connect(button, &QPushButton::clicked, this, [this, item]() {
            LargeImageWidget *viewer = new LargeImageWidget(this, item.imagePath);
            viewer->setAttribute(Qt::WA_DeleteOnClose); // 确保窗口关闭时删除对象
            this->hide(); // 隐藏backpack窗口
            viewer->show();
            QWidget::connect(viewer, &LargeImageWidget::windowClosed, this, &backpack::show); // 当viewer关闭时，显示backpack窗口

        });
        // 将标签和按钮添加到网格布局中

        gridLayout->addWidget(label, rowCount, colIndex);       // 标签放在当前行和列
        gridLayout->addWidget(button, rowCount+1, colIndex, 1, 1, Qt::AlignTop); // 按钮放在下一行，与标签同列

        // 更新列索引，如果达到每行列数限制，则重置为0并增加行数
        colIndex++;
        if (colIndex >= columnsPerRow) {
            colIndex = 0;
            rowCount += 2; // 每张图片和它的按钮占用两行
        }
    }

    // 可选：添加额外的垂直间距或滚动条策略
    // gridLayout->addRow(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
     ui->scrollArea->setWidgetResizable(true); // 确保滚动区域可以调整大小以适应内容
}




backpack::~backpack()
{
    delete ui;
}
