#pragma once
#include <iostream>

using namespace std;


class Position
{
public:
    Position();
    Position(int _x, int _y);

    Position(const Position &obj);

    Position &operator =(const Position &obj);

    bool operator==(const Position &obj);


    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();
    int getIndex(int width, int height);

private:
    int x;
    int y;

};

