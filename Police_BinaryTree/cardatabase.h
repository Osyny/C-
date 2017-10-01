#pragma once
#include "car.h"

#include "tree.h"
//#include "str.h"


class CarDataBase
{
public:
    CarDataBase();

    void addOffence(int carNumber, const char *offense);
    void show(int from = -1, int to = -1);

private:
   /* void initDataBase();
    const char* initRandOffence();*/

    Tree<Car> dataBase;
};


