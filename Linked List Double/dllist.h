/* 
 * dllist.h / Double Linked List
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 4:56 PM
 */

#ifndef DLLIST_H
#define DLLIST_H

using namespace std;

template <class T>
class dllist
{
    class node
    {
    public:
        T info;
        node *next;
        node *prev;
        node()
        {
            info = 0;
            next = NULL;
            prev = NULL;
        }
    } * first, *last;

public:
    dllist()
    {
        first = last = NULL;
    }
    bool isempty()
    {
        return first == NULL;
    }
    bool clear();
    void insert(T);
    bool deleteel(T);
    int searchel(T);
    void reverse();
    void display();
};

template <class T>
bool dllist<T>::clear()
{
    node *de;
    while (!isempty())
    {
        de = first;
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
        de->next = NULL;
        de->prev = NULL;
        delete de;
    }
    first = last = NULL;
    return true;
}

template <class T>
void dllist<T>::insert(T el)
{
    node *tp, *tra, *temp = new node();
    temp->info = el;
    tra = first;
    tp = NULL;

    if (isempty())
        first = last = temp;
    else if (tra->info >= el) //first position
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        while ((tra->info) <= el && (tra->next) != NULL)
        {
            tp = tra;
            tra = (tra->next);
        }
        if (tra->info > el)
        {
            temp->next = tp->next;
            temp->prev = tra->prev;
            tp->next = temp;
            tra->prev = temp;
        }
        else if ((tra->info) <= el)
        {
            tra->next = temp;
            temp->prev = tra;
        }
    }
}

template <class T>
bool dllist<T>::deleteel(T el)
{
    if (isempty())
        throw 1;
    node *tra;
    tra = first;
    if (tra->info == el) //first node
    {
        first = first->next;
        first->prev = NULL;
        if (first == NULL)
            last = NULL;
        tra->next = NULL;
        tra->prev = NULL;
        delete tra;
        return true;
    }
    if (last->info == el)
    {
        last = last->prev;
        last->next->prev = NULL;
        delete last->next;
        last->next = NULL;
        return true;
    }
    while (tra != NULL)
    {
        if ((tra->info) == el)
        {
            tra->prev->next = tra->next;
            tra->next->prev = tra->prev;
            tra->next = tra->prev = NULL;
            delete tra;
            return true;
        }
        tra = (tra->next);
    }
    throw 2;
}

template <class T>
int dllist<T>::searchel(T el)
{
    int pos = 1;
    node *tra;
    if (isempty())
        throw 1;
    tra = first;
    while (tra != NULL)
    {
        if (tra->info == el)
            return pos;
        tra = tra->next;
        pos++;
    }
    throw 2;
}

template <class T>
void dllist<T>::display()
{
    cout << endl;
    if (isempty())
        throw 1;
    node *tra;
    tra = first;
    while (tra != NULL)
    {
        cout << " " << tra->info;
        tra = tra->next;
    }
}

template <class T>
void dllist<T>::reverse()
{
    node *t1, *t2, *t3;
    t1 = first;
    if (isempty())
        throw 1;
    if (!isempty() && (t1->next) != NULL)
    {
        t2 = t1->next;
        if (t2->next != NULL)
            t3 = t2->next;
        t1->next = NULL;
        t1->prev = t2;
        last = first;
        while (t3->next != NULL)
        {
            t2->next = t1;
            t2->prev = t3;
            t1 = t2;
            t2 = t3;
            t3 = t2->next;
        }
        t2->next = t1;
        t2->prev = t3;
        t3->prev = NULL;
        t3->next = t2;
        first = t3;
    }
    display();
}

#endif /* DLLIST_H */