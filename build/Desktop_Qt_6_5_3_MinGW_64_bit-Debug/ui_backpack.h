/********************************************************************************
** Form generated from reading UI file 'backpack.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKPACK_H
#define UI_BACKPACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_backpack
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *backpack)
    {
        if (backpack->objectName().isEmpty())
            backpack->setObjectName("backpack");
        backpack->resize(673, 501);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        backpack->setFont(font);
        scrollArea = new QScrollArea(backpack);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 671, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 669, 499));
        scrollAreaWidgetContents->setAutoFillBackground(false);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(backpack);

        QMetaObject::connectSlotsByName(backpack);
    } // setupUi

    void retranslateUi(QWidget *backpack)
    {
        backpack->setWindowTitle(QCoreApplication::translate("backpack", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class backpack: public Ui_backpack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKPACK_H
