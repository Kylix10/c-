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
    setStatusBar(nullptr);
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




// void mainsence1::on_pushButton_3_clicked()//音乐按键
// {

//     QMediaPlayer *player = new QMediaPlayer;
//     QAudioOutput *audioOutput = new QAudioOutput;
//     connect(ui->musicbutton, &QPushButton::clicked, this, &mainsence1::on_pushButton_3_clicked);
//     player->setAudioOutput(audioOutput);
//     player->setSource(QUrl::fromLocalFile("D:\\c-\\c-\\res\\M500000rv3ic2LlIPm.mp3"));//因为歌曲本地存储不同可能要更改歌的所在目录
//     audioOutput->setVolume(50);
//     player->play();

// }//播放音乐





QMediaPlayer *player = new QMediaPlayer;
QAudioOutput *audioOutput = new QAudioOutput;
int i=1;

void mainsence1::on_musicbutton_clicked()
{
    connect(ui->musicbutton, &QPushButton::clicked, this, &mainsence1::on_musicbutton_clicked);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:\\Users\\kaiya\\Desktop\\xuxiake\\res\\M500000rv3ic2LlIPm.mp3"));//因为歌曲本地存储不同可能要更改歌的所在目录
    audioOutput->setVolume(50);
    if(i){
        player->play();
        i--;
    }
    else{
        i=1;
        player->stop();
    }
}

void mainsence1::on_cancelButton_clicked()
{
    this->close();
}


