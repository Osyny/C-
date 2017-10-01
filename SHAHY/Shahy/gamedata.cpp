#include "gamedata.h"

GameData *GameData::instance = nullptr;

GameData *GameData::getInstance()
{
    if (instance == nullptr)
    {
        instance = new GameData();
    }
    return instance;
}

Dlist<Figure*> *GameData::getUpBeatFig()
{
    return upBeatFig;
}

Dlist<Figure*> *GameData::getDownBeatFig()
{
    return downBeatFig;
}

GameData::~GameData()
{
    delete upBeatFig;
    delete downBeatFig;
}

void GameData::setUpColor(int _upColor)
{
    upColor = _upColor;
}

int GameData::getUpColor()
{
    return upColor;
}

GameData::GameData():upColor(0)
{
    upBeatFig = new Dlist<Figure*>;
    downBeatFig = new Dlist<Figure*>;
}
