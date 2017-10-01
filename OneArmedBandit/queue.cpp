#include "Queue.h"



Queue::Queue()
{}

Queue::~Queue()
{}

char Queue::getFirst()
{
    return list.getFirst()->getData();
}

char Queue::getSecond()
{
    if (list.getSize() >= 2)
        return list.getFirst()->getNext()->getData();
    else
        return '\0';
}

char Queue::getThird()
{
    if (list.getSize() >= 3)
        return list.getFirst()->getNext()->getNext()->getData();
    else
        return '\0';
}

void Queue::push(char val)
{
    list.pushBack(val);
}
//Queue circl
void Queue::pop()
{
    list.pushBack(list.getFirst()->getData());
    list.deleteStart();
}

void Queue::show()
{
    list.print();
}

bool Queue::isEmpty()
{
    return false;
}
