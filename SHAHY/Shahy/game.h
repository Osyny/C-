#pragma once

#include "view.h"
#include "cell.h"
#include "dlist.h"

class Game
{
public:
    Game();

private:
    void init();

    Figure* initFigure(Position *pos);

    GameView *view;
};

