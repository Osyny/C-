#include "figure.h"

Figure::Figure(int _color) : data(nullptr)
{
    color = _color;
}

Figure::~Figure()
{
    if (data != nullptr)
    {
        delete data;
    }
}

FigureData *Figure::getData()
{
    return data;
}

int Figure::getColor()
{
    return color;
}
