#pragma once
#include "Node.h"


class List
{
public:
    List();
    List(const List& obj);
    List(List && obj);
    List& operator=(List&& obj);


    ~List();

    Node* getFirst();
    int getSize();

    void pushBack(char data);
    void pushStart(char data);
    void deleteStart();
    void deleteBack();

    void deleteElem(int index);
    void deleteElements(int from, int to);

    void insert(char newElem, int index);

    void print();

private:
    Node* head;
    Node* taile;

    int size;
};
