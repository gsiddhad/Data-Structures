/* 
 * hash.h / Hash
 * Author : Gourav Siddhad
 * Created on April 19, 2014, 2:00 PM
 */

#ifndef HASH_H
#define	HASH_H
using namespace std;

class table{
    int tsize,total;
    class node{
    public:
        int key;
        int marker;
        node(){
            key=0;
            marker=-2;
        }
    }*htable;
public:
    table(){
        tsize=10;
        total=0;
    }
    bool isempty(){
        return total==0;
    }
    bool isfull(){
        return total==tsize;
    }
    void inserth(int);
    bool deleteh(int);
    int search(int);
    void display();
};

void table :: inserth(int k)
{
    if(isfull())
        throw 3;
    
    int hindex=0;
    hindex=k%tsize;
    
    while(htable[hindex].marker==1)
        hindex=(++hindex)%tsize;
   
    htable[hindex].key=k;
    htable[hindex].marker=1;
    total++;
}

bool table :: deleteh(int k)
{
    if(isempty())
        throw 1;
    
    int count=0,hindex=k % tsize;
    
    while(htable[hindex].key!=k && count<=tsize)
        hindex=(++hindex)%tsize;
    
    if(htable[hindex].key==k){
        htable[hindex].marker=-2;
        total--;
    }
    else
        throw 2;
}

int table :: search(int k)
{
    if(isempty())
        throw 1;
    
    int count=0,hindex=k % tsize;
    
    while(htable[hindex].key!=k && count<=tsize)
        hindex=(++hindex)%tsize;
    
    if(htable[hindex].key!=k)
        return hindex;
    else
        throw 2;
}

void table :: display()
{
    if(isempty())
        throw 1;
    cout<<" Index Key";
    for(int i=0;i<tsize;i++)
    {
        cout<<endl<<i;
        if(htable[i].marker==1)
            cout<<" "<<htable[i].key;
    }
}

#endif	/* HASH_H */