#include "king.h"

King::King(int col):Figure(col)
{
    Dlist<Position> *goPath = new Dlist<Position>;


    Position pos1(0, -1);
    Position pos2(-1, -1);
    Position pos3(-1, 0);
    Position pos4(-1, 1);
    Position pos5(0, 1);
    Position pos6(1, 1);
    Position pos7(1, 0);
    Position pos8(1, -1);

    goPath->pushBack(pos1);
    goPath->pushBack(pos2);
    goPath->pushBack(pos3);
    goPath->pushBack(pos4);
    goPath->pushBack(pos5);
    goPath->pushBack(pos6);
    goPath->pushBack(pos7);
    goPath->pushBack(pos8);


    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/King");

    data = new FigureData(typeStr + colorStr, goPath);
}
