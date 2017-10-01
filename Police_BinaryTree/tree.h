#pragma once
#include "Node.h"

template <typename T>
class Tree
{
public:
    Tree() : root(nullptr), size(0)
    {}
    Tree(const Tree &obj)
    {

        root = nullptr;
        copyTree(obj.root);
    }

    Node<T>* getRoot()
    {
        return root;
    }
    T getSize(Node<T> * node)
    {
        if (node)
            return 1 + getSize(node->getLeft()) + getSize(node->getRight());
        return 0;
    }

    ~Tree()
    {
        while (root)
        {
            deleteNode(root);
        }
    }

    Tree &operator=(Tree &obj)
    {
        if (this == &obj)
            return *this;

        deleteNode(root);

        copyTree(obj.root);
        return *this;
    }

    void insert(T val, int key)
    {
        Node<T>* tmp = new Node<T>(val, key);

        Node<T>* cur = root;
        Node<T>* prev = nullptr;

        if (find(key))
            return;

        while (cur)
        {
            prev = cur;
            if (key < (cur->getKey()))
            {
                cur = cur->getLeft();
            }
            else
            {
                cur = cur->getRight();
            }
        }

        tmp->setParent(prev);
        if (prev == nullptr)
        {
            root = tmp;
            return;
        }
        else
        {
            if (key < (prev->getKey()))
            {
                prev->setLeft(tmp);
            }
            else
            {
                prev->setRight(tmp);
            }
        }
        size++;
    }


    void show(Node<T>* node)
    {
        if (node)
        {
            show(node->getLeft());
            cout << node->getData() << " ";
            show(node->getRight());
        }
    }
    void show()
    {
        show(getRoot());
    }

    Node<T>* find(int key)
    {
        Node<T> *cur = root;
        while (cur)
        {
            if (key == (cur->getKey()))
            {
                return cur;
            }

            if (key < (cur->getKey()))
            {
                cur = cur->getLeft();
            }
            else
            {
                cur = cur->getRight();
            }
        }

        return cur;
    }



    Node<T>* findMinElem(Node<T>* node)
    {
        if (node)
        {
            while (node->getLeft())
            {
                node = node->getLeft();
            }
        }

        return node;
    }

    Node<T>* findMaxElem(Node<T>* node)
    {
        if (node)
        {
            while (node->getRight())
            {
                node = node->getRight();
            }
        }
        return node;
    }

    Node<T> *nextElem(Node<T> *node)
    {
        Node<T> *par = nullptr;
        if (node)
        {
            if (node->getRight())
            {
                return findMinElem(node->getRight());
            }

            par = node->getParent();

            while (par && node == par->getRight())
            {
                node = par;
                par = par->getParent();
            }

        }
        return par;
    }

    Node<T> *prevElem(Node<T> *node)
    {
        Node<T> *par = nullptr;
        if (node)
        {
            if (node->getLeft())
            {
                return findMaxElem(node->getLeft());
            }

            par = node->getParent();

            while (par && node == par->getLeft())
            {
                node = par;
                par = par->getParent();
            }

        }
        return par;
    }

    void deleteNode(Node<T>* node)
    {
        if (!node)
            return;

        Node<T>* tmp, *son;

        if (!node->getLeft() || !node->getRight())
            tmp = node;
        else
            tmp = nextElem(node);


        if (tmp->getLeft())
            son = tmp->getLeft();
        else
            son = tmp->getRight();


        if (son)
            son->setParent(tmp->getParent());

        if (!tmp->getParent())
        {
            root = son;
        }
        else
        {
            if (tmp == tmp->getParent()->getLeft())
                tmp->getParent()->setLeft(son);
            else
                tmp->getParent()->setRight(son);
        }
        if (tmp != node)
        {
            node->setData(tmp->getData());
            delete tmp;
        }

        size--;
    }


private:
    Node<T>* root;
    int size;

    void copyTree(Node<T> *node)
    {
        if (node)
        {
            insert(node->getData(), node->getKey());
            copyTree(node->getLeft());
            copyTree(node->getRight());
        }
    }
};
