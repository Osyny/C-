#include "queen.h"

Queen::Queen(int col):Figure(col)
{
    Dlist<Position>* goPath = new Dlist<Position>;

    for (int i = 0; i < 8; i++)
    {
        Position pos1(i, i);
        Position pos2(-i, i);
        Position pos3(i, -i);
        Position pos4(-i, -i);
        Position pos5(0, i);
        Position pos6(0, -i);
        Position pos7(i, 0);
        Position pos8(-i, 0);
        goPath->pushBack(pos1);
        goPath->pushBack(pos2);
        goPath->pushBack(pos3);
        goPath->pushBack(pos4);
        goPath->pushBack(pos5);
        goPath->pushBack(pos6);
        goPath->pushBack(pos7);
        goPath->pushBack(pos8);
    }

    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/Queen");

    data = new FigureData(typeStr + colorStr, goPath);
}
