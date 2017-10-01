#include "rook.h"

Rook::Rook(int col):Figure(col)
{
    Dlist<Position> *goPath = new Dlist<Position>;

    for (int i = -(8-1); i < 8; i++)
    {
        Position pos1(0, i);
        Position pos2(i, 0);

        goPath->pushBack(pos1);
        goPath->pushBack(pos2);
    }
    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/Rook");

    data = new FigureData(typeStr + colorStr, goPath);
}
