/* 
 * stst.h / Reverse Stack
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 3:10 PM
 */

#ifndef STST_H
#define	STST_H
#include <cstdlib>
using namespace std;

template <class T>
class mystack
{
    class node{
    public:
        T info;
        node *next;
        node(){
            info=0;
            next=NULL;
        }
    }*top;
    
public:
    mystack(){
        top=NULL;
    }
    bool isempty(){
        return (top==NULL);
    }
    T topel(){
        return top->info;
    }
    void push(T);
    T pop();
    bool clear();
    void display();
};

template <class T>
void mystack<T> :: push(T el)
{
    node *temp=new node;
    temp->info=el;
    if(isempty())
        top=temp;
    else
    {
        temp->next=top;
        top=temp;
    }
}

template <class T>
T mystack<T> :: pop()
{
    T info=top->info;
    node *de=top;
    if(isempty())
        throw 1;
    else
    {
        top=top->next;
        de->next=NULL;
        delete de;
        return info;
    }
}

template <class T>
void mystack<T> :: display()
{
    cout<<endl;
    node *tra;
    tra=top;
    if(isempty())
        throw 1;
    while(tra!=NULL)
    {
        cout<<" "<<tra->info;
        tra=tra->next;
    }
}

template <class T>
bool mystack<T> :: clear()
{
    node *de;
    while(top!=NULL)
    {
        de=top;
        de->next=NULL;
        top=top->next;
        delete de;
    }
    return true;
}

#endif	/* STST_H */