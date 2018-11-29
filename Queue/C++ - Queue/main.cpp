/* 
 * Queue
 * Author : Gourav Siddhad
 * Created on February 20, 2014, 11:10 PM
 */

#include <iostream>
#include <cstdlib>
#include "queu.h"
using namespace std;

int main()
{
    myqueue <int> q;
    while(1)
    {
        cout<<"\t Queue Using Array\n";
        cout<<" 01. Enqueue\n";
        cout<<" 02. Dequeue\n";
        cout<<" 03. Display\n";
        cout<<" 04. Exit\n";
        cout<<" Enter Choice ... ";
        int ch;
        cin>>ch;
        system("clear");
        switch(ch)
        {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout<<" Enter Valid Choice .. \n";
        }
    }
    return 0;
}