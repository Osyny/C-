#ifndef MENU_H
#define MENU_H

#include "game.h"


class Menu
{
public:
    Menu();

    void showMenu();
    void delay();

private:
    Game game;

    void handlerPutMany();
    void handlerStart();
    void handlerExit();
};

#endif // MENU_H
