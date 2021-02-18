/* 
 * Linked List
 * Author : Gourav Siddhad
 * Created on April 6, 2014, 1:08 AM
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "llist.h"
using namespace std;

int main()
{
    llist<int> l;
    int ch=0;
    do{
        cout<<"\n Linked List Implementation";
        cout<<"\n 1. Enter New Element";
        cout<<"\n 2. Delete Element By Value";
        cout<<"\n 3. Delete Element At A Position";
        cout<<"\n 4. Search Element By Value";
        cout<<"\n 5. Search Element By Position";
        cout<<"\n 6. Reverse List";
        cout<<"\n 7. Concatenate Two Lists";
        cout<<"\n 8. Add Two Lists (operator+)";
        cout<<"\n 9. Display List";
        cout<<"\n 10. Exit";
        cout<<"\n Enter Choice : ";
        cin>>ch;
        system("clear");
        int el,pos,s;
        llist<int> l1,l2,l3;
        switch(ch)
        {
            case 1:
                cout<<"\n Enter Element : ";
                cin>>el;
                l.insertlllas(el);
                cout<<" Element Inserted Succesfully ";
                l.displayll();
                break;
            case 2:
                cout<<"\n Enter Element To Be Deleted : ";
                cin>>el;
                try{
                    if(l.deletellel(el))
                        cout<<" Element Succesfully Deleted ";
                    else
                        cout<<" Element Not Found ";
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                }
                l.displayll();
                break;
            case 3:
                cout<<"\n Enter Element Position To Be Deleted : ";
                cin>>pos;
                try{
                    if(l.deletellloc(pos))
                        cout<<" Element Succesfully Deleted ";
                    else
                        cout<<" Element Not Found ";
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                    if(er==2)   cout<<"\n Location Doesn't Exist";
                }
                l.displayll();
                break;
            case 4:
                cout<<"\n Enter Element To Be Searched : ";
                cin>>el;
                try{
                    int pos;
                    if(pos=l.searchllel(el))
                        cout<<"\n Element "<<el<<" Found At "<<pos;
                    else
                        cout<<"\n Element Not Found";
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                    if(er==2)   cout<<"\n Element Doesn't Exist";
                }
                break;
            case 5:
                cout<<"\n Enter Element Position To Be Searched : ";
                cin>>pos;
                try{
                    int el;
                    if(el=l.searchllpos(pos))
                        cout<<"\n Element At "<<pos<<" Is "<<el;
                    else
                        cout<<"\n Element No Found";
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                    if(er==2)   cout<<"\n Location Doesn't Exist";
                }
                break;        
            case 6:
                try{
                    l.reversell();
                    cout<<"\n Reversed List Is : \n";
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                }
                l.displayll();
                break;
            case 7:
                cout<<"\n Enter Size Of First Linked List : ";
                cin>>s;
                cout<<"\n Enter Elements In First Linked List : ";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l1.insertlllas(el);
                }
                cout<<"\n Enter Size Of Second Linked List : ";
                cin>>s;
                cout<<"\n Enter Elements In Second Linked List : ";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l2.insertlllas(el);
                }
                l3=l.concatll(l1,l2);
                cout<<"\n First Linked List : ";
                l1.displayll();
                cout<<"\n Second Linked List : ";
                l2.displayll();
                cout<<"\n Concatenated Linked List : ";
                l3.displayll();
                break;
            case 8:
                cout<<"\n Enter Size Of First Linked List : ";
                cin>>s;
                cout<<"\n Enter Elements In First Linked List : ";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l1.insertlllas(el);
                }
                cout<<"\n Enter Size Of Second Linked List : ";
                cin>>s;
                cout<<"\n Enter Elements In Second Linked List : ";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l2.insertlllas(el);
                }
                l3=l1+l2;
                cout<<"\n First Linked List : ";
                l1.displayll();
                cout<<"\n Second Linked List : ";
                l2.displayll();
                cout<<"\n Merged Linked List : ";
                l3.displayll();
                break;
            case 9:
                try{
                    l.displayll();
                }catch(int er){
                    if(er==1)   cout<<"\n Linked List Empty";
                }
                break;
        }
        cout<<endl;
    }while(ch!=10);
    return 0;
}