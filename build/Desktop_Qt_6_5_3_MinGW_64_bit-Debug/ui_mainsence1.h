/********************************************************************************
** Form generated from reading UI file 'mainsence1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSENCE1_H
#define UI_MAINSENCE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainsence1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainsence1)
    {
        if (mainsence1->objectName().isEmpty())
            mainsence1->setObjectName("mainsence1");
        mainsence1->resize(900, 506);
        mainsence1->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/res/first_page(2).jpg);"));
        centralwidget = new QWidget(mainsence1);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 280, 141, 51));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(20, 20));
        pushButton->setAutoRepeatDelay(300);
        pushButton->setAutoRepeatInterval(100);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 360, 141, 51));
        pushButton_2->setFont(font);
        pushButton_2->setIconSize(QSize(20, 20));
        pushButton_2->setAutoRepeatDelay(300);
        pushButton_2->setAutoRepeatInterval(100);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(830, 370, 41, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/res/voice.png);\n"
"border-radius:50%; "));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(830, 430, 41, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/res/cancel.png);\n"
"border-radius:50%; "));
        mainsence1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainsence1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 17));
        mainsence1->setMenuBar(menubar);
        statusbar = new QStatusBar(mainsence1);
        statusbar->setObjectName("statusbar");
        mainsence1->setStatusBar(statusbar);

        retranslateUi(mainsence1);

        QMetaObject::connectSlotsByName(mainsence1);
    } // setupUi

    void retranslateUi(QMainWindow *mainsence1)
    {
        mainsence1->setWindowTitle(QCoreApplication::translate("mainsence1", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("mainsence1", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainsence1", "\346\223\215\344\275\234\346\214\207\345\215\227", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainsence1: public Ui_mainsence1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSENCE1_H
