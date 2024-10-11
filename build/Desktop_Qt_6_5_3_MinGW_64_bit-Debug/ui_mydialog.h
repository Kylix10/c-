/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QLabel *label;
    QPushButton *buttonNext;
    QLabel *label2;

    void setupUi(QWidget *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName("MyDialog");
        MyDialog->resize(910, 506);
        label = new QLabel(MyDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 230, 851, 261));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        label->setFont(font);
        label->setFrameShadow(QFrame::Shadow::Sunken);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        buttonNext = new QPushButton(MyDialog);
        buttonNext->setObjectName("buttonNext");
        buttonNext->setGeometry(QRect(770, 440, 41, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(12);
        buttonNext->setFont(font1);
        label2 = new QLabel(MyDialog);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(0, 0, 911, 531));
        label2->setFont(font);
        label2->setAutoFillBackground(false);

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QWidget *MyDialog)
    {
        MyDialog->setWindowTitle(QCoreApplication::translate("MyDialog", "Form", nullptr));
        label->setText(QString());
        buttonNext->setText(QCoreApplication::translate("MyDialog", "\347\241\256\345\256\232", nullptr));
        label2->setText(QCoreApplication::translate("MyDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
