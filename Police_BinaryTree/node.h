#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node(T _data, int _key)
    {
        data = _data;
        key = _key;
        parent = left = right = nullptr;
    }

    void setData(T _data)
    {
        data = _data;
    }
    void setKey(int _key)
    {
        key = _key;
    }

    void setParent(Node* _parent)
    {
        parent = _parent;
    }
    void setLeft(Node* _left)
    {
        left = _left;
    }
    void setRight(Node* _right)
    {
        right = _right;
    }

    T& getData()
    {
        return data;
    }

    int getKey()
    {
        return key;
    }

    Node* getParent()
    {
        return parent;
    }

    Node* getLeft()
    {
        return left;
    }

    Node* getRight()
    {
        return right;
    }


private:
    T data;

    int key;
    Node* parent;
    Node* left;
    Node* right;

};
