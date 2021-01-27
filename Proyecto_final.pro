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
    load_game.cpp \
    lvl_2.cpp \
    main.cpp \
    dialog.cpp \
    menu.cpp \
    new_game.cpp \
    obstaculos.cpp \
    pausa.cpp \
    personaje.cpp \
    ventana.cpp \
    vidas.cpp

HEADERS += \
    bala.h \
    contador.h \
    dialog.h \
    enemigo_1.h \
    load_game.h \
    lvl_2.h \
    menu.h \
    new_game.h \
    obstaculos.h \
    pausa.h \
    personaje.h \
    ventana.h \
    vidas.h

FORMS += \
    dialog.ui \
    load_game.ui \
    lvl_2.ui \
    menu.ui \
    new_game.ui \
    pausa.ui \
    ventana.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourse.qrc

DISTFILES += \
    ../informatica/Sprites/3 Scorpio/Scorpio_attack.png \
    Resourse/Muros proyecto final.png
