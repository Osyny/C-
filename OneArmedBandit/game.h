#pragma once
#include "drum.h"
#include <conio.h>

class Game
{
public:

    static const int STARTING_MONEY = 500;
    static const int TURN_COST = 5;
    Game(){}
    Game(int n);
    ~Game();

    int getBalance();
    void setMony(int count);

    void play();

private:
    Drum one;
    Drum two;
    Drum three;

    int balance;

    void doStep();

    int checkWin();

};
