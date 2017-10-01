#pragma once

#include <iostream>
using namespace std;

class Node
{
public:

    Node(char _data = '\0');

    void setData(char _data);

    char getData();

    void setNext(Node* _next);

    Node* getNext();

    ~Node();

private:

    char data;
    Node* next;
};
