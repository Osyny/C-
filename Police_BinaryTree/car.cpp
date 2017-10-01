#include "car.h"

Car::Car(int _num): num(0)
{
    num = _num;
}

Car &Car::operator =( Car &obj)
{
    if(this==&obj)
        return *this;

    num = obj.num;
    offences = obj.offences;

    return *this;
}

int Car::getNum()
{
    return num;
}

const Dlist<String> &Car::getOffences() const
{
    return offences;
}

void Car::addOffence(const char *offence)
{
    String str(offence);
    offences.pushStart(str);
}


