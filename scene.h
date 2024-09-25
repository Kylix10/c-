#ifndef SCENE_H
#define SCENE_H



#include <QMainWindow>
#include<map.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Scene;
}
QT_END_NAMESPACE

class Scene : public QMainWindow
{
    Q_OBJECT

public:
    Scene(QWidget *parent = nullptr);
    ~Scene();

    //初始化场景
    void initScene();

private slots:

    //声明槽函数
    void on_Yesbtn_clicked();

private:
    Ui::Scene *ui;
    Map*map;//指向第二个窗口的指针
};
#endif // SCENE_H
