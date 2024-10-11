/********************************************************************************
** Form generated from reading UI file 'weight2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEIGHT2_H
#define UI_WEIGHT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weight2
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *weight2)
    {
        if (weight2->objectName().isEmpty())
            weight2->setObjectName("weight2");
        weight2->resize(475, 263);
        weight2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/res/first_page(2).jpg);"));
        centralwidget = new QWidget(weight2);
        centralwidget->setObjectName("centralwidget");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 280, 141, 51));
        QFont font;
        font.setPointSize(16);
        pushButton_2->setFont(font);
        pushButton_2->setIconSize(QSize(20, 20));
        pushButton_2->setAutoRepeatDelay(300);
        pushButton_2->setAutoRepeatInterval(100);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(400, 360, 141, 51));
        pushButton_3->setFont(font);
        pushButton_3->setIconSize(QSize(20, 20));
        pushButton_3->setAutoRepeatDelay(300);
        pushButton_3->setAutoRepeatInterval(100);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 190, 41, 20));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(60, 90, 41, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/res/A.png);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(140, 90, 41, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/res/D.png);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(100, 90, 41, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/res/S.png);"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(100, 50, 41, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/res/W.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 70, 161, 51));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        weight2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(weight2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 475, 17));
        weight2->setMenuBar(menubar);
        statusbar = new QStatusBar(weight2);
        statusbar->setObjectName("statusbar");
        weight2->setStatusBar(statusbar);

        retranslateUi(weight2);

        QMetaObject::connectSlotsByName(weight2);
    } // setupUi

    void retranslateUi(QMainWindow *weight2)
    {
        weight2->setWindowTitle(QCoreApplication::translate("weight2", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("weight2", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("weight2", "\346\223\215\344\275\234\346\214\207\345\215\227", nullptr));
        pushButton->setText(QCoreApplication::translate("weight2", "\350\277\224\345\233\236", nullptr));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        label->setText(QCoreApplication::translate("weight2", "\344\270\212\344\270\213\345\267\246\345\217\263\347\247\273\345\212\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class weight2: public Ui_weight2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEIGHT2_H
