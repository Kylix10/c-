/********************************************************************************
** Form generated from reading UI file 'level2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL2_H
#define UI_LEVEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_level2
{
public:

    void setupUi(QWidget *level2)
    {
        if (level2->objectName().isEmpty())
            level2->setObjectName("level2");
        level2->resize(400, 300);

        retranslateUi(level2);

        QMetaObject::connectSlotsByName(level2);
    } // setupUi

    void retranslateUi(QWidget *level2)
    {
        level2->setWindowTitle(QCoreApplication::translate("level2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class level2: public Ui_level2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL2_H
