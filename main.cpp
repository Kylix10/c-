#include "mainsence1.h"
#include "map.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<additiem.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Project1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Map w1;//开始


    w1.show();//展示界面1




    return a.exec();
}
