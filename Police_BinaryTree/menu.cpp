#include "menu.h"

Menu::Menu()
{
	ManagerBasaDate::initDataBase(dataBase);
}

void Menu::showMenu()
{
    int item;
    system("cls");

    cout << "\n\t DATABASE POLICE! \n\n";
    cout << " 1 - Database listing .\n";
    cout << " 2 - Printing data from a number . \n";
    cout << " 3 - Printing data in numerical range . \n";
    cout << " 4 - New car in the database . \n";


    cout << "\n\n ENTER ITEM MENU : ";
    cin >> item;

    switch (item)
    {
        case 1:
            handlerShowDataBase();
            break;
        case 2:
            handlerEnterNumCar();
            break;
        case 3:
            handlerEnterNumRange();
            break;
        case 4:
            handlerEnterNewCar();
            break;
        default:
            cout << " Incorect item ! \n" ;
            delay();
            break;
    }
}

void Menu::handlerShowDataBase()
{
    dataBase.show();
    delay();
}

void Menu::handlerEnterNumCar()
{
    int numCar;
    cout << "\n\n Enter number Car : ";
    cin >> numCar;

    dataBase.show(numCar);
    delay();

}

void Menu::handlerEnterNumRange()
{
    int from, to;
    cout << "\n\n Enter the number range cars : ";
    cin >> from ;
    cout << " ";
    cin >> to;

    dataBase.show(from, to);
    delay();
}
void Menu::handlerEnterNewCar()
{
    int numCar;
    char buff[255] = {0};
    cout << "\n\n Enter the number car : ";
    cin >> numCar;
    cout << "\n\n Enter the offences car : ";
    cin.get();
    cin.getline(buff, 255);

    dataBase.addOffence(numCar, buff);
    delay();
}

void Menu::delay()
{
    cout << "\n Press any key to continue...\n";
    _getch();
    showMenu();
}
