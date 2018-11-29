/* 
 * llistqu.h / Queue Linked List
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 3:20 PM
 */

#ifndef LLISTQU_H
#define	LLISTQU_H

#include <cstdio>
using namespace std;

template <class T>
class llistqueue{
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
        llistqueue(){
            first=last=NULL;
        }
        bool isempty(){
            return first==NULL;
        }
        bool clear();
        void enqueue(T);
        T dequeue();
        void display();
};

template <class T>
bool llistqueue<T> :: clear()
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
void llistqueue<T> :: enqueue(T el)
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
T llistqueue<T> :: dequeue()
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
void llistqueue<T> :: display()
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

#endif	/* LLISTQU_H */