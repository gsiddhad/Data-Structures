/* 
 * Double Linked List
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 4:55 PM
 */

#include <iostream>
#include <cstdlib>
#include "dllist.h"
using namespace std;

int main()
{
    dllist<int> dll;
    int ch = 0, el;
    do
    {
        cout << "\n Double Linked List";
        cout << "\n 1. Enter New Element";
        cout << "\n 2. Delete Element";
        cout << "\n 3. Clear List";
        cout << "\n 4. Search Element";
        cout << "\n 5. Reverse List";
        cout << "\n 6. Display List";
        cout << "\n 7. Exit";
        cout << "\n Enter Choice .. ";
        cin >> ch;
        system("clear");
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << " Enter New Element : ";
            cin >> el;
            dll.insert(el);
            cout << " Element Entered Successfully";
            dll.display();
            break;
        case 2:
            cout << " Enter Element To Be Deleted : ";
            cin >> el;
            try
            {
                if (dll.deleteel(el))
                    cout << " Element " << el << " Deleted Succesfully";
                dll.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " List Empty";
                if (er == 2)
                    cout << " Element Not Found";
            }
            break;
        case 3:
            if (dll.clear())
                cout << " List Cleared Succesfully";
            break;
        case 4:
            cout << " Enter Element To Be Searched : ";
            cin >> el;
            int pos;
            try
            {
                if (pos = dll.searchel(el))
                    cout << " Element " << el << " Found At Position " << pos;
                dll.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " List Empty";
                if (er == 2)
                    cout << " Element Not Found";
            }
            break;
        case 5:
            try
            {
                dll.reverse();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " List Empty";
            }
            break;
        case 6:
            try
            {
                dll.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " List Empty";
            }
            break;
        }
        cout << endl;
    } while (ch != 7);
    return 0;
}