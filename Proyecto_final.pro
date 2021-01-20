QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    contador.cpp \
    enemigo_1.cpp \
    main.cpp \
    dialog.cpp \
    muros.cpp \
    obstaculos.cpp \
    personaje.cpp \
    vidas.cpp

HEADERS += \
    bala.h \
    contador.h \
    dialog.h \
    enemigo_1.h \
    muros.h \
    obstaculos.h \
    personaje.h \
    vidas.h

FORMS += \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourse.qrc

DISTFILES += \
    ../informatica/Sprites/3 Scorpio/Scorpio_attack.png \
    Resourse/Muros proyecto final.png
