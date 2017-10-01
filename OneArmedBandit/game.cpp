#include "game.h"

Game::Game(int n): one(n), two(n), three(n)
{
    balance = 0;
}

Game::~Game()
{}

void Game::play()
{

    do
    {
        system("cls");

        cout<< "\t\t\" BANDIT !!!\"\n\n";
        cout<< "\t\t -------------\n";
        cout<< "\t\t | " << one.get1Sector() << " | " << two.get1Sector() << " | " << three.get1Sector() << " |" << "\n";
        cout<< "\t\t===============\n";
        cout<< "\t\t | " << one.get2Sector() << " | " << two.get2Sector() << " | " << three.get2Sector() << " |" << "\n";
        cout<< "\t\t===============\n";
        cout<< "\t\t | " << one.get3Sector() << " | " << two.get3Sector() << " | " << three.get3Sector() << " |" << "\n";
        cout<< "\t\t -------------\n";

        int bonus = checkWin();
        balance += bonus;

        if (bonus)
        {
            cout << "\n\t\tCongratulations!!! You took a bonus: " << bonus << "!!!\n";
        }

        cout << "\n\t\tYour balance: " << balance << endl;

        _getch();

        doStep();

    }
    while(balance >= TURN_COST);

    cout << "\t\tNo money on Your balance!!!\n";
}

int Game::getBalance()
{
    return balance;
}

void Game::setMony(int count)
{
    balance += count;
}


void Game::doStep()
{
    one.workDrum();
    two.workDrum();
    three.workDrum();

    balance -= TURN_COST;

}

int Game::checkWin()
{
    int bonus = 0;
    if (one.get2Sector() == two.get2Sector() && one.get2Sector() == three.get2Sector())
    {
        bonus = (rand() % 15 + 3) * TURN_COST;
    }

    return bonus;
}
