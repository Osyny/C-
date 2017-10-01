#pragma once
#include <iostream>
#include <cstring>

using namespace std;


template <typename T>
class NodeList
{
public:
    NodeList(T _data)
    {
        data = _data;
        prev = next = nullptr;
    }

    ~NodeList()
    {}

    void setData(T _data)
    {
        data = _data;
    }
    void setNext(NodeList * _next)
    {
        next = _next;
    }

    void setPrev(NodeList* _prev)
    {
        prev = _prev;
    }

    T getData()
    {
        return data;
    }

    NodeList* getNext()
    {
        return next;
    }

    NodeList* getPrev()
    {
        return prev;
    }

private:
    T data;

    NodeList* next;
    NodeList* prev;

};

