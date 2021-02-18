/* 
 * Reverse Stack Using Queue
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 3:24 PM
 */

#include <iostream>
#include <cstdlib>
#include "stqu_st.h"
#include "stqu_qu.h"
using namespace std;

int main()
{
    mystack<int> s;
    myqueue<int> q;
    int el,ch=0;
    
    do{
        cout<<"\n Stack Implementation";
        cout<<"\n 1. Push";
        cout<<"\n 2. Pop";
        cout<<"\n 3. Clear";
        cout<<"\n 4. Reverse Using Queue";
        cout<<"\n 5. Display";
        cout<<"\n 6. Exit";
        cout<<"\n Enter Choice .. ";
        cin>>ch;
        system("clear");
        cout<<endl;
        switch(ch)
        {
            case 1:
                cout<<" Enter Element To Push : ";
                cin>>el;
                s.push(el);
                cout<<" Element "<<el<<" Pushed Succesfully";
                try{
                    s.display();
                }catch(int er){
                    if(er==1)   cout<<" Stack Empty";
                }
                break;
            case 2:
                try{
                    el=s.pop();
                    cout<<" Element "<<el<<" Poped Succesfully";
                    s.display();
                }catch(int er){
                    if(er==1)   cout<<" Stack Empty";
                }
                break;
            case 3:
                try{
                 if(s.clear())
                     cout<<" Stack Cleared Succesfully";
                }catch(int er){
                    if(er==1)   cout<<" Stack Empty";
                }
                 break;
            case 4:
                while(!s.isempty())
                    q.enqueue(s.pop());
                while(!q.isempty())
                    s.push(q.dequeue());
                cout<<" Stack Reversed Successfully ";
                try{
                    s.display();
                }catch(int er){
                    if(er==1)   cout<<" Stack Empty";
                }
                break;
            case 5:
                try{
                    s.display();
                }catch(int er){
                    if(er==1)   cout<<" Stack Empty";
                }
                break;
        }
        cout<<endl;
    }while(ch!=6);
    return 0;
}