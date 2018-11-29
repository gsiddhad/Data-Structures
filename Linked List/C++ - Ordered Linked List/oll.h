/* 
 * oll.h / Ordered Linked List
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 12:15 PM
 */

#ifndef OLL_H
#define	OLL_H
using namespace std;

template <class T>
class oll
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
        oll(){
            first=NULL;
        }
        bool isempty(){
            return first==NULL;
        }
        void clear();
        void insertel(T);
        bool deleteel(T);
        oll<T> merge(oll<T>,oll<T>);
        void display();
};

template <class T>
void oll<T> :: clear()
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
void oll<T> :: insertel(T el)
{
    node *tp,*tra,*temp=new node();    
    temp->info=el;
    tra=first;
    tp=NULL;
    
    if(isempty())
        first=temp;
    else if(tra->info >= el) //first position
    {
        temp->next=first;
        first=temp;
    }
    else
    {
        while((tra->info)<=el && (tra->next)!=NULL)
        {
            tp=tra;
            tra=(tra->next);
        }
        if(tra->info > el)
        {
            temp->next=tp->next;
            tp->next=temp;
        }
        else if((tra->info)<=el)
        {
            tra->next=temp;
        }
    }
}

template <class T>
bool oll<T> :: deleteel(T el)
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
void oll<T> :: display()
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
oll<T> oll<T> :: merge(oll<T> ll1,oll<T> ll2)
{
    oll<T> ll3;
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
        ll3.insertel(temp->info);
    }
    while(n1!=NULL)
    {
        ll3.insertel(n1->info);
        n1=n1->next;
        
    }
    while(n2!=NULL)
    {
        ll3.insertel(n2->info);
        n2=n2->next;
    }
    return ll3;
}
#endif	/* OLL_H */