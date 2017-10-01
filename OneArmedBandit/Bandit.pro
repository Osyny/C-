TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    queue.cpp \
    node.cpp \
    list.cpp \
    game.cpp \
    drum.cpp \
    menu.cpp

HEADERS += \
    queue.h \
    node.h \
    list.h \
    game.h \
    drum.h \
    menu.h
