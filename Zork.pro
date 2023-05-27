TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    attacklistener.cpp \
    binaryoverloading.cpp \
    character.cpp \
    characterdeathlistener.cpp \
    defeatlistener.cpp \
    dispatch.cpp \
    dispatchthesecondcoming.cpp \
    enterroomlistener.cpp \
    eventmanager.cpp \
    exitlistener.cpp \
    game.cpp \
    golistener.cpp \
    hurtlistener.cpp \
    infolistener.cpp \
    inheritanceboi.cpp \
    inputlistener.cpp \
    item.cpp \
    keylistener.cpp \
    main.cpp \
    maplistener.cpp \
    oldman.cpp \
    overloading.cpp \
    restartlistener.cpp \
    room.cpp \
    takelistener.cpp \
    teleportlistener.cpp \
    victorylistener.cpp

DISTFILES += \
    main.txt

HEADERS += \
    abstractclass.h \
    attacklistener.h \
    binaryoverloading.h \
    character.h \
    characterdeathlistener.h \
    defeatlistener.h \
    dispatch.h \
    dispatchthesecondcoming.h \
    enterroomlistener.h \
    eventlistener.h \
    eventmanager.h \
    exitlistener.h \
    game.h \
    golistener.h \
    hurtlistener.h \
    infolistener.h \
    inheritanceboi.h \
    inputlistener.h \
    item.h \
    keylistener.h \
    maplistener.h \
    oldman.h \
    overloading.h \
    restartlistener.h \
    room.h \
    takelistener.h \
    teleportlistener.h \
    victorylistener.h
