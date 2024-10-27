#include "mainsence1.h"
#include "ui_mainsence1.h"
#include <weight2.h>
#include "QAudioOutput"
mainsence1::mainsence1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainsence1)
    , mdl(nullptr)
    , player(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
    , flag(false)

{
    ui->setupUi(this);
    this->setWindowTitle("万里遐征");
    setStatusBar(nullptr);
   // connect(ui->musicbutton, &QPushButton::clicked, this, &mainsence1::on_musicbutton_clicked);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:\\Users\\kaiya\\Desktop\\xuxiake\\res\\M500000rv3ic2LlIPm.mp3"));//因为歌曲本地存储不同可能要更改歌的所在目录
    audioOutput->setVolume(50);
}

mainsence1::~mainsence1()
{
    delete ui;
    delete mdl; // 不再需要检查是否为nullptr，因为delete空指针是安全的
    // delete player; // 虽然QMediaPlayer作为子对象会被自动删除，但显式删除也无妨

}

void mainsence1::on_pushButton_2_clicked()
{
    weight2 *in = new weight2();
    in->show();

}

void mainsence1::on_pushButton_clicked()
{
    if (!mdl) {
        mdl = new MyDialog(nullptr);
    }
    this->hide();
    mdl->show();
}
// bool flag=false;

void mainsence1::on_musicbutton_clicked()
{
    flag = !flag;
    // connect(ui->musicbutton, &QPushButton::clicked, this, &mainsence1::on_musicbutton_clicked);
    // player->setAudioOutput(audioOutput);
    // player->setSource(QUrl::fromLocalFile("C:\\Users\\kaiya\\Desktop\\xuxiake\\res\\M500000rv3ic2LlIPm.mp3"));//因为歌曲本地存储不同可能要更改歌的所在目录
    // audioOutput->setVolume(20);
    if (flag) {
        player->play();
    } else {
        player->stop();
    }
}

void mainsence1::on_cancelButton_clicked()
{
    this->close();
}

