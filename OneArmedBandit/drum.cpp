#include "drum.h"

Drum::Drum(int size)
{
    this->size = size;
    init();
}

char Drum::get1Sector()
{
    return sectors.getFirst();
}

char Drum::get2Sector()
{
    return sectors.getSecond();
}

char Drum::get3Sector()
{
    return sectors.getThird();
}

void Drum::print()
{
    sectors.show();
}

void Drum::addSector()
{
    char randSimbol = 'A' + rand() % 5;

    sectors.push(randSimbol);
}

void Drum::workDrum()
{
    int numSteps = rand() % 15 + 5;

    for (int i = 0; i < numSteps; i++)
    {
        sectors.pop();
    }

}


void Drum::init()
{
    for (int i = 0; i < size; i++)
        addSector();


    //sectors.show();
}

