#pragma once
#include "queue.h"

class Drum
{
public:
    Drum(){}
    Drum(int size);

    void workDrum();

    char get1Sector();
    char get2Sector();
    char get3Sector();

    void print();


private:
    Queue sectors;
    int size;

    void init();
    void addSector();
};

