#pragma once
#include "dlist.h"
#include "position.h"
#include "figuredata.h"

class Figure
{
public:
    Figure(int _color);
    virtual ~Figure();

    virtual FigureData *getData();
    virtual int getColor();


protected:
    int color;
    FigureData *data;

};

