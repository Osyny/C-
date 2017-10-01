#ifndef GAMEDATA_H
#define GAMEDATA_H
#include "dlist.h"
#include "figure.h"

#define WINDOW_WIDTH 800.0
#define WINDOW_HEIGHT 800.0
#define BOARD_SIZE 8
#define CELL_SIZE 70
#define BOARD_X 130
#define BOARD_Y 100
#define UP_BEATEN_Y (BOARD_Y - 40)
#define DOWN_BEATEN_Y (BOARD_Y + BOARD_SIZE * CELL_SIZE + 5)

class GameData
{
public:

    static GameData* getInstance();

    Dlist<Figure*> *getUpBeatFig();
    Dlist<Figure*> *getDownBeatFig();

    ~GameData();

    void setUpColor(int _upColor);
    int getUpColor();

private:

    static GameData *instance;
    GameData();

    Dlist<Figure*> *upBeatFig;
    Dlist<Figure*> *downBeatFig;

    int upColor;

};

#endif // GAMEDATA_H
