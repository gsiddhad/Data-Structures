/* 
 * Circular Linked List
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 12:07 AM
 */

#include <iostream>
#include <cstdlib>
#include "cllist.h"
using namespace std;

int main()
{
    cllist<int> cll;
    int ch=0,el=0;
    do{
        cout<<"\n Cicular Linked List";
        cout<<"\n 1. Enter New Element";
        cout<<"\n 2. Delete Element";
        cout<<"\n 3. Clear List";
        cout<<"\n 4. Search Element";
        cout<<"\n 5. Reverse List";
        cout<<"\n 6. Display List";
        cout<<"\n 7. Exit";
        cout<<"\n Enter Choice .. ";
        cin>>ch;
        system("clear");
        cout<<endl;
        switch(ch)
        {
            case 1:
                cout<<" Enter New Element : ";
                cin>>el;
                cll.insertel(el);
                cout<<" Element Entered Successfully";
                try{
                    cll.display();
                }catch(int er){
                    if(er==1)   cout<<" Linked List Empty";
                }
                break;
            case 2:
                cout<<" Enter Element To Be Deleted : ";
                cin>>el;
                try{
                if(cll.deleteel(el))
                    cout<<" Element "<<el<<" Deleted Succesfully";
                cll.display();
                }catch(int er){
                    if(er==1)   cout<<" List Empty";
                    if(er==2)   cout<<" Element Not Found";
                }
                break;
            case 3:
                try{
                    if(cll.clear())
                        cout<<" List Cleared Succesfully";
                }catch(int er){
                    if(er==1)   cout<<" List Empty";
                }
                break;
            case 4:
                cout<<" Enter Element To Be Searched : ";
                cin>>el;
                int pos;
                try{
                    if(pos=cll.searchel(el))
                        cout<<" Element "<<el<<" Found At Position "<<pos;
                    cll.display();
                }catch(int er){
                    if(er==1)   cout<<" List Empty";
                    if(er==2)   cout<<" Element Not Found";
                }
                break;
            case 5:
                try{
                    cll.reverse();
                    cout<<" Reversed List Is : ";
                    cll.display();
                }catch(int er){
                    if(er==1)   cout<<" List Empty";
                }
                break;
            case 6:
                try{
                    cll.display();
                }catch(int er){
                    if(er==1)   cout<<" List Empty";
                }
                break;
        }
        cout<<endl;
    }while(ch!=7);
    return 0;
}