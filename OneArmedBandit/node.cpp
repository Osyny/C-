#include "Node.h"
#include <cstring>

Node::Node(char _data) : next(nullptr)
{
    data = _data;
}

Node::~Node()
{}

void Node::setData(char _data)
{
    data = _data;
}
char Node::getData()
{
    return data;
}

void Node::setNext(Node* _next)
{
    next = _next;
}

Node* Node::getNext()
{
    return next;
}
