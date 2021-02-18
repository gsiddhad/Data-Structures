/* 
 * llistst.h / Stack Linked List
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 2:35 PM
 */

#ifndef LLISTST_H
#define	LLISTST_H
#include <cstdio>

using namespace std;

template <class T>
class lliststack
{
    class node
    {
    public:
      T info;
      node *next;
      node(){
          info=0;
          next=NULL;
      }
    }*top;
    
    public:
        lliststack(){
            top=NULL;
        }
        void push(T);
        T pop();
        bool clear();
        bool isempty(){
            return (top==NULL);
        }
        void display();
};

template <class T>
void lliststack<T> :: push(T el)
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
T lliststack<T> :: pop()
{
    if(isempty())
        throw 1;
    else
    {
        T info=top->info;
        node *de=top;
        top=top->next;
        de->next=NULL;
        delete de;
        return info;
    }
}

template <class T>
void lliststack<T> :: display()
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
bool lliststack<T> :: clear()
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

#endif	/* LLISTST_H */