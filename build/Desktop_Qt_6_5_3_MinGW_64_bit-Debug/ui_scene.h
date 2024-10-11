/********************************************************************************
** Form generated from reading UI file 'scene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENE_H
#define UI_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scene
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *Yesbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Scene)
    {
        if (Scene->objectName().isEmpty())
            Scene->setObjectName("Scene");
        Scene->resize(800, 600);
        centralwidget = new QWidget(Scene);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(250, 190, 281, 161));
        Yesbtn = new QPushButton(centralwidget);
        Yesbtn->setObjectName("Yesbtn");
        Yesbtn->setGeometry(QRect(350, 280, 81, 31));
        Scene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Scene);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Scene->setMenuBar(menubar);
        statusbar = new QStatusBar(Scene);
        statusbar->setObjectName("statusbar");
        Scene->setStatusBar(statusbar);

        retranslateUi(Scene);

        QMetaObject::connectSlotsByName(Scene);
    } // setupUi

    void retranslateUi(QMainWindow *Scene)
    {
        Scene->setWindowTitle(QCoreApplication::translate("Scene", "Scene", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Scene", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span"
                        " style=\" font-size:16pt;\">\346\230\257\345\220\246\350\267\237\351\232\217\345\276\220\351\234\236\345\256\242\345\274\200\345\247\213\346\227\205\350\241\214\357\274\237</span></p></body></html>", nullptr));
        Yesbtn->setText(QCoreApplication::translate("Scene", "\346\230\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scene: public Ui_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENE_H
