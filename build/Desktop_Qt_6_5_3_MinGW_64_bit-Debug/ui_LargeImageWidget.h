/********************************************************************************
** Form generated from reading UI file 'LargeImageWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LARGEIMAGEWIDGET_H
#define UI_LARGEIMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LargeImageWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *LargeImageWidget)
    {
        if (LargeImageWidget->objectName().isEmpty())
            LargeImageWidget->setObjectName("LargeImageWidget");
        LargeImageWidget->resize(460, 577);
        label = new QLabel(LargeImageWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 20, 361, 231));

        retranslateUi(LargeImageWidget);

        QMetaObject::connectSlotsByName(LargeImageWidget);
    } // setupUi

    void retranslateUi(QWidget *LargeImageWidget)
    {
        LargeImageWidget->setWindowTitle(QCoreApplication::translate("LargeImageWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("LargeImageWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LargeImageWidget: public Ui_LargeImageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LARGEIMAGEWIDGET_H
