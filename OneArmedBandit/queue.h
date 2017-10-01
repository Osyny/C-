#pragma once
#include "List.h"

class Queue
{
public:
    Queue();
    ~Queue();

    void push(char val);
    void pop();
    void show();

    bool isEmpty();

    char getFirst();
    char getSecond();
    char getThird();

private:
    List list;
};
