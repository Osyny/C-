TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cell.cpp \
    figure.cpp \
    position.cpp \
    dlist.cpp \
    nodedlist.cpp \
    view.cpp \
    game.cpp \
    Figures/rook.cpp \
    Figures/bishop.cpp \
    Figures/king.cpp \
    Figures/knight.cpp \
    Figures/pawn.cpp \
    Figures/queen.cpp \
    figuredata.cpp \
    str.cpp \
    gamedata.cpp

HEADERS += \
    cell.h \
    figure.h \
    position.h \
    dlist.h \
    nodedlist.h \
    view.h \
    game.h \
    Figures/rook.h \
    Figures/bishop.h \
    Figures/king.h \
    Figures/knight.h \
    Figures/pawn.h \
    Figures/queen.h \
    figuredata.h \
    str.h \
    gamedata.h

#LIBS += -LD:/Install/SFML/SFML-2.4.2-MINGW/lib/
LIBS += -LD:/Install/SFML/SFML-2.4.2/lib/

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

#INCLUDEPATH += D:/Install/SFML/SFML-2.4.2-MINGW/include
#DEPENDPATH += D:/Install/SFML/SFML-2.4.2-MINGW/include

INCLUDEPATH += D:/Install/SFML/SFML-2.4.2/include
DEPENDPATH += D:/Install/SFML/SFML-2.4.2/include
