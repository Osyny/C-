#include "bishop.h"

Bishop::Bishop(int col): Figure(col)
{
    Dlist<Position>* goPath = new Dlist<Position>;

    for (int i = 0; i < 8; i++)
    {
        Position pos1(i, i);
        Position pos2(-i, i);
        Position pos3(i, -i);
        Position pos4(-i, -i);

        goPath->pushBack(pos1);
        goPath->pushBack(pos2);
        goPath->pushBack(pos3);
        goPath->pushBack(pos4);
    }

    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/Bishop");

    data = new FigureData(typeStr + colorStr, goPath);
}
