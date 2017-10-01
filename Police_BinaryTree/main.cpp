#include "menu.h"
#include <time.h>


int main()
{
    srand(time(0));

    Menu menu;
    menu.showMenu();

    cout << endl;

    return 0;
}
