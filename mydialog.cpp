#include "mydialog.h"
#include "ui_mydialog.h"
#include "config.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QTimer>
#include <QString>
MyDialog::MyDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDialog)
    , label(new QLabel(this))
    , label2(new QLabel(this))
    , timer1(new QTimer(this))
    , timer2(new QTimer(this))
    , scene(nullptr),
    currentParagraphIndex(0)

{
    ui->setupUi(this);
    initScene();
}

MyDialog::~MyDialog()
{
    delete ui;
    // 检查指针是否为nullptr，并仅在非空时删除它
    if (scene!= nullptr) {
        delete scene;
        scene = nullptr; // 可选：将指针设置为nullptr，但在这个析构函数中它已经是作用域末尾了
    }
}

void MyDialog::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置窗口的背景图片
    QPixmap backgroundPixmap(":/new/prefix1/dialogue_back.jpg"); // 注意替换为你的图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    this->setPalette(palette);


    ui->label2->setStyleSheet("QLabel { "
                            "background-image: url(:/new/prefix1/black.jpg); " // 设置背景图片
                             "color: white; " // 设置文字颜色，以便在深色背景上清晰可见
                             "padding: 10px; " // 增加内边距，避免文字直接贴边
                             "font-size: 26px; " // 设置文字大小
                             "}");
    ui->label2->setText("你感到头痛欲裂... ...\r\n[你睁开眼，面前是一个风尘仆仆的古装男人]\r\n[点击“确定”开始对话]");
    ui->label2->setAlignment(Qt::AlignCenter);
    ui->label2->setVisible(true); // 初始显示


    // 连接 QTimer 的 timeout 信号到 slot 函数
    connect(timer1, &QTimer::timeout, this, &MyDialog::switchLabels);
    // 连接 timer2 的信号和槽（只连接一次）
    connect(timer2, &QTimer::timeout, this, &MyDialog::onTimer2Timeout);
    // 启动 QTimer，设置延迟时间（例如 3 秒）
    timer1->start(3000); // 3000 毫秒 = 3 秒


    // 初始化文本段落
    textParagraphs << "   醒醒,醒醒"
                   << "     小兄弟，光天化日的，\r\n     你怎么就晕倒在大街上了？"
                   << "    什么？你不知道要去哪里？？"
                   << "    我？你问我要去干什么？"
                   << "     我正打算开始我的旅程，\r\n    探寻书中未曾描绘的山川奇景!!\r\n     要跟我一起出发吗？";


    // 在你的MainWindow或其他适当的类的构造函数或某个初始化函数中设置样式表
    ui->label->setStyleSheet("QLabel { "
                               "background-image: url(:/new/prefix1/dialogue.png); " // 设置背景图片
                               "background-repeat: no-repeat; " // 防止图片重复
                               "background-position: center; " // 你可以调整图片的位置
                               "color: black; " // 设置文字颜色，以便在深色背景上清晰可见
                               "padding: 10px; " // 增加内边距，避免文字直接贴边
                               "font-size: 24px; " // 设置文字大小
                               "}");
    ui->label->setVisible(false); // 初始隐藏

 }
QString currentText="";
//由黑窗到对话框
void MyDialog::switchLabels()
{
        // 停止计时器
        timer1->stop();

        // 切换标签的可见性
        ui->label->setVisible(true);
        ui->label2->setVisible(false);
 }
//点击按钮显示下一段文本
void MyDialog::on_buttonNext_clicked()
{
    // 检查是否还有更多文本段落
    if (currentParagraphIndex < textParagraphs.size()) {
        currentCharIndex = 0;
        currentText="";
        updateDisplayText();
    } else {
        // 可选：如果没有更多文本，可以禁用按钮或显示消息
        ui->buttonNext->setEnabled(false);
        // 或者显示一个消息框告诉用户没有更多文本
    }
}
//实现打字效果
// 修改 updateDisplayText 函数以使用现有状态
void MyDialog::updateDisplayText()
{
        QString fullText = textParagraphs.at(currentParagraphIndex);

        // 如果还有未打印的字符，则继续定时器
        if (currentCharIndex < fullText.length()) {

            currentText += fullText.at(currentCharIndex); // 使用已打印的字符
            // 更新显示的文本
            ui->label->setText(currentText);
            timer2->start(90); // 每90毫秒更新一次文本
        } else {
            // 如果已经打印完整个段落，则停止定时器并准备下一个段落
            timer2->stop();
            ++currentParagraphIndex; // 移动到下一个段落（如果需要的话）
            // 如果需要，可以在这里禁用“下一个”按钮或做其他处理
            // 检查是否还有更多段落，如果没有，则禁用“下一个”按钮
            if (currentParagraphIndex >= textParagraphs.size()) {
                ui->buttonNext->setEnabled(false);
                if (!scene) { // 如果map还没创建，则创建它

                    scene= new Scene(nullptr);
                }
                this->hide(); // 隐藏当前窗口
                scene->show(); // 显示第二个窗口
            }
        }

}

// 添加一个新的槽函数来处理 timer2 的超时事件
void MyDialog::onTimer2Timeout()
{
    ++currentCharIndex; // 增加打印进度
    updateDisplayText(); // 调用这个函数来更新显示的文本（但这次它只会更新，不会重置状态）
}
