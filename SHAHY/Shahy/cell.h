#pragma once
#include "figure.h"
#include "position.h"
#include "gamedata.h"

class Cell
{
public:
    Cell(Position* _pos, int _type, Figure* _figure = nullptr);
    ~Cell();

    bool getActive();

    void setPosition(Position* _pos);
    Position *getPosition();

    int getType();
    Figure *getFigure();
    void setFigure(Figure* _figure);

    Cell* doStep(Dlist<Cell *> *cells, Cell *activeCell);


    bool isEmpty();


private:
    int type;
    bool isActive;

    Position* pos;
    Figure* figure;

    bool checkPath(Dlist<Position>* path, Position *activePos);
    bool checkFreeWay(Dlist<Cell *> *cells, Position* activePos);

};

