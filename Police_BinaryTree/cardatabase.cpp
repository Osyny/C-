#include "cardatabase.h"

CarDataBase::CarDataBase()
{}


void CarDataBase::addOffence(int carNumber, const char* offense)
{
    Node<Car>* found = dataBase.find(carNumber);

    if (found != nullptr)
    {
        found->getData().addOffence(offense);
    }
    else
    {
        Car car(carNumber);
        car.addOffence(offense);
        dataBase.insert(car, carNumber);
    }
}

void CarDataBase::show(int from, int to)
{
    Node<Car>* cur = nullptr;

    if (from == -1)
    {
        cur = dataBase.findMinElem(dataBase.getRoot());
    }
    else
    {
        cur = dataBase.find(from);
    }

    if (cur == nullptr)
    {
        cout << "Not exist!!!\n";
        return;
    }

    while (cur != nullptr && (to == -1 || cur->getKey() <= to))
    {
        int carNumber = cur->getData().getNum();
        cout << "---------------------------------------\n";
        cout << "Car number \"" << carNumber << "\": \n";
        Dlist<String> offences = cur->getData().getOffences();

        //offences.show();

        NodeList<String>* curStr = offences.getHead();
        while (curStr != nullptr)
        {
            curStr->getData().println();
            curStr = curStr->getNext();
        }

        cout << "---------------------------------------\n";

        if (from != -1 && to == -1)
            break;

        cur = dataBase.nextElem(cur);
    }
}

