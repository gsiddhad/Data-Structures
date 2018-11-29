/* 
 * Hash
 * Author : Gourav Siddhad
 * Created on April 10, 2014, 2:12 PM
 */

#include <iostream>
#include <cstdlib>
#include "hash.h"
using namespace std;

int main()
{
    int ch=0;
    table t;
    int k=0;
    do{
        cout<<"\n Hash Table Implementation";        
        cout<<"\n 1. Insert";
        cout<<"\n 2. Delete";
        cout<<"\n 3. Search";
        cout<<"\n 4. Display";
        cout<<"\n 5. Exit";
        cout<<"\n Enter Choice : ";
        cin>>ch;
        system("clear");
        cout<<endl;
        switch(ch)
        {
            case 1:
                try{
                    cout<<" Enter Element To Be Inserted : ";
                    cin>>k;
                    cout<<"hello";
                    t.inserth(k);
                    cout<<" Key "<<k<<" Inserted";
                }catch(int er){
                    if(er==3)   cout<<" Table Full";
                }
                break;
            case 2:
                try{
                    cout<<" Enter Element To Be Deleted : ";
                    cin>>k;
                    t.deleteh(k);
                    cout<<" Key "<<k<<" Deleted";
                }catch(int er){
                    if(er==1)   cout<<" Table Empty";
                    if(er==2)   cout<<" Element Doesn't Exist";
                }
                break;
            case 3:
                try{
                    cout<<" Enter Element To Be Searched : ";
                    cin>>k;
                    cout<<" Element Found At Position "<<t.search(k);
                }catch(int er){
                    if(er==1)   cout<<" Table Empty";
                    if(er==2)   cout<<" Element Doesn't Exist";
                }
                break;
            case 4:
                try{
                    t.display();
                }catch(int er){
                    if(er==1)   cout<<" Table Empty";
                }
                break;
        }
        cout<<endl;
    }while(ch!=5);
    return 0;
}