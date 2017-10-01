#pragma once
#include "Dlist.h"

class Car
{
public:
    Car() : num(0) {}
    Car(int _num);
    Car &operator =(Car &obj);

    int getNum();

    const Dlist<String> &getOffences() const;

    void addOffence(const char* offence);


private:
    int num;
    Dlist<String> offences;
};

