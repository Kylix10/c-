QT       += core gui
QMAKE_PROJECT_DEPTH = 0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    level1.cpp \
    level2.cpp \
    main.cpp \
    mainsence1.cpp \
    map.cpp \
    mydialog.cpp \
    scene.cpp \
    weight2.cpp

HEADERS += \
    config.h \
    level1.h \
    level2.h \
    mainsence1.h \
    map.h \
    mydialog.h \
    scene.h \
    weight2.h

FORMS += \
    level1.ui \
    level2.ui \
    mainsence1.ui \
    map.ui \
    mydialog.ui \
    scene.ui \
    weight2.ui

TRANSLATIONS += \
    Project1_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
