#pragma once
#include "nodelist.h"
#include "str.h"

template <typename T>
class Dlist
{
public:

    Dlist()
    {
        head = tail = nullptr;
        size = 0;
    }

    Dlist(const Dlist &obj)
    {
       // cout << "\n Constr COPY...\n";
        head = tail = nullptr;
        size = 0;

        NodeList<T>* cur = obj.head;
        while (cur != nullptr)
        {
            pushBack(cur->getData());
            cur = cur->getNext();
        }
    }
    Dlist (Dlist&& obj)
    {
       // cout << " ConstrMOVE. \n";

        head = obj.head;
        tail = obj.tail;
        size = obj.size;

        obj.head = nullptr;
        obj.tail = nullptr;
        obj.size = 0;
    }

    NodeList<T>* getHead()
    {
        return head;
    }
    NodeList<T>* getTail()
    {
        return tail;
    }
    int getSize()
    {
        return size;
    }

    ~Dlist()
    {

        while (size)
        {
           deleteStart();
        }

    }
    Dlist& operator=(Dlist& obj)
    {
        if(this==&obj)
            return *this;

        while (size)
            deleteStart();

        NodeList<T> * cur= obj.head;
        while (cur!=nullptr)
        {
            pushBack(cur->getData());
            cur = cur->getNext();
        }
        return *this;
    }

    Dlist& operator=(Dlist && obj)
    {
       // cout << "\n operator= ...&&\n";
        while (size)
            deleteStart();

        size = obj.size;
        head = obj.head;
        tail = obj.tail;

        obj.head = nullptr;
        obj.tail = nullptr;
        obj.size = 0;

        return*this;

    }

    void pushStart(T data)
    {
        NodeList<T>* tmp = new NodeList<T>(data);

        if (size == 0)
        {
            head = tail = tmp;
        }
        else
        {

            tmp->setNext(head);
            head->setPrev(tmp);
            tmp->setPrev(nullptr);
            head = tmp;
        }
        size++;

    }

    void pushBack(T data)
    {
        NodeList<T>* tmp = new NodeList<T>(data);
        if (size == 0)
        {
            head = tail = tmp;
        }
        else
        {
            tail->setNext(tmp);
            tmp->setPrev(tail);
            tail = tmp;
        }
        size++;
    }

    void deleteStart()
    {

        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete  head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        head = head->getNext();
        delete head->getPrev();

        head->setPrev(nullptr);

        size--;
    }

    void deleteBack()
    {
        if (size == 0)
        {
            return;
        }
        if (size == 1)
        {
            delete  head;
            head = tail = nullptr;
            size = 0;
            return;
        }


        tail = tail->getPrev();
        delete tail->getNext();

        tail->setNext(nullptr);
        size--;

    }

    void insert(int index, int newElem)
    {
        if (index >= 0 && index <= size)
        {
            if(index == 0)
            {
                pushStart(newElem);
                return;
            }
            if (index == size)
            {
                pushBack(newElem);
                return;
            }

            NodeList<T>* tmp = new NodeList<T>(newElem), *cur = head;

            for (int i = 0; i < index - 1; i++)
            {
                cur->getNext();
            }

            tmp->setNext(cur->getNext());
            tmp->setPrev(cur);
            cur->setNext(tmp);
            tmp->getNext()->setPrev(tmp);

            size++;
        }
        else
        {
            cout << "Cannot insert! Index out of bounds!\n";
        }

    }

    void deleteElem(int index)
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
                    NodeList<T>* cur = head;
                    for (int i = 0; i < index - 1; i++)
                    {
                        cur = cur->getNext();
                    }

                    NodeList<T>* toDelete = cur->getNext();

                    cur->setNext(toDelete->getNext());
                    cur->getNext()->setPrev(cur);


                    delete toDelete;
                    size--;
                }
            }
            else
            {
                cout << "Cannot deleting! Index out of bounds!\n";
            }

    }

    void sort()
    {
        NodeList<T>* cur = head;
        while (cur->getNext() != nullptr)
        {
            cur = cur->getNext();

            if(cur->getData() < cur->getPrev()->getData())
            {

            }
        }
    }

    void show()
    {
        //Print<T>::printList(head);
        NodeList<T>* cur = head;
        while (cur)
        {
            cur->getData().println();
            cur = cur->getNext();
        }
        cout << endl;
    }

    void clear()
    {
        head = tail = nullptr;
        size = 0;
    }

private:
    NodeList<T> *head;
    NodeList<T> *tail;
    int size;

};
