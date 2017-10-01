#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include "cardatabase.h"
#include "ManagerBasaDate.h"


class Menu
{
public:
    Menu();

    void showMenu();
    void delay();

private:
    CarDataBase dataBase;

    void handlerShowDataBase();
    void handlerEnterNumCar();
    void handlerEnterNumRange();
    void handlerEnterNewCar();

};

#endif // MENU_H
