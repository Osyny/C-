#include "List.h"



List::List() : head(nullptr), taile(nullptr), size(0)
{}

List::List(const List& obj)
{
    cout << " ConstrCopy. \n";

    head = taile = nullptr;
    size = 0;
    Node* cur = obj.head;

    while (cur != nullptr)
    {
        pushBack(cur->getData());
        cur = cur->getNext();
    }

}

List::List(List&& obj)
{
    cout << " ConstrMOVE. \n";

    head = obj.head;
    taile = obj.taile;
    size = obj.size;

    obj.head = nullptr;
    obj.taile = nullptr;
    obj.size = 0;
}

List & List::operator=(List && obj)
{

    cout << " operator = " << endl;
    if (size != 0)
    {
        delete head;
        delete taile;
    }
    size = obj.size;
    head = obj.head;
    taile = obj.taile;

    obj.head = nullptr;
    obj.taile = nullptr;
    obj.size = 0;

    return*this;

}

List::~List()
{
    if (size > 0)
        deleteElements(0, size - 1);
    head = taile = nullptr;
}

Node *List::getFirst()
{
    return head;
}

int List::getSize()
{
    return size;
}

void List::pushBack(char data)
{
    Node* tmp = new Node(data);

    if (size == 0)
    {
        head = taile = tmp;
    }
    else
    {
        taile->setNext(tmp);
        taile = tmp;
    }
    size++;
}

void List::pushStart(char data)
{
    Node* tmp = new Node(data);

    if (size == 0)
    {
       head = taile = tmp;
    }
    else
    {
        tmp->setNext(head);
        head = tmp;
    }
    size++;
}

void List::deleteStart()
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        delete  head;
        head = taile = nullptr;
        size = 0;
        return;
    }

    Node* tmp = head;
    head = head->getNext();
    delete tmp;

    size--;
}

void List::deleteBack()
{
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        delete  head;
        head = taile = nullptr;
        size = 0;
        return;
    }

    Node* cur = head;
    // Pointer cur set on the penultimate element
    while (cur->getNext() != taile)
    {
        cur = cur->getNext();
    }
    //delete last elenent
    delete taile;
    //Set taile to penultimate element
    taile = cur;
    //Set next ptr to nullptr for last element
    taile->setNext(nullptr);
    size--;

}

void List::deleteElem(int index)
{
    if (index >= 0 && index <= size)
    {
        if (index == 0)
        {
            deleteStart();
        }
        else if (index == size)
        {
            deleteBack();
        }
        else
        {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++)
            {
                cur = cur->getNext();
            }

            Node* toDelete = cur->getNext();
            cur->setNext(cur->getNext()->getNext());

            //toDelete->setNext(nullptr);
            delete toDelete;
            size--;
        }
    }
    else
    {
        cout << "Cannot deleting! Index out of bounds!\n";
    }
}

void List::deleteElements(int from, int to)
{
    if (from >= 0 && to >= 0 && from <= to && to < size)
    {
        for (int i = from; i <= to; i++)
        {
            deleteElem(from);
        }
    }
    else
    {
        cout << "Cannot deleting. Incorect index range!!!\n";
    }
}

void List::insert(char newElem, int index)
{
    if (index >= 0 && index <= size)
    {
        if (index == 0)
        {
            pushStart(newElem);
            return;
        }
        else if (index == size)
        {
            pushBack(newElem);
            return;
        }
        Node* tmp = new Node(newElem);
        Node* cur = head;

        for (int i = 0; i < index - 1; i++)
        {
            cur = cur->getNext();
        }
        tmp->setNext(cur->getNext());
        cur->setNext(tmp);
        delete tmp;
        size++;

    }
    else
    {
        cout << "Cannot insert! Index out of bounds!\n";
    }
}

void List::print()
{
    Node* cur = head;
    while (cur)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}
