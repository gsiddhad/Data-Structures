/* 
 * Ordered Linked List
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 12:15 PM
 */

#include <iostream>
#include <cstdlib>
#include "oll.h"
using namespace std;

int main()
{
    oll<int> l;
    int el=0,pos=0,s=0,ch=0;
    do{
        cout<<"\n Ordered Linked List";
        cout<<"\n 1. Enter New Element";
        cout<<"\n 2. Delete Element";
        cout<<"\n 3. Merge Two Lists";
        cout<<"\n 4. Display List";
        cout<<"\n 5. Exit";
        cout<<"\n Enter Choice : ";
        cin>>ch;
        system("clear");
        cout<<endl;
        switch(ch)
        {
            case 1:
                cout<<" Enter Element : ";
                cin>>el;
                l.insertel(el);
                cout<<" Element Inserted Succesfully ";
                l.display();
                break;
            case 2:
                cout<<" Enter Element To Be Deleted : ";
                cin>>el;
                try{
                    if(l.deleteel(el))
                        cout<<" Element Succesfully Deleted ";
                    else
                        cout<<" Element Not Found ";
                }catch(int er){
                    if(er==1)   cout<<" Linked List Empty";
                }
                l.display();
                break;
            case 3:
            {
                oll<int> l1,l2,l3;
                cout<<" Enter Size Of First Linked List : ";
                cin>>s;
                cout<<" Enter Elements In First Linked List : \n";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l1.insertel(el);
                }
                cout<<" Enter Size Of Second Linked List : ";
                cin>>s;
                cout<<" Enter Elements In Second Linked List : \n";
                for(int i=1;i<=s;i++)
                {
                    cout<<" Enter Element No. "<<i<<" : ";
                    int el;
                    cin>>el;
                    l2.insertel(el);
                }
                l3=l.merge(l1,l2);
                cout<<"\n First Linked List : ";
                try{
                    l1.display();
                }catch(int er){
                    if(er==1)   cout<<" Empty List";
                }
                cout<<"\n Second Linked List : ";
                try{
                    l2.display();
                }catch(int er){
                    if(er==1)   cout<<" Empty List";
                }
                cout<<"\n Merged Linked List : ";
                try{
                    l3.display();
                }catch(int er){
                    if(er==1)   cout<<" Empty List";
                }
                cout<<endl;
            }
                break;
            case 4:
                try{
                    l.display();
                }catch(int er){
                    if(er==1)   cout<<" Linked List Empty";
                }
                break;
        }
        cout<<endl;
    }while(ch!=5);
    return 0;
}