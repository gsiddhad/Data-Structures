/* 
 * stqu_qu.h / Reverse Stack Using Queue
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 3:28 PM
 */

#ifndef STQU_QU_H
#define	STQU_QU_H

#include <cstdio>
using namespace std;

template <class T>
class myqueue{
    class node{
    public:
        T info;
        node *next;
        node(){
            info=0;
            next=NULL;
        }
    }*first,*last;
    
    public:
        myqueue(){
            first=last=NULL;
        }
        bool isempty(){
            return first==NULL;
        }
        bool clear();
        void enqueue(T);
        T dequeue();
        void display();
        void del_last();
};

template <class T>
void myqueue<T> :: del_last()
{
    if(first==last)
    {
        delete first;
        first=last=NULL;
    }
    else
    {
        node *tp,*tra;
        tp=tra=first;
        while(tra!=last)
        {
            tp=tra;
            tra=tra->next;
        }
        last=tp;
        tp->next=NULL;
        delete tra;
    }
}
template <class T>
bool myqueue<T> :: clear()
{
    node *de;
    while(!isempty())
    {
        de=first;
        first=first->next;
        de->next=NULL;
        delete de;
    }
    return true;
}

template <class T>
void myqueue<T> :: enqueue(T el)
{
    node *temp=new node;
    temp->info=el;
    if(isempty())
        first=last=temp;
    else
    {        
        last->next=temp;
        last=temp;
    }
}

template <class T>
T myqueue<T> :: dequeue()
{
    if(isempty())
        throw 1;
    node *de;
    T info=first->info;
    de=first;
    first=first->next;
    de->next=NULL;
    delete de;
    return info;
}

template <class T>
void myqueue<T> :: display()
{
    if(isempty())
        throw 1;
    cout<<endl;
    node *tra=first;
    while(tra!=NULL)
    {
        cout<<" "<<tra->info;
        tra=tra->next;
    }
}

#endif	/* STQU_QU_H */