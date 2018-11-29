/* 
 * llist.h / Linked List
 * Author : Gourav Siddhad
 * Created on April 6, 2014, 3:40 PM
 */

#ifndef LLIST_H
#define	LLIST_H
#include <cstdio>
using namespace std;

template <class T>
class llist
{
    class node{
    public:
        T info;
        node *next;
        node(){
            info=0;
            next=NULL;
        }
    }*first;
    public:
        llist(){
            first=NULL;
        }
        bool isempty(){
            return first==NULL;
        }
        void clear();
        void insertllbef(T);
        void insertlllas(T);
        T deletellloc(int);
        bool deletellel(T);
        int searchllel(T);
        T searchllpos(int);
        void reversell();
        llist<T> concatll(llist<T>,llist<T>);
        llist<T> operator+(llist<T>);
        void displayll();
};


template <class T>
void llist<T> :: clear()
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
void llist<T> :: insertllbef(T el)
{
    node *temp=new node;
    temp->info=el;
    if(isempty())
        first=temp;
    else
    {
        temp->next=first;
        first=temp;
    }
}

template <class T>
void llist<T> :: insertlllas(T el)
{
    node *temp=new node;
    node *tra;
    temp->info=el;
    if(isempty())
        first=temp;
    else
    {
        tra=first;
        while((tra->next)!=NULL)
        {
            tra=(tra->next);
        }
        tra->next=temp;
    }
}

template <class T>
T llist<T> :: deletellloc(int pos)
{
    if(isempty())
        throw 1;
    if(pos<0)
        throw 2;
    node *tra=new node;
    tra=first;
    if(pos==1)
    {
        first=tra->next;
        tra->next=NULL;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            tra=(tra->next);
            if(tra==NULL)
                throw 2;
        }
        node *tp=new node;
        tp=tra;
        tra=(tra->next);
        (tp->next)=(tra->next);
        tra->next=NULL;
    }
    T info=(tra->info);
    delete tra;
    return info;
}

template <class T>
bool llist<T> :: deletellel(T el)
{
    if(isempty())
        throw 1;
    bool flag=0;
    node *tra,*tp;
    tra=first;
    tp=NULL;
    if(tra->info==el)
    {
        first=tra->next;
        tra->next=NULL;
        delete tra;
        return true;
    }
    while((tra->info)!=el && (tra->next)!=NULL)
    {
        tp=tra;
        tra=(tra->next);
    }
    if((tra->info)==el)
    {
        tp->next=(tra->next);
        tra->next=NULL;
        delete tra;
        return true;
    }
    return false;
}

template <class T>
int llist<T> :: searchllel(T el)
{
    int pos=1;
    node *tra;
    if(isempty())
        throw 1;
    tra=first;
    if(tra->info==el)
        return 1;
    while((tra->info)!=el && (tra->next)!=NULL)
    {
        tra=(tra->next);
        pos++;
    }
    if(tra->info==el)
            return pos;
    throw 2;
}

template <class T>
T llist<T> :: searchllpos(int pos)
{
    if(isempty())
        throw 1;
    node *tra=new node;
    tra=first;
    for(int i=1;i<pos;i++)
    {
        tra=tra->next;
        if(tra==NULL)
            throw 2;
    }
    return tra->info;
}

template <class T>
void llist<T> :: displayll()
{
    cout<<endl;
    if(isempty())
        throw 1;
    node *tra=new node;
    tra=first;
    while(tra!=NULL)
    {
        cout<<" "<<tra->info;
        tra=tra->next;
    }
}

template <class T>
void llist<T> :: reversell()
{
    if(isempty())
        throw 1;
    node *t1,*t2,*t3;
    t2=t3=NULL;
    t1=first;
    if(!isempty() && (t1->next)!=NULL)
    {
        t2=t1->next;
        if(t2->next!=NULL)
            t3=t2->next;
        t1->next=NULL;
        while(t3!=NULL)
        {
            t2->next=t1;
            t1=t2;
            t2=t3;
            t3=t2->next;
        }
        t2->next=t1;
        first=t2;
    }
}

template <class T>
llist<T> llist<T> :: concatll(llist<T> ll1,llist<T> ll2)
{
    llist<T> ll3;
    if(ll1.isempty() && ll2.isempty())
    {
        ll3.first=NULL;
        return ll3;
    }
    node *n1,*n2,*n3;
    node *temp=new node;
    n1=ll1.first;
    n2=ll2.first;
    while(n1!=NULL && n2!=NULL)
    {
        if(n1->info < n2->info)
        {
            temp->info=n1->info;        
            n1=n1->next;
        }
        else
        {
            temp->info=n2->info;
            n2=n2->next;
        }
        ll3.insertlllas(temp->info);
    }
    while(n1!=NULL)
    {
        ll3.insertlllas(n1->info);
        n1=n1->next;
    }
    while(n2!=NULL)
    {
        ll3.insertlllas(n2->info);
        n2=n2->next;
    }
    return ll3;
}

template <class T>
llist<T> llist<T> :: operator+(llist<T> ll)
{
    llist<T> rell;
    if(isempty() && ll.isempty())
    {
        rell.first=NULL;
        return rell;
    }
    node *n1,*n2;
    n1=ll.first;
    n2=first;
    while(n1!=NULL && n2!=NULL)
    {
        if(n1->info < n2->info)
        {
            rell.insertlllas(n1->info);
            n1=n1->next;
        }
        else
        {
            rell.insertlllas(n2->info);
            n2=n2->next;
        }
    }
    while(n1!=NULL)
    {
        rell.insertlllas(n1->info);
        n1=n1->next;
    }
    while(n2!=NULL)
    {
        rell.insertlllas(n2->info);
        n2=n2->next;
    }
    return rell;
}

#endif	/* LLIST_H */
