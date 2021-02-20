/* 
 * Stack Linked List
 * Author : Gourav Siddhad
 * Created on April 7, 2014, 12:23 PM
 */

#include <iostream>
#include "llistst.h"
#include <cstdlib>
using namespace std;

int main()
{
    int ch = 0, el;
    lliststack<int> llst;
    do
    {
        cout << "\n Stack Implementation Using Linked List";
        cout << "\n 1. Push";
        cout << "\n 2. Pop";
        cout << "\n 3. Clear";
        cout << "\n 4. Display";
        cout << "\n 5. Exit";
        cout << "\n Enter Choice : ";
        cin >> ch;
        system("clear");
        switch (ch)
        {
        case 1:
            cout << "\n Enter Element To Push : ";
            cin >> el;
            llst.push(el);
            cout << " Element Pushed Succesfully";
            llst.display();
            break;
        case 2:
            try
            {
                el = llst.pop();
                cout << " Element " << el << " Poped Succesfully";
                llst.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Stack Empty";
            }
            break;
        case 3:
            if (llst.clear())
                cout << " Stack Cleared Succesfully";
            break;
        case 4:
            try
            {
                llst.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Stack Empty";
            }
            break;
        }
        cout << endl;
    } while (ch != 5);
    return 0;
}