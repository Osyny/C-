#include "position.h"

Position::Position(): x(0), y(0) {}

Position::Position(int _x, int _y)
{
    x = _x;
    y = _y;
}

Position::Position(const Position &obj)
{
    x = obj.x;
    y = obj.y;
}

Position &Position::operator =(const Position &obj)
{
    if(this != &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    return *this;
}

bool Position::operator==(const Position &obj)
{
    return x == obj.x && y == obj.y;
}

void Position::setX(int _x)
{
    x = _x;
}

void Position::setY(int _y)
{
    y =_y;
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}

int Position::getIndex(int whidth, int height)
{
    int idx = y * whidth + x;

    return idx >= whidth*height ? -1 : idx;
}
