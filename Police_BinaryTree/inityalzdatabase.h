#pragma once
#include "cardatabase.h"


class InityalzDataBase
{
public:
    InityalzDataBase();

    const char *initRandOffence();
    void initDataBase();
private:
    CarDataBase carDataBase;
};
