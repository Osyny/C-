#include "pawn.h"
#include "gamedata.h"

Pawn::Pawn(int col):Figure(col)
{
    int dir = col == GameData::getInstance()->getUpColor() ? 1 : -1;
    Dlist<Position> *goPath = new Dlist<Position>;

    Position pos1(0, 1 * dir);
    Position pos2(0, 2 * dir);

    goPath->pushBack(pos1);
    goPath->pushBack(pos2);

    Dlist<Position> *atackPath = new Dlist<Position>;

    pos1 = Position(1, 1 * dir);
    pos2 = Position(-1, 1 * dir);

    atackPath->pushBack(pos1);
    atackPath->pushBack(pos2);

    String colorStr(col == 0 ? "Black.png" : "White.png");
    String typeStr("Images/Pawn");

    data = new FigureData(typeStr + colorStr, goPath, atackPath);
}
