/* 
 * cllist.h / Circular Linked List
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 12:11 AM
 */

#ifndef CLLIST_H
#define CLLIST_H

#include <cstdio>
using namespace std;

template <class T>
class cllist
{
    class node
    {
    public:
        T info;
        node *next;
        node()
        {
            info = 0;
            next = NULL;
        }
    } * last;

public:
    cllist()
    {
        last = NULL;
    }
    bool isempty()
    {
        return last == NULL;
    }
    bool clear();
    void insertel(T);
    bool deleteel(T);
    int searchel(T);
    void reverse();
    void display();
};

template <class T>
bool cllist<T>::clear()
{
    node *de;
    if (isempty())
        throw 1;
    while (!isempty())
    {
        de = last;
        last = last->next;
        de->next = NULL;
        delete de;
    }
    last = NULL;
    return true;
}

template <class T>
void cllist<T>::insertel(T el)
{
    node *temp = new node;
    temp->info = el;
    if (isempty())
    {
        last = temp;
        last->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = last->next;
    }
}

template <class T>
bool cllist<T>::deleteel(T el)
{ //couldn't delete last element
    if (isempty())
        throw 1;
    node *tra, *tp;
    tp = last;
    tra = last->next;

    if (last->next == last) //single node
    {
        if (last->info == el)
        {
            delete last;
            last = NULL;
            return true;
        }
        else
            throw 2;
    }
    if (tra->info == el) //first node
    {
        tp->next = tra->next;
        tra->next = NULL;
        delete tra;
        return true;
    }
    while (tra->next != last)
    {
        if ((tra->next->info) == el)
        {
            tp = tra->next;
            tra->next = tp->next;
            tp->next = NULL;
            delete tp;
            return true;
        }
        tra = tra->next;
    }
    if (tra->next->info == el)
    {
        tp = tra->next;
        tra->next = tp->next;
        tp->next = NULL;
        last = tra;
        delete tp;
        return true;
    }
    throw 2;
    return false;
}

template <class T>
int cllist<T>::searchel(T el)
{
    int pos = 1;
    node *tra;
    if (isempty())
        throw 1;
    tra = last->next;
    if (tra->info == el)
        return 1;
    while ((tra->info) != el && tra != last)
    {
        tra = tra->next;
        pos++;
    }
    if (tra->info == el)
        return pos;
    throw 2;
}

template <class T>
void cllist<T>::display()
{
    cout << endl;
    if (isempty())
        throw 1;
    node *tra;
    tra = last;
    if (tra->next == tra) //only one node
        cout << " " << last->info;
    else
    {
        tra = tra->next;
        while (tra != last)
        {
            cout << " " << tra->info;
            tra = tra->next;
        }
        cout << " " << tra->info;
    }
}

template <class T>
void cllist<T>::reverse()
{
    node *t1, *t2, *t3;
    t1 = last->next;
    if (isempty())
        throw 1;
    if (!isempty() && (t1->next) != NULL)
    {
        t2 = t1->next;
        if (t2->next != NULL)
            t3 = t2->next;
        t1->next = NULL;
        while (t3 != NULL)
        {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t2->next;
        }
        t2->next = t1;
        last = t2;
    }
}

#endif /* CLLIST_H */