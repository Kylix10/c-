#ifndef LARGEIMAGEWIDGET_H
#define LARGEIMAGEWIDGET_H

#include <QWidget>

namespace Ui {
class LargeImageWidget;
}

class LargeImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LargeImageWidget(QWidget *parent = nullptr,const QString &imagePath = QString(),const QString &imageContent = QString());
    ~LargeImageWidget();
signals:
    void windowClosed();
private:
    Ui::LargeImageWidget *ui;
    QString imagePath;
    QString imageContent;
    void closeEvent(QCloseEvent *event) override ;
};


#endif // LARGEIMAGEWIDGET_H
