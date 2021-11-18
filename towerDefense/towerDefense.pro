QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BuildGreenTowerIcon.cpp \
    BuildRedTowerIcon.cpp \
    BuildYellowTowerIcon.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    GreenTower.cpp \
    RedTower.cpp \
    Tower.cpp \
    YellowTower.cpp \
    main.cpp

HEADERS += \
    BuildGreenTowerIcon.h \
    BuildRedTowerIcon.h \
    BuildYellowTowerIcon.h \
    Bullet.h \
    Enemy.h \
    Game.h \
    GreenTower.h \
    RedTower.h \
    Tower.h \
    YellowTower.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
