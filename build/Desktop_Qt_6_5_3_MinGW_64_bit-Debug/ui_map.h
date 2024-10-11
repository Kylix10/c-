/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *backpackButton;

    void setupUi(QWidget *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName("Map");
        Map->resize(400, 300);
        btn1 = new QPushButton(Map);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(60, 40, 56, 18));
        btn2 = new QPushButton(Map);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(60, 80, 56, 18));
        btn3 = new QPushButton(Map);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(60, 120, 56, 18));
        btn4 = new QPushButton(Map);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(60, 160, 56, 18));
        btn5 = new QPushButton(Map);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(60, 210, 56, 18));
        backpackButton = new QPushButton(Map);
        backpackButton->setObjectName("backpackButton");
        backpackButton->setGeometry(QRect(270, 250, 80, 24));

        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QWidget *Map)
    {
        Map->setWindowTitle(QCoreApplication::translate("Map", "Form", nullptr));
        btn1->setText(QCoreApplication::translate("Map", "\351\273\204\345\261\261", nullptr));
        btn2->setText(QCoreApplication::translate("Map", "\345\205\263\345\215\2412\344\271\235\345\257\250\346\262\237", nullptr));
        btn3->setText(QCoreApplication::translate("Map", "\345\205\263\345\215\2413", nullptr));
        btn4->setText(QCoreApplication::translate("Map", "\345\205\263\345\215\2414", nullptr));
        btn5->setText(QCoreApplication::translate("Map", "\345\205\263\345\215\2415", nullptr));
        backpackButton->setText(QCoreApplication::translate("Map", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
