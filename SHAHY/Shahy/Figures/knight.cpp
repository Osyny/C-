#include "knight.h"

Knight::Knight(int col):Figure(col)
{
    Dlist<Position> *goPath = new Dlist<Position>;


        Position pos1(-1, -2);
        Position pos2(-2, -1);
        Position pos3(-2, 1);
        Position pos4(-1, 2);
        Position pos5(1, 2);
        Position pos6(2, 1);
        Position pos7(2, -1);
        Position pos8(1, -2);

        goPath->pushBack(pos1);
        goPath->pushBack(pos2);
        goPath->pushBack(pos3);
        goPath->pushBack(pos4);
        goPath->pushBack(pos5);
        goPath->pushBack(pos6);
        goPath->pushBack(pos7);
        goPath->pushBack(pos8);


    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/Knight");

    data = new FigureData(typeStr + colorStr, goPath);
}
