/* 
 * Queue Linked LIst
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 12:24 PM
 */

#include <iostream>
#include <cstdlib>
#include "llistqu.h"
using namespace std;

int main()
{
    llistqueue<int> llqu;
    int ch = 0, el;
    do
    {
        cout << "\n Queue Implementation Using Linked List";
        cout << "\n 1. Enqueue";
        cout << "\n 2. Dequeue";
        cout << "\n 3. Clear";
        cout << "\n 4. Display";
        cout << "\n 5. Exit";
        cout << "\n Enter Choice .. ";
        cin >> ch;
        system("clear");
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << " Enter Element To Enqueue : ";
            cin >> el;
            llqu.enqueue(el);
            cout << " Element Enqueued Successfully";
            llqu.display();
            break;
        case 2:
            try
            {
                el = llqu.dequeue();
                cout << " Element Dequeued Is " << el;
                llqu.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Queue Empty";
            }
            break;
        case 3:
            if (llqu.clear())
                cout << " Queue Cleared Succesfully";
            break;
        case 4:
            try
            {
                llqu.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Queue Empty";
            }
            break;
        }
        cout << endl;
    } while (ch != 5);
    return 0;
}
