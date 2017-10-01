#pragma once
#include <SFML\Graphics.hpp>
#include "cell.h"
#include "dlist.h"
#include "gamedata.h"

using namespace sf;

class GameView
{
public:

    GameView(Dlist<Cell*> *_cells);
    ~GameView();

    void init();
    void startLoop();
    void stopLoop();


private:
    bool isStarted;
    Cell* activeCell;
    Dlist<Cell*> *cells;

    RenderWindow *window;

    Texture bgImage;

    void eventLoop();
    void updateGraphics();

};

