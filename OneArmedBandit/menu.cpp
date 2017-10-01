#include "menu.h"

Menu::Menu(): game(10)
{}

void Menu::handlerPutMany()
{
     int count;
     cout << "\n Howe mony you put : ";
     cin >> count;
     game.setMony(count);

     handlerStart();

}

void Menu::handlerStart()
{
    system("cls");
    game.play();
    showMenu();
}


void Menu::showMenu()
{
    int item;
    system("cls");
    cout << "\n THE ONE-ARMED BANDIT !!! \n\n";

    cout << " 1 - Put money. " << endl;
    cout << " 2 - Start game. " << endl;

    cout << "\n You balans : " << game.getBalance() << endl;

    cout << " Enter item menu: ";
    cin >> item;

    switch (item)
    {
        case 1:
            handlerPutMany();
            break;
        case 2:
            handlerStart();
            break;
        default:
            cout << " Incorect item ! \n" ;
            delay();
            break;
    }
}

void Menu::delay()
{
    cout << "Press any key to continue...\n";
    _getch();
    showMenu();
}
